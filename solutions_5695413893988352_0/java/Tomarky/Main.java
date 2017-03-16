import java.util.*;


public class Main
{
	public static void main(String[] args) throws Exception
	{
		Scanner in = new Scanner(System.in);
		
		int t = in.nextInt();
		
		List<long[]>
			cur = new ArrayList<>(),
			nxt = new ArrayList<>(),
			tmp = null;
		
		for (int i = 0; i < t; i++)
		{
			String s1 = in.next();
			String s2 = in.next();
			
			cur.clear();
			cur.add(new long[]{ 0L, 0L});
			for (int j = 0; j < s1.length(); j++)
			{
				char
					c1 = s1.charAt(j),
					c2 = s2.charAt(j);
				
				nxt.clear();
				if (c1 == '?')
				{
					if (c2 == '?')
					{
						for (long[] x : cur)
						{
							long[] y = Arrays.copyOf(x, 2);
							y[0] *= 10L; y[1] *= 10L; nxt.add(y);
							y = Arrays.copyOf(x, 2);
							y[0] *= 10L; y[1] *= 10L; y[0]++; nxt.add(y);
							y = Arrays.copyOf(x, 2);
							y[0] *= 10L; y[1] *= 10L; y[1]++; nxt.add(y);
							y = Arrays.copyOf(x, 2);
							y[0] *= 10L; y[1] *= 10L; y[0]++; y[1]++; nxt.add(y);
							y = Arrays.copyOf(x, 2);
							y[0] *= 10L; y[1] *= 10L; y[0] += 9L; nxt.add(y);
							y = Arrays.copyOf(x, 2);
							y[0] *= 10L; y[1] *= 10L; y[1] += 9L; nxt.add(y);
							y = Arrays.copyOf(x, 2);
							y[0] *= 10L; y[1] *= 10L; y[0] += 9L; y[1]++; nxt.add(y);
							y = Arrays.copyOf(x, 2);
							y[0] *= 10L; y[1] *= 10L; y[0]++; y[1] += 9L; nxt.add(y);
						}
					}
					else
					{
						for (long[] x : cur)
						{
							long p = (long)(c2 - '0');
							long[] y = Arrays.copyOf(x, 2);
							y[0] *= 10L; y[1] *= 10L; y[0] += p; y[1] += p; nxt.add(y);
							y = Arrays.copyOf(x, 2);
							y[0] *= 10L; y[1] *= 10L; y[0] += (p + 9L) % 10L; y[1] += p; nxt.add(y);
							y = Arrays.copyOf(x, 2);
							y[0] *= 10L; y[1] *= 10L; y[0] += (p + 1L) % 10L; y[1] += p; nxt.add(y);
							if (p != 9L)
							{
								y = Arrays.copyOf(x, 2);
								y[0] *= 10L; y[1] *= 10L; y[0] += 9L; y[1] += p; nxt.add(y);
							}
							if (p != 1L)
							{
								y = Arrays.copyOf(x, 2);
								y[0] *= 10L; y[1] *= 10L; y[0] += 1L; y[1] += p; nxt.add(y);
							}
							if (p != 0L)
							{
								y = Arrays.copyOf(x, 2);
								y[0] *= 10L; y[1] *= 10L; y[1] += p; nxt.add(y);
							}
						}
					}
				}
				else
				{
					if (c2 == '?')
					{
						for (long[] x : cur)
						{
							long p = (long)(c1 - '0');
							long[] y = Arrays.copyOf(x, 2);
							y[0] *= 10L; y[1] *= 10L; y[0] += p; y[1] += p; nxt.add(y);
							y = Arrays.copyOf(x, 2);
							y[0] *= 10L; y[1] *= 10L; y[0] += p; y[1] += (p + 9L) % 10L; nxt.add(y);
							y = Arrays.copyOf(x, 2);
							y[0] *= 10L; y[1] *= 10L; y[0] += p; y[1] += (p + 1L) % 10L; nxt.add(y);
							if (p != 9L)
							{
								y = Arrays.copyOf(x, 2);
								y[0] *= 10L; y[1] *= 10L; y[0] += p; y[1] += 9L; nxt.add(y);
							}
							if (p != 1L)
							{
								y = Arrays.copyOf(x, 2);
								y[0] *= 10L; y[1] *= 10L; y[0] += p; y[1] += 1L; nxt.add(y);
							}
							if (p != 0L)
							{
								y = Arrays.copyOf(x, 2);
								y[0] *= 10L; y[1] *= 10L; y[0] += p; nxt.add(y);
							}
						}
					}
					else
					{
						for (long[] x : cur)
						{
							x[0] *= 10L; x[0] += (long)(c1 - '0');
							x[1] *= 10L; x[1] += (long)(c2 - '0');
						}
						tmp = cur;
						cur = nxt;
						nxt = tmp;
						tmp = null;
					}
				}
				
				nxt.sort( (a, b) -> {
					int cmp = Long.compare(Math.abs(a[0] - a[1]), Math.abs(b[0] - b[1]));
					if (cmp != 0) return cmp;
					cmp = Long.compare(a[0], b[0]);
					if (cmp != 0) return cmp;
					return Long.compare(a[1], b[1]);
				}); 
				cur.clear();
				for (int k = 0; k < Math.min(10, nxt.size()); k++)
				{
					cur.add(nxt.get(k));
				}
			}
			
			long[] z = cur.get(0);
			String fmt =" %0" + String.format("%d", s1.length()) + "d";
			System.out.print("Case #" + (i + 1) + ":");
			//System.out.print(" " + s1 + " " + s2 + ":");
			System.out.print(String.format(fmt, z[0]));
			System.out.print(String.format(fmt, z[1]));
			//for (long[] x : cur)
			{
				//System.out.print(" " + Arrays.toString(x) + ",");
			}				
			System.out.printf("\n");
		}
	}
	
}