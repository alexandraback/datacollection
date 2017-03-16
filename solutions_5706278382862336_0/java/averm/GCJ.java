
/**
 *
 * @author amit
 */
import java.io.*;
import java.util.regex.Pattern;

public class GCJ {

    BufferedReader rin;
    BufferedWriter wout;
    int numCases;
    
    public long gcd(long a, long b) {
        if(a == 0 || b == 0) return a+b;
        return gcd(b,a%b);
    }
    
    public boolean check2(long a) {
        if (a==2||a==0) return true;
        if(a%2!=0) return false;
        return check2(a/2);
    }
    
    public String getNextInput() {
        try {
            String [] s = rin.readLine().split("/");
            long P = Integer.parseInt(s[0]);
            long Q = Integer.parseInt(s[1]);
            
            long G = gcd(P,Q);
            
            //System.out.println("gcd: " + G);
            P = P/G;
            Q = Q/G;
            if(!check2(Q)) return "impossible";
            int count = 1;
            double frac = ((double)P)/((double)Q);
            while (frac < 0.5 && count < 41) {
                Q = Q/2;
                frac = ((double)P)/((double)Q);
                count++;
            }
            if (count>40) return "impossible";
            
            return Integer.toString(count);
        } catch (IOException e) {
            System.out.println("File Error! Could not read line from file");
        }
        return null;
    }

    public void writeNextOutput(String s) {
        try {
            wout.write(s);
            wout.write("\n");
        } catch (IOException e) {
            System.out.println("Error! Could not write to the file!");
        }
    }

    public GCJ(String s1, String s2) {
        try {
            rin = new BufferedReader(
                    new FileReader(s1));
            wout = new BufferedWriter(new FileWriter(s2));
            numCases = Integer.parseInt(rin.readLine());

            for (int i = 1; i <= numCases; i++) {
                System.out.println("case#" + i);
                String sout = getNextInput();
                sout = "Case #" + Integer.toString(i) + ":" + " " + sout;
                writeNextOutput(sout);
                //System.out.println("case#" + i);
            }
            rin.close();
            wout.close();
        } catch (IOException e) {
            System.out.println("File error");
            System.exit(0);
        }
    }

    public static void main(String[] args) {/*
         if (args.length!=2) {
         System.out.println("Enter input file!");
         System.exit(0);
         }*/
        GCJ a = new GCJ("infile.txt", "out.txt");
    }
}
