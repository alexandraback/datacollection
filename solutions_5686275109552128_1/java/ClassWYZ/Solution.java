import java.util.Scanner;


public class Solution {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int num = in.nextInt();
		in.nextLine();
		for (int i = 0; i < num; ++i) {
			int people = in.nextInt();
			in.nextLine();
			int[] a= new int[people];
			for (int j = 0; j < people; ++j) a[j] = in.nextInt();
			in.nextLine();
			int res = 0;
			for (int j = 0; j < people; ++j) res = Math.max(res, a[j]);
			int count = 2;
			while (count < res) {
				int sum = 0;
				for (int j = 0; j < people; ++j) sum += (a[j] - 1) / count;
				sum += count;
				res = Math.min(res, sum);
				count++;
			}
			System.out.println("Case #" + (i + 1) + ": " + res);
		}
		in.close();
	}
}
