package codejam.recyclednumbers;

public class RecycledNumbersProblem {

	private int minValue;
	private int maxValue;

	public RecycledNumbersProblem(String problemAsString) {
		String[] split = problemAsString.split(" ");
		minValue = Integer.parseInt(split[0]);
		maxValue = Integer.parseInt(split[1]);
	}

	public int solve() {
		int result = 0;
		DigitsArray minValueDigitsArray = new DigitsArray(minValue);
		DigitsArray maxValueDigitsArray = new DigitsArray(maxValue);
		for (int i = 0; i <= maxValue - minValue; i++) {
			DigitsArray toTest = new DigitsArray(minValue + i);
			result += toTest.numberRecycles(minValueDigitsArray,
					maxValueDigitsArray);
		}
		return result;
	}

}
