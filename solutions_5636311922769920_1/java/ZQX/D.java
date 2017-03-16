/**
 * Created by qixinzhu on 4/8/16.
 */

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;

public class D {

    public static void genLargeP () throws FileNotFoundException {
        File inputFile = new File("D-small-attempt0.in");
        PrintWriter out = new PrintWriter("test_b.txt");
        Scanner in = new Scanner(inputFile);
        int T = in.nextInt();
        out.println(T);
        for (int i=0; i<T; i++) {
            out.printf("%d\n",(int) (Math.random()*100000));
        }
        in.close();
        out.close();
    }



    public static void test3(int K) {
        String[] orgs = {"GGG","GGL","GLG","LGG","GLL","LGL","LLG","LLL"};
        for (int i=0;i<8;i++) {
            int temp = K;
            String org = new String(orgs[i]);
            while (temp > 1) {
                String cur = "";
                for (int j=0;j<orgs[i].length();j++) {
                    if (orgs[i].charAt(j) == 'G') {
                        cur += "GGG";
                    } else {
                        cur += org;
                    }
                }
                orgs[i] = cur;
                temp--;
            }
            System.out.printf("Org %s: %s\n", org, orgs[i]);
        }
    }

    public static void test4(int K) {
        String[] orgs = {"GGGG","GGGL","GGLG","GLGG","LGGG","GGLL","GLGL","LGGL","GLLG","LGLG","LLGG","GLLL","LGLL","LLGL","LLLG","LLLL"};
        for (int i=0;i<16;i++) {
            int temp = K;
            String org = new String(orgs[i]);
            while (temp > 1) {
                String cur = "";
                for (int j=0;j<orgs[i].length();j++) {
                    if (orgs[i].charAt(j) == 'G') {
                        cur += "GGGG";
                    } else {
                        cur += org;
                    }
                }
                orgs[i] = cur;
                temp--;
            }
            System.out.printf("Org %s: %s\n", org, orgs[i]);
        }
    }

    public static void main(String[] args) throws FileNotFoundException{
        // test case
//        genLargeP();
//        test4(3);
//        File inputFile = new File("test.txt");
//        PrintWriter out = new PrintWriter("test_out.txt");

        // real case
//        File inputFile = new File("D-small-attempt1.in");
//        PrintWriter out = new PrintWriter("D_out.txt");
        File inputFile = new File("D-large.in");
        PrintWriter out = new PrintWriter("D_out_large.txt");

        Scanner in = new Scanner(inputFile);

        int T = in.nextInt();
        for (int i=0;i<T;i++) {
            int K = in.nextInt();
            int C = in.nextInt();
            int S = in.nextInt();
            String clean = "";
            if (K == 1) {
                clean = "1";
            } else if (C == 1) {
                if (S == K) {
                    for (int j=0;j<K;j++) {
                        if (j>0) {
                            clean += " ";
                        }
                        clean += (j+1);
                    }
                } else {
                    clean = "IMPOSSIBLE";
                }
            } else {
                if (S >= K-1) {
                    for (int j=1;j<K;j++) {
                        if (j>1) {
                            clean += " ";
                        }
                        clean += (j+1);
                    }
                } else {
                    clean = "IMPOSSIBLE";
                }
            }
            out.printf("Case #%d: %s\n", i+1, clean);
        }

        in.close();
        out.close();
    }
}
