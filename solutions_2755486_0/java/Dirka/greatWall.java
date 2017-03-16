import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.Hashtable;
import java.util.LinkedList;

public class greatWall {
	static String filename = "C-small-attempt1.in";

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		BufferedReader br = null;
		try {
			br = new BufferedReader(new FileReader(filename));
			String line = br.readLine();
			int T = Integer.parseInt(line);
			for (int i = 1; i <= T; i++) {
				Hashtable<Integer, Integer> wall = new Hashtable<Integer, Integer>();
				LinkedList<tribe> tribes = new LinkedList<tribe>();

				line = br.readLine();
				int N = Integer.parseInt(line);
				for (int j = 0; j < N; j++) {
					line = br.readLine();
					String temp[] = line.split("\\s");
					int day = Integer.parseInt(temp[0]);
					int num = Integer.parseInt(temp[1]);
					int w = Integer.parseInt(temp[2]);
					int e = Integer.parseInt(temp[3]);
					int str = Integer.parseInt(temp[4]);
					int delD = Integer.parseInt(temp[5]);
					int delP = Integer.parseInt(temp[6]);
					int delS = Integer.parseInt(temp[7]);

					int[] days = new int[num];
					for (int l = 0; l < num; l++)
						days[l] = day + l * delD;

					tribes.add(new tribe(days, w, e, str, delP, delS));

				}
				int dayCounter = 0, attackCounter = 0;
				while (dayCounter <= 676060) {
					
					for (tribe trb : tribes) {
						if (trb.index < trb.days.length
								&& trb.days[trb.index] == dayCounter) { // attack
																		// happens
							boolean success = false;
							for (int j = trb.w; j < trb.e; j++) {
								if (wall.get(j) == null) {
									success = true;
									break;
								} else {
									if (wall.get(j) < trb.str) {										
										success = true;
										break;
									}
								}
							}
							if (success) {
								attackCounter++;	
							}						
						}
					}
					for (tribe trb : tribes) {
						if (trb.index < trb.days.length
								&& trb.days[trb.index] == dayCounter) { // attack
																		// happens
							boolean success = false;
							for (int j = trb.w; j < trb.e; j++) {
								if (wall.get(j) == null) {
									wall.put(j, trb.str);
								} else {
									if (wall.get(j) < trb.str) {
										wall.put(j, trb.str);
									}
								}
							}
							trb.w += trb.delP;
							trb.e += trb.delP;
							trb.str += trb.delS;
							trb.index++;
						}
					}
					dayCounter++;
				}

				System.out.println("Case #" + i + ": " + attackCounter);
			}

			br.close();
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

}

class tribe {
	int[] days;
	int w;
	int e;
	int str;
	int delP;
	int delS;

	int index;

	public tribe(int[] days, int w, int e, int str, int dp, int ds) {
		this.days = days;
		index = 0;

		this.w = w;
		this.e = e;
		this.str = str;
		this.delP = dp;
		this.delS = ds;
	}
}
