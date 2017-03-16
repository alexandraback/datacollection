package assignmentC;

import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;

public class C {
	public static void main(String[] args) throws IOException {
		Scanner in = new Scanner(new File("test2"));
		PrintWriter out = new PrintWriter(new FileWriter("output.txt"));
		Solver s = new Solver(in, out);
		s.solveCases();
		out.flush();
		out.close();
		in.close();
	}
}

class Solver {
	Scanner in;
	PrintWriter out;
	public Solver(Scanner scanner, PrintWriter printStream) {
		in = scanner;
		out = printStream;
	}

	public void solveCases() {
		int numCases = in.nextInt();
		in.nextLine();
		for(int i=0;i<numCases;i++) {
			out.println("Case #"+(i+1)+": " + solveNextCase());
		}
	}

	public String solveNextCase() {
		int a = in.nextInt();
		int b = in.nextInt();
		long[][] boxes = new long[a][2];
		long[][] toys = new long[b][2];
		for (int i = 0; i < a; i++) {
			boxes[i][0] = in.nextLong();
			boxes[i][1] = in.nextLong();
		}
		for (int i = 0; i < b; i++) {
			toys[i][0] = in.nextLong();
			toys[i][1] = in.nextLong();
		}
		
		long answer = calculateMax(boxes, toys, 0, 0, 0, 0);
		return answer + "";
	}

	private long calculateMax(long[][] boxes, long[][] toys, int countA, int countB, long subtractedA, long subtractedB) {
		if (countA >= boxes.length || countB >= toys.length) {
			return 0;
		}
		long result = 0;
		if (boxes[countA][1] == toys[countB][1]) {
			long amountA = boxes[countA][0] - subtractedA;
			long amountB = toys[countB][0] - subtractedB;
			if (amountA < amountB) {
				result += amountA;
				result += calculateMax(boxes, toys, countA + 1, countB, 0, amountA);
			} else {
				result += amountB;
				result += calculateMax(boxes, toys, countA, countB + 1, amountB, 0);
			}
		} else {
			long tak1 = calculateMax(boxes, toys, countA + 1, countB, 0 , subtractedB);
			long tak2 = calculateMax(boxes, toys, countA, countB + 1, subtractedA , 0);
			return Math.max(tak1, tak2);
		}
		return result;
	}
}