// Google Code Jam Qualification Round 2013
// Problem B. Lawnmower

import java.util.*;
import java.io.*;

class Lawnmower{
    static String inname = "B-large.in";    // input file name here
    static String outname = "B-large.out";  // output file name here
    static int n;
    public static void main(String[] args){
        try{
            Scanner in = new Scanner(new BufferedReader(new FileReader(inname)));
        	//Scanner in = new Scanner(System.in);
            BufferedWriter out = new BufferedWriter(new FileWriter(outname));
            int t = in.nextInt();
            int n, m;
            int[][] a;
            in.nextLine();
            for (int cas = 1; cas <= t; cas++){

            	n = in.nextInt();
            	m = in.nextInt();
            	a = new int[n][m];
            	for (int i = 0; i < n; i++){
            		for (int j = 0; j < m; j++){
            			a[i][j] = in.nextInt();
            		}
            	}
            	
            	String ans = "YES";
            	for (int i = 0; i < n; i++){
            		for (int j = 0; j < m; j++){
            			boolean hok = true, vok = true;
            			for (int k = 0; k < n; k++)
            				if (a[k][j] > a[i][j]){ hok = false; break; }
            			for (int k = 0; k < m; k++)
            				if (a[i][k] > a[i][j]){ vok = false; break; }
            			if (!hok && !vok){
            				ans = "NO";
            				break;
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