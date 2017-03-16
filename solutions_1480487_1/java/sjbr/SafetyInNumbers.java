import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;

public class SafetyInNumbers {

	/**
	 * @param args
	 * @throws IOException
	 * @throws NumberFormatException
	 */
	public static void main(String[] args) throws NumberFormatException,
			IOException {
		new SafetyInNumbers().solve();
	}

	private void solve() throws NumberFormatException, IOException {
		BufferedReader reader = new BufferedReader(new FileReader("A-large.in"));
		int T = Integer.parseInt(reader.readLine());
		for (int i = 0; i < T; i++) {
			String[] split = reader.readLine().split("\\s+");
			int N = Integer.parseInt(split[0]);
			int s[] = new int[N];
			int sum = 0;
			for (int j = 1; j < N + 1; j++) {
				s[j - 1] = Integer.parseInt(split[j]);
				sum += s[j - 1];
			}
			
			double g = (sum * 2.) / N;
			double perc[] = new double[N];
			double neg = 0; int negN = 0;
			for (int j = 0; j < N; j++) {
				perc[j] = (g - s[j])*100 / sum;
				if(perc[j]<0) {
					neg += perc[j];
					negN ++;
				}
			}
			double minus = neg/(N-negN);
			System.out.printf("Case #%d: ", i + 1);
			for (int j = 0; j < perc.length; j++) {
				System.out.printf("%.6f%s", perc[j]<0?0:perc[j]+minus,
						j < perc.length - 1 ? " " : "");
			}
			System.out.println();
		}
	}

}
