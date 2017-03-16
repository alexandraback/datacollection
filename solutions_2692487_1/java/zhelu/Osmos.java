import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Collections;
import java.util.Scanner;
import java.util.Stack;

public class Osmos {

	static void readInWriteOut(String input, String output) throws IOException {
		Scanner sc = new Scanner(new File(input));
		BufferedWriter bw = new BufferedWriter(new FileWriter(output));
		int num = sc.nextInt();
		for (int i = 1; i <= num; i++) {
			int start = sc.nextInt();
			int numMotes = sc.nextInt();
			Stack<Integer> otherMotes = new Stack<Integer>();
			for (int j = 0; j < numMotes; j++) {
				otherMotes.push(sc.nextInt());
			}
			Collections.sort(otherMotes);
			Collections.reverse(otherMotes);
			int answer = solve(start, otherMotes);
			System.out.println("Case #" + i + ": " + answer);
			bw.write("Case #" + i + ": " + answer);
			if (i != num) {
				bw.newLine();
			}
		}
		sc.close();
		bw.close();
	}


	static int solve(int start, Stack<Integer> otherMotes) {
		int size = start;
		while (!otherMotes.empty() && otherMotes.peek() < size) {
			size += otherMotes.pop();
		}
		if (otherMotes.empty()) {
			return 0;
		}
		int removeCost = otherMotes.size();
		if (size != 1) {
			otherMotes.push(size - 1);
			int addOneCost = 1 + solve(size, otherMotes);
			return Math.min(removeCost, addOneCost);
		} else {
			return removeCost;
		}

	}


	/**
	 * @param args
	 * @throws IOException
	 */
	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		readInWriteOut("Osmos-large.in", "Osmos-large-out.txt");

	}

}
