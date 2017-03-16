// Google Code Jam Qualification Round 2015
// Problem C. Dijkstra

import java.util.*;
import java.io.*;

class Dijkstra{
    static String inname = "C-small-attempt0.in";    // input file name here
    static String outname = "C-small-attempt0.out";  // output file name here
    static int n;
    public static void main(String[] args){
        try{
            Scanner in = new Scanner(new BufferedReader(new FileReader(inname)));
        	//Scanner in = new Scanner(System.in);
            BufferedWriter out = new BufferedWriter(new FileWriter(outname));
            
            int t = in.nextInt();
            in.nextLine();
            for (int cas = 1; cas <= t; cas++){
            	String ans = "";
                in.nextInt();
                int x = in.nextInt();
                String str = in.next();
                if (ijk(str, x)) ans = "YES";
                else ans = "NO";
                //System.out.print("Case #" + cas + ": " + ans + "\n");
                out.write("Case #" + cas + ": " + ans + "\n");
            }
            in.close();
            out.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
	private static boolean ijk(String str, int x) {
		int cycleSize = detectCycle(str, x);
		int l = str.length();
		// state 1 = 1, i = 2, j = 3, k = 4; -i = -1 etc
		int st = 1;
		for (int ii = 0; ii < x; ii++){
			for (int ji = 0; ji < l; ji++){
				if (st == 1 && cycleSize != -1 && ii >= cycleSize && ji == 0) 
					return false;
				st = mult(st, str.charAt(ji)-'i'+2);
				if (st == 2){
					
					int stj = 1;
					for (int ij = ii; ij < x; ij++){
						int startj;
						if (ij == ii) startj = ji+1; else startj = 0;
						for (int jj = startj; jj < l; jj++){
							stj = mult(stj, str.charAt(jj)-'i'+2);
							if (stj == 1 && cycleSize != -1 && ij >= ii+cycleSize && jj == ji)
								return false;
							if (stj == 3){

								int stk = 1;
								for (int ik = ij; ik < x; ik++){
									int startk;
									if (ik == ij) startk = jj+1; else startk = 0;
									for (int jk = startk; jk < l; jk++){
										stk = mult(stk, str.charAt(jk)-'i'+2);
										if (stk == 1 && cycleSize != -1 && ik >= ij+cycleSize && jk == jj)
											return false;
										if (stk == 4 && jk == l-1 && (ik == x-1 || (cycleSize != -1 && (x-ik-1)%cycleSize == 0)))
											return true;
									}
								}
								
							}
						}
					}
					
				}
			}
		}
		return false;
	}
	
	private static int detectCycle(String str, int x) {
		int l = str.length();
		int st = 1;
		for (int i = 0; i < x; i++){
			for (int j = 0; j < l; j++){
				st = mult(st, str.charAt(j)-'i'+2);
				if (st == 1 && j == l-1) return i+1; 
			}
		}
		return -1;
	}
	
	private static int mult(int a, int b) {
		int as, bs;
		if (a < 0) as = -1; else as = 1;
		if (b < 0) bs = -1; else bs = 1;
		if (a < 0) a *= -1;
		if (b < 0) b *= -1;
		if (a >= 'i') a-= 'i'+2;
		if (b >= 'i') b-= 'i'+2;
		switch(a){
		case 1:
			return b*as*bs;
		case 2: 
			switch(b){
			case 2: return -1*as*bs;
			case 3: return 4*as*bs;
			case 4: return -3*as*bs;
			}
		case 3: 
			switch(b){
			case 2: return -4*as*bs;
			case 3: return -1*as*bs;
			case 4: return 2*as*bs;
			}
		case 4: 
			switch(b){
			case 2: return 3*as*bs;
			case 3: return -2*as*bs;
			case 4: return -1*as*bs;
			}
		}
		return a;
	}
}