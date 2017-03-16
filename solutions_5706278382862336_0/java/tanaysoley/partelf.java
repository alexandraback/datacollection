import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class partelf {
	public static void main(String args[]) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		long T, a, b,ctr=0,pow;
		String s;
		StringTokenizer st;

		s = br.readLine();
		T = Long.parseLong(s);
		for (int I = 1; I <= T; I++) {
			ctr=0;
			System.out.print("Case #"+I+": ");
			s = br.readLine();
			st = new StringTokenizer(s, "/");
			a = Long.parseLong(st.nextToken());
			b = Long.parseLong(st.nextToken());
			if ((pow=checkP2(b))==-1) {
				System.out.println("impossible");
			} else {
				while (true) {
					if (a / 2 > 0) {
						ctr++;
						a=a/2;
					}else{
						break;
					}
				}
				System.out.println(pow-ctr);
			}
		}
	}

	public static int checkP2(long a) {
		int ctr=0;
		int b = 1;
		while (b <= a) {
			//System.out.println(ctr);
			if (b == a) {
				return ctr;
			}
			ctr++;
			b = b * 2;
		}
		return -1;
	}
}