import java.util.*;
public class c {
public static void main(String[] args)
{
	Scanner input = new Scanner(System.in);
	int T = input.nextInt();
	for(int t = 0; t<T; t++)
	{
		int n = input.nextInt();
		long reps = input.nextLong();
		String data = input.next();
		if(reps > 20) reps = reps%4 + 16;
		char[] ch = new char[n*(int)reps];
		for(int i = 0; i<ch.length; i++)
		{
			ch[i] = data.charAt(i%n);
		}
		Quat at = new Quat('l', false);
		n = ch.length;
		int[] pref = new int[n];
		int[] suff = new int[n];
		for(int i = 0; i<n; i++)
		{
			at = at.mult(new Quat(ch[i], false));
			pref[i] = at.code();
		}
		at = new Quat('l', false);
		for(int i = n-1; i>=0; i--)
		{
			at =(new Quat(ch[i], false)).mult(at);
			suff[i] = at.code();
		}
		int[][] last = new int[8][8];
		for(int i = 0; i<n-1; i++) last[pref[i]][suff[i+1]] = i;
		boolean good = false;
		Quat a = new Quat('i', false);
		Quat b = new Quat('k', false);
		for(int i = 0; i<n; i++)
		{
			if(pref[i] == a.code())
			{
				if(last[b.code()][b.code()] > i)
				{
					good = true;
					break;
				}
			}
		}
		System.out.println("Case #" + (t+1)+": " + (good ? "YES": "NO"));
	}
}
static class Quat
{
	char c;
	boolean neg;
	public Quat(char cc, boolean nn)
	{
		c = cc; neg = nn;
	}
	Quat mult(Quat q)
	{
		boolean n = neg ^ q.neg;
		if(c == 'l') return new Quat(q.c, n);
		if(q.c == 'l') return new Quat(c, n);
		if(c == q.c) return c == 'l' ? new Quat(c, n) : new Quat('l', !n);  
		if(c == 'i')
		{
			if(q.c == 'j') return new Quat('k', n);
			return new Quat('j', !n);
		}
		if(c == 'j')
		{
			if(q.c == 'i') return new Quat('k', !n);
			return new Quat('i', n);
		}
		if(q.c == 'i') return new Quat('j', n);
		return new Quat('i', !n);
	}
	int code()
	{
		return neg ? c - 'i' + 4 : c - 'i';
	}
}
}
