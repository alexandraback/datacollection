import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Scanner;

public class three {
	
	static final String name = "c-small-attempt0";
	
	public static void main(String[] args) throws IOException{
		Scanner in = new Scanner(new File(name + ".in"));
		PrintWriter out = new PrintWriter(new File(name + ".out"));
		
		int tc = in.nextInt();
		for(int i = 1; i <= tc; i++){
			out.print("Case #" + i + ": ");
			solve(in, out);
		}
		
		in.close();
		out.close();
	}

	private static void solve(Scanner in, PrintWriter out) {
		int j = in.nextInt();
		int p = in.nextInt();
		int s = in.nextInt();
		int k = in.nextInt();
		int[][] jp = new int[j][p];
		int[][] ps = new int[p][s];
		int[][] js = new int[j][s];
		ArrayList<String> possible = new ArrayList<String>();
		for(int j1 = 0; j1 < j; j1++){
			for(int p1 = 0; p1 < p; p1++){
				for(int s1 = 0; s1 < s; s1++){
					if(jp[j1][p1] < k && ps[p1][s1] < k && js[j1][s1] < k){
						possible.add((j1 + 1) + " " + (p1 + 1) + " " + (s1 + 1));
						jp[j1][p1]++;
						ps[p1][s1]++;
						js[j1][s1]++;
					}
				}
			}
		}
		out.println(possible.size());
		for(String t : possible){
			out.println(t);
		}
	}
}
