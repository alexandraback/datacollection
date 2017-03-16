import java.util.*;

public class D
{
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		int test = 1, cases = Integer.parseInt(sc.nextLine());
		int blocks;
		ArrayList<Double> n = new ArrayList<Double>();
		ArrayList<Double> k = new ArrayList<Double>();

		int i;

		while(test <= cases)
		{
			n.clear();
			k.clear();

			blocks = sc.nextInt();

			for(i = 0; i < blocks; i++)
			{
				n.add(sc.nextDouble());
			}

			for(i = 0; i < blocks; i++)
			{
				k.add(sc.nextDouble());
			}

			Collections.sort(n);
			Collections.sort(k);

			System.out.println("Case #" + test + ": " + dwar(n, k) + " " + war(n, k));

			test++;
		}
	}

	public static int war(ArrayList<Double> n, ArrayList<Double> ken)
	{
		int ni = 0;
		int ki;
		ArrayList<Double> k = new ArrayList<Double>();
		int score = 0;

		k.addAll(ken);

		for(ni = 0; ni < n.size(); ni++)
		{
			ki = search(k, n.get(ni), 0, k.size() - 1);
			if(ki >= 0)
				k.remove((int) ki);
			else score++;
		}

		return score;
	}

	public static int search(ArrayList<Double> a, double val, int start, int end)
	{
		if(start > end)
			return -1;
		else if(start == end)
		{
			if(a.get(start) > val)
				return start;
			else return -1;
		}
		else
		{
			int mid = (start + end) / 2;

			if(a.get(mid) <= val)
				return search(a, val, mid + 1, end);
			else return search(a, val, start, mid);
		}
	}

	public static int dwar(ArrayList<Double> n, ArrayList<Double> k)
	{
		int nstart = 0;
		int kend = k.size() - 1;
		int matched = 0;

		while(matched <= kend && n.get(nstart + matched) > k.get(matched))
		{
			matched++;
		}

		while(matched <= kend)
		{
			// Sacrifice a block
			nstart++;
			kend--;

			while(matched <= kend && n.get(nstart + matched) > k.get(matched))
			{
				matched++;
			}
		}

		return matched;
	}
}