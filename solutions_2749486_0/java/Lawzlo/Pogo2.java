import java.io.*;
import java.util.*;

public class Pogo2 {

	static Scanner sc;

	static int X;
	static int Y;
	static char[] ans = new char[1000];

	public static String solve() {
		X = sc.nextInt();
		Y = sc.nextInt();

		StringBuilder answer = new StringBuilder();
		if (X > 0)
			for (int i = 0; i < X; i++)
				answer.append("WE");
		else if (X < 0)
			for (int i = 0; i < -X; i++)
				answer.append("EW");

		if (Y > 0)
			for (int i = 0; i < Y; i++)
				answer.append("SN");
		else if (Y < 0)
			for (int i = 0; i < -Y; i++)
				answer.append("NS");

		return answer.toString();
	}

	public static void main(String[] args) throws IOException {

		sc = new Scanner(System.in);
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(
				new FileOutputStream("output.txt")));
		;
		int k = sc.nextInt();
		for (int i = 0; i < k; i++) {
			String s = "Case #" + (i + 1) + ": " + solve();
			System.out.println(s);
			bw.write(s);
			bw.newLine();
		}

		bw.close();

	}
}
