package software.wild.qualification.jamcoin;

import com.google.common.base.Stopwatch;
import org.testng.annotations.Test;

import java.io.File;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.*;

import static org.testng.Assert.*;

public class JamcoinGenerator {
    private static final BigInteger TWO = new BigInteger("2");

    public static void main(String[] args) throws Exception {
        String base = args[0];
        String smallOut = "jamcoin_small.out";
        String largeOut = "jamcoin_large.out";

        writeSolution(base, smallOut, 16, 50);
        writeSolution(base, largeOut, 32, 500);
    }

    private static void writeSolution(String base, String filename, int length, int size) throws Exception {
        try(PrintWriter writer = new PrintWriter(new File(base, filename))) {
            writer.println("Case #1:");
            for(String line : solve(length, size)) {
                writer.println(line);
            }
        }
    }

    private static List<String> solve(int length, int num) {
        List<String> solutions = new ArrayList<>(num);
        for(Jamcoin jamcoin : generateJamcoins(length, num)) {
            StringBuilder builder = new StringBuilder();
            builder.append(jamcoin.value);
            for(Integer divisor : jamcoin.getNontrivialDivisors()) {
                builder.append(" ").append(divisor);
            }
            solutions.add(builder.toString());
        }
        return solutions;
    }

    private static Collection<Jamcoin> generateJamcoins(int length, int num) {
        Set<Jamcoin> jamcoins = new LinkedHashSet<>();
        String value = generateFirstJamcoinValue(length);
        BigInteger v = null;

        while(jamcoins.size() < num) {
            Jamcoin j;
            do {
                v = v==null ? new BigInteger(value, 2) : v.add(TWO);
                j = new Jamcoin(v.toString(2));
            } while(jamcoins.contains(j) || !j.isValid());
            jamcoins.add(j);
        }

        return jamcoins;
    }

    private static String generateFirstJamcoinValue(int length) {
        String value = "1";
        for(int i=1; i<length-1; i++)
            value += "0";
        value += "1";
        return value;
    }

    public static class Jamcoin {
        final String value;
        List<Integer> nontrivialDivisors = new ArrayList<>();

        public Jamcoin(String value) {
            this.value = value;
        }

        public boolean isValid() {
            return value.length() > 2 &&
                    value.startsWith("1") &&
                    value.endsWith("1") &&
                    getNontrivialDivisors().size() == 9;
        }

        public List<Integer> getNontrivialDivisors() {
            if(nontrivialDivisors.size() == 9)
                return nontrivialDivisors;

            for(int i = 2; i<=10; i++) {
                BigInteger integer = new BigInteger(value, i);
                if(integer.isProbablePrime(3))
                    break;

                BigInteger divisor = getDivisor(integer);
                if(divisor != null)
                    nontrivialDivisors.add(divisor.intValue());
                else
                    break;
            }

            return nontrivialDivisors;
        }

        @Override
        public int hashCode() {
            return value.hashCode();
        }
    }

    private static BigInteger getDivisor(BigInteger n) {
        Double val = Double.valueOf(n.toString(10));
        double max = Math.min(1000, Math.sqrt(val));
        for(int i=2; i<=max; i++) {
            BigInteger bigI = BigInteger.valueOf(i);
            if(n.mod(bigI).equals(BigInteger.ZERO))
                return bigI;
        }
        return null;
    }

    @Test
    public void testJamcoinValidity() {
        assertValidJamcoin("100011");
        assertValidJamcoin("110011");
        assertValidJamcoin("111111");
        assertValidJamcoin("111001");
        assertValidJamcoin("1001");
        assertValidJamcoin("10000000000000000000000000000001");

        assertNotValidJamcoin("11");
        assertNotValidJamcoin("101");
        assertNotValidJamcoin("0000101");
        assertNotValidJamcoin("1000010");
        assertNotValidJamcoin("1");
        assertNotValidJamcoin("0");
        assertNotValidJamcoin("");
    }

    @Test
    public void testGenerationSmall() {
        testGeneration(16, 50);
    }

    @Test
    public void testGenerationLarge() {
        testGeneration(32, 500);
    }

    private void testGeneration(int length, int size) {
        Stopwatch s = Stopwatch.createStarted();
        Collection<Jamcoin> coinset = generateJamcoins(length, size);
        s.stop();
        System.out.println(s);

        assertEquals(coinset.size(), size);
        Iterator<Jamcoin> iter = coinset.iterator();
        while(iter.hasNext()) {
            Jamcoin j = iter.next();
            assertEquals(j.value.length(),length);
            assertTrue(j.isValid());
            assertEquals(j.getNontrivialDivisors().size(), 9);
            assertValidDivisors(j);
        }
    }

    private void assertValidDivisors(Jamcoin jamcoin) {
        Iterator<Integer> iter = jamcoin.getNontrivialDivisors().iterator();
        for(int i=2; i<=10; i++) {
            Integer next = iter.next();
            BigInteger big = new BigInteger(jamcoin.value, i);
            assertNotNull(next);
            assertNotEquals(next, 1);
            assertNotEquals(next.toString(), big.toString(10));
            BigInteger divisor = BigInteger.valueOf(next);
            BigInteger remainder = big.divideAndRemainder(divisor)[1];
            assertTrue(remainder.equals(BigInteger.ZERO));
        }
    }

    private void assertValidJamcoin(String value) {
        Jamcoin j = new Jamcoin(value);
        assertTrue(j.isValid());
        assertValidDivisors(j);
    }

    private void assertNotValidJamcoin(String value) {
        Jamcoin j = new Jamcoin(value);
        assertFalse(j.isValid());
    }
}
