import java.io.*;
import java.util.*;

class Solver {

	boolean isInFile, isOutFile;
	Scanner reader;
	DataOutputStream writer;

	public Solver(String[] args) throws Exception {
		isInFile = (args.length > 0);
		if (isInFile)
			reader = new Scanner(new File(args[0]));
		else
			reader = new Scanner(System.in);
		isOutFile = (args.length > 1);
		if (isOutFile)
			writer = new DataOutputStream(new FileOutputStream(new File(args[1])));
	}

	public void write(String str) throws Exception {
		if (isOutFile)
			writer.writeBytes(str);
		System.out.print(str);
	}

	public void writeln(String str) throws Exception {
		write(str + System.lineSeparator());
	}

	public static void main(String[] args) throws Exception {
		new Solver(args).solve();
	}

	public void solve() throws Exception {
		int T = reader.nextInt();
		reader.nextLine();
		for (int i = 1; i <= T; i++) {
			write("Case #" + i + ": ");
			solveOne();
			writeln("");
		}
	}

	public void printS(int[] S) {
		for (int i : S)
			System.out.print(i + " ");
		System.out.println();
	}

	public void solveOne() throws Exception {
		/* read data */
		int A = reader.nextInt();
		int N = reader.nextInt();
		reader.nextLine();
		int[] S = new int[N];
		for (int i = 0; i < N; i++)
			S[i] = reader.nextInt();
		reader.nextLine();

		/* solve */
		Arrays.sort(S);
		// printS(S);

		int minAction = N;
		for (int i = 0; i < N; i++) {
			int pos = 0;
			int targetPos = N - i;
			int action = i;
			int total = A;
			// System.out.println("#" + targetPos);
			while (pos < targetPos && action < N) {
				// System.out.println("#" + pos + " " + total);
				if (total > S[pos]) {
					total += S[pos];
					pos++;
				} else {
					total += total - 1;
					action++;
				}
			}
			if (pos == targetPos)
				minAction = Math.min(minAction, action);
		}

		write(minAction + "");
	}
}
