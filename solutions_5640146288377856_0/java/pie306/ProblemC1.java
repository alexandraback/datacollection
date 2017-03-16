import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;


public class ProblemC1 {
	public static void main(String[] args) throws IOException {
		Scanner s = null;
		Scanner lineScan = null;
		int size;
		int currentSize;
		String line;
		File output = new File("output.txt");
		PrintWriter printer = new PrintWriter(output);
		s = new Scanner(new BufferedReader(new FileReader("A-small-attempt0.in")));
		size = s.nextInt();
		s.nextLine();
		for (int i = 0; i < size; i++) {
			line = s.nextLine();
			lineScan = new Scanner(line);
			int a = lineScan.nextInt();
			int b = lineScan.nextInt();
			int c = lineScan.nextInt();
			int temp = calc(a, b, c);
			printer.print("Case #" + (i + 1) + ": ");
			printer.println(temp);
		}
		printer.close ();   
	}
	public static int calc(int a, int b, int c) {
		if (b % c == 0) {
			int temp = b / c;
			temp *= a;
			return temp + c - 1;
		} else {
			int temp = b / c;
			temp += c;
			return temp;
		}
	}
}
