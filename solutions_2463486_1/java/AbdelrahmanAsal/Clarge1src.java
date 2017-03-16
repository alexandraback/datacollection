import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;


public class C {
	
	boolean isPalin(long n) {
		char[] c = (n + "").toCharArray();
		for(int i = 0; i < c.length / 2; ++i)
			if (c[i] != c[c.length - i- 1])
				return false;
		return true;
	}
	
	void run() throws Exception {
		BufferedReader bfd = new BufferedReader(
				new InputStreamReader(System.in));
		int tc = Integer.parseInt(bfd.readLine());
		long a, b;
		StringTokenizer tk;
		long fs[] = new long[39];
		int k = 0;
		for(long i = 1; i < 10000000; ++i) {
			if(isPalin(i) && isPalin(i*i)) {
				fs[k++] = i*i;
			}
		}
//		System.out.println(Arrays.toString(fs));
		for(int t = 1; t <= tc; ++t) {
			System.out.print("Case #"+ t +": ");
			tk = new StringTokenizer(bfd.readLine());
			a = Long.parseLong(tk.nextToken());
			b = Long.parseLong(tk.nextToken());
			int fid = 0, lid = 0;
			int xa = Arrays.binarySearch(fs, a);
			if(xa >= 0) {
				fid = xa;
			} else {
				fid = - xa - 1;
			}
			int xb = Arrays.binarySearch(fs, b);
			if(xb >= 0) {
				lid = xb;
				++lid;
			} else {
				lid = - xb - 1;
			}
			System.out.println(lid - fid);
		}

	}
	
	public static void main(String[] args) throws Exception {
		new C().run();
	}

}

