import java.awt.*;
import java.io.File;
import java.io.FileInputStream;
import java.io.PrintStream;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Scanner;

/**
 * Created by mengqingdi on 16/4/9.
 */
public class Test4 {
    public static void main(String[] args) throws Exception {

        System.setOut(new PrintStream(new File("test4.out")));

//        Scanner scan = new Scanner(new FileInputStream("test4.in"));
        Scanner scan = new Scanner(new FileInputStream("D-small-attempt0.in.txt"));

        int t = Integer.parseInt(scan.nextLine());

        for(int i = 1;i <=t; i++) {
            int k = scan.nextInt();
            int c = scan.nextInt();
            int s = scan.nextInt();

            if(k/c>s) {
                System.out.println("Case #"+i+": IMPOSSIBLE");
            } else {
                ArrayList<BigInteger> rtn= new ArrayList<BigInteger>();
                BigInteger base = new BigInteger(Integer.toString(k));
                for(int j = 0; j< k; j=j+c) {
                    BigInteger a = new BigInteger("0");
                    for(int l = 0; l<c; l++) {
                        a = a.add(base.pow(l).multiply(new BigInteger(Integer.toString((j+l)%k))));
                    }
                    rtn.add(a.add(BigInteger.ONE));
                }
                System.out.print("Case #"+i+":");
                for(BigInteger o : rtn) {
                    System.out.print(" "+o);
                }
                System.out.println();
            }

//            System.out.println(k+ " " + c + " "+s);

//            System.out.println("Case #"+i+": ");
        }
    }
}
