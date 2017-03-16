import java.util.Scanner;

public class D {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int nt = in.nextInt();
		for(int t = 1; t <= nt; t++)
		{
			int k = in.nextInt();
			int c = in.nextInt();
			int s = in.nextInt();
			System.out.print("Case #" + t + ":");
			for(int i = 1; i <= k; i++)
				System.out.print(" " + i);
			System.out.println();
		}
	}
}
