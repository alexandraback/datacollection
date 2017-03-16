import java.util.HashSet;
import java.util.Set;


public class TestCase {

	private int totalDigit = -1;
	private int max;
	private int min;
	public TestCase(String s) {
		String[] results = s.split(" ");
		totalDigit = results[0].length();
		min = Integer.parseInt(results[0]);
		max = Integer.parseInt(results[1]);
	}
	
	public int solve() {
		Set<Pair> total = new HashSet<Pair>();
		for (int i = min; i <= max; i++) {
			for (int j = 1; j < totalDigit; j++) {
				Pair p = getPair(i, j);
				if (p != null) {
					//System.out.printf("Adding pair(%d, %d), %b\n", p.getFirst(), p.getSecond(), total.add(p));
					total.add(p);
				}
			}
		}
		return total.size();
		
	}

	private Pair getPair(int number, int digit) {
		String source = String.valueOf(number);
		String target;
		Pair result = null;
		String first;
		String second;
//		if (digit == 1) {
//			first = source.substring(totalDigit - digit);
//			second = source.substring(0, digit);
////			target = source.substring(0, totalDigit) + source.substring(totalDigit - digit);
//		} else if (digit == 2) {
			first = source.substring(totalDigit - digit);
			second = source.substring(0, totalDigit - digit);
//		}
		target =  first + second;
		int targetNumber = Integer.parseInt(target);
		if (targetNumber >= min && targetNumber <= max & targetNumber != number) {
			result = new Pair(number, targetNumber);
		}
		return result;
	}
}
