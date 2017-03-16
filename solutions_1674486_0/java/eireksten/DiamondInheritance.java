import java.io.*;
import java.text.*;
import java.util.*;

public class DiamondInheritance {
	
	public static final String in = "A-small-attempt0.in";
	public static final String ou = "A-small.out";
	
	public static final DecimalFormat DF = new DecimalFormat("0.000",new DecimalFormatSymbols(Locale.ENGLISH));
	public static final double EPSILON = 1E-9;
	
	public DiamondInheritance(BufferedReader input) {
		this.input = input;
		this.outputBuilder = new StringBuilder();
	}
	
	public String go() throws Exception {
		// Solve problem here!
		int cases = INT();
		for(int cc = 1; cc <= cases; cc++) {
			
			write("Case #" + cc + ": ");
			writeln(solve());
			
		}
		return outputBuilder.toString();
	}
	
	private String solve() throws Exception {
		int N = INT();
		int[][] mat = new int[N][N];
		for(int i = 0; i < N ; i++) {
			int M = INT();
			for(int j = 0; j < M; j++) {
				int neigh = INT() - 1;
				mat[i][neigh] = 1;
			}
		}
		
		int[][] paths = new int[N][N];
		int[][] ans = new int[N][N];
		for(int i = 0; i < N ; i++) {
			ans[i][i] = 1;
		}
		ans = multMatrices(ans, mat);
		addPaths(ans, paths);
		for(int i = 0; i < N; i++) {
			ans = multMatrices(ans, mat);
			if(addPaths(ans, paths)) {
				return "Yes";
			}
		}
		
		return "No";
	}

	private void printMatrix(int[][] ans) {
		int N = ans.length;
		System.out.println();
		for(int x = 0; x < N; x++) {
			System.out.println(Arrays.toString(ans[x]));
		}
	}
	
	
	private boolean addPaths(int[][] ans, int[][] paths) {
		for (int i = 0; i < ans.length; i++) {
			int[] js = ans[i];
			for (int j = 0; j < js.length; j++) {
				paths[i][j] += js[j];
				if(paths[i][j] > 1)
					return true;
			} 
		}
		return false;
	}

	public static int[][] multMatrices(int[][] A, int[][] B) {
		int[][] ans = new int[A.length][B[0].length];
		for(int i = 0;i<A.length;i++)
			for(int j = 0;j<B[0].length;j++)
				for(int k = 0;k<B.length;k++)
					ans[i][j] += A[i][k]*B[k][j];
		return ans;
	}

	// Scaffolding
	public static void main(String[] args) throws Exception {
		BufferedWriter output = new BufferedWriter(new FileWriter(new File(ou)));
		output.write(new DiamondInheritance(new BufferedReader(new FileReader(new File(in)))).go());
		output.flush();
		output.close();
	}
	
	// Output methods
	StringBuilder outputBuilder = new StringBuilder();
	void write(String str) { outputBuilder.append(str); }
	void write(int num) {    outputBuilder.append(num); }
	void write(long num) {   outputBuilder.append(num); }
	void write(char ch) {    outputBuilder.append(ch); }
	void writeln(String str) { outputBuilder.append(str); outputBuilder.append("\n");}
	void writeln(int num) {    outputBuilder.append(num); outputBuilder.append("\n"); }
	void writeln(long num) {   outputBuilder.append(num); outputBuilder.append("\n"); }
	void writeln(char ch) {    outputBuilder.append(ch); outputBuilder.append("\n"); }
	
	// Input methods
	BufferedReader input;
	StringTokenizer st;
	String LINE() throws Exception { return input.readLine(); }
	String TOKEN() throws Exception {
		while (st == null || !st.hasMoreTokens())st = new StringTokenizer(LINE());
		return st.nextToken();
	}
	int INT() throws Exception {return Integer.parseInt(TOKEN());}
	long LONG() throws Exception {return Long.parseLong(TOKEN());}
	double DOUBLE() throws Exception {return Double.parseDouble(TOKEN());}
	

}
