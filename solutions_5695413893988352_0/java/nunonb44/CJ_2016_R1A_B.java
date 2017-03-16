
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class CJ_2016_R1A_B {
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		int nT = Integer.parseInt(in.readLine());
		for (int t = 1; t <= nT; t++) {
			System.out.print("Case #" + t + ": ");
			StringTokenizer st = new StringTokenizer(in.readLine());
			String a = st.nextToken();
			String b = st.nextToken();
			int minDif = Integer.MAX_VALUE;
			int minA = 0;
			int minB = 0;
			for (int i = 0; i < 1000; i++)
				for (int j = 0; j < 1000; j++)
					if (match(i, a) && match(j, b)) {
						if (Math.abs(i - j) < minDif) {
							minDif = Math.abs(i - j);
							minA = i;
							minB = j;
						}
						else if (Math.abs(i - j) == minDif && i < minA) {
							minDif = Math.abs(i - j);
							minA = i;
							minB = j;
						}
						else if (Math.abs(i - j) == minDif && i == minA && j < minB) {
							minDif = Math.abs(i - j);
							minA = i;
							minB = j;
						}
					}
			String ans = String.valueOf(minA);
			while (ans.length() != a.length())
				ans = "0" + ans;
			System.out.print(ans + " ");
			ans = String.valueOf(minB);
			while (ans.length() != a.length())
				ans = "0" + ans;
			System.out.println(ans);
		}
	}

	private static boolean match(int n, String a) {
		for (int i = a.length() - 1; i >= 0; i--) {
			if (a.charAt(i) != '?')
				if (a.charAt(i) - '0' != n % 10)
					return false;
			n /= 10;
		}
		return n == 0;
	}

}
