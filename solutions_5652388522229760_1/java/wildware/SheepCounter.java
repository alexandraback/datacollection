package software.wild.qualification.sheep;

import org.testng.annotations.Test;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.HashSet;
import java.util.Set;

import static java.lang.Integer.parseInt;
import static org.testng.Assert.assertEquals;

public class SheepCounter {

    public static void main(String[] args) throws Exception {
        String baseURL = args[0];
        String inFileName = "sheep_counter_large.in";

        consumeInput(baseURL, inFileName);
    }

    public static void consumeInput(String baseURL, String inFileName) throws Exception {
        String outFileNAme = inFileName.split("\\.")[0] + ".out";
        try (
                BufferedReader reader = new BufferedReader(new FileReader(new File(baseURL, inFileName)));
                PrintWriter writer = new PrintWriter(new File(baseURL, outFileNAme))
        ) {
            Integer numTests = parseInt(reader.readLine());
            for(int i=0; i<numTests; i++) {
                BigInteger n = new BigInteger(reader.readLine());
                String answer = solve(n);
                writer.println(String.format("Case #%d: %s", i+1, answer));
            }
        }
    }

    @Test
    public void testSolver() {
        assertEquals(solve(2), "90");
        assertEquals(solve(11), "110");
        assertEquals(solve(1), "10");
        assertEquals(solve(0), "INSOMNIA");
        assertEquals(solve(10000000), "90000000");
    }

    @Test
    public void testAllDontThrowExceptions() {
        BigInteger i = new BigInteger("10000000");
        while(!i.equals(BigInteger.ZERO)) {
            solve(i);
            i = i.subtract(BigInteger.ONE);
            if(i.mod(new BigInteger("1000")).equals(BigInteger.ZERO))
                System.out.println(i);
        }
    }

    public static String solve(int n) {
        return solve(BigInteger.valueOf(n));
    }

    public static String solve(BigInteger n) {
        BigInteger sheep = getSheep(n);
        return sheep == null ? "INSOMNIA" : sheep.toString();
    }

    public static final BigInteger TEN = new BigInteger("10");

    public static BigInteger getSheep(BigInteger n) {
        Set<BigInteger> nums = new HashSet<>();
        BigInteger lastVal = n;
        BigInteger val = n;

        while(nums.size() < 10) {
            if(val.equals(BigInteger.ZERO)) {
                val = lastVal.add(n);
                lastVal = val;
                if(lastVal.equals(n))
                    return null;
            }

            BigInteger digit = val.mod(TEN);
            nums.add(digit);
            val = val.divide(TEN);
        }
        return lastVal;
    }
}
