// Google Code Jam Round 1C 2015
// Problem A. Brattleship

import java.util.*;
import java.io.*;

public class Brattleship{
	static String filename = "A-small-attempt1";	// io filnename here
    static String inname = filename + ".in";    
    static String outname = filename + ".out";  
    static int n;
    public static void main(String[] args){
        try{
            Scanner in = new Scanner(new BufferedReader(new FileReader(inname)));
        	//Scanner in = new Scanner(System.in);
            BufferedWriter out = new BufferedWriter(new FileWriter(outname));
            int t = in.nextInt();
            in.nextLine();
            for (int cas = 1; cas <= t; cas++){
            	
                int r = in.nextInt();
                int c = in.nextInt();
                int w = in.nextInt();
                int ans = play(r, c, w);
                System.out.print("Case #" + cas + ": " + ans + "\n");
                out.write("Case #" + cas + ": " + ans + "\n");
            }
            in.close();
            out.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
	private static int play(int r, int c, int w) {
		int ans = 0;
		ans +=  Math.min(c%w, 1)+w + c/w-1;
		if (r > 1) ans += (r-1)*(c/w);
		return ans;
	}
}



