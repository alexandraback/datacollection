package by.home.sss.google.codejam;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.io.UnsupportedEncodingException;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.List;
import java.util.Random;
import java.util.Scanner;

/**
 * Created by Sergey on 4/9/2016.
 */
public class CoinJam {
    private static final String CHARSET_NAME = "US-ASCII";
    private static final int MAX_ATTEMPT = 100;
    private List<TestCase> testCases;
    private List<TestCaseResult> results;
    private List<BigInteger> primes;

    private class CoinJamWithProve {
        private String coinJam;
        BigInteger witnesses[] = new BigInteger[9];
    }

    private class TestCaseResult {
        List<CoinJamWithProve> coinJams;
    }

    private class TestCase {
        private final int length;
        private final int number;

        public TestCase(int length, int number) {
            this.length = length;
            this.number = number;
        }
    }

    private void init() throws FileNotFoundException {
        Scanner scanner = new Scanner(new File("input.txt"), CHARSET_NAME);
        try {
            if (scanner.hasNext()) {
                int numberOfTest = scanner.nextInt();
                testCases = new ArrayList<TestCase>(numberOfTest);
                results = new ArrayList<TestCaseResult>(numberOfTest);
                for (int i = 0;i < numberOfTest; i++){
                    if (scanner.hasNext()) {
                        testCases.add(new TestCase(scanner.nextInt(),scanner.nextInt()) );
                    }
                }
            }
        }
        finally {
            scanner.close();
        }
    }

    private BigInteger getDevisor(BigInteger condidate) {
        for (BigInteger prime: primes) {
            if ((prime.multiply(prime)).compareTo(condidate) > 0) {
                return null;
            }
            BigInteger mod = condidate.mod(prime);
            if (mod.compareTo(BigInteger.ZERO) == 0){
                return prime;
            }
        }
        return null;
    }

    private String getString(long inner, int len) {
        StringBuilder sb = new StringBuilder();
        sb.append("1");
        for (int i = 0; i < len; i++){
            sb.append(inner%2);
            inner /=2;
        }
        sb.append("1");
        return sb.reverse().toString();
    }

    private BigInteger longToDec(String number, int base){
        BigInteger result = BigInteger.ZERO;
        BigInteger mult = BigInteger.ONE;
        BigInteger bBase = BigInteger.valueOf(base);
//        long result = 0;
        for (int i = number.length()-1; i>=0;i--) {
            if (number.charAt(i) =='1') {
                result =  result.add(mult);
            }
            mult = mult.multiply( bBase);
        }
        return result;
    }

    private void solve() {
        for (TestCase testCase: testCases){
            TestCaseResult result = new TestCaseResult();
            result.coinJams = new ArrayList<CoinJamWithProve>(testCase.number);
            for (int i = 0; i < 2<<(testCase.length-3); i++) {
                CoinJamWithProve coinJamWithProve = new CoinJamWithProve();
                coinJamWithProve.coinJam = getString(i, testCase.length-2);
                boolean succsess = true;
//                long condidate = ((2<<(testCase.length-2) + i) << 1)+1;
                for (int j = 2; j <= 10; j++ ){
                    BigInteger condidate = longToDec(coinJamWithProve.coinJam, j);
                    BigInteger witness = getDevisor(condidate);
                    if (witness == null){
                        succsess = false;
                        break;
                    }
                    coinJamWithProve.witnesses[j-2] = witness;
                }
                if (succsess){
                    result.coinJams.add(coinJamWithProve);
                    System.out.println("Success: " +result.coinJams.size());
                    if (result.coinJams.size() == testCase.number) {
                        break;
                    }
                }
            }
            results.add(result);
        }
    }

    private void saveResults () throws FileNotFoundException, UnsupportedEncodingException {
        PrintWriter writer = new PrintWriter("output.txt",CHARSET_NAME);
        try {
            for (int i = 0; i < results.size(); i++) {
                writer.println(String.format("Case #%d:", i+1));
                TestCaseResult result = results.get(i);
                for (CoinJamWithProve coinJam: result.coinJams) {
                    StringBuilder sb = new StringBuilder();
                    sb.append(coinJam.coinJam);
                    for (int j = 0; j < 9; j++){
                        sb.append(" " );
                        sb.append(coinJam.witnesses[j]);
                    }
                    writer.println(sb.toString());
                }

            }
        }
        finally {
            writer.close();
        }

    }



    public static void main(String[] args) throws FileNotFoundException, UnsupportedEncodingException {
        CoinJam problem = new CoinJam();
//        problem.genInput();
        long start = System.currentTimeMillis();
        problem.init();
        problem.initPrimes();
        System.out.println("primes: " + (System.currentTimeMillis()-start));
        problem.solve();
        problem.saveResults();
        System.out.println(System.currentTimeMillis()-start);

    }

    private void initPrimes() {
        primes = new ArrayList<BigInteger>();
        for (int i =2; i < 1000000; i++){
            boolean isPrime = true;
            for (int j = 0; j<primes.size() ; j++){
                int existedP = primes.get(j).intValue();
                if (existedP*existedP > i) {
                    break;
                }
                if (i % existedP == 0) {
                    isPrime = false;
                    break;
                }
            }
            if (isPrime) {
                primes.add(BigInteger.valueOf(i));
            }
        }
        System.out.println(primes.size());
    }
}
