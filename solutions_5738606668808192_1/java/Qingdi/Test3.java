import java.io.File;
import java.io.FileInputStream;
import java.io.PrintStream;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Scanner;

/**
 * Created by mengqingdi on 16/4/9.
 */
public class Test3 {

    public static void main(String[] args) throws Exception{

//        System.setOut(new PrintStream(new File("test3.out")));
        Scanner scan = new Scanner(new FileInputStream("test3.in"));
//    Scanner scan = new Scanner(new FileInputStream("A-small-attempt0.in.txt"));

        int t = Integer.parseInt(scan.nextLine());
        int n = scan.nextInt();
        int j = scan.nextInt();

        long a = (1L<<n-1) + 1;
        long top = 1L<<n;

//        System.out.println(Long.toBinaryString(a));
//        System.out.println(Long.toBinaryString(top));

        int c = 0;

        System.out.println("Case #1:");
        while(a < (1L<<n)) {
//            System.out.println(Long.toBinaryString(a));
            HashMap<Integer, BigInteger> divs = new HashMap<Integer, BigInteger>();

            for(int i=2;i<=10;i++) {

//                System.out.println(i);
                BigInteger cand = new BigInteger("0");
                BigInteger current = new BigInteger("1");
                BigInteger base = new BigInteger(Integer.toString(i));

                long temp = a;

                while(temp>0) {
//                    System.out.println(temp);
//                    System.out.println(current);
//                    System.out.println(cand);

                    if (temp % 2 == 1) {
                        cand = cand.add(current);
                    }
                    temp /=2;
                    current = current.multiply(base);
                }
                if (cand.isProbablePrime(2)) {
//                    System.out.println(cand +"is prime");
                    break;
                }
                else {
                    for (BigInteger pi = new BigInteger("2");  ;pi = pi.nextProbablePrime()) {

                        if (pi.compareTo(new BigInteger("300000"))>0)
                            break;

//                        System.out.println(pi);

                        if(pi.compareTo(cand.divide(pi)) > 0) {
                            break;
                        }

                        if(cand.mod(pi).compareTo(BigInteger.ZERO) == 0) {
                            divs.put(i,pi);
                            break;
                        }
                    }
                }
                if (!divs.containsKey(i)) {
                    break;
                } else {
                    continue;
                }
            }

            if(divs.size()==9) {
                System.out.print(Long.toBinaryString(a));
                for(int i=2;i<=10;i++) {
                    System.out.print(" " + divs.get(i));
                }
                System.out.println();
                c++;
            }

            a+=2L;

            if (c==j)
                break;
        }

//        System.out.println(t+" "+n+" " +j);
    }
}
