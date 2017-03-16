package codejam2012.round1a;

import java.util.ArrayList;
import java.util.List;

import reusable.CodeJamBase;

public class B_KingdomRush {

	public static void main(String[] args) {
		new CodeJamBase("B-large") {

			@Override
			protected String solution() {
				int levels = nextInt();

				List<int[]> levelRequirements = new ArrayList<>();
				for (int i = 0; i < levels; i++) {
					levelRequirements.add(nextIntArray());
				}

				int stars = 0;
				int result = 0;

				while (true) {
					int lowestI = -1;
					for (int i = 0; i < levelRequirements.size(); i++) {
						if (levelRequirements.get(i)[1] <= stars) {
							lowestI = i;
							break;
						}
					}

					if (lowestI >= 0) {
						stars += ((levelRequirements.get(lowestI)[0] == Integer.MAX_VALUE) ? 1 : 2);
						result++;
						levelRequirements.remove(lowestI);
						continue;
					}

					int lowestJ = -1;
					for (int i = 0; i < levelRequirements.size(); i++) {
						if ((levelRequirements.get(i)[0] <= stars) && (levelRequirements.get(i)[1] > lowestJ)) {
							lowestI = i;
							lowestJ = levelRequirements.get(i)[1];
						}
					}

					if (lowestI >= 0) {
						stars++;
						result++;
						levelRequirements.get(lowestI)[0] = Integer.MAX_VALUE;
					} else {
						break;
					}
				}

				return ((levelRequirements.size() != 0) ? "Too Bad" : String.valueOf(result));
			}

		}.run();
	}
}
