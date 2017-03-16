import java.util.Scanner;
import java.util.TreeSet;

public class C {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		long t = sc.nextInt();
		TreeSet<Character> set = new TreeSet<Character>();
		set.add('a');
		set.add('e');
		set.add('i');
		set.add('o');
		set.add('u');
		for (long i = 1; i <= t; i++) {
			String s = sc.next();
			long l = sc.nextInt();
			sc.nextLine();
			long[] arr = new long[s.length()];
			long[] arr2 = new long[s.length()];
			if (set.contains(s.charAt(0))) {
				arr2[0] = 0;
			} else {
				arr2[0] = 1;
			}
			for (int j = 1; j < s.length(); j++) {
				if (set.contains(s.charAt(j))) {
					arr2[j] = 0;
				} else {
					arr2[j] = arr2[j - 1] + 1;
				}
			}
			if (set.contains(s.charAt(0))) {
				arr[0] = 0;
				// System.out.println("V:" +arr[0]);
			} else {
				arr[0] = Math.max(0, 0 - l + 2);
				// System.out.println("C:" +arr[0]);
			}
			long sum = arr[0];
			for (int j = 1; j < s.length(); j++) {
				if ((arr2[j - 1] >= l - 1) && (!set.contains(s.charAt(j)))) {
					arr[j] = (long) Math.max(0, j - l + 2);
					// System.out.println("C:" +arr[j]);
				} else {
					arr[j] += arr[j - 1];
					// System.out.println("V:" +arr[j]);
				}
				sum += arr[j];
			}
			System.out.println("Case #" + i + ": " + sum);
		}
	}

}
