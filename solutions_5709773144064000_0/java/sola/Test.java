package test4;
import java.io.*;
import java.util.*;

public class Test {
    final static String WORK_DIR = "C:\\Users\\Sola\\Desktop\\";
    
    public static void main (String[] args) throws IOException {

        //generateInput(100);
        Scanner sc = new Scanner(new FileReader(WORK_DIR + "test.in"));
        PrintWriter pw = new PrintWriter(new FileWriter(WORK_DIR + "test.out"));

        int tc = sc.nextInt();
        
        for (int tci=1;tci<=tc;tci++) {
            double C = sc.nextFloat();
            double F = sc.nextFloat();
            double X = sc.nextFloat();
            double t = X/2;
            for (int i=0;;i++) {
                // want to increase i?
                double inc = C/(2+i*F)+X/(2+(i+1)*F)- X/(2+i*F);
                if (inc>=0) {
                    break;
                }
                else {
                    t+= inc;
                }
            }
            
            pw.println("Case #" + tci + ": " + t);
        }
        pw.close();
        sc.close();
    }

    public static void generateInput(int tc) throws IOException {
        PrintWriter pw = new PrintWriter(new FileWriter(WORK_DIR + "3.in"));
        int maxL = 1000000;
        pw.print(tc);
        Random rd = new Random();
        for (int tci = 1; tci <= tc; tci++) {
            pw.println();
            int l = rd.nextInt(maxL);
            int n = rd.nextInt(l);
            String s = "";
            for (int i = 0; i < l; i++) {
                s += (char) rd.nextInt('a' + 26);
            }
            pw.println(s + " " + n);
        }
        pw.close();
    }
}
