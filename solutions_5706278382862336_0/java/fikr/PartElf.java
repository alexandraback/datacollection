// Google Code Jam Round 1C 2014
// Problem A. Part Elf

import java.util.*;
import java.io.*;

class PartElf{
	static String file = "A-small-attempt0";
    static String inname = file + ".in";    // input file name here
    static String outname = file + ".out";  // output file name here
    static long maxDenom; //2^40
    public static void main(String[] args){
        try{
            Scanner in = new Scanner(new BufferedReader(new FileReader(inname)));
        	//Scanner in = new Scanner(System.in);
            BufferedWriter out = new BufferedWriter(new FileWriter(outname));
            maxDenom = 1;
        	for (int i = 0; i < 40; i++) maxDenom*=2; //2^40
            int t = in.nextInt();
            in.nextLine();
            for (int cas = 1; cas <= t; cas++){
            	String ans = "";
            	long p, q;
            	StringTokenizer frac = new StringTokenizer(in.next(), "/");
            	p = Long.parseLong(frac.nextToken());
            	q = Long.parseLong(frac.nextToken());
            	int anss = solve(p, q);
            	if (anss == -1) ans = "impossible";
            	else ans = ""+anss;
                //System.out.print("Case #" + cas + ": " + ans + "\n");
                out.write("Case #" + cas + ": " + ans + "\n");
            }
            in.close();
            out.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
	private static int solve(long p, long q) {
		//System.out.println(p + " " + q);
		if (!checkDenom(q)) return -1;
		if (p+p-q >= 0) return 1;
		return 1 + solve(p, q/2);
	}
	private static boolean checkDenom(long q) {
		if (q > maxDenom) return false;
		while(q%2 == 0) q/=2;
		if (q!=1) return false;
		return true;
	}
}