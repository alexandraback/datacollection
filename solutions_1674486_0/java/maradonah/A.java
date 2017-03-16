import java.io.*;
import java.util.*;
import java.math.*;

public class A {
	public static void main(String[] args) throws IOException {
		long start = System.currentTimeMillis();
		BufferedInputStream bis = new BufferedInputStream(new FileInputStream("A-small-attempt0.in"));
		BufferedReader br = new BufferedReader(new InputStreamReader(bis));
		PrintWriter out = new PrintWriter("A-small-attempt0.out");
		int cases = Integer.parseInt(br.readLine().trim());
		StringTokenizer st;
		for (int c = 1; c <= cases; c++) {
			int N = Integer.parseInt(br.readLine().trim());
			int [][] adjMat = new int [N][N];
			for (int i = 0; i < adjMat.length; i++) {
				st = new StringTokenizer(br.readLine());
				int nebs = Integer.parseInt(st.nextToken());
				for (int j = 0; j < nebs; j++) {
					int neighbor = Integer.parseInt(st.nextToken())-1;
					adjMat [i][neighbor] = 1;
				}
			}
			for (int k = 0; k < adjMat.length; k++) {
				for (int i = 0; i < adjMat.length; i++) {
					for (int j = 0; j < adjMat.length; j++) {
						adjMat [i][j] += adjMat [i][k]*adjMat [k][j];
					}
				}
			}
			boolean can = false;
			for (int i = 0; i < adjMat.length && !can; i++) {
				for (int j = 0; j < adjMat.length && !can; j++) {
					if(i != j && adjMat [i][j] > 1)
						can = true;
				}
			}
			out.println("Case #" + c + ": " + (can?"Yes":"No"));
		}
		out.close();
		long finish = System.currentTimeMillis();
		System.out.println(finish - start);
	}
}