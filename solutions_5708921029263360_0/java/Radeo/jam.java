import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Scanner;

public class jam {

	public static void main(String[] args) throws IOException {
		Scanner sc = new Scanner(new FileReader("C-small-attempt4.in"));
		PrintWriter pw = new PrintWriter(new FileWriter("output.txt"));
		int cases = sc.nextInt();
		for (int i = 0; i < cases; i++) {
			System.out.println("Case #" + (i + 1));
			pw.print("Case #" + (i + 1) + ": ");
			solve(sc, pw);
			pw.println("");
		}
		pw.flush();
		pw.close();
		sc.close();
		System.out.println("DONE");

	}

	static void solve(Scanner sc, PrintWriter pw) {
		int J = sc.nextInt();
		int P = sc.nextInt();
		int S = sc.nextInt();
		int K = sc.nextInt();
		
		int ij[][] = new int[10][10];
		int ik[][] = new int[10][10];
		int jk[][] = new int[10][10];
		int y = 0;
		
		StringBuilder sb = new StringBuilder();
		for(int i = 0; i < J; i++) {
			for(int j = 0; j < P; j++) {
				for(int k = 0; k < S; k++) {
					
					if(jk[j][k] < K && ik[i][k] < K && ij[i][j] < K ) {
						jk[j][k]++; ik[i][k]++; ij[i][j]++;
						sb.append("\n" + (i+1) + " " + (j+1) + " " + (k+1));
						y++;
					} else {
						
					}
				}
			}
		}
		pw.print(y);
		pw.print(sb.toString());
	}
}
