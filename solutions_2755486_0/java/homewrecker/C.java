import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.Map;
import java.util.TreeMap;

public class C {

	static class Tribe {
		int startDate;
		int strength;
		int noAttacks;
		int startWest, startEast;
		int deltaStrength;
		int deltaPosition;
		int deltaDays;
	}

	public static void main(String[] args) throws Exception {

		BufferedReader reader = new BufferedReader(new FileReader("/Users/jon/Downloads/C-small-attempt1.in.txt"));

		BufferedWriter writer = new BufferedWriter(new FileWriter("/Users/jon/Documents/workspace/Codejam/out"));

		String line = reader.readLine();

		int T = Integer.parseInt(line);

		for (int i = 1; i <= T; i++) {
			writer.write("Case #" + i + ": ");

			line = reader.readLine();

			int N = Integer.parseInt(line);
			Tribe[] tribes = new Tribe[N];

			int endDate = 0;
			for (int j = 1; j <= N; j++) {

				line = reader.readLine();
				String[] flds = line.split(" ");
				tribes[j - 1] = new Tribe();

				tribes[j - 1].startDate = Integer.parseInt(flds[0]);
				tribes[j - 1].noAttacks = Integer.parseInt(flds[1]);
				tribes[j - 1].startWest = Integer.parseInt(flds[2]);
				tribes[j - 1].startEast = Integer.parseInt(flds[3]);
				tribes[j - 1].strength = Integer.parseInt(flds[4]);
				tribes[j - 1].deltaDays = Integer.parseInt(flds[5]);
				tribes[j - 1].deltaStrength = Integer.parseInt(flds[7]);
				tribes[j - 1].deltaPosition = Integer.parseInt(flds[6]);

				endDate = Math.max(endDate, tribes[j - 1].startDate + tribes[j - 1].noAttacks * tribes[j - 1].deltaDays);
			}

			int count = 0;
			Map<Integer, Integer> wall = new TreeMap<Integer, Integer>();
			Map<Integer, Integer> building = new TreeMap<Integer, Integer>();
			for (int j = 0; j < endDate + 1; j++) {
				for (Tribe t : tribes) {
					if (t.startDate > j)
						continue;
					if ((j - t.startDate) % t.deltaDays != 0)
						continue;
					if ((j - t.startDate) / t.deltaDays >= t.noAttacks)
						continue;
					int x = (j - t.startDate) / t.deltaDays;
					// atk
					int west = t.startWest + x * t.deltaPosition;
					int east = t.startEast + x * t.deltaPosition;
					int str = t.strength + x * t.deltaStrength;

					boolean succ = false;
					for (int p = west; p < east; p++) {
						Integer wStr = wall.get(p);
						if (wStr == null || wStr < str) {
							succ = true;
							Integer bStr = building.get(p);
							if (bStr == null || bStr < str)
								building.put(p, str);
						}
					}
					if (succ)
						count++;
				}
				wall.putAll(building);
				building.clear();
			}

			System.out.println("done " + i);

			writer.write(count + "\n");
		}

		writer.close();

	}

}
