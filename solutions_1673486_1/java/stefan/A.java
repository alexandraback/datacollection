import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;


public class A {
	public static final String FILENAME = "A-large";
	public static void main(String[] args) throws IOException {
		BufferedReader in = new BufferedReader(new FileReader("src/"+FILENAME+".in"));
		BufferedWriter out = new BufferedWriter(new FileWriter("src/"+FILENAME+".out"));
		Scanner s = new Scanner(in);
		int T = s.nextInt();
		s.nextLine();
		for(int i = 1; i <= T; i++) {
			System.out.println(i);
			int A = s.nextInt();
			int B = s.nextInt();
			double e[] = new double[2];
			double edel[] = new double[A+1];
			double p[] = new double[A];
			for(int j = 0; j < A; j++) {
				p[j] = Float.parseFloat(s.next());
			}
			for(int wrong = 0; wrong <= A; wrong++) {
				double prob = (wrong == A ? 1 : p[A - wrong - 1]);
				for(int j = A - wrong; j < A; j++) {
					prob *= 1 - p[j];
				}
				double probCorrect = 1;
				edel[A] = A + B + 1;
				for(int j = 0; j < A - wrong - 1; j++) {
					probCorrect *= p[j];
					edel[A - j - 1] += prob * probCorrect * (2 * (A - j - 1) + B - A + 1); 
					edel[A - j - 1] += prob * (1 - probCorrect) * (2 * (A - j - 1) + B - A + 1 + B + 1); 
				}
				if( wrong != A) {
					edel[wrong] += prob * probCorrect * (2 * wrong + B - A + 1); 
					edel[wrong] += prob * (1 - probCorrect) * (2 * wrong + B - A + 1 + B + 1);
				}
				if(wrong == 0) {
					e[0] += prob * probCorrect * (B - A + 1);
					e[0] += prob * (1 - probCorrect) * (B - A + 1 + B + 1);
				}
				else {
					e[0] += prob * (B - A + 1 + B + 1);
				}
				e[1] += prob * (1 + B + 1);
				for(int j = wrong - 1; j >= 0; j--) {
					edel[j] += prob * (2 * j + B - A + 1 + B + 1); 
				}
			}
			double ret = Math.min(e[0], e[1]);
			for(int j = 0; j < A; j++) {
				if(edel[j] < ret) {
					ret = edel[j];
				}
			}
			out.write("Case #"+i+": "+ret+"\n");
		}
		in.close();
		out.close();
	}
}
