import java.util.*;

public class C_large1 {
public static void main(String [] args) {
	Scanner scanner = new Scanner(System.in);
	int nCase = scanner.nextInt();
	int bSize = 10000000;
	long [] pal = new long[1000];
	int palSize = 0;
	for (long i = 1; i <= bSize; i++) {
		if (isPal(i) && isPal(i*i)) {
			pal[palSize++] = i*i;
		}
	}
	
	for (int nc = 1; nc <= nCase; nc++) {
		long A = scanner.nextLong();
		long B = scanner.nextLong();
		long ans = 0;
		// find first num that is sqrted
		for (int i = 0; i < palSize; i++) {
			if (pal[i] >= A && pal[i] <= B)
				ans++;
		}
		
		System.out.println("Case #" + nc + ": " + ans);
	}
}

public static boolean isPal(long n) {
	String str = Long.toString(n);
	int len = str.length();
	int end = len/2;	
	for (int i = 0, j = len-1; i < end; i++, j--) {
		if (str.charAt(i) != str.charAt(j))
			return false;
	}
	return true;
}
}