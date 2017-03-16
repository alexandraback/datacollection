import java.io.*;
import java.util.Scanner;

public class QR_A {

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

}

class Case {
	Case(Scanner sc, PrintWriter pw, int caseNo) {
		int N = sc.nextInt() + 1;
		String S_str = sc.next();
		int S[] = new int[N];
		for (int i = 0; i < N; i++)
			S[i] = S_str.charAt(i) - '0';
		int sum = 0, need = 0;
		for (int i = 0; i < N; i++) {
			if (i - sum > 0) {
				need += i - sum;
				sum = i;
			}
			sum += S[i];
		}
		pw.println("Case #" + caseNo + ": " + need);
	}
}