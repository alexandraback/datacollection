package test2;
import java.io.*;
import java.util.*;

public class Test {
    final static String WORK_DIR = "C:\\Users\\Sola\\Desktop\\";
    
    static int[][] b;
    
    public static void main (String[] args) throws IOException {

        //generateInput(100);
        Scanner sc = new Scanner(new FileReader(WORK_DIR + "test.in"));
        PrintWriter pw = new PrintWriter(new FileWriter(WORK_DIR + "test.out"));

        int tc = sc.nextInt();
        
        for (int tci=1;tci<=tc;tci++) {
            int N = sc.nextInt();
            float[] naomi = new float[N];
            float[] ken = new float[N];
            for (int i=0;i<N;i++) {
                naomi[i] = sc.nextFloat();
            }
            for (int i=0;i<N;i++) {
                ken[i] = sc.nextFloat();
            }
            Arrays.sort(naomi);
            Arrays.sort(ken);
            int n = 0;
            int k = 0;
            int kw = 0;
            while (n<N && k<N) {
                if (ken[k]<naomi[n]) {
                    k++;
                }
                else {
                    k++;
                    n++;
                    kw++;
                }
            }
            int nw = N-kw;
            
            int ndw = 0;
            n = N-1;
            k = N-1;
            while (n>=0 && k>=0) {
                if (ken[k]>naomi[n]) {
                    k--;
                }
                else {
                    k--;
                    n--;
                    ndw++;
                }
            }
            
            pw.println("Case #" + tci + ": " + ndw + " " + nw);
        }
        pw.close();
        sc.close();
    }

    
    public static void generateInput(int tc) throws IOException {
        PrintWriter pw = new PrintWriter(new FileWriter(WORK_DIR + "test.in"));
        pw.print(tc);
        Random rd = new Random();
        for (int tci = 1; tci <= tc; tci++) {
            pw.println();
            
            double C = rd.nextDouble()*10000;
            double F = rd.nextDouble()*100;
            double X = rd.nextDouble()*100000;
            pw.println(C+" "+F+" "+X);
        }
        pw.close();
    }
}
