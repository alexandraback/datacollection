import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class A {

	public static void main(String[] args) {
		try {
			new A();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

	Scanner sc = new Scanner(System.in);
	BufferedWriter w = new BufferedWriter(new FileWriter("outputA"));
	int R, C, W;

	public A() throws IOException {
		long s = System.currentTimeMillis();

		int t = Integer.parseInt(sc.nextLine());
		String output = null;
		String[] line;
		for (int i = 0; i < t; i++) {
			line = sc.nextLine().split(" ");
			R = Integer.parseInt(line[0]);
			C = Integer.parseInt(line[1]);
			W = Integer.parseInt(line[2]);

			output = Integer.toString(solve());
			writeOutput(i + 1, output);
		}
		System.out.println(System.currentTimeMillis() - s);
		sc.close();
		w.close();
	}

	public int solve() {
		int minimal = 0;
		minimal += (R - 1) * (C / W);
		minimal += Math.max(0, C / W - 1);
		if (C % W != 0) {
			minimal++;
		}
		minimal += W;
		return minimal;
	}

	public void writeOutput(int casenr, String output) throws IOException {
		w.write("Case #" + Integer.toString(casenr) + ": " + output + "\n");
		System.out.println("Case #" + Integer.toString(casenr) + ": " + output
				+ "\n");
	}

}