import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;
import java.util.StringTokenizer;
import java.util.Arrays;

class Main
{
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static Scanner sc = new Scanner(new InputStreamReader(System.in));

	public static void main (String[] args) throws java.lang.Exception {
		int T = Integer.parseInt(br.readLine());
		for (int i=0; i<T; i++){
			solve(i);
		}
	}

	public static void solve(int num) throws IOException{
		StringTokenizer st = new StringTokenizer(br.readLine());
		int K = Integer.parseInt(st.nextToken());
		int L = Integer.parseInt(st.nextToken());
		int S = Integer.parseInt(st.nextToken());

		String type     = br.readLine();
		String target   = br.readLine();
		int[] checkList = new int[S+1];
		for (int i=0; i<S; i++) {
			checkList[i] = 0;
		}
		int maxCount = 0;

		long pattern = (long)Math.pow(K, S);

		for (int i=0; i<pattern; i++) {
			String str = "";
			int tmp = i;
			for (int j=0; j<S; j++) {
				str += ("" + type.charAt(tmp % K));
				tmp = (tmp - tmp % K) / K;
			}

			int count = checkMatch(str,target);
			checkList[count]++;
			maxCount = Math.max(maxCount,count);
		}


		long totalRemain = 0;
		for (int i=0; i<maxCount; i++) {
			totalRemain += checkList[i] * (maxCount - i);
		}

		System.out.println("Case #" + (num+1) + ": " + ((double)totalRemain / (double)pattern));
	}

	public static int checkMatch(String str, String target) {
		int counter = 0;
		for (int start = 0; start <= str.length() - target.length(); start++) {
			boolean checker = true;
			for (int i=0; i<target.length(); i++) {
				if (str.charAt(start+i) != target.charAt(i)) {
					checker = false;
					break;
				}
			}

			if (checker) counter++;
		}

		return counter;
	}
}

