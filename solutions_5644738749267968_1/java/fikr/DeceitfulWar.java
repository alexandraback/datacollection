// Google Code Jam Qualification Round 2014
// Problem D. Deceitful War

import java.util.*;
import java.io.*;

public class DeceitfulWar {
	static String inname = "D-large.in";    // input file name here
	static String outname = "D-large.out";  // output file name here
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
				double[] nao = new double[n];
				double[] ken = new double[n];
				for (int i = 0; i < n; i++)
					nao[i] = in.nextDouble();
				for (int i = 0; i < n; i++)
					ken[i] = in.nextDouble();
				ans = solve(nao, ken);
				//System.out.print("Case #" + cas + ": " + ans + "\n");
				out.write("Case #" + cas + ": " + ans + "\n");
			}
			in.close();
			out.close();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
	
	public static String solve(double[] nao, double[] ken){
		int n = nao.length;
		int warAns = n;
		int dwarAns = 0;
		Arrays.sort(nao);
		Arrays.sort(ken);

		int j = 0;
		for (int i = 0; i < n; i++){
			while(j < n && nao[i]>ken[j]) j++;
			if (j >= n) break;
			if (nao[i]<ken[j]) warAns--;
			j++;
		}
		j = 0;
		for (int i = 0; i < n; i++){
			while(j < n && ken[i]>nao[j]) j++;
			if (j >= n) break;
			if (ken[i]<nao[j]) dwarAns++;
			j++;
		}
		
		return dwarAns + " " + warAns;
	}
}