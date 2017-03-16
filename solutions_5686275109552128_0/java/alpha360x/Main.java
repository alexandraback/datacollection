import java.io.BufferedReader;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.List;
import java.util.PriorityQueue;
import java.util.Queue;
import java.util.Scanner;

public class Main {

	// class MaxComp implements
	class Pancake {
		public int min;
		public int[] solution;
		public int special;

		public Pancake() {
		}
	}

	Pancake table[];

	public void fillTable(int max) {
		table = new Pancake[max + 1];
		for (int i = 4; i <= max; i++) {
			int upperBound = (int) Math.round(Math.sqrt(i));
			// int min = i;
			// for (int j = 2; j < upperBound; j ++) {
			int seg = (int) Math.round((double) i / (double) upperBound);
			int tmp = seg * upperBound;
			table[i] = new Pancake();
			if (tmp == i) {
				int[] solution = new int[upperBound];
				table[i].min = upperBound * 2 - 1;
				table[i].special = upperBound - 1;
				for (int j = 0; j < upperBound; j++) {
					solution[j] = upperBound;
				}
				table[i].solution = solution;
			} else if (tmp > i) {
				int[] solution = new int[upperBound];
				table[i].min = upperBound - 1 + seg;
				table[i].special = upperBound - 1;
				solution[0] = i - (upperBound - 1) * seg;
				for (int j = 1; j < upperBound; j++) {
					solution[j] = seg;
				}
				table[i].solution = solution;
			} else {
				int[] solution = new int[upperBound + 1];
				table[i].min = upperBound + seg;
				table[i].special = upperBound;
				solution[0] = i - tmp;
				for (int j = 1; j < upperBound + 1; j++) {
					solution[j] = seg;
				}
				table[i].solution = solution;
			}
			// }
		}
	}

	public int solve(int dinerCount, int[] diners) throws IOException {
		PriorityQueue<Integer> maxQ;

		if (dinerCount == 0)
			return 0;
		// if (dinerCount == 1) return diners[0];

		// minQ = new PriorityQueue<Integer>();
		maxQ = new PriorityQueue<Integer>(Collections.reverseOrder());

		int theMin = Integer.MAX_VALUE;
		for (int diner : diners) {
			// minQ.offer(diner);
			maxQ.offer(diner);
			theMin = Math.min(theMin, diner);
		}

		int theMax = maxQ.peek();
		int special = 0;
		int min = theMax;

		for (int i = 1; i < theMax; i++) {
			int totalMove = 0;
			PriorityQueue<Integer> theQ = new PriorityQueue<Integer>(maxQ);
			while (true) {
				int max = theQ.poll();				
				if (max - i <= 1) {
					min = Math.min(max + totalMove, min);
					break;
				}
				int div = max / i;
				int rem = max % i;
				int move = div;
				if (rem == 0) {
					move -= 1;
				}
				totalMove += move;
				if (totalMove + i >= min) {
					break;
				} else {
					if (rem != 0) {
						theQ.offer(rem);
					}
					for (int j = 0; j < div; j ++) {
						theQ.offer(i);
					}
				}
			}
		}

		/*
		 * while (true) { max = maxQ.poll();
		 * 
		 * 
		 * if (max + special <= min) { min = max + special; }
		 * 
		 * if (special + 3 >= min) { break; }
		 * 
		 * if (max < 4) { break; }
		 * 
		 * Pancake pan = table[max];
		 * 
		 * for (int p : pan.solution) { maxQ.offer(p); }
		 * 
		 * special += pan.special;
		 * 
		 * }
		 */

		return min;

	}

	public Main() throws IOException {

		Scanner scanner = new Scanner(System.in);
		String userDir = System.getProperty("user.dir");
		FileWriter fWriter = new FileWriter(new File(userDir + "\\result.txt"));

		fillTable(100);
		int count = scanner.nextInt();
		StringBuilder content = new StringBuilder();
		for (int i = 0; i < count; i++) {

			int dinerCount = scanner.nextInt();
			int[] diners = new int[dinerCount];
			for (int j = 0; j < dinerCount; j++) {
				diners[j] = scanner.nextInt();
			}
			int result = solve(dinerCount, diners);
			content.append("Case #").append(i + 1).append(": ").append(result)
					.append("\r\n");
		}

		// System.out.print(content.toString());

		fWriter.write(content.toString());
		fWriter.flush();
		fWriter.close();
	}

	public static void main(String[] args) {
		try {
			new Main();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
}
