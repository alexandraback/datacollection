import java.util.*;

public class C_small {
public static void main(String [] args) {
	Scanner scanner = new Scanner(System.in);
	int nCase = scanner.nextInt();
	
	for (int nc = 1; nc <= nCase; nc++) {
		int A = scanner.nextInt();
		int B = scanner.nextInt();
		int ans = 0;
		for (int i = A; i <= B; i++) {
			if (isPal(i) && isSqOfPal(i))
				ans++;
		}
		
		System.out.println("Case #" + nc + ": " + ans);
	}
}

public static boolean isSqOfPal(int n) {
	int r = (int) Math.sqrt(n);
	if (r*r != n)
		return false;
	return isPal(r);
}
public static boolean isPal(int n) {
	String str = Integer.toString(n);
	int len = str.length();
	int end = len/2;	
	for (int i = 0, j = len-1; i < end; i++, j--) {
		if (str.charAt(i) != str.charAt(j))
			return false;
	}
	return true;
}
}