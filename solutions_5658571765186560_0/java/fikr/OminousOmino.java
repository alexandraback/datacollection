// Google Code Jam Qualification Round 2015
// Problem D. Ominous Omino

import java.util.*;
import java.io.*;

public class OminousOmino{
    static String inname = "D-small-attempt0.in";    // input file name here
    static String outname = "D-small-attempt0.out";  // output file name here
    static int n;
    public static void main(String[] args){
        try{
            Scanner in = new Scanner(new BufferedReader(new FileReader(inname)));
        	//Scanner in = new Scanner(System.in);
            BufferedWriter out = new BufferedWriter(new FileWriter(outname));

            int t = in.nextInt();
            in.nextLine();
            for (int cas = 1; cas <= t; cas++){
            	String ans;
                int x = in.nextInt();
                int r = in.nextInt();
                int c = in.nextInt();
                if (tile(x, r, c)) ans = "GABRIEL";
                else ans = "RICHARD";
                //System.out.print("Case #" + cas + ": " + ans + "\n");
                out.write("Case #" + cas + ": " + ans + "\n");
            }
            in.close();
            out.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
    public static boolean tile(int x, int r, int c){
        if (x == 1) return true;
        else if (x >= 7) return false;
        else if (r*c % x != 0) return false;
        int l = Math.max(r, c);
        int w = Math.min(r, c);
        if (l >= x && w >= x-1) return true;
        return false;
    }
}