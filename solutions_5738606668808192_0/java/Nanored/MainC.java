import java.awt.font.NumericShaper.Range;
import java.io.FileWriter;
import java.io.IOException;

public class MainC {

	public static void next(int[] b, int n) {
		int k = n-2;
		do {
			if(b[k] == 1)
				b[k] = 0;
			else b[k] = 1;
			k --;
		} while(b[k+1] == 0);
	}

	public static long prime(long a) {
		if(a%2 == 0) return 2;
		int j = -1;
		for(long i = 3; i <= Math.sqrt(a); i+=2+j) {
			if(a%i == 0) return i;
			j *= -1;
		}
		return -1;
	}

	public static void main(String[] args) {
		try {
			FileWriter f = new FileWriter("rep.txt");
			f.write("Case #1:\n");
			int n =16, j = 50;
			int[] b = new int[n];
			long[] e = new long[10];
			b[0] = 1;
			b[n-1] = 1;
			int k = 0;
			while(k < j) {
				boolean ok = true;
				for(int p = 2; p <= 10; p++) {
					long a = 0;
					for(int i = 0; i < n; i++)
						if(b[i] == 1) a += Math.pow(p, n-i-1);
					long pr = prime(a);
					if(pr == -1) {
						ok = false;
						break;
					} else {
						e[p-1] = pr;
						if(p == 10) e[0] = a;
					}
				}
				if(ok) {
					for(int z = 0; z < 9; z++)
						f.write(e[z] + " ");
					f.write(e[9] + "\n");
					k++;
				}
				next(b, n);
			}
			f.close();
	  } catch (IOException e) {
		  e.printStackTrace();
	  }
	}
 
}