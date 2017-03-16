import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collection;
import java.util.Collections;
import java.util.HashMap;
import java.util.List;
import java.util.Set;
import java.util.StringTokenizer;

public class A {
	int N,M;
	// 0 will describe any
	int[][] a;
	
	ArrayList<Integer> unique = new ArrayList<Integer>();
	
	public A(BufferedReader reader) throws IOException {
		String lineNM = reader.readLine();
		StringTokenizer tokenNM = new StringTokenizer(lineNM, " ");
		N = Integer.parseInt(tokenNM.nextToken());
		M = Integer.parseInt(tokenNM.nextToken());
		
		a = new int[N][M];
		
		for (int i=0; i<N; i++) {
			String line = reader.readLine();
			StringTokenizer token = new StringTokenizer(line, " ");

			for (int j = 0; j < M; j++) {
				int x = Integer.parseInt(token.nextToken());
				a[i][j] = x;
			}
		}
	}
	
	private void getUniqueNR() {
		for (int i=0; i<N; i++) {
			for (int j = 0; j < M; j++) {
				if (!unique.contains(a[i][j])) {
					unique.add(a[i][j]);
				}
			}
		}
		
		Collections.sort(unique);
	}
	
	public boolean existsN(int x) {
		for (int i=0; i<N; i++) {
			for (int j = 0; j < M; j++) {
				if (a[i][j] == x) {
					return true;
				}
			}
		}
		return false;
	}
	
	public void setCol0(int colN) {
		for (int i=0;i<N;i++) {
			a[i][colN] = 0;
		}
	}
	
	public boolean isOkCol(int colN, int nr) {
		for (int i=0;i<N;i++) {
			if (a[i][colN] > nr) {
				return false;
			}
		}
		return true;
	}
	
	public void setRow0(int rowN) {
		for (int j=0;j<M;j++) {
			a[rowN][j] = 0;
		}
	}
	
	public boolean isOkRow(int rowN, int nr) {
		for (int j=0;j<M;j++) {
			if (a[rowN][j] > nr) {
				return false;
			}
		}
		return true;
	}
	
	
	
	public boolean solveUnique(int nr) {
		for (int i=0;i<N;i++) {
			if (isOkRow(i, nr)) {
				setRow0(i);
			}
		}
		for (int j=0;j<M;j++) {
			if (isOkCol(j, nr)) {
				setCol0(j);
			}
		}
		
		return !existsN(nr);		
	}
	
	
	public String solve() {
		getUniqueNR();
		
		for (Integer nr:unique) {
			if (!solveUnique(nr)) {
				return "NO";
			}
		}
		return "YES";
	}
	
	public static void main(String[] args) throws IOException {
		String inputFile = args[0];
		BufferedReader reader = new BufferedReader(new FileReader(inputFile
				+ ".in"));
		FileWriter outFile = new FileWriter(inputFile + ".out");
		PrintWriter out = new PrintWriter(outFile);
		String strNrLines = reader.readLine();
		int nrLines = Integer.parseInt(strNrLines);
		for (int i = 1; i <= nrLines; i++) {
			A b = new A(reader);
			out.println("Case #" + i + ": " + b.solve());
		}
		reader.close();
		out.close();
	}
	
}
