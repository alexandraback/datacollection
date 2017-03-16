import java.util.*;

public class pB {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);

		int T = in.nextInt();
		for(int t=0; t<T; ++t) {
			int a = in.nextInt(), b = in.nextInt(), k = in.nextInt();

			int count = 0;
			for(int i=0; i<a; ++i) {
				for(int j=0; j<b; ++j) {
					if((i&j) < k) ++count;
				}
			}

			System.out.println("Case #" + (t+1) + ": " + count);
		}
	}
}