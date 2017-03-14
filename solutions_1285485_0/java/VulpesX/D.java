import java.util.*;
import java.awt.*;

public class D
{
	public static void main(String args[])
	{
		Scanner scan = new Scanner(System.in);

		int T = scan.nextInt();
		double EPS = 0.0000001;

		for(int ca=1;ca <= T;ca++)
		{
			int m = scan.nextInt();
			int n = scan.nextInt();
			int d = scan.nextInt();
			int r = -1;
			int c = -1;

			for(int i=0;i < m;i++)
			{
				String str = scan.next();
				for(int j=0;j < n;j++)
					if(str.charAt(j) == 'X')
					{
						r = i;
						c = j;
					}
			}

			m -= 2;
			n -= 2;
			r--;
			c--;
			HashSet<Point> h = new HashSet<Point>();
			//System.out.println("XX " + m + " " + n + " " + r + " " + c);

			for(int dx=-d;dx <= d;dx++)
			for(int dy=-d;dy <= d;dy++)
			{
				if(dx == 0 && dy == 0) continue;

				int nr = r;
				int nc = c;

				if(dy % 2 != 0) nr = (m-nr-1);
				if(dx % 2 != 0) nc = (n-nc-1);
				nr += (dy)*m;
				nc += (dx)*n;

				if(Math.hypot(nr-r, nc-c)-EPS <= d) h.add(fix(nr-r, nc-c));
			}

			System.out.println("Case #" + ca + ": " + h.size());
		}
	}

	public static Point fix(int a, int b)
	{
		if(a == 0 && b > 0) return new Point(0, 1);
		if(a == 0 && b < 0) return new Point(0, -1);
		if(a > 0 && b == 0) return new Point(1, 0);
		if(a < 0 && b == 0) return new Point(-1, 0);

		int g = gcd(Math.abs(a), Math.abs(b));
		a /= g;
		b /= g;

		return new Point(a, b);
	}

	public static int gcd(int a, int b)
	{
		return b == 0 ? a : gcd(b, a%b);
	}
}