import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;

public class OnceC_B {
	public static void main(String[] args) throws IOException {
		Scanner sc2 = new Scanner(System.in);
		String inFile = sc2.nextLine();
		String outFile = inFile + ".out.txt";
		FileReader fr = new FileReader(inFile);
		Scanner sc = new Scanner(new BufferedReader(fr));
		FileWriter fw = new FileWriter(outFile);
		BufferedWriter bw = new BufferedWriter(fw);
		PrintWriter pw = new PrintWriter(bw);
		int T = sc.nextInt();
		for (int i = 0; i < T; i++)
			new Case(sc, pw, i + 1);
		sc.close();
		pw.close();
	}

	static class Case {
		int count = 0, total = 0, L = 0, S = 0, worst = 0;
		String target;
		char key[];

		Case(Scanner sc, PrintWriter pw, int caseNo) {
			int K = sc.nextInt();
			L = sc.nextInt();
			S = sc.nextInt();
			String keyStr = sc.next();

			key = new char[keyStr.length()];
			for (int i = 0; i < keyStr.length(); i++)
				key[i] = keyStr.charAt(i);

			target = sc.next();
			permutation("");
			pw.println("Case #" + caseNo + ": " + (worst - (count / (double) total)));
		}

		void permutation(String prefix) {
			int n = key.length;
			if (prefix.length() == S) {
				total++;
				int thisCount = 0;
				for (int i = 0; i < S; i++)
					if (prefix.indexOf(target, i) == i)
						thisCount++;
				if (thisCount > worst)
					worst = thisCount;
				count += thisCount;
			} else {
				for (int i = 0; i < n; i++)
					permutation(prefix + key[i]);
			}
		}
	}
}
