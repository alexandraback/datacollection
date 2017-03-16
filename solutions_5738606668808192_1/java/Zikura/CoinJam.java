import java.math.BigInteger;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class CoinJam {

    private final int numCoins;
    private final String initialCoin;
    private final Long initialMask;

    private List<BigInteger> primes;

    public CoinJam(int coinLength, int numCoins) {
        this.numCoins = numCoins;

        initialCoin = generateInitialCoin(coinLength);
        initialMask = Long.parseLong(initialCoin, 2);

        System.out.println("Generating primes");
        primes = new PrimeSieve().getPrimes();
        System.out.println("Finished generating primes");
    }


    public void generateCoins() {
        int coinsFound = 0;
        String possibleCoin = initialCoin;

        System.out.println("Case #1:");
        while(coinsFound < numCoins) {
            List<BigInteger> divisors = isJamCoin(possibleCoin);
            if(divisors != null) {
                printCase(possibleCoin, divisors);
                coinsFound++;
            }

            possibleCoin = generateNextCoin(possibleCoin);
        }
    }

    private void printCase(String possibleCoin, List<BigInteger> divisors) {
        StringBuilder sb = new StringBuilder();
        sb.append(possibleCoin);
        for(BigInteger divisor : divisors) {
            sb.append(" ").append(divisor);
        }
        System.out.println(sb.toString());
    }

    protected String generateNextCoin(String possibleCoin) {
        Long number = Long.parseLong(possibleCoin, 2);
        do {
          number++;
        } while((number & initialMask)!=initialMask);
        return Long.toBinaryString(number);
    }

    protected List<BigInteger> isJamCoin(String possibleCoin) {
        List<BigInteger> divisors = new ArrayList<BigInteger>();

        StringBuilder sb = new StringBuilder();
        sb.append("possibleCoin=").append(possibleCoin);
        for(int radix=2;radix<=10;radix++) {
            BigInteger number = new BigInteger(possibleCoin, radix);
            sb.append("\nradix=").append(radix).append(", number=").append(number);

            boolean found = false;

            for(BigInteger prime : primes) {
                if(number.mod(prime)==BigInteger.ZERO && prime.compareTo(number)<0) {
                    divisors.add(prime);
                    sb.append(", divisor=").append(prime);
                    found = true;
                    break;
                }
            }
            if(!found) {
                return null;
            }
        }
//        System.out.println(sb);
        return divisors;
    }

    public static String generateInitialCoin(int coinLength) {
        StringBuilder sb = new StringBuilder();
        sb.append("1");
        while(coinLength-->2) {
            sb.append("0");
        }
        sb.append("1");
        return sb.toString();
    }

    public static void main(String[] args) {

        Scanner s = new Scanner(System.in);
        int numCases = s.nextInt();
        for(int i=1;i<=numCases;i++) {
            int coinLength = s.nextInt();
            int numCoins = s.nextInt();
            new CoinJam(coinLength, numCoins).generateCoins();
        }
    }
}

class PrimeSieve {

    private static final Integer MAX_VALUE = Integer.MAX_VALUE/4;

    boolean[] isNotPrime = new boolean[MAX_VALUE];

    public PrimeSieve() {
        for(int i=2;i<MAX_VALUE;i++) {
            if(!isNotPrime[i]) {
                for(int j=2*i;j<MAX_VALUE; j+=i) {
                    isNotPrime[j] = true;
                }
            }
        }
    }

    public List<BigInteger> getPrimes() {
        List<BigInteger> primes = new ArrayList<BigInteger>();

        for(int i=2;i<MAX_VALUE;i++) {
            if(!isNotPrime[i]) {
                primes.add(BigInteger.valueOf(i));
            }
        }
        return primes;
    }
}