import java.util.HashSet;

public class CSolver extends SolverModule {

	@Override
	String processLine(String line) {
		int[] lines = toIntegers(line.split(" "));
		int A = lines[0];
		int B = lines[1];
		HashSet<String> hashSet = new HashSet<String>();
		for (int i = A; i < B; i++) {
			int length = String.valueOf(A).length();
			for (int j = 1; j < length; j++) {
				int a = rightMove(i, length - j);
				int b = leftMove(i, j)
						- leftMove(rightMove(i, (length - j)), length);
				int total = a + b;
				if (total >= A && total <= B && total > i) {
					hashSet.add(i + "," + total);
				}
			}
		}
		return String.valueOf(hashSet.size());
	}

	private int leftMove(int number, int count) {
		number = number * (int) (Math.pow(10, count));
		return number;
	}

	private int rightMove(int number, int count) {
		if (count == 0) {
			return number;
		}
		number = (number / (int) (Math.pow(10, count)));
		return number;
	}
}
