import java.util.*;

public class clarge {

	final public static int[][] TABLE = {{1,2,3,4},{2,-1,4,-3},
										 {3,-4,-1,2},{4,3,-2,-1}};

	public static void main(String[] args) {

		Scanner stdin = new Scanner(System.in);
		int numCases = stdin.nextInt();

		for (int loop=1; loop<=numCases; loop++) {
			int len = stdin.nextInt();
			long rep = stdin.nextLong();
			char[] pat = stdin.next().toCharArray();

			// To make life easier for me.
			int n = len*((int)Math.min(8,rep));
			char[] str = new char[n];
			for (int i=0; i<((int)Math.min(8,rep)); i++)
				for (int j=0; j<len; j++)
					str[i*len+j] = pat[j];

			int[] vals = new int[n];
			vals[0] = (int)(str[0] - 'i' + 2);

			// Build products.
			for (int i=1; i<n; i++) {
				int neg = 0, myVal = vals[i-1];
				if (vals[i-1] < 0) {
					neg = 1;
					myVal = -vals[i-1];
				}

				int thisval = (int)(str[i] - 'i' + 2);
				if (neg == 0)
					vals[i] = TABLE[myVal-1][thisval-1];
				else
					vals[i] = -TABLE[myVal-1][thisval-1];
			}

			// This part is okay.
			if ((vals[len-1] == -1 && rep%2L != 1L) || vals[len-1] == 1 || (vals[len-1] != -1 && rep%4L != 2L)) {
				System.out.println("Case #"+loop+": NO");
			}


			else {

				boolean res = false;
				int end = 0;
				while (end < vals.length && vals[end] != 2) end++;
				int next = end+1;
				while (next < vals.length && vals[next] != 4) next++;

				System.out.print("Case #"+loop+": ");
				if (next < vals.length) System.out.println("YES");
				else System.out.println("NO");
			}
		}
	}
}