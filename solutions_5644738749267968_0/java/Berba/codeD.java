import java.util.*;

public class codeD{
	public static void main(String args[]){
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		for(int ca = 1; ca <= T; ca++){
			int N = sc.nextInt();
			double a[] = new double[N];
			double b[] = new double[N];
			for(int i = 0;i < N; i++)
				a[i] = sc.nextDouble();
			for(int i = 0; i < N; i ++)
				b[i] = sc.nextDouble();
			Arrays.sort(a);
			Arrays.sort(b);

			int war = 0;
			int max = N-1;
			int min = 0;

			for(int i = N-1; i >= 0; i--){
				if(a[i] > b[max]){
					war++;
				}else{
					max--;
				}
			}

			int deceit = 0;
			for(int i = 0; i < N; i++){
				if(a[i] < b[min]){
					continue;
				}else{
					min++;
					deceit++;
				}
			}


			System.out.println("Case #" + ca + ": " + deceit + " " + war);
		}
	}
}