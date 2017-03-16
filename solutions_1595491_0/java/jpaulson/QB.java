import java.util.*;

public class QB {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int T = in.nextInt(); in.nextLine();
		for(int cas=0; cas<T; cas++) {
			int n = in.nextInt();
			int s = in.nextInt();
			int p = in.nextInt();
			int ans = 0;
			for(int i=0; i<n; i++) {
				int score = in.nextInt();
				if(score>=p && score>=3*p-2)
					ans++;
				else if(score>=p && score>=3*p-4 && s>0) {
					ans++;
					s--;
				}
			}
			System.out.println("Case #"+(cas+1)+": "+ans);
		}
	}
}