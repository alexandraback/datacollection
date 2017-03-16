import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.PriorityQueue;

public class ProbDeceitWar
{
	public static void main(final String[] args) throws IOException
	{
		BufferedReader reader = new BufferedReader(new FileReader(new File(
				"data42.txt")));
		PrintWriter writer = new PrintWriter(new FileWriter(new File(
				"out42.txt")));
		int noCases = Integer.parseInt(reader.readLine());
		for (int testCase = 1; testCase <= noCases; testCase++) {
			int n = Integer.parseInt(reader.readLine());
			ArrayList<Double> naomi = new ArrayList<Double>();
			ArrayList<Double> ken = new ArrayList<Double>();
			String[] nLine = reader.readLine().split(" ");
			for (int b = 0; b < n; b++)
				naomi.add(Double.parseDouble(nLine[b]));
			String[] kLine = reader.readLine().split(" ");
			for (int b = 0; b < n; b++)
				ken.add(Double.parseDouble(kLine[b]));
			Collections.sort(naomi);
			Collections.sort(ken);
			int score1 = dwar(new ArrayList<Double>(naomi),
					new ArrayList<Double>(ken));
			int score2 = war(new ArrayList<Double>(naomi),
					new ArrayList<Double>(ken));
			writer.printf("Case #%d: %d %d%n", testCase, score1, score2);
		}
		writer.close();
		reader.close();
	}

	private static int war(ArrayList<Double> naomi, ArrayList<Double> ken)
	{
		int score = 0;
		while (!naomi.isEmpty()) {
			double np = naomi.remove(0);
			int index = Collections.binarySearch(ken, np);
			if (index < 0)
				index = -index - 1;
			if (index == ken.size())
				index = 0;
			double kp = ken.remove(index);
			if (np > kp)
				score++;
		}
		return score;
	}

	private static int dwar(ArrayList<Double> naomi, ArrayList<Double> ken)
	{
		int score = 0;
		while (!naomi.isEmpty()) {
			double np = naomi.remove(0);
			double kp = ken.remove(np > ken.get(0) ? 0 : ken.size()-1);
			if (np > kp)
				score++;
		}
		return score;
	}
}
