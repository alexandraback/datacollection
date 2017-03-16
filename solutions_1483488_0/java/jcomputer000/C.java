import java.util.*;
import java.io.*;
public class C {
	int numLen(int n) {
		int ans = 0;
		while(n>0) {
			ans++;
			n/=10;
		}
		return ans;
	}
	int shift(int n, int pow) {
		int tmp = n%10;
		return n/10 + tmp*pow;
	}
	public C(Scanner in, PrintWriter out) {
		int T = in.nextInt();
		in.nextLine();
		for (int t=0; t<T; t++) {
			int A = in.nextInt();
			int B = in.nextInt();
			long ans = 0;
			int powLen = 1;
			int pow = 1;
			for (int i=A; i<=B; i++) {
				int x = i;
				int len = numLen(i);
				while(powLen < len) {
					powLen++;
					pow*=10;
				}
				HashSet<Integer> seen = new HashSet<Integer>();
				for (int j=0; j<len; j++) {
					if (x<i && x>=A && x<=B && numLen(x) == len && !seen.contains(x)) {
						seen.add(x);
						ans++;
					}
					x = shift(x,pow);
				}
			}
			out.printf("Case #%d: %d\n",t+1,ans);
		}
		out.close();
	}
	public static void main(String[] args) throws FileNotFoundException {
		new C(new Scanner(new File("c.in")),new PrintWriter(new File("c.out")));
	}
}
