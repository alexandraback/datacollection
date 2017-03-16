import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.StringTokenizer;

public class B {

	int N = 0;
	int[] a;
	int[] b;
	
	int moves = 0;
	boolean aa[]; //completed 1 stars
	boolean bb[]; //completed 2 stars
	int stars = 0;
	
	public B(BufferedReader reader) throws IOException {
		String line = reader.readLine();
		StringTokenizer token = new StringTokenizer(line, " ");
		N = Integer.parseInt(token.nextToken());
			
		a = new int[N];
		b = new int[N];
		
		for (int i = 0; i < N; i++) {
			line = reader.readLine();
			StringTokenizer token2 = new StringTokenizer(line, " ");
			int ai = Integer.parseInt(token2.nextToken());
			a[i] = ai;
			int bi = Integer.parseInt(token2.nextToken());
			b[i] = bi;
		}
		
		aa = new boolean[N];
		Arrays.fill(aa, false);
		bb = new boolean[N];
		Arrays.fill(bb, false);
		
	}
	
	
	private boolean check2star() {
		boolean found = false;
		boolean remaining = false;
		do{
			remaining = false;
			found = false;
			for (int i= 0; i<N; i++) {
				if (!bb[i] && (b[i] <= stars)) {
					bb[i] = true;
					if (aa[i]) {
						stars += 1;
					} else {
						stars += 2;
					}
					moves++;
					found = true;
				}
				if (!bb[i]) {
					remaining = true;
				}
			}
		} while (found);
		
		return remaining;
	}

	
	private boolean check1star() {
		boolean found = false;
		int indexLow = -1;
		for (int i= 0; i<N; i++) {
			if (!aa[i] && !bb[i] && (a[i] <= stars)) {
				if (indexLow < 0) {
					indexLow = i;
				}
				if (b[i] > b[indexLow]) {
					indexLow = i;
				}
				found = true;
			}
		}
		
		if (found) {
			aa[indexLow] = true;
			stars += 1;
			moves++;
		}
		
		return found;
	}
	
	public String solve() {
		boolean remaining2 = true;
		do{
			// check 2 stars
			remaining2 = check2star();
			if (remaining2) {
				boolean found1 = check1star();				
				if (found1) {
					remaining2 = true;
				} else {
					return "Too Bad";
				}
			}
		} while (remaining2);
		
		return moves + "";
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
			B b = new B(reader);
			out.println("Case #" + i + ": " + b.solve());
		}
		reader.close();
		out.close();
	}

}
