import java.util.*;

public class S1 {

	static long solve(long i) {
		HashSet<String> set = new HashSet<>();
		set.addAll(Arrays.asList(Long.toString(i).split("")));
		long myNum = i;
		while (set.size() < 10) {
			myNum += i;
			set.addAll(Arrays.asList(Long.toString(myNum).split("")));
		}
		return myNum;
	}

	public static void main(String[] args) {

		try (Scanner sc = new Scanner(System.in)) {
			int t = sc.nextInt();
			for (int i = 1; i <= t; i++) {
				System.out.print("Case #");
				System.out.print(i);
				System.out.print(": ");
				int n = sc.nextInt();
				if (n == 0) {
					System.out.println("INSOMNIA");
				} else {
					System.out.println(solve(n));
				}
			}
		}
	}

}
