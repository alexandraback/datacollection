
// Google Code Jam Round 1A 2013
// Problem C. Good Luck

import java.util.*;
import java.io.*;

public class GoodLuck {
	static String inname = "C-small-1-attempt0.in";    // input file name here
	static String outname = "C-small-1-attempt0.out";  // output file name here

	public static void main(String[] args){
		try{
			Scanner in = new Scanner(new BufferedReader(new FileReader(inname)));
			//Scanner in = new Scanner(System.in);
			BufferedWriter out = new BufferedWriter(new FileWriter(outname));
			//int t = in.nextInt();
			in.nextLine();
			//System.out.print("Case #1:\n");
			out.write("Case #1:\n");
			int r = in.nextInt();
			int n = in.nextInt();
			int m = in.nextInt();
			int k = in.nextInt();
			for (int cas = 1; cas <= r; cas++){
				Vector<Integer> ans = new Vector<Integer>(n);
				int[]p = new int[k];
				for (int i = 0; i < k; i++)
					p[i] = in.nextInt();
				for (int i = 0; i < k; i++){
					while (p[i]%3 == 0){ ans.add(3); p[i]/=3;}
					while (p[i]%5 == 0){ ans.add(5); p[i]/=5;}
					if (m<4){
						while (p[i]%2 == 0){ ans.add(2); p[i]/=2;}
					} else {
						while (p[i]%4 == 0){ ans.add(4); p[i]/=4;}
					}
					while (p[i]%2 == 0){ ans.add(2); p[i]/=2;}

				}
				while (ans.size() < n){
					for (int i = 2; i <= m; i++) ans.add(i);
				}
				String anss = "";
				for (int i = 0; i < n; i++)
					anss += ans.get(i);

				//System.out.print(anss + "\n");
				out.write(anss + "\n");
			}
			in.close();
			out.close();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
}