import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class CCodeJam
{
	public static void solve(int num[])
	{
		int n = num.length;
		int mid = n / 2;
		boolean leftsmaller = false;
		int i = mid - 1;
		int j = (n % 2) != 0 ? mid + 1 : mid;
		while (i >= 0 && num[i] == num[j])
		{
			i--;
			j++;
		}
		if (i < 0 || num[i] < num[j])
			leftsmaller = true;
		while (i >= 0)
		{
			num[j] = num[i];
			j++;
			i--;
		}
		if (leftsmaller == true)
		{
			int carry = 1;
			i = mid - 1;
			if (n % 2 == 1)
			{
				num[mid] += carry;
				carry = num[mid] / 10;
				num[mid] %= 10;
				j = mid + 1;
			} else
				j = mid;
			while (i >= 0)
			{
				num[i] += carry;
				carry = num[i] / 10;
				num[i] %= 10;
				num[j++] = num[i--];
			}
		}
	}

	public static int[] nextP(int num[])
	{
		int n = num.length;
		if (all9(num))
		{
			int[] a = new int[n + 1];
			a[0] = 1;
			for (int i = 1; i < n; i++)
				a[i] = 0;
			a[n] = 1;
			return a;
		}
		solve(num);
		return num;
	}

	public static boolean all9(int[] num)
	{
		int n = num.length;
		for (int i = 0; i < n; ++i)
			if (num[i] != 9)
				return false;
		return true;
	}

	public static boolean isP(long x)
	{
		char[] s = (x + "").toCharArray();
		for (int i = 0, j = s.length - 1; i < j; i++, j--)
			if (s[i] != s[j])
				return false;
		return true;
	}

	public static int[] toInt(long x)
	{
		char[] c = (x + "").toCharArray();
		int[] n = new int[c.length];
		for (int i = 0; i < n.length; i++)
			n[i] = c[i] - '0';
		return n;
	}

	public static long toLong(int[] n)
	{
		long r = 0l;
		long p = 1l;
		for (int i = n.length - 1; i >= 0; i--, p *= 10)
			r += n[i] * p;
		return r;
	}

	public static void main(String[] args) throws FileNotFoundException
	{

		Scanner in = new Scanner(new File("D:\\D\\C-large-1.in"));
		PrintWriter out = new PrintWriter(new File("D:\\D\\output.txt"));
		int t = in.nextInt();
		for (int tc = 1; tc <= t; tc++)
		{
			long A = in.nextLong(), B = in.nextLong();
			long a = (long) Math.sqrt(A), b = (long) Math.sqrt(B);
			// int res = 0;
			// for (long i = a; i <= b; i++)
			// if (isP(i) && i * i >= A && i * i <= B && isP(i * i))
			// res++;
			long ans = isP(a) && isP(a * a) && a * a >= A && a * a <= B ? 1l
					: 0l;
			while (a <= b)
			{
				a = toLong(nextP(toInt(a)));
				if (a * a <= B && a * a >= A && isP(a * a))
					ans++;
			}
			System.out.println(tc);
			out.printf("Case #%d: %d", tc, ans);
			out.println();
		}
		out.close();

	}
}
