import java.util.*;

public class D {
public static void main(String [] args) {
	Scanner scanner = new Scanner(System.in);
	int nCase = scanner.nextInt();
	
	for (int nc = 1; nc <= nCase; nc++) {
		int N = scanner.nextInt();
		double[] a = new double[N];
		double[] b = new double[N];
		for (int i = 0; i < N; i++)
			a[i] = scanner.nextDouble();
		for (int i = 0; i < N; i++)
			b[i] = scanner.nextDouble();
		
		Arrays.sort(a);
		Arrays.sort(b);
		
		int y = 0, z = 0;
		// doing war
		{
			for (int i = N-1, j = N-1; i >= 0; i--) {
				if (a[i] < b[j]) {
					j--;					
				} else {
					z++;
				}
			}
		}
		
		// doing fake war
		for (int i = 0, j = 0; i < N; i++) {
			if (a[i] > b[j]) {
				j++;
				y++;					
			}
		}
		
		System.out.println("Case #" + nc + ": " + y + " " + z);
	}
}
}