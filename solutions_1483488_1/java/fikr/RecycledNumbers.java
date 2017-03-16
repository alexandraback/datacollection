// Google Code Jam Qualification Round 2012
// Problem C. Recycled Numbers

import java.util.*;
import java.io.*;

public class RecycledNumbers{
    static String inname = "C-large.in";    // input file name here
    static String outname = "C-large.out";  // output file name here
    public static void main(String[] args){
        try{
            Scanner in = new Scanner(new BufferedReader(new FileReader(inname)));
        	//Scanner in = new Scanner(System.in);
            BufferedWriter out = new BufferedWriter(new FileWriter(outname));
            int t = in.nextInt();
            int a, b;
            for (int cas = 1; cas <= t; cas++){
            	int ans = 0;
            	a = in.nextInt();
            	b = in.nextInt();
                for (int n = a; n < b; n++){
                	String ns = Integer.toString(n);
                	int d = ns.length();
                	int mss[] = new int[d];
                	for(int i = 1; i < d; i++){
                		String ms = ns.substring(i);
                		ms += ns.substring(0,i);
                		int m = Integer.parseInt(ms);
                		mss[i] = m;
                		if (n < m && m > a && m <= b){ 
                			boolean flag = true;
                			for (int j = 0; j < i; j++) 
                				if (m == mss[j]) flag = false;
                			if (flag) ans++;
                		}
                	}
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