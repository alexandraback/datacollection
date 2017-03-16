package codejam.numbers;

public class Numbers {

	public String solve(String line) {

		String[] flds = line.split(" ");
		int n = Integer.parseInt(flds[0]);

		int[] judge = new int[n];
		int x = 0;
		for (int i = 0; i < n; i++) {
			judge[i] = Integer.parseInt(flds[1 + i]);
			x += judge[i];
		}

		String answerString = "";
		for (int i = 0; i < n; i++) {

			double answer = 0.5;
			double move = 0.25;

			while (move > 1e-10) {
				double pi = judge[i] + answer * x;

				boolean high = false;

				double left = 1 - answer;
				for (int j = 0; j < n; j++) {
					if (j != i) {
						double yj = (pi - judge[j]) / x;
						left -= Math.max(yj, 0);
						if (left < 0) {
							high = true;
						}
					}
				}
				answer += high ? -move : move;
				move /= 2;
			}
			answerString += 100 * answer + " ";
		}

		return answerString;
	}
}
