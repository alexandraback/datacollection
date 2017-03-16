// Google Code Jam 2012 Round 1B
// Problem A. Safety in Numbers

import java.util.*;
import java.io.*;

class SafetyInNumbers{
    static String inname = "A-small-attempt3.in";    // input file name here
    static String outname = "A-small-attempt3.out";  // output file name here
    static int n;
    public static void main(String[] args){
        try{
            Scanner in = new Scanner(new BufferedReader(new FileReader(inname)));
        	//Scanner in = new Scanner(System.in);
            BufferedWriter out = new BufferedWriter(new FileWriter(outname));
            int t = in.nextInt();
            in.nextLine();
            for (int cas = 1; cas <= t; cas++){
            	//String ans = "";
            	int n = in.nextInt();
            	int needVote = n;
            	int[] s = new int[n];
            	int x = 0;
            	for (int i = 0; i < n; i++){
            		s[i] = in.nextInt();
            		x += s[i];
            	}
            	int xNeedVote = x;
            	for (int i = 0; i < n; i++){
            		if ((double)s[i]/(double)(x*2) >= 1.0/(double)n){
            			needVote -= 1;
            			xNeedVote -= s[i];
            		}
            	}
            	double[] ans = new double[n];
            	String anss = "";// + " " + xNeedVote + " " + needVote + " ";
            	for (int i = 0; i < n; i++){
            		if ((double)s[i]/(double)(x*2) >= 1.0/(double)n)
            			ans[i] = 0.0;
            		else {
            			if (xNeedVote > 0){
            				ans[i] = ((double)(x+xNeedVote)/(double)needVote - (double)s[i])/(double)x;
            			}
            			else ans[i] = 1.0/(double)needVote;
            			ans[i] *= 100.0;
            		}
            		anss += " " + ans[i];
            	}
                //System.out.print("Case #" + cas + ":" + anss + "\n");
                out.write("Case #" + cas + ": " + anss + "\n");
            }
            in.close();
            out.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}