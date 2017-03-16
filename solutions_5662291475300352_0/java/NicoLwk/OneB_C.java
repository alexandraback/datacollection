import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class OneB_C {

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
		int N;
		ArrayList<Hiker> hikers = new ArrayList<Hiker>();

		Case(Scanner sc, PrintWriter pw, int caseNo) {
			int min = 0;
			N = sc.nextInt();
			for (int i = 0; i < N; i++) {
				int D = sc.nextInt();
				int H = sc.nextInt();
				int M = sc.nextInt();
				for (int j = 0; j < H; j++) {
					hikers.add(new Hiker(D, M + j));
				}
			}
			Collections.sort(hikers);
			Hiker h1 = hikers.get(0);
			Hiker h2 = hikers.get(1);
			if (h1.speed > h2.speed) {
				if (h2.ETA >= h1.ETA + h1.period) {
					min = 1;
				} else {
					min = 0;
				}
			} else if (h1.speed < h2.speed) {
				if (h1.ETA >= h2.ETA + h2.period) {
					min = 1;
				} else {
					min = 0;
				}
			} else {
				min = 0;
			}
			pw.println("Case #" + caseNo + ": " + min);
		}
	}

	static class Hiker implements Comparable<Hiker> {
		int startPos, period;
		double speed, ETA;

		Hiker(int pos, int p) {
			startPos = pos;
			period = p;
			speed = 1.0 / p;
			ETA = (360 - startPos) / 360.0 * p;
		}

		@Override
		public int compareTo(Hiker arg0) {
			return startPos - arg0.startPos;
		}
	}
}
