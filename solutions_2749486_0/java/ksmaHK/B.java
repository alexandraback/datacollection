import java.util.*;
import java.math.*;

public class B {
public static void main(String [] args) {
	Scanner scanner = new Scanner(System.in);
	int nCase = scanner.nextInt();
	
	for (int nc = 1; nc <= nCase; nc++) {
		int X = scanner.nextInt();
		int Y = scanner.nextInt();
		StringBuilder ans = new StringBuilder(500);
		if (X > 0) {
			for (int i = 0; i < X; i++)
				ans.append('W').append('E');
		} else if (X < 0) {
			for (int i = 0; i > X; i--)
				ans.append('E').append('W');
		}
		if (Y > 0) {
			for (int i = 0; i < Y; i++)
				ans.append('S').append('N');
		} else if (Y < 0) {
			for (int i = 0; i > Y; i--)
				ans.append('N').append('S');
		}
		System.out.println("Case #" + nc + ": " + ans.toString());
	}
}
}