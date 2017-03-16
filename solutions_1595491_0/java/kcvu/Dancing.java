import java.util.*;


public class Dancing {
	public static void main(String[] args) { 
		Scanner sc = new Scanner(System.in);
		int lines = sc.nextInt();
		for (int i=0; i<lines; i++) {
			int n = sc.nextInt();
			int s = sc.nextInt();
			int p = sc.nextInt();
			int rNormal = p;
			int rSurprise = p;
			if (p>1) {
				rNormal = p*3 - 2;
				rSurprise = p*3 - 4;
			}
			int countPassedNormal = 0;
			int countPassedSurprise = 0;
			for (int j=0; j<n; j++) {
				int t = sc.nextInt();
				if (t>=rNormal) {
					countPassedNormal++;
				}
				else if (t>=rSurprise) {
					countPassedSurprise++;
				}
			}
			
			if (countPassedSurprise>s) countPassedSurprise = s;
			
			System.out.println("Case #"+(i+1)+": "+(countPassedNormal+countPassedSurprise));
		}
	}
}
