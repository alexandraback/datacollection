import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class partelf {
	public static void main(String args[]) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		long T, a, b, ctr = 0, pow, temp;
		boolean flag;
		String s;
		StringTokenizer st;

		s = br.readLine();
		T = Long.parseLong(s);
		for (int I = 1; I <= T; I++) {
			flag = true;
			ctr = 0;
			System.out.print("Case #" + I + ": ");
			s = br.readLine();
			st = new StringTokenizer(s, "/");
			a = Long.parseLong(st.nextToken());
			b = Long.parseLong(st.nextToken());
			temp = b;
			if ((pow = checkP2(b)) == -1) {
				while (temp % 2 == 0) {
					temp = temp / 2;
					//System.out.println(temp);
				}
				if (a % temp != 0) {
					System.out.println("impossible");
					flag = false;
				}else{
					a=a/temp;
					b=b/temp;
					//System.out.println(a+","+b);
					pow = checkP2(b);
				}
			}
			if (flag) {
				while (true) {
					if (a / 2 > 0) {
						ctr++;
						a = a / 2;
					} else {
						break;
					}
				}
				System.out.println(pow - ctr);
			}
		}
	}

	public static long checkP2(long a) {
		long ctr = 0;
		long b = 1;
		while (b <= a) {
			//System.out.println(">>"+ctr);
			if (b == a) {
				return ctr;
			}
			ctr++;
			b = b * 2;
		}
		return -1;
	}

}