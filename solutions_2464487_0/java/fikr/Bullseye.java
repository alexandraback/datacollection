// Google Code Jam Round 1A 2013
// Problem A. Bullseye

import java.util.*;
import java.io.*;

class Bullseye{
    static String inname = "A-small-attempt0.in";    // input file name here
    static String outname = "A-small-attempt0.out";  // output file name here
    public static void main(String[] args){
        try{
            Scanner in = new Scanner(new BufferedReader(new FileReader(inname)));
        	//Scanner in = new Scanner(System.in);
            BufferedWriter out = new BufferedWriter(new FileWriter(outname));
            int T = in.nextInt();
            in.nextLine();
            for (int cas = 1; cas <= T; cas++){
            	long ans = 0;
                long r = in.nextLong();
                long t = in.nextLong();
                
                // ax^2 + bx + c = 0;
                // 2n^2 + (2r-1)n - t = 0;
                long a = 2;
                long b = 2*r-1;
                long c = -t;
                
                double d = ((double)b*(double)b) - (4*a*c);
                
                if (d < 0) ans = -1;
                else if (d == 0){ 
                	ans = (long) (-b/(4*a*c));
                } else {
                	double sqrtd = Math.sqrt(d);
                	//System.out.println(a + " " + b + " " + c + " " + d + " " + sqrtd);
                	double ans1 = (-b+sqrtd)/(2*a);
                	double ans2 = (-b-sqrtd)/(2*a);
                	//System.out.println(ans1 + " " + ans2);
                	ans = Math.max((long)ans1, (long)ans2);
                }
                
                //System.out.print("Case #" + cas + ": " + ans + "\n");
                out.write("Case #" + cas + ": " + ans + "\n");
            }
            in.close();
            out.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}