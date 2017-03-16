import java.util.*;
public class B {
	static Scanner in;
	
	static void testcase(int t) {
		int x = in.nextInt(), y = in.nextInt();
		System.out.print("Case #"+t+": ");
		String a = x < 0 ? "EW" : "WE";
		String b = y < 0 ? "NS" : "SN";
		x = x < 0 ? -x : x;
		y = y < 0 ? -y : y;
		for(int i = 0;i < x; ++i) System.out.print(a);
		for(int i = 0;i < y; ++i) System.out.print(b);
		System.out.println();
	}
	
	public static void main(String[] args) {
		in = new Scanner(System.in);
		int T = in.nextInt();
		for(int t = 1; t <= T; ++t) testcase(t);
	}
}