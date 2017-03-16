import java.util.*;

public class DeceitfulWar {
	@SuppressWarnings("unchecked")
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		in.useLocale(Locale.ENGLISH);
		int T = in.nextInt(), i = 0, N, j, resultNormalWar, resultDeceitfulWar;
		LinkedList<Double> blocksNaomi = new LinkedList<Double>(), blocksKen = new LinkedList<Double>();
		LinkedList<Double> modifNaomi, modifKen;
		ListIterator<Double> iter;
		while (i++ < T)
		{
			System.out.print("Case #" + i + ": ");
			blocksNaomi.clear();
			blocksKen.clear();
			N = in.nextInt();
			for (j = 0; j < N; ++j)
				blocksNaomi.add(in.nextDouble());
			for (j = 0; j < N; ++j)
				blocksKen.add(in.nextDouble());
			Collections.sort(blocksNaomi);
			Collections.sort(blocksKen);
			/* Normal game */
			modifNaomi = (LinkedList<Double>) blocksNaomi.clone();
			modifKen = (LinkedList<Double>) blocksKen.clone();
			resultNormalWar = 0;
			while ((!modifNaomi.isEmpty()) && (modifKen.getLast() > modifNaomi.getFirst()))
			{
				while ((!modifNaomi.isEmpty()) && (modifKen.getLast() < modifNaomi.getLast()))
					modifNaomi.removeLast();
				if (!modifNaomi.isEmpty())
				{
					modifKen.removeLast();
					modifNaomi.removeLast();
					++resultNormalWar;
				}
			}
			resultNormalWar = N - resultNormalWar;
			/* Deceitful War */
			resultDeceitfulWar = 0;
			while (!blocksNaomi.isEmpty())
			{
				while ((!blocksNaomi.isEmpty()) && ((blocksNaomi.getFirst() < blocksKen.getFirst()) ||
						(blocksNaomi.getLast() < blocksKen.getLast())))
				{
					blocksNaomi.removeFirst();
					blocksKen.removeLast();
				}
				if (!blocksNaomi.isEmpty())
				{
					blocksNaomi.removeFirst();
					blocksKen.removeFirst();
					++resultDeceitfulWar;
				}
			}
			/* Result : */
			System.out.println("" + resultDeceitfulWar + " " + resultNormalWar);
		}
		in.close();
	}
}
