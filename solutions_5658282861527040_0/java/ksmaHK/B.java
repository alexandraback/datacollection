import java.util.*;

public class B {
public static void main(String [] args) {
	Scanner scanner = new Scanner(System.in);
	int nCase = scanner.nextInt();
	
	for (int nc = 1; nc <= nCase; nc++) {
		int A = scanner.nextInt();
		int B = scanner.nextInt();
		int K = scanner.nextInt();
		
		int ans = 0;
		for (int a = 0; a < A; a++)
		for (int b = 0; b < B; b++) {
			if ((a & b) < K)
				ans++;
		}
		
		
		System.out.println("Case #" + nc + ": " + ans);
	}
}
}