import java.util.Scanner;

public class problemB {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner cin = new Scanner(System.in);
		int t = cin.nextInt();
		int k = 0, n, s, p, i, ans;
		int[] a;
		while (t > 0) {
			t--;
			k++;
			n = cin.nextInt();
			s = cin.nextInt();
			p = cin.nextInt();
			a = new int[n];
			for (i = 0; i < n; i++)
				a[i] = cin.nextInt();
			ans = 0;
			for (i = 0; i < n; i++) {				
				if(a[i]>=p+Math.max(p-1, 0)*2){
					ans++;
				}else
					if(a[i]>=p+Math.max(p-2, 0)*2 && s>0){
						ans++;
						s--;
					}
			}
			System.out.println("Case #"+k+": "+ans);
		}
	}

}
