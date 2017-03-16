import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.HashSet;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.ListIterator;
import java.util.Scanner;

public class RecycledNumbers {

	/**
	 * @param args
	 * @throws FileNotFoundException
	 */
	public static void main(String[] args) throws FileNotFoundException {
		// TODO Auto-generated method stub
		//System.setOut(new PrintStream(new File("RecycledNumbers.txt")));
	
		Scanner scanner = new Scanner(System.in);
		int testcasenum = Integer.valueOf(scanner.next());
		scanner.nextLine();
		for (int testcase = 0; testcase < testcasenum; testcase++) {
			System.out.print("Case #");
			System.out.print(testcase+1);
			System.out.print(": ");
			int from = scanner.nextInt();
			int to = scanner.nextInt();
			int count = 0;
			boolean table[] = new boolean[to+1];
			for (int num = from; num <= to; num++) {
				if (!table[num]){
					int len = String.valueOf(num).length();
			
					int shift = num;
					table[num] = true;
					int pair = 1;
					for (int i = 0;i < len-1;i++){
						shift = shiftLeft(shift, len);
						if (shift >= from && shift <= to&& !table[shift]){
							pair++;
							table[shift] = true;
							
						}
					}
					count += pair*(pair-1)/2;
				}
			}
			System.out.println(count);

		}
	}


	public static int shiftLeft(int num, int len) {
		int digit = num % 10;
		num = num / 10;
		return num += Math.pow(10, len-1)*digit;	
	}
	
	
	public static int getUniqueDigits(int num){
		boolean digits[] = new boolean[10];
		while (num != 0) {
			int digit = (num % 10);
			digits[digit] = true;
			num = num / 10;
		}
		int count = 0;
		for (int i = 0;i < 10;i++){
			count += digits[i]?1:0;
		}
		return count;
	}
	

}
