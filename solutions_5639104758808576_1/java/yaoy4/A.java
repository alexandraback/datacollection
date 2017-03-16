import java.io.*;
import java.util.*;

public class A {

	public static void main(String[] args) throws FileNotFoundException {
		Scanner console = new Scanner(new File("A-large.in"));
		PrintStream output = new PrintStream(new File("AL.txt"));
		int caseNum = console.nextInt();
		for (int i = 1; i <= caseNum; i++) {
			int max = console.nextInt();
			String people = console.next();
			output.println("Case #" + i + ": " + friend(max, people));
		}
	}

	public static int friend(int max, String people) {
		int a[] = new int[max + 1];
		for (int i = 0; i <= max; i++) {
			a[i] = people.charAt(i)-'0';
		}
		int sum = a[0];
		int friend = 0;
		while (sum < max) {
			int sum2=friend;
			for (int i = 0; i <= sum; i++) {
				sum2 = sum2 + a[i];
			}
			if (sum2 <=sum) {
				sum2=sum+1;
				friend++;
			}
			sum=sum2;
		}
		return friend;
	}

}
