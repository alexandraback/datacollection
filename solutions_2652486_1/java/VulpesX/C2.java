import java.util.*;
import java.math.*;

public class C2
{
	static String sol;
	static String cur;
	static double best;
	static int[] facts;
	static long[] pro;
	static long[][] prods;
	static int count;
	static int N, K;
	static int[] fast;
	static long curprod;

	public static void main(String args[])
	{
		Scanner scan = new Scanner(System.in);

		int T = scan.nextInt(); // lol
		System.out.println("Case #1:");

		int R = scan.nextInt();
		N = scan.nextInt();
		int M = scan.nextInt();
		K = scan.nextInt();

		while(R --> 0)
		{
			prods = new long[K][8];
			pro = new long[K];
			int min5 = 0;
			int min7 = 0;

			for(int i=0;i < K;i++)
			{
				long tmp = pro[i] = scan.nextLong();
				int n2 = 0;
				int n3 = 0;
				int n5 = 0;
				int n7 = 0;
				while(tmp % 2 == 0)
				{
					n2++;
					tmp /= 2;
				}
				while(tmp % 3 == 0)
				{
					n3++;
					tmp /= 3;
				}
				while(tmp % 5 == 0)
				{
					n5++;
					tmp /= 5;
				}
				while(tmp % 7 == 0)
				{
					n7++;
					tmp /= 7;
				}
				min5 = Math.max(n5, min5);
				min7 = Math.max(n7, min7);

				prods[i][2] = n2;
				prods[i][3] = n3;
				prods[i][5] = n5;
				prods[i][7] = n7;
			}
			
			int need = N - min5 - min7;
			
			
			if(need > 11) //Too hard; give up
			{
				String rtn = "";
				for(int i=0;i < N;i++)
					rtn += "2";
				System.out.println(rtn);
				continue;
			}
			

			facts = new int[8];
			facts[5] = min5;
			facts[7] = min7;
			count = 0;
			best = 0;
			
			cur = "";
			for(int i=0;i < min7;i++)
				cur += "7";
			for(int i=0;i < min5;i++)
				cur += "5";
	
			f(need, M);

			//System.out.println(R + " " + sol + " " + count);
			System.out.println(sol);
		}
		
	}

	public static void f(int k, int M)
	{
		if(count > 140)
			return;

		if(k == 0)
		{
			boolean good = true;

			for(int i=0;i < prods.length;i++)
			{
				for(int j=0;j < 8;j++)
					if(facts[j] < prods[i][j])
						good = false;
			}

			if(good)
			{
				//NEVER TELL ME THE ODDS
				count++;
				double p = 1;

				fast = new int[N];
				for(int i=0;i < N;i++)
					fast[i] = cur.charAt(i) - '0';

				for(int j=0;j < K;j++)
				{
					curprod = 1;
					double subp = count(0, j);
					p *= subp;
				}

				if(p > best)
				{
					//System.out.println("\t" + count + " PROBABILITY " + p);
					sol = cur;
					best = p;
				}
			}

			return;
		}

		//Use something smaller than M
		if(M > 2) f(k, M-1);

		//Use an M
		int tmp = M;
		for(int i=2;i <= 7;i++)
		{
			while(tmp % i == 0)
			{
				facts[i]++;
				tmp /= i;
			}
		}
		String hold = cur;
		cur += M;

		f(k-1, M);

		cur = hold;
		tmp = M;
		for(int i=2;i <= 7;i++)
		{
			while(tmp % i == 0)
			{
				facts[i]--;
				tmp /= i;
			}
		}

	}


	public static double count(int k, int idx)
	{
		if(k == N) return curprod == pro[idx] ? 1 : 0;

		//Don't use current digit
		double rtn = count(k+1, idx);

		//Use current digit if possible
		boolean good = false;

		switch(fast[k])
		{
			case 2:
				if(prods[idx][2] > 0)
				{
					prods[idx][2]--;
					good = true;
				}
				break;
			case 3:
				if(prods[idx][3] > 0)
				{
					prods[idx][3]--;
					good = true;
				}
				break;
			case 4:
				if(prods[idx][2] > 1)
				{
					prods[idx][2] -= 2;
					good = true;
				}
				break;
			case 5:
				if(prods[idx][5] > 0)
				{
					prods[idx][5]--;
					good = true;
				}
				break;
			case 6:
				if(prods[idx][2] > 0 && prods[idx][3] > 0)
				{
					prods[idx][2]--;
					prods[idx][3]--;
					good = true;
				}
				break;
			case 7:
				if(prods[idx][7] > 0)
				{
					prods[idx][7]--;
					good = true;
				}
				break;
			case 8:
				if(prods[idx][2] > 2)
				{
					prods[idx][2] -= 3;
					good = true;
				}
				break;
		}

		if(good)
		{
			curprod *= fast[k];
			rtn += count(k+1, idx);
			curprod /= fast[k];

			switch(fast[k])
			{
				case 2:
						prods[idx][2]++;
					break;
				case 3:
						prods[idx][3]++;
					break;
				case 4:
						prods[idx][2] += 2;
					break;
				case 5:
						prods[idx][5]++;
					break;
				case 6:
						prods[idx][2]++;
						prods[idx][3]++;
					break;
				case 7:
						prods[idx][7]++;
					break;
				case 8:
						prods[idx][2] += 3;
					break;
			}
		}

		return rtn;
	}
}