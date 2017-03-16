import java.util.*;

public class B {
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		int total = s.nextInt();
		int current = 1;
		while (current <= total) {
			int a = s.nextInt();
			int b = s.nextInt();
			int k = s.nextInt();
			int count = 0;
			for (int i = 0; i < a; i++) {
				for (int j = 0; j < b; j++) {
					//System.out.printf("%d %d %d\n", a, b, a&b);
					if ((i&j) < k) count++;
				}
			}
			System.out.println("Case #" + (current++) +": "+count);
		}
	}
}
