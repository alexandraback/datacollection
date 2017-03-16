import java.util.Scanner;
public class Paint {
	public static void main(String argsp[]) {
		Scanner in = new Scanner(System.in);
		int t = in.nextInt();
		for (int c = 0; c < t; c++) {
			long r = in.nextLong();
			long p = in.nextLong();
			
			int times = 0;
			do {
				long area = (r+1) * (r+1) -  r * r;
				if (area > p)
					break;
				times++;
				r += 2;
				p -= area;
			} while (true);
			System.out.printf("Case #%d: %d\n", c + 1, times);
		}
	}

}
