import static java.lang.System.*;

import java.util.*;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(in);

		int setnum = sc.nextInt();
		for(int seti=1; seti<=setnum; seti++) {
			int a = sc.nextInt();
			int b = sc.nextInt();
			int k = sc.nextInt();
			
			long ans = 0L;
			for(int i=0; i<a; i++) {
				for(int j=0; j<b; j++) {
					if((i&j) < k) ans++;
				}
			}
			
			out.println("Case #" + seti + ": " + ans);
		}
	}

}
