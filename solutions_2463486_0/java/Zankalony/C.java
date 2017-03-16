import java.io.FileReader;
import java.io.IOException;
import java.util.Scanner;

public class C {
	public static void main(String[] args) throws IOException {
		long[] a = { 1, 4, 9, 121, 484, 10201, 12321, 14641, 40804, 44944,
				1002001, 1234321, 4008004, 100020001, 102030201, 104060401,
				121242121, 123454321, 125686521, 400080004, 404090404,
				10000200001l, 10221412201l, 12102420121l, 12345654321l,
				40000800004l, 1000002000001l, 1002003002001l, 1004006004001l,
				1020304030201l, 1022325232201l, 1024348434201l, 1210024200121l,
				1212225222121l, 1214428244121l, 1232346432321l, 1234567654321l,
				4000008000004l, 4004009004004l, 100000020000001l };
		Scanner sc = new Scanner(new FileReader("input.txt"));
		int tc = sc.nextInt();
		for (int i = 1; i <= tc; i++) {
			long f = sc.nextLong(), t = sc.nextLong();
			int cnt = 0;
			for (int j = 0; j < a.length; j++) 
				if (a[j] >= f && a[j] <= t)
					cnt++;
			System.out.printf("Case #%d: %d\n", i, cnt);
		}
	}
}