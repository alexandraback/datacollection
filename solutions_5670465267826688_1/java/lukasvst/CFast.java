import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;


public class CFast {

	private static int[][] rev;
	private static int[] mul;

	public static void main(String[] args) throws NumberFormatException, IOException {
		
		rev = new int[9][9];
		int[] values = {-4, -3, -2, -1, 1, 2, 3, 4};
		for(int x = 0; x < values.length; ++x)
		{
			for(int y = 0; y < values.length; ++y)
			{
				int xx = values[x];
				int yy = values[y];
				int res = mult(xx, yy);
				rev[xx+4][res+4] = yy;
			}
		}
		
		// -j * x = k
		// System.out.println(inv(-3, 4));
		
		BufferedReader r = new BufferedReader(new InputStreamReader(System.in));
		int numCases = Integer.parseInt(r.readLine());
		
		for(int numC = 0; numC < numCases; ++numC)
		{
			String line = r.readLine();
			StringTokenizer t = new StringTokenizer(line);
			int n = Integer.parseInt(t.nextToken());
			long x = Long.parseLong(t.nextToken());
			char[] li = r.readLine().toCharArray();
			
			int[] l = new int[n];
			for(int i = 0; i < n; ++i)
			{
				switch(li[i])
				{
				case 'i':
					l[i] = 2;
					break;
				case 'j':
					l[i] = 3;
					break;
				case 'k':
					l[i] = 4;
					break;
				}
			}
			
			int multiplied = l[0];
			for(int i = 1; i < n; ++i)
			{
				multiplied = mult(multiplied, l[i]);
			}
			
			int expTime = 0;
			int test = multiplied;
			for(int i = 2; i < 10; ++i)
			{
				test = mult(test, multiplied);
				if(test == multiplied)
				{
					expTime = i;
					break;
				}
			}
			// => multiplied^expTime = multiplied;
			// <= 15
			
			expTime--;
			
			int numIterations = expTime * 3;
			
			if(x < numIterations)
			{
				numIterations =  (int) x;
			}else
			{
				long mod = x % expTime;
				while(numIterations % expTime != mod)
				{
					numIterations++;
				}
			}
			
			int nn = n;
			n = numIterations * nn;
			int[] ll = new int[n];
			for(int i = 0; i < n; ++i)
			{
				ll[i] = l[i%nn];
			}
			l = ll;
			
			mul = new int[n];
			mul[0] = l[0];
			for(int i = 1; i < n; ++i)
			{
				mul[i] = mult(mul[i-1], l[i]);
			}
			
			boolean possible = false;
			// 0 ... start, start+1 ... end-1, end ... n-1
			// => start >= 0, end <= n-1, start <= end-1  => start <= n-2
			for(int start = 0; start <= n-2 && !possible; ++start)
			{
				if(mul[start] != 2)
				{
					continue;
				}
				for(int end = n-1; end >= start+1 && !possible; --end)
				{
					if(fromTo(end, n-1) == 4 && fromTo(start+1, end-1) == 3)
					{
						possible = true;
					}
				}
			}
			
			String res = possible ? "YES" : "NO";
			System.out.print("Case #");
			System.out.print(numC+1);
			System.out.print(": ");
			System.out.println(res);
			
		}

	}
	
	// including both
	static int fromTo(int a, int b)
	{
		if(b < a)
		{
			return 1000;
		}
		if(a == 0)
		{
			return mul[b];
		}
		return inv(mul[a-1], mul[b]); 
	}
	
	static int inv(int a, int b)
	{
		return rev[a+4][b+4];
	}
	
	static int mult(int a, int b)
	{
		int signA = (a > 0) ? 1 : -1;
		int signB = (b > 0) ? 1 : -1;
		int mA = Math.abs(a);
		int mB = Math.abs(b);
		int m = 10000;
		if(mA == 1) // 1
		{
			m = mB;
		}else if(mA == 2) // i
		{
			if(mB == 1)
			{
				m = 2;
			}else if(mB == 2) // i
			{
				m = -1;
			}else if(mB == 3) // j
			{
				m = 4; // k
			}else if(mB == 4) // K
			{
				m = -3; // -j
			}
		}else if(mA == 3) // j
		{
			if(mB == 1)
			{
				m = 3;
			}else if(mB == 2) // i
			{
				m = -4; // -k
			}else if(mB == 3) // j
			{
				m = -1;
			}else if(mB == 4) // k
			{
				m = 2;
			}
		}else if(mA == 4) // k
		{
			if(mB == 1)
			{
				m = 4; 
			}else if(mB == 2) // i
			{
				m = 3; // j
			}else if(mB == 3) // j
			{
				m = -2;
			}else if(mB == 4)
			{
				m = -1;
			}
		}
		if(m == 10000)
		{
			System.out.println("wrong...");
		}
		
		m *= signA * signB;
		return m;
		
	}

}
