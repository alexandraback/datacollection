import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;


public class Main {

	public static void main (String[] args) throws IOException {
		new Main();
	}
	
	public Main() throws IOException {
		Scanner in = new Scanner(new File("C-small-attempt1.in"));
		//Scanner in = new Scanner(new File("C-test.txt"));
		BufferedWriter out = new BufferedWriter(new FileWriter("C-small.txt"));
		
		int amountOfTasks = in.nextInt();
		for (int task = 0; task < amountOfTasks; task++) {
			int n = in.nextInt();
			int m = in.nextInt();
			int k = in.nextInt();
			if (k < 5) {
				out.write("Case #" + (task+1) + ": " + k);
				out.newLine();
			} else if (n == 1 || m == 1) {
				out.write("Case #" + (task+1) + ": " + k);
				out.newLine();
			} else if (n == 2 || m == 2) {
				out.write("Case #" + (task+1) + ": " + k);
				out.newLine();
			} else if (n == 3 || m == 3) {
				int min = k-2;
				min /= 3;
				out.write("Case #" + (task+1) + ": " + (k-min));
				out.newLine();
			} else if (n == 4 || m == 4) {
				int answer = 0;
				if (k == 5) {
					answer = 4;
				} else if (k == 6) {
					answer = 5;
				} else if (k == 7) {
					answer = 6;
				} else if (k == 8) {
					answer = 6;
				} else if (k == 9) {
					answer = 7;
				} else if (k == 10) {
					answer = 8;
				} else if (k == 11) {
					answer = 8;
				} else if (k == 12) {
					answer = 8;
				} else if (k == 13) {
					answer = 9;
				} else if (k == 14) {
					answer = 10;
				} else if (k == 15) {
					answer = 11;
				} else if (k == 16) {
					answer = 10;
				} else if (k == 17) {
					answer = 11;
				} else if (k == 18) {
					answer = 12;
				} else if (k == 19) {
					answer = 13;
				} else {
					answer = 14;
				}
				out.write("Case #" + (task+1) + ": " + answer);
				out.newLine();
			}
		}
		
		out.close();
		in.close();
	}
}
