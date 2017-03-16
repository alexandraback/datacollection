import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;

public class OneC_A {
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
		Case(Scanner sc, PrintWriter pw, int caseNo) {
			int R = sc.nextInt();
			int C = sc.nextInt();
			int W = sc.nextInt();
			int posCount = C - W + 1;
			int hitCount = 0;
			boolean possPos[] = new boolean[C - W + 1];
			for (int i = 0; i < C - W + 1; i++)
				possPos[i] = true;
			int prob[] = new int[C];
			boolean selected[] = new boolean[C];
			int step = 0;
			while (true) {
				int maxProb = 0;
				for (int i = 0; i < C; i++) {
					prob[i] = 0;
					for (int j = Math.max(0, i - W + 1); j <= Math.min(C-W, i); j++)
						prob[i] += possPos[j] ? 1 : 0;
					if (prob[i] > maxProb && selected[i] == false)
						maxProb = prob[i];
				}
				int selectedIndex = -1;
				for (int i = 0; i < C; i++) {
					if (prob[i] == maxProb && !selected[i]) {
						selectedIndex = i;
						break;
					}
				}
				selected[selectedIndex] = true;
				boolean noProb = true;
				int subPosCount = 0;
				for (int i = Math.max(0, selectedIndex - W + 1); i <= Math.min(C-W, selectedIndex); i++) {
					subPosCount += possPos[i] ? 1 : 0;
				}
				noProb = posCount - subPosCount == 0;
				if (!noProb) {
					for (int i = Math.max(0, selectedIndex - W + 1); i <= Math.min(C-W, selectedIndex); i++) {
						possPos[i] = false;
					}
					posCount = 0;
					for (int i = 0; i < C - W + 1; i++)
						posCount += possPos[i] ? 1 : 0;
				} else {
					hitCount++;
				}
				step++;
				if (posCount == 1 && hitCount == W)
					break;
			}
			pw.println("Case #" + caseNo + ": " + step * R);
		}
	}
}
