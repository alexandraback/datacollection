import java.io.*;
import java.util.*;

public class KingdomRush {
	public static void main(String[] args) {
		try {
			BufferedReader ifStream = new BufferedReader(new FileReader("in"));
			PrintWriter ofStream = new PrintWriter(new FileWriter("out"));
			int numCase = Integer.parseInt(ifStream.readLine());

			for (int i=1; i<=numCase; i++) {
				ofStream.println("Case #"+i+": "+computeAns(ifStream));
			}

			ifStream.close();
			ofStream.close();
		}
		catch (IOException e) {
			System.out.println("IOException.");
		}
	}

	private static String computeAns(BufferedReader ifStream) {
		try {
			int numLevel = Integer.parseInt(ifStream.readLine());
			Level[] level = new Level[numLevel];
			int numClear = 0;
			int numStar = 0;
			boolean earnFlag = false;
			int clearCount = 0;
			Level nextClear = null;

			for (int i=0; i<numLevel; i++) {
				StringTokenizer st = new StringTokenizer(ifStream.readLine(), " ",
														 false);
				level[i] = new Level(Integer.parseInt(st.nextToken()),
									 Integer.parseInt(st.nextToken()));
			}

			while (!(numClear == numLevel)) {
				nextClear = null;
				for (int i=0; i<numLevel; i++) {
					if ((level[i].completed2 == false) && (numStar >= level[i].star2)) {
						if (nextClear == null) {
							nextClear = level[i];
						}
						else if (level[i].star2 < nextClear.star2) {
							nextClear = level[i];
						}
					}
				}
				if (nextClear != null) {
					numClear++;
					clearCount++;
					nextClear.completed2 = true;
					if (nextClear.completed1 == true) {
						numStar = numStar + 1;
					}
					else {
						numStar = numStar + 2;
					}
					continue;
				}


				earnFlag = false;
				for (int i=0; i<numLevel; i++) {
					if ((level[i].completed1 == false) && (level[i].star1 == 0)) {
						clearCount++;
						numStar++;
						earnFlag = true;
						break;
					}
					if ((level[i].completed1 == true) && (level[i].star2 == 0)) {
						clearCount++;
						numStar++;
						earnFlag = true;
						break;
					}
				}
				if (earnFlag) {
					continue;
				}

				return "Too Bad";
			}

			return clearCount + "";
		}
		catch (IOException e) {
			System.out.println("IOException.");
		}
		return null;
	}
}

class Level {
	boolean completed1;
	boolean completed2;
	int star1;
	int star2;

	Level (int star1, int star2) {
		boolean completed1 = false;
		boolean completed2 = false;
		this.star1 = star1;
		this.star2 = star2;
	}
}
