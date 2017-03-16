import java.util.*;

public class D {
public static void main(String [] args) {
	Scanner scanner = new Scanner(System.in);
	int nCase = scanner.nextInt();
	boolean RWIN = false;
	for (int nc = 1; nc <= nCase; nc++) {
		int X = scanner.nextInt();
		int R = scanner.nextInt();
		int C = scanner.nextInt();
		boolean g_win = RWIN;
		
		if ((R*C % X == 0) && Math.max(R, C) >= X && Math.min(R, C) >= X-1)
			g_win = !g_win;
		System.out.println("Case #" + nc + ": " + (g_win ? "GABRIEL" : "RICHARD"));
	}
}
}