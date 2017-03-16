import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;


public class C {
	
	boolean isPalin(int n) {
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
		int a, b;
		StringTokenizer tk;
		long fs[] = new long[10];
		int k = 0;
		for(int i = 1; k < fs.length; ++i) {
			if(isPalin(i) && isPalin(i*i))
				fs[k++] = i*i;
		}
		for(int t = 1; t <= tc; ++t) {
			System.out.print("Case #"+ t +": ");
			tk = new StringTokenizer(bfd.readLine());
			a = Integer.parseInt(tk.nextToken());
			b = Integer.parseInt(tk.nextToken());
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

