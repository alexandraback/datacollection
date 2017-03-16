import java.util.*;
class Password {
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		int numCases = sc.nextInt();
		for (int i = 0; i < numCases; i++) {
			int numTyped = sc.nextInt();
			int length = sc.nextInt();
			//double [] chance = new double [numTyped];
			double current = 1;
			double combined = length + 2;
			for (int k = 0; k < numTyped; k++) {
				double x = sc.nextDouble();
				current *= x;
				//System.out.println("Chance: " + k + " " + current);
				//chance[k] = current;
				double temp =  (current * (length - k)) + ((1 - current) * (length * 2 - k + 1)) + (numTyped - k - 1);
				if (temp < combined)
					combined = temp;
				//System.out.println("combined: " + combined);
			}
			String str = "Case #" + (i+1) + ": ";
			System.out.print(str);
			System.out.printf("%.6f", combined);
			System.out.println();
		}
	}
}