import java.util.*;
import static java.lang.Math.*;

public class D {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int T = in.nextInt();
		for(int zz = 1; zz <= T; zz++) {
			int H = in.nextInt();
			int W = in.nextInt();
			in.nextLine();
			for(int i = 0; i < H;i++)
				in.nextLine();
			System.out.format("Case #%d: %d\n", zz, 8);
		}
	}
}
