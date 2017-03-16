import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;

public class Main {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new FileReader(new File("A.in")));
		PrintWriter pw = new PrintWriter(new BufferedWriter(new FileWriter(new File("A.out"))));

		int T = Integer.parseInt(br.readLine());
		for (int t = 0; t < T; t++) {
			String[] str = br.readLine().split("/");
			long P = Long.parseLong(str[0]);
			long Q = Long.parseLong(str[1]);
			pw.println("Case #"+(t+1)+": "+analyze(P, Q));
			pw.flush();
		}

		pw.close();
		br.close();
	}
	
	private static String analyze(long P, long Q) {
		long r = gcm(P, Q);
		P /= r;
		Q /= r;
		if ((1L<<40)%Q != 0) return "impossible";
		r = (1L<<40)/Q;
		P *= r;
		if ((P&(1L<<40)) != 0) return ""+1;
		for (int i = 1; i <= 40; i++) {
			if ((P&(1L<<(40-i))) != 0) return ""+i;
		}
		return "impossible";
	}
	
	private static long gcm(long a, long b) {
		long c = a%b;
		while (c != 0) {
			a = b;
			b = c;
			c = a%b;
		}
		return b;
	}
}
