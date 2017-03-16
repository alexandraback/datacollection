package osmos;

import java.util.Arrays;

public class Osmos {
	
public static String[] execute(String[] input) {
		
		String[] out;
		String[] splitted;
		
		int a, n;
		int[] sizes;		
		long result;
		
		int test = 1;
		int ntests;		
		
		ntests = Integer.parseInt(input[0]);
		out = new String[ntests];
		
		for (int i = 1; test < 1+ntests;) {			
			splitted = input[i++].split("\\s");			
			a = Integer.parseInt(splitted[0]);			
			n = Integer.parseInt(splitted[1]);
			sizes = new int[n];
			splitted = input[i++].split("\\s");
			for (int j = 0; j < n; j++) {
				sizes[j] = Integer.parseInt(splitted[j]);
			}
			
			result = minOperations(a, sizes, n);
			out[test-1] = "Case #" + test + ": " + result;
			System.out.println(out[test-1]);
			
			test++;								
		}
		return out;
	}

	private static int minOperations(int a, int[] sizes, int n) {
		Arrays.sort(sizes);		
		if(a==1)
			return n;
		
		int[] integral = new int[n];
		integral[0] = a;
		for (int i = 1; i < n; i++) {
			integral[i] = integral[i-1] + sizes[i-1];
		}		
		
		int last = 0;		
		for (int i = 0; i < n; i++) {
			if(sizes[i]<a)
				a += sizes[i];
			else
				break;
			last++;
		}
		return computeMin(a, sizes, n, last);		
	}
	
	private static int computeMin(int a, int[] sizes, int n, int last) {
		if(last==n)
			return 0;		
		
		int r = howMany(a, sizes[last]);
		if(r<n-last) {
			int pow = modPow(2, r);
			a = a*pow - (pow-1) + sizes[last];
			r += computeMin(a, sizes, n, last+1);
		}
		else
			return n-last;
		
		return Math.min(r, n-last);
	}

	private static int howMany(int a, int reach) {
		int r = 0;
		while(a<=reach) {
			a += a - 1;
			r++;
		}
		return r;
	}
	
	static int modPow(int x, int y)
    {
        int res = 1;
        while (y > 0) {
            if ( (y & 1L) == 1L) {
                res = (res * x );
            }
            x = (x * x);
            y >>= 1;
        }
        return res;
    }
}
