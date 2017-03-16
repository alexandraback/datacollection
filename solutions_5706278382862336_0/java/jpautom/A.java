import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.util.*;


public class A {
	static void solveCase() {
		String[] s = sc.next().split("/");
		long P = Long.valueOf(s[0]);
		long Q = Long.valueOf(s[1]);
		long g = gcd(P, Q);
		P /= g;
		Q /= g;
		
		int k = isPower(Q);
		if (k < 0) {
			printf("impossible\n");
		}
		else {
			printf("%d\n", calculate(P, Q));
		}
	}
	
	static int calculate(long p, long q) {
		int k = 0;
		while (p < q) {
			p *= 2;
			k++;
		}
		return k;
	}
	
	static int isPower(long a) {
		int e = -1;
		for (int i=0; i<63; i++) {
			if (((1L<<i) & a) > 0) {
				if (e >= 0) return -1;
				e = i;
			}
		}
		return e;
	}
	
	static long gcd(long a, long b) {
		if (b==0) return a;
		return gcd(b, a%b);
	}
	
	static void printf(String f, Object... args) {
		System.out.printf(f, args);
	}
	
	static void p(Object... args) {
		System.out.println(Arrays.deepToString(args));
	}
	
	static Scanner sc;
	public static void main(String[] args) throws FileNotFoundException {
		sc = new Scanner(args.length > 0 ? new FileInputStream(args[0]) : System.in);
		int numCases = sc.nextInt();
		for (int nCase=1; nCase<=numCases; nCase++) {
			printf("Case #%d: ", nCase);
			solveCase();
		}
		sc.close();
	}

}
