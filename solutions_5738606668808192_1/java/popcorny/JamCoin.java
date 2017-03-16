package idv.popcorny.jam2016;

import java.io.File;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.Scanner;

/**
 * Created by popcorny on 4/9/16.
 */
public class JamCoin {

    private static int primes[] = {
            2,      3,      5,      7,     11,     13,     17,     19,     23,     29,
            31,     37,     41,     43,     47,     53,     59,     61,     67,     71,
            73,     79,     83,     89,     97,    101,    103,    107,    109,    113,
            127,    131,    137,    139,    149,    151,    157,    163,    167,    173,
            179,    181,    191,    193,    197,    199,    211,    223,    227,   229,
            233,    239,    241,    251,    257,    263,    269,    271,    277,    281,
            283,    293,    307,    311,    313,    317,    331,    337,    347,    349,
            353,    359,    367,    373,    379,    383,    389,    397,    401,    409,
            419,    421,    431,    433,    439,    443,    449,    457,    461,    463,
            467,    479,    487,    491,    499,    503,    509,    521,    523,    541,
            547,    557,    563,    569,    571,    577,    587,    593,    599,    601,
            607,    613,    617,    619,    631,    641,    643,    647,    653,    659,
            661,    673,    677,    683,    691,    701,    709,    719,    727,    733,
            739,    743,    751,    757,    761,    769,    773,    787,    797,    809,
            811,    821,    823,    827,    829,    839,    853,    857,    859,    863,
            877,    881,    883,    887,    907,    911,    919,    929,    937,    941,
            947,    953,    967,    971,    977,    983,    991,    997,   1009,   1013
    };
    private static BigInteger[] bprimes;

    static {
        bprimes = new BigInteger[primes.length];
        for (int i=0; i<primes.length;i++) {
            bprimes[i] = BigInteger.valueOf(primes[i]);
        }
    }

    String str;
    int[] ans;

    JamCoin(int n, int offset) {
        ans = new int[11];
        StringBuffer sb = new StringBuffer(n);
        sb.append("1");
        sb.append(String.format("%" + (n - 2) + "s", Integer.toBinaryString(offset)).replace(' ', '0'));
        sb.append("1");


        str =sb.toString();
    }

    @Override
    public String toString() {
        return String.format("%s %d %d %d %d %d %d %d %d %d",
                str,
                ans[2],ans[3],ans[4],ans[5],ans[6],ans[7],ans[8],ans[9],ans[10]);
    }


    public static JamCoin genCoin(int n, int offset) {

        JamCoin coin;
        boolean pass = true;
        coin = new JamCoin(n, offset);

        System.out.println(coin.str);
        outer: for (int i = 2; i <= 10; i++) {

            BigInteger value = new BigInteger(coin.str, i);
            for (int j=0; j<bprimes.length;j++) {
                BigInteger p = bprimes[j];

                if (value.compareTo(p) < 0) {
//                    System.out.printf("rule 1: %s > %d", value, p);
                    break;
                }

                if (value.mod(p).intValue() == 0) {
                    coin.ans[i] = p.intValue();

//                    System.out.printf("[%d] %s x %s = %s\n", i, p, value.divide(p), value);

                    continue  outer;
                }

            }
//            System.out.println("rule 2");

            pass = false;
            System.out.println(coin.str + " fail at base " + i);
            break;
        }

        return pass ? coin : null;
    }

    public static void main(String[] args) throws Exception {
        Scanner scanner;
        PrintWriter writer;
        String quizname = "jamcoin";
        String testname = "large";
        String input   = String.format("quiz/%s/%s.in", quizname, testname);
        String output  = String.format("quiz/%s/%s.out", quizname, testname);

        if (new File(input).exists()) {
            scanner = new Scanner(new File(input));
            if (testname.equals("sample")) {
                writer = new PrintWriter(System.out);
            } else {
                writer = new PrintWriter(output);
            }
        } else {
            scanner = new Scanner(System.in);
            writer = new PrintWriter(System.out);
        }


        int t = scanner.nextInt();

        for (int i = 0; i < t; i++) {
            int n = scanner.nextInt();
            int J = scanner.nextInt();


            writer.printf("Case #%d:\n", i+1);

            int offset = 0;
            for (int j=0; j<J; j++) {

                JamCoin jamCoin = null;

                do {
                    jamCoin = genCoin(n, offset++);
                } while(jamCoin == null);


                writer.println(jamCoin);
            }
        }
        writer.flush();
    }




}
