// Google Code Jam Round 1B 2015
// Problem B. Typewriter Monkey

import java.util.*;
import java.io.*;

public class TypewriterMonkey{
	static String filename = "B-small-attempt0";	// io filnename here
    static String inname = filename + ".in";    
    static String outname = filename + ".out";  
    static double eps = 10E-8;
    public static void main(String[] args){
        try{
            Scanner in = new Scanner(new BufferedReader(new FileReader(inname)));
        	//Scanner in = new Scanner(System.in);
            BufferedWriter out = new BufferedWriter(new FileWriter(outname));
            int t = in.nextInt();
            in.nextLine();
            for (int cas = 1; cas <= t; cas++){
            	//String ans = "";
                in.nextInt();
                in.nextInt();
                int s = in.nextInt();
                String key = in.next();
                String targ = in.next();
                double ans = solve(key, targ, s);
                System.out.print("Case #" + cas + ": " + ans + "\n");
                out.write("Case #" + cas + ": " + ans + "\n");
            }
            in.close();
            out.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
	private static double solve(String key, String targ, int s) {
		int l = targ.length();
		int k = key.length();
		double[] probtarg = new double[l];
		for (int i = 0; i < l; i++){
			probtarg[i] = 0;
			for (int j = 0; j < k; j++){
				if (key.charAt(j) == targ.charAt(i)) probtarg[i]++;
			}
			if (probtarg[i] == 0.0) return 0.0;
			probtarg[i]/=k;
		}
		double expected = s-(l-1);
		for (int i = 0; i < l; i++){
			expected*=probtarg[i];
		}
		int maxCnt = maxCount(targ, s);
		return (double)maxCnt - expected;
	}
	
	private static int maxCount(String targ, int s) {
		int l = targ.length();
		int rep = l;
		for (int i = 1; i < l; i++){
			if (targ.substring(i).equals(targ.substring(0, l-i))){
				rep = i;
				break;
			}
		}
		return 1 + (s-l)/rep;
	}
}