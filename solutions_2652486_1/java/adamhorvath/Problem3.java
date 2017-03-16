package round1;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.HashSet;

public class Problem3 {

	static ArrayList<Long> fs = new ArrayList<>();
	static int R;
	static int N;
	static int M;
	static int K;

	public static void main(String[] args) throws IOException {
		File file = new File(args[0]);
		BufferedReader reader = new BufferedReader(new FileReader(file));

		String line;
		line = reader.readLine();
		line = reader.readLine();
		String[] lineArr = line.split("\\s");
		R = Integer.parseInt(lineArr[0]);
		N = Integer.parseInt(lineArr[1]);
		M = Integer.parseInt(lineArr[2]);
		K = Integer.parseInt(lineArr[3]);
		
		System.out.println("Case #1: ");

		for (int j = 0; j < R; j++) {
			line = reader.readLine();
			lineArr = line.split("\\s");
			long[] nums = new long[lineArr.length];
			for (int i = 0; i < lineArr.length; i++) {
				nums[i] = Long.parseLong(lineArr[i]);
			}
			solve(j + 1, nums);
		}

		reader.close();
	}

	private static void solve(int caseN, long[] nums) {
		HashSet<Integer> h = new HashSet<>();
		for (long n : nums) {
			prod(n, h);
		}

		int cnt = 0;
		int[] ret = new int[N];

		if (h.size() > 0) {
			while (cnt < ret.length) {
				for (int n : h) {
					ret[cnt++] = n;
					if (cnt == ret.length)
						break;
				}
			}
		} else {
			while (cnt < ret.length) {
				ret[cnt++] = 2;
			}
		}

		String retStr = "";
		for (int i : ret) {
			retStr += i;
		}
		System.out.println(retStr);
	}

	private static void prod(long n, HashSet<Integer> curr) {
		long norig = n;

		if (n == 1)
			return;

		int cnt = 0;
		for (Integer i : curr) {
			if (n < 2) {
				break;
			}

			while (n % i == 0) {
				n /= i;
				cnt++;
			}

			if (cnt > N) {
				break;
			}
		}

		if (cnt > N) {
			n = norig;
		}

		for (int i = M; i >= 2 && n > 1; i--) {
			if (n % i == 0) {
				curr.add(i);
				n /= i;
			}
		}
	}
}
