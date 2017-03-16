import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;

public class Main {
	
	public static void main(String[] args) {
		try {
			BufferedReader br = new BufferedReader(new FileReader(new File("B.in")));
			PrintWriter pw = new PrintWriter(new BufferedWriter(new FileWriter(new File("B.out"))));

			int T = Integer.parseInt(br.readLine());
			String[] param;
			for (int i = 0; i < T; i++) {
				param = br.readLine().split(" ");
				int N = Integer.parseInt(param[0]);
				int X = Integer.parseInt(param[1]);
				int Y = Integer.parseInt(param[2]);
				pw.println("Case #"+(i+1)+": "+analyze(N, X, Y));
			}
			
			pw.close();
			br.close();
		} catch (IOException e) {
			e.printStackTrace();
			return;
		}
	}
	
	private static double analyze(int N, int X, int Y) {
		
		int s = (Math.abs(X) + Y)/2+1;
		int max = 	(s*(2+(s-1)*4))/2;
		int min = ((s-1)*(2+(s-2)*4))/2;
		if (N >= max) return 1.0;
		if (N <= min) return 0.0;
		if (X == 0) return 0.0;
		int rest = N - min;
		if (rest > 2*(s-1) + Y) return 1.0;
		double total = Math.pow(2.0, rest);
		double answer = 1.0;
		for (int i = 0; i < Y; i++) {
			double ue = 1.0;
			double shita = 1.0;
			for (int j = 0; j < i+1; j++) {
				ue *= rest - j;
				shita *= (j+1);
			}
			answer += ue / shita;
		}
		return 1.0 - (answer / total);
	}
}
