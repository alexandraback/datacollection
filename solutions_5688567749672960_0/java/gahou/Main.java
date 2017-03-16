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
		int[] list = createArray();
		for (int i=0; i<T; i++){
			int N = Integer.parseInt(br.readLine());
			System.out.println("Case #" + (i + 1) + ": " + list[N]);
		}
	}

	public static int[] createArray() {
		int[] list = new int[1000001];
		list[0] = 0;
		list[1] = 1;
		for (int i=2; i<1000001; i++) {
			list[i] = 9999999;
		}

		for (int i=1; i<1000001; i++) {
			String strI = Integer.toString(i);
			int reverseI = 0;
			for (int k=strI.length()-1; k>=0; k--) {
				reverseI *= 10;
				reverseI += Integer.parseInt("" + strI.charAt(k));
			}

			if (i != 1000000) list[i+1] = Math.min(list[i+1], list[i] + 1);
			if (reverseI <= 1000000) list[reverseI] = Math.min(list[reverseI], list[i] + 1);
		}

		return list;
	}

	public static void solve(int num) throws IOException{
		long N = Long.parseLong(br.readLine());
		int digit = (int)Math.floor(Math.log10(N));
		if (N <= 20) {
			System.out.println("Case #" + (num+1) + ": " + N);
			return;
		}

		long ans = 0;
		for (int i=0; i<digit-1; i++) {
			int p = i==0 ? 1 : i;
			ans += Math.pow(10, p);
			ans += 9;
		}

		long devide = (long)Math.pow(10, digit);
		long tail = N % devide;
		long head = (N - tail) / devide;
		if (digit == 1) digit = 2;
		ans += Math.pow(10, digit-1);
		ans += tail;
		if (head > 1) {
			ans += head;
		}
		System.out.println("Case #" + (num+1) + ": " + ans);
	}
}

