import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;


public class Round1bQuestion1 {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new FileReader(new File("r1q1.in")));
		int T = Integer.parseInt(br.readLine());
		for (int i = 0;i < T;i++) {
			doCase(i + 1, br.readLine());
		}
	}

	static void doCase(int caseNum, String ss) {
		String[] args = ss.split(" ");
		int N = Integer.parseInt(args[0]);
		int[] ses = new int[N];
		double[] ret = new double[N];
		int X = 0;
		for (int i = 0;i < N;i++) {
			ses[i] = Integer.parseInt(args[i + 1]);
			X += ses[i];
		}
		int X2 = X + X;
		int Xc = N;
		boolean finished = false;
		while (!finished) {
			finished = true;
			double targ = ((double)X2) / Xc;
			for (int i = 0;i < N;i++) {
				if (ses[i] != -1) {
					if (X > 0)
						ret[i] = (targ - ses[i]) / X;
					else
						ret[i] = 1 / N;
				}
				if (ret[i] < 0)
				{
					ret[i] = 0;
					X2 -= ses[i];
					Xc--;
					ses[i] = -1;
					finished = false;
				}
			}
		}
		double total = 0;
		for (int i = 0;i < N;i++)
		{
			total += ret[i];
		}
		System.out.print("Case #" + caseNum + ": ");
		for (int i = 0;i < N;i++) {
			System.out.print("" + ret[i] * 100 + " " /*+ " (" + (X * ret[i] + ses[i]) + ") "*/);
		}
		System.out.println("");
	}
}
