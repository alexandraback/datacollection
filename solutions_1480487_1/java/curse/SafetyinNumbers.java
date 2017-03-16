import java.io.*;
import java.util.*;

public class SafetyinNumbers {
	public static void main(String[] args) {
		try {
			BufferedReader ifStream = new BufferedReader(new FileReader("in"));
			PrintWriter ofStream = new PrintWriter(new FileWriter("out"));
			int numCase = Integer.parseInt(ifStream.readLine());

			for (int i=1; i<=numCase; i++) {
				ofStream.println("Case #"+i+": "+computeAns(ifStream.readLine()));
			}

			ifStream.close();
			ofStream.close();
		}
		catch (IOException e) {
			System.out.println("IOException.");
		}
	}

	private static String computeAns(String input) {
		String ans = "";
		StringTokenizer st = new StringTokenizer(input, " ", false);
		int N = Integer.parseInt(st.nextToken());
		int[] s = new int[N];
		int X, cnt;
		double m = 0.0;
		int[] sort = new int[N];
		int temp = 0;

		X = 0;
		for (int i=0; i<N; i++) {
			s[i] = Integer.parseInt(st.nextToken());
			X += s[i];
			sort[i] = s[i];
		}

		for (int i=0; i<N-1; i++) {
			for (int j=0; j<N-i-1; j++) {
				if (sort[j] > sort[j+1]) {
					temp = sort[j];
					sort[j] = sort[j+1];
					sort[j+1] = temp;
				}
			}
		}

		int t = X;
		cnt = 0;
		int index = 0;
		for (int i=0; i<N; i++) {
			if (i == N-1) {
				index = i;
				cnt++;
				break;
			}
			if (t - (i+1)*(sort[i+1]-sort[i]) >= 0) {
				t -= (i+1)*(sort[i+1]-sort[i]);
				cnt++;
			}
			else {
				index = i;
				break;
			}
		}
		double minScore = sort[index] + t/(double)cnt;

		for (int i=0; i<N; i++) {
			m = ((minScore - s[i])/(double)X)*100;
			if (m < 0.0) {
				m = 0.0;
			}
			ans += m + " ";
		}
		
		return ans.trim();
	}
}
