import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;

public class Main {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new FileReader(new File("D.in")));
		PrintWriter pw = new PrintWriter(new BufferedWriter(new FileWriter(new File("D.out"))));

		int T = Integer.parseInt(br.readLine());
		for (int t = 0; t < T; t++) {
			String[] str = br.readLine().split(" ");
			int X = Integer.parseInt(str[0]);
			int R = Integer.parseInt(str[1]);
			int C = Integer.parseInt(str[2]);
			pw.println("Case #"+(t+1)+": "+(analyze(X, R, C) ? "GABRIEL" : "RICHARD"));
			pw.flush();
		}
		
		pw.close();
		br.close();
	}
	
	private static boolean analyze(int X, int R, int C) {
		if ((R*C)%X > 0) return false;
		if (X <= 2) return true;
		if (X >= 7) return false;
		int max = Math.max(R, C);
		int min = Math.min(R, C);
		switch (X) {
		case 3:
			if (max <= 2) return false;
			if (min <= 1) return false;
			break;
		case 4:
			if (max <= 3) return false;
			if (min <= 2) return false;
			break;
		case 5:
			if (max <= 4) return false;
			if (min <= 2) return false;
			break;
		case 6:
			break;
		}
		return true;
	}
}
