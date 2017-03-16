import java.io.BufferedReader;
import java.io.FileReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Iterator;

public class DeceitfulWar
{
	public static void main(String args[])
	{
		try
		{
			BufferedReader br = new BufferedReader(new FileReader(args[0]));
			int anzTC = Integer.parseInt(br.readLine());
			for (int tc = 0; tc < anzTC; tc++)
			{
				int nr = Integer.parseInt(br.readLine());
				String[] naomi = br.readLine().split(" ");
				String[] ken = br.readLine().split(" ");
				ArrayList<Double> dNaomi = new ArrayList<Double>();
				ArrayList<Double> dKen = new ArrayList<Double>();
				for (int i = 0; i < nr; i++)
				{
					dNaomi.add(Double.parseDouble(naomi[i]));
					dKen.add(Double.parseDouble(ken[i]));
				}
				solve(tc + 1, dNaomi, dKen);
			}
			br.close();
		}
		catch (Exception ex)
		{
			ex.printStackTrace();
		}
	}

	private static void solve(int tc, ArrayList<Double> naomi, ArrayList<Double> ken)
	{
		Collections.sort(naomi);
		Collections.sort(ken);
		int pointsWar = pointsWar(naomi, ken);
		int pointsDecWar = pointsDecWar(naomi, ken);
		System.out.println("Case #" + tc + ": " + pointsDecWar + " " + pointsWar);
	}

	private static int pointsWar(ArrayList<Double> naomi, ArrayList<Double> ken)
	{
		ArrayList<Double> inNaomi = new ArrayList<>(naomi);
		ArrayList<Double> inKen = new ArrayList<>(ken);
		int pointsNaomi = 0;
		Iterator<Double> itNaomi = inNaomi.iterator();
		while (itNaomi.hasNext())
		{
			double wN = itNaomi.next();
			itNaomi.remove();
			int chosenKen = -1;
			for (int iKen = 0; iKen < inKen.size(); iKen++)
			{
				if (wN < inKen.get(iKen))
				{
					chosenKen = iKen;
					iKen = inKen.size();
				}
			}
			if (chosenKen == -1)
			{
				inKen.remove(0);
				pointsNaomi++;
			}
			else
			{
				inKen.remove(chosenKen);
			}
		}
		return pointsNaomi;
	}

	private static int pointsDecWar(ArrayList<Double> naomi, ArrayList<Double> ken)
	{
		ArrayList<Double> inNaomi = new ArrayList<>(naomi);
		ArrayList<Double> inKen = new ArrayList<>(ken);
		int pointsNaomi = 0;
		
		while (!inNaomi.isEmpty())
		{
			double wN = inNaomi.remove(0);
			if (wN > inKen.get(0))
			{
				wN = inKen.get(inKen.size() - 1) + 0.000001;
			}
			else{
				wN = inKen.get(inKen.size() - 1) - 0.000001;
			}
			int chosenKen = -1;
			for (int iKen = 0; iKen < inKen.size(); iKen++)
			{
				if (wN < inKen.get(iKen))
				{
					chosenKen = iKen;
					iKen = inKen.size();
				}
			}
			if (chosenKen == -1)
			{
				inKen.remove(0);
				pointsNaomi++;
			}
			else
			{
				inKen.remove(chosenKen);
			}
		}
		return pointsNaomi;
	}
}
