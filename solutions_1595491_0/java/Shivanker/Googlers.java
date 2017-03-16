import java.util.Scanner;

public class Googlers {

	public static void main(String[] args) {
		// 3p-4 n 3p-3 are critical..
		Scanner c = new Scanner(System.in);
		int t = c.nextInt();
		for (int i = 1; i <= t; ++i) {
			System.out.print("Case #" + i + ": ");
			int n = c.nextInt();
			int s = c.nextInt();
			int p = c.nextInt();
			int count = 0, num;
			if (p == 0) {
				int m=n;
				while(n-- >0)
					c.nextInt();
				System.out.println(m);
			} else if (p == 1) {
				while(n-- >0)
					if(c.nextInt() > 0)
						count++;
				System.out.println(count);
			} else {
				while (n-- > 0)
					if ((num = c.nextInt()) < 3 * p - 4)
						continue;
					else if (num < 3 * p - 2 && s-- > 0)
						count++;
					else if (num >= 3 * p - 2)
						count++;
				System.out.println(count);
			}
		}

	}

}
