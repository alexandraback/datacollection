// Google Code Jam Qualification Round 2012
// Problem B. Dancing With the Googlers

import java.util.*;
import java.io.*;

public class DancingWithTheGooglers {
    static String inname = "B-small-attempt0.in";    // input file name here
    static String outname = "B-small-attempt0.out";  // output file name here
    public static void main(String[] args){
        try{
            Scanner in = new Scanner(new BufferedReader(new FileReader(inname)));
        	//Scanner in = new Scanner(System.in);
            BufferedWriter out = new BufferedWriter(new FileWriter(outname));
            int n, s, p, t[];
            int T = in.nextInt();
            for (int cas = 1; cas <= T; cas++){
            	int ans = 0;
            	n = in.nextInt();
            	s = in.nextInt();
            	p = in.nextInt();
            	t = new int[n];
            	for (int i = 0; i < n; i++)
            		t[i] = in.nextInt();
            	for (int i = 0; i < n; i++){
            		if (t[i]%3 == 0){
            			if (t[i]/3 >= p) ans++;
            			else if (t[i]/3 == p-1 && t[i] > 1 && s > 0){
            				ans++; s--;
            			}
            		} else {
            			if (t[i]/3+1 >= p) ans++;
            			else if (t[i]/3+1 == p-1 && t[i] > 1 && t[i]%3 == 2 && s > 0){
            				ans++; s--;
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
