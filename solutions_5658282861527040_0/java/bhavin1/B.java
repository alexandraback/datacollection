import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Arrays;
import java.util.Scanner;

public class B {

	Scanner in;
	// BufferedReader in;
	BufferedWriter out;

	public B() throws IOException {
		in = new Scanner(new File("prob.in"));
		// in = new BufferedReader(new FileReader("prob.in"));

		out = new BufferedWriter(new FileWriter("prob.out"));
	}

	public void solve() throws Exception {

		int numCases = in.nextInt();

		for (int i = 1; i <= numCases; i++) {
			runCase(i);
		}
		out.close();
		in.close();
	}

	private void runCase(int caseNum) throws Exception {

		int A = in.nextInt();
		int B = in.nextInt();
		int K = in.nextInt();

		String s = "";
		int count=0;
		for (int i = 0; i < A; i++) {
			for (int j = 0; j < B; j++) {
				int x=i&j;
				if(x < K) count++;
			}
		}

		output(out, caseNum, count);

	}


	public static void main(String[] args) throws Exception {
		B s = new B();
		s.solve();

	}

	public void output(BufferedWriter out, int caseNum, int string)
			throws IOException {
		out.write("Case #" + caseNum + ": " + string + "\n");
	}

	public void output(BufferedWriter out, int caseNum, double string)
			throws IOException {
		out.write("Case #" + caseNum + ": " + string + "\n");
	}

	public void output(BufferedWriter out, int caseNum, String string)
			throws IOException {
		out.write("Case #" + caseNum + ": " + string + "\n");
	}

}
