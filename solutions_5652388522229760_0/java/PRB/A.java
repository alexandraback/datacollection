import java.util.HashSet;
import java.util.Scanner;

public class A {
	private String getName(int name) {
		HashSet<Integer> digits = new HashSet<>();
		int result = 0;
		int count = 1;
		while (digits.size() < 10) {
			int nextResult = count * name;
			if (result == nextResult) {
				return "INSOMNIA";
			}
			result = nextResult;
			while (nextResult > 0) {
				int cur = nextResult % 10;
				digits.add(cur);
				nextResult = nextResult / 10;
			}
			count++;
		}

		return "" + result;
	}

	public static void main(String[] args) {
		Scanner in = null;
		A a = new A();
		try {
			in = new Scanner(System.in);
			int count = in.nextInt();
			for (int test = 1; test <= count; test++) {
				int name = in.nextInt();
				String result = a.getName(name);
				System.out.println("Case #" + test + ": " + result);
			}
			in.close();
		} catch (Exception e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
}
