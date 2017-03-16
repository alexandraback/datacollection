import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;

public class OneB_A {
	long step[] = new long[1000001];

	public static void main(String[] args) throws IOException {
		new OneB_A().run();
	}

	void run() throws IOException {
		Scanner sc2 = new Scanner(System.in);
		String inFile = sc2.nextLine();
		String outFile = inFile + ".out.txt";
		FileReader fr = new FileReader(inFile);
		Scanner sc = new Scanner(new BufferedReader(fr));
		FileWriter fw = new FileWriter(outFile);
		BufferedWriter bw = new BufferedWriter(fw);
		PrintWriter pw = new PrintWriter(bw);

		for (int i = 1; i <= 1000000; i++)
			step[i] = i;
		for (int i = 1; i < 1000000; i++) {
			step[i + 1] = Math.min(step[i] + 1, step[i + 1]);
			long r = Long.valueOf(new StringBuilder(String.valueOf(i)).reverse().toString());
			if (r <= 1000000)
				step[(int) r] = Math.min(step[i] + 1, step[(int) r]);
		}

		int T = sc.nextInt();
		for (int i = 0; i < T; i++)
			new Case(sc, pw, i + 1);
		sc.close();
		pw.close();
	}

	class Case {
		Case(Scanner sc, PrintWriter pw, int caseNo) {
			pw.println("Case #" + caseNo + ": " + step[sc.nextInt()]);
		}
	}
}
