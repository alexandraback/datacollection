import java.util.*;
import java.io.*;

public class d {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);

		int t = in.nextInt();
		for(int caseN = 1; caseN <= t; caseN++) {
			long k = in.nextLong();
			long c = in.nextLong();
			int s = in.nextInt();

			long dif = expo(k, c - 1);
			long temp = 1;

			System.out.print("Case #" + caseN + ":");
			for(int i = 0; i < k; i++) {
				System.out.print(" " + temp);
				temp += dif;
			}
			System.out.println();
		}

	}

	public static long expo(long a, long e) {
		if(e == 0) return 1L;
		if(e == 1) return a;
		if(e % 2 == 0) {
			long temp = expo(a, e / 2);
			return temp * temp;
		}
		return expo(a, e - 1) * a;
	}

}