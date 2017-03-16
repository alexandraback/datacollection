import java.util.*;
import java.io.*;
public class B {
	public B(Scanner in, PrintWriter out) {
		int T = in.nextInt();
		in.nextLine();
		for (int t=0; t<T; t++) {
			int N = in.nextInt();
			int S = in.nextInt();
			int P = in.nextInt();
			int[] vals = new int[31];
			for (int i=0; i<N; i++)
				vals[in.nextInt()]++;
			int ans = 0;
			for (int d=0; d<=2; d++)
				for (int a=0; a<=10; a++)
					for (int b=Math.max(a-d,0); b<=a; b++)
						for (int c=Math.max(a-d,0); c<=a; c++) {
							if (d < 2 && a >= P) {
								ans+=vals[a+b+c];
								vals[a+b+c]=0;
							} else if (a >= P) {
								int tmp = Math.min(vals[a+b+c], S);
								S -= tmp;
								ans += tmp;
								vals[a+b+c] -= tmp;
							}
						}
			out.printf("Case #%d: %d\n",t+1,ans);
		}
		out.close();
	}
	public static void main(String[] args) throws FileNotFoundException {
		new B(new Scanner(new File("b.in")),new PrintWriter(new File("b.out")));
	}
}
