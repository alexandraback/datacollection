// Google Code Jam Qualification Round 2013
// Problem C. Fair and Square

import java.util.*;
import java.io.*;

class FairAndSquare{
    static String inname = "C-small-attempt0.in";    // input file name here
    static String outname = "C-small-attempt0.out";  // output file name here
    static long[] fns;
    public static void main(String[] args){
        try{
            Scanner in = new Scanner(new BufferedReader(new FileReader(inname)));
        	//Scanner in = new Scanner(System.in);
            BufferedWriter out = new BufferedWriter(new FileWriter(outname));
            generate(20000000);
            int t = in.nextInt();
            in.nextLine();
            for (int cas = 1; cas <= t; cas++){
            	int ans = 0;
            	long a = in.nextLong(), b = in.nextLong();
                
            	int n = fns.length;
            	for (int i = 0; i < n; i++){
            		if (fns[i] >= a && fns[i] <= b) ans++;
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
    
	private static void generate(int n) {
		Vector<Long> v = new Vector<Long>();
		for (long i = 0; i <= n; i++){
			if (isPalindrome(i) && isPalindrome(i*i)) v.add(i*i);
		}
		fns = new long[v.size()];
		for (int i = 0; i < fns.length; i++)
			fns[i] = v.get(i);
	}

	private static boolean isPalindrome(long num) {
		if (num < 10) return true;
		String s = Long.toString(num);
		int n = s.length();
		for (int i = 0; i < n; i++){
			if (s.charAt(i)!=s.charAt(n-i-1)) return false;
		}
		return true;
	}
}
