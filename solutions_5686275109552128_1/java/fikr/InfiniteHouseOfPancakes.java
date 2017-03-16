// Google Code Jam Qualification Round 2015
// Problem B. Infinite House of Pancakes

import java.util.*;
import java.io.*;

public class InfiniteHouseOfPancakes{
    static String inname = "B-large.in";    // input file name here
    static String outname = "B-large.out";  // output file name here
    static int n;
    public static void main(String[] args){
        try{
            Scanner in = new Scanner(new BufferedReader(new FileReader(inname)));
        	//Scanner in = new Scanner(System.in);
            BufferedWriter out = new BufferedWriter(new FileWriter(outname));
            //out.write("\n\n");
            int t = in.nextInt();
            in.nextLine();
            for (int cas = 1; cas <= t; cas++){
            	int d = in.nextInt();
            	int[] p = new int[d];
            	for (int i = 0; i < d; i++) p[i] = in.nextInt();
            	Arrays.sort(p);
            	int ans = eatPancake(p);
                //System.out.print("Case #" + cas + ": " + ans + "\n");
                out.write("Case #" + cas + ": " + ans + "\n");
            }
            in.close();
            out.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
    
    private static int eatPancake(int[] p) {
    	int d = p.length;
    	int ans = p[d-1];
    	for (int i = 2; i < p[d-1]; i++){
    		int currTime = special(p, i) + i;
    		if (currTime < ans) ans = currTime;
    	}
		return ans;
	}

	private static int special(int[] p, int di) {
		int d = p.length;
		int specialTime = 0;
		for (int i = 0; i < d; i++){
			if (p[i] > di){
				//System.out.println("special " + p[i] + " " + di + " " + ((p[i]-1)/di+1));
				specialTime += (p[i]-1)/di;
			}
		}
		return specialTime;
	}
}