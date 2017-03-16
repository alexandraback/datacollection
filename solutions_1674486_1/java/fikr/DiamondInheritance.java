// Google Code Jam 2012 Round 1C
// Problem A. Diamond Inheritance

import java.util.*;
import java.io.*;
public class DiamondInheritance {
	static String inname = "A-large.in";    // input file name here
	static String outname = "A-large.out";  // output file name here
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
				int[][] g = new int[n][];
				for (int i = 0; i < n; i++){
					int m = in.nextInt();
					g[i] = new int[m]; 
					for (int j = 0; j < m; j++){
						g[i][j] = in.nextInt() - 1;
					}
				}
//				for (int i = 0; i < n; i++){
//					System.out.print(i+ ": ");
//					for (int j = 0; j < g[i].length; j++){
//						System.out.print(g[i][j] + " ");
//					} System.out.println();
//				}
				if (containsDI(g)) ans = "Yes";
				else ans = "No";
				
				//System.out.print("Case #" + cas + ": " + ans + "\n");
				out.write("Case #" + cas + ": " + ans + "\n");
			}
			in.close();
			out.close();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
	
	public static boolean containsDI(int[][]g){
		for(int i = 0; i < g.length; i++){
			Vector<Integer> visd = new Vector<Integer>();
			LinkedList<Integer> open = new LinkedList<Integer>();
			for (int j = 0; j < g[i].length; j++)
				open.add(g[i][j]);
			while(!open.isEmpty()){
				int next = open.poll();
				if (visd.contains(next)) return true;
				visd.add(next);
				for (int j = 0; j < g[next].length; j++)
					open.add(g[next][j]);
			}
			//System.out.println(visd);
		}
		return false;
	}
}