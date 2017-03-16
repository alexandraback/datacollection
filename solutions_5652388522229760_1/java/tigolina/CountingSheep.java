import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Scanner;

public class CountingSheep {

	public static void main(String[] args) {
		Scanner in = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
		int testCount = in.nextInt();
		
		for (int test = 0; test < testCount; test++) {
			int startNumber = in.nextInt();
			
			solveCase(test, startNumber);
		}
		
		in.close();
	}
	
	public static void solveCase(int test, int startNumber) {
		if (startNumber == 0) {
			System.out.println("Case #" + (test + 1) + ": " + "INSOMNIA");	
			return;
		}
		
		int flag = 0;
		int currentNumber = 0;
		for (int i = 1; i <= 72; i++) {
			currentNumber = i * startNumber;
			while (currentNumber > 0) {
				int digit = currentNumber % 10;
				currentNumber = currentNumber / 10;
				flag = flag | 1 << digit;
			}
			if (flag == 1023) {
				currentNumber = i * startNumber;
				break;
			}
		}
		System.out.println("Case #" + (test + 1) + ": " + currentNumber);
	}
}
