// Google Code Jam Round 1C 2014
// Problem B. Reordering Train Cars

import java.util.*;
import java.io.*;

class ReorderingTrainCars{
	static String file = "B-small-attempt1";
    static String inname = file + ".in";    // input file name here
    static String outname = file + ".out";  // output file name here
    static int n;
    static long mod = 1000000007;
    public static void main(String[] args){
        try{
            Scanner in = new Scanner(new BufferedReader(new FileReader(inname)));
        	//Scanner in = new Scanner(System.in);
            BufferedWriter out = new BufferedWriter(new FileWriter(outname));
            int t = in.nextInt();
            in.nextLine();
            for (int cas = 1; cas <= t; cas++){
            	String ans = "";
            	int n = in.nextInt();
            	String[] cars = new String[n];
            	for (int i = 0; i < n; i++){
            		cars[i] = in.next();
            	}
            	ans = "" + solve(cars);
                //System.out.print("Case #" + cas + ": " + ans + "\n");
                out.write("Case #" + cas + ": " + ans + "\n");
            }
            in.close();
            out.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

	private static long solve(String[] cars) {
		int n = cars.length;
		int[] lc = new int[26];
		int[] rc = new int[26];
		int[] mc = new int[26];
		int[] ac = new int[26];
		for (int i = 0; i < 26; i++){
			char c = (char)('a'+i);
			lc[i] = 0;
			rc[i] = 0;
			mc[i] = 0;
			ac[i] = 0;
			for (int j = 0; j < n; j++){
				boolean left = false;
				boolean right = false;
				boolean mid = false;
				boolean all = true;
				if (cars[j].charAt(0) == c && cars[j].charAt(cars[j].length()-1) != c){
					left = true;
				}
				if (cars[j].charAt(0) != c && cars[j].charAt(cars[j].length()-1) == c){
					right = true;
				}
				for (int k = 1; k < cars[j].length()-1; k++){
					if (cars[j].charAt(k)==c && cars[j].charAt(k-1) != c){
						for (int l = k+1; l < cars[j].length(); l++){
							if (cars[j].charAt(l)!=c) mid = true;
						}
					}
				}
				for (int k = 0; k < cars[j].length(); k++){
					if (cars[j].charAt(k)!=c){
						all = false;
						break;
					}
				}
				if ((mid && left) ||(mid && right)) return 0;
				if (left) lc[i]++;
				if (right) rc[i]++;
				if (mid) mc[i]++;
				if (all) ac[i]++;
			}
			if (lc[i] > 1 || rc[i] > 1) return 0;
			if (mc[i] > 1) return 0;
			if (mc[i] >= 1 && (lc[i] >= 1 || rc[i] >= 1 || ac[i] >= 1)) return 0;
		}
		long ans = 1;
		for (int i = 0; i < 26; i++){
			if (ac[i]>1){
				for (int j = 2; j<= ac[i]; j++){
					ans*=j;
					ans%=mod;
				}
			}
			if ((ac[i] > 0 && lc[i] == 0 && rc[i] == 0)||(lc[i] == 1)||(rc[i] == 1)){
				ans*=2;
				ans%=mod;
			}
		}
		return ans;
	}
}