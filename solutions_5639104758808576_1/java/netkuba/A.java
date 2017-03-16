import java.util.Scanner;

public class A {
	
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		int testsNumber = scanner.nextInt();
		for (int test = 1; test <= testsNumber; ++test) {
			int maxLevel = scanner.nextInt();
			String shyness = scanner.next();
			System.out.println(String.format("Case #%s: %s",
					test, new A().solve(maxLevel, shyness)));
		}
		scanner.close();
	}

	private int solve(int maxLevel, String shyness) {
		int result = 0;
		int prefixSum = 0;
		for (int level = 0; level <= maxLevel; ++level) { 
			result = Math.max(result, level - prefixSum);
			prefixSum += Character.getNumericValue(shyness.charAt(level));;
		}
		return result;
	}
}
