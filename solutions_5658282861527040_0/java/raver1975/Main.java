import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.io.UnsupportedEncodingException;
import java.util.Arrays;
import java.util.HashSet;
import java.util.Scanner;

public class Main {
	static PrintWriter writer;

	public static void main(String[] args) {
		try {
			writer = new PrintWriter("out.txt", "UTF-8");
		} catch (FileNotFoundException e1) {
			e1.printStackTrace();
		} catch (UnsupportedEncodingException e1) {
			e1.printStackTrace();
		}
		Scanner sc = null;
		try {
			sc = new Scanner(new File("in.txt"));
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}
		int T = sc.nextInt();
		top: for (int t = 0; t < T; t++) {
			// ----------------------------------------------------------
			int A=sc.nextInt();
			int B=sc.nextInt();
			int K=sc.nextInt();
			int won=0;
			int total=0;
			for (int i=0;i<A;i++){
				for (int j=0;j<B;j++){
					if ((i&j)<K)won++;
				}
			}
			out(t,won+"");

			// ----------------------------------------------------------
		}
		writer.close();
	}

	public static void out(int t, String s) {
		String g = "Case #" + (t + 1) + ": " + s;
		System.out.println(g);
		writer.write(g + "\n");

	}
}

