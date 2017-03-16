import java.util.Scanner;

public class c {
	static final int MAX = 2;
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		for (int caseNum = 1; caseNum <= t; caseNum++) {
			int n = sc.nextInt();
			long[] d = new long[MAX];
			long[] m = new long[MAX];
			int k = 0;
			for (int i = 0; i < n; i++) {
				long D = sc.nextInt();
				long H = sc.nextInt();
				long M = sc.nextInt();
				for (int j = 0; j < H; j++) {
					d[k + j] = D;
					m[k + j] = M + j;
				}				
				k += H;
			}
			int e;
			if (k == 1 || m[0] == m[1]) {
				e = 0;
			}
			else {
				if (m[0] > m[1]) {
					long j = d[0];
					d[0] = d[1];
					d[1] = j;
					j = m[0];
					m[0] = m[1];
					m[1] = j;
				}
				//System.err.println(d[0] + " " + m[0]);
				//System.err.println(d[1] + " " + m[1]);
				if ((360 - d[1]) * m[1] >= (720 - d[0]) * m[0]) {
					e = 1;
				}
				else {
					e = 0;
				}
			}
			System.out.println("Case #" + caseNum + ": " + e);
		}
	}
}
