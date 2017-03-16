import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;

public class RevengeofthePancakes {

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter pw = new PrintWriter(System.out);
		int n;
		n = Integer.parseInt(br.readLine());
		for (int i = 0; i < n; i++) {
			String x = br.readLine();
			int[] orignalArr = new int[x.length()];
			int allOnesOnorAfter = x.length(), flag = 1;
			for (int j = x.length() - 1; j >= 0; j--) {
				if (x.charAt(j) == '+') {
					orignalArr[j] = 1;
					if (flag == 1)
						allOnesOnorAfter = j;
				} else {
					orignalArr[j] = 0;
					flag = 0;
				}
			}

			if (allOnesOnorAfter == 0) {
				pw.println("Case #" + (i + 1) + ": 0");
				continue;
			}

			int reqiredFlip = 0, temp;
			while (allOnesOnorAfter != 0) {
				if (orignalArr[0] == 0) {
					// flip till the allOnesOnorAfter
					for (int j = 0; j < allOnesOnorAfter / 2; j++) {
						temp = orignalArr[j];
						orignalArr[j] = (orignalArr[allOnesOnorAfter - 1] + 1) % 2;
						orignalArr[allOnesOnorAfter - 1] = (temp + 1) % 2;
					}
					if (allOnesOnorAfter % 2 != 0) {
						orignalArr[allOnesOnorAfter / 2] = (orignalArr[allOnesOnorAfter / 2] + 1) % 2;
					}
				} else {
					int a = 0;
					while (orignalArr[a] == 1) {
						orignalArr[a] = 0;
						a++;
					}
				}
				allOnesOnorAfter = getAllOneOnOrAfter(orignalArr);
				reqiredFlip++;
			}
			pw.println("Case #" + (i + 1) + ": " + reqiredFlip);
		}
		pw.flush();
	}

	private static int getAllOneOnOrAfter(int[] orignalArr) {

		for (int i = orignalArr.length - 1; i >= 0; i--) {
			if (orignalArr[i] == 0)
				return i + 1;
		}
		return 0;
	}

}
