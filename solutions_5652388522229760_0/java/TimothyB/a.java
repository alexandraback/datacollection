import java.util.*;
import java.io.*;
import java.math.BigInteger;

public class a {

	public static boolean[] seen;
	public static int count;

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);

		int t = in.nextInt();
		for(int caseN = 1; caseN <= t; caseN++) {
			seen = new boolean[10];
			count = 0;

			//long nn = in.nextLong();
			BigInteger n = new BigInteger(in.next());
			BigInteger m = n;
			boolean good = false;
			for(int i = 0; i < 10000; i++) {
				if(updateSeens(n.toString())) {
					System.out.println("Case #" + caseN + ": " + n);
					good = true;
					break;
				}
				n = n.add(m);
			}
			if(!good)
				System.out.println("Case #" + caseN + ": INSOMNIA");
		}

	}

	public static boolean updateSeens(String str) {
		for(int i = 0; i < str.length(); i++) {
			int a = str.charAt(i) - '0';
			if(seen[a]) continue;
			seen[a] = true;
			count++;
		}
		return count == 10;
	}

}