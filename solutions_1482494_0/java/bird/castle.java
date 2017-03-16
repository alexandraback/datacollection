import java.util.*;
class Castle {
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		int numCases = sc.nextInt();
		for (int i = 0; i < numCases; i++) {
			String str = "Case #" + (i + 1) + ": ";
			int numLvl = sc.nextInt();
			int [][] stars = new int [2002][2];
			for (int k = 0; k < numLvl; k++) {
				for (int h = 0; h < 2; h++) {
					int temp = sc.nextInt();
					stars[temp][h]++;
				}
			}
			int k = 0;
			int numReached = 0;
			int maxCurrent = 0;
			// if (stars[0][1] != 0) {
				// maxCurrent += 2;
				// numReached++;
				// k++;
				// stars[0][1]--;
			// }
			// else if(stars[0][0] != 0) {
				// maxCurrent++;
				// k++;
				// stars[0][0]--;
			// }
			// else {
				// System.out.println(str + "Too Bad");
				// continue;
			// }
			boolean failed = false;
			while (numReached < numLvl && !failed) {
				boolean worked = false;
				for (int z = maxCurrent; z >= 0; z--) {
					int h = z;
					if (h > 2001)
						h = 2001;
					if (stars[h][1] != 0) {
						maxCurrent += 2;
						numReached++;
						k++;
						stars[h][1]--;
						worked = true;
						break;
					}
					else if(stars[h][0] != 0) {
						maxCurrent++;
						k++;
						stars[h][0]--;
						worked = true;
						break;
					}
					
				}
				if (!worked)
						failed = true;
			}
			if (failed)
				System.out.println(str + "Too Bad");
			else
				System.out.println(str + k);
		}
	}
}