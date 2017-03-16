import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.HashSet;
import java.util.Scanner;

public class Diamonds {

	static void readInWriteOut (String input, String output) throws IOException {
		Scanner sc = new Scanner(new File(input));
		BufferedWriter bw = new BufferedWriter(new FileWriter(output));
		int numCases = sc.nextInt();
		for (int i = 1; i <= numCases; i++) {
			int n = sc.nextInt();
			int x = sc.nextInt();
			int y = sc.nextInt();
			double answer = solve(n, x, y);
			System.out.println("Case #"+ i +": " + answer);
			bw.write("Case #"+ i +": " + answer);
			if (i != numCases)
				bw.newLine();
		}
		sc.close();
		bw.close();
	}
	
	static double solve(int N, int x, int y) {
		x = (x < 0) ? -x : x;
		int i = 1;
		while (i * (i + 1) / 2 <= N) {
			i += 2;
		}
		i -= 2;
		N -= (i * (i + 1) / 2);
		// System.out.println(N);
		if (x + y <= i - 1) {
			return 1.0;
		}
		else if (x + y > i + 1) {
			return 0.0;
		}
		HashSet<Integer[]> possibilities = new HashSet<Integer[]>();
		possibilities.add(new Integer[] { 0, 0 });
		for (int j = 0; j < N; j++) {
			HashSet<Integer[]> update = new HashSet<Integer[]>();
			for (Integer[] pair : possibilities) {
				if (pair[0] < i + 1) {
					update.add(new Integer[] { pair[0] + 1, pair[1] });
				} else {
					update.add(new Integer[] { pair[0] , pair[1] + 1});
				}
				if (pair[1] < i + 1) {
					update.add(new Integer[] { pair[0], pair[1] + 1 });
				} else {
					update.add(new Integer[] { pair[0] + 1, pair[1] });
				}
				possibilities = update;
			}
		}
		int count = 0;
		for (Integer[] pair : possibilities) {
			if (y < pair[0])
				count++;
		}
		return ((double) count ) / possibilities.size();
	}

	/**
	 * @param args
	 * @throws IOException 
	 */
	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		readInWriteOut("B-small-attempt3.in", "Diamond-small-out.txt");
	}

}
