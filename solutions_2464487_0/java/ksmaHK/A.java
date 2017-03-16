import java.util.*;
import java.math.*;

public class A {
public static void main(String [] args) {
	Scanner scanner = new Scanner(System.in);
	int nCase = scanner.nextInt();
	
	for (int nc = 1; nc <= nCase; nc++) {
		long r = scanner.nextLong();
		long t = scanner.nextLong();
		long ans = 0;
		double remain = t;
		remain -= ((r+1)*(r+1) - r*r);
		long R = r+2;
		ans++;
		while (remain >= 0) {
			double rr = ((R+1)*(R+1) - R*R);
			remain -= rr;
			if (remain >= 0)
				ans++;
			R+=2;
		}
		
		
		System.out.println("Case #" + nc + ": " + ans);
	}
}
}