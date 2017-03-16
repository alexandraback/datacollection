import java.util.*;

public class GC1C_15{

	static int dp[][] = {{0},{0,1,2,3,4},{0,2,-1,4,-3},{0,3,-4,-1,2},{0,4,3,-2,-1}};

	static int mult(int a, int b){
		int inv = 1;
		if(a < 0){
			inv *= -1;
			a *= -1;
		}
		if(b < 0){
			inv *= -1;
			b *= -1;
		}
		return inv*dp[a][b];
	}

	public static void main(String args[]){
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		for(int ca = 1; ca <= T; ca++){
			int L = sc.nextInt();
			int X = sc.nextInt();
			String str = sc.next();

			int arr[] = new int[L];
			for(int i = 0; i < str.length(); i++){
				char c = str.charAt(i);
				if(c=='i')
					arr[i] = 2;
				else if(c=='j')
					arr[i] = 3;
				else if(c=='k')
					arr[i] = 4;
			}

			int prod = 1;
			for(int e: arr)
				prod = mult(prod,e);
			int total = 1;
			for(int i = 1; i <= X%4; i++)
				total = mult(total,prod);

			boolean has = false;
			if(total == -1){
				int leftmin = -1;
				int left = 1;
				for(int i = 0; i < 4 && leftmin == -1; i++){
					int curr = 1;
					for(int j = 0; j <= L; j++){
						if(mult(left,curr) == 2){
							leftmin = L*i + j;
							break;
						}
						if(j < L) curr = mult(curr,arr[j]);
					}
					left= mult(left,prod);
				}

				int rightmin = -1;
				int right = 1;
				for(int i = 0; i < 4 && rightmin == -1; i++){
					int curr = 1;
					for(int j = 0; j <= L; j++){
						if(mult(curr,right) == 4){
							rightmin = L*i + j;
							break;
						}
						if(j < L) curr = mult(arr[L-1-j],curr);
					}
					right = mult(right,prod);
				}
				if(leftmin == -1 || rightmin == -1) {}
				else if(leftmin + rightmin < X*L)
					has = true;
			}
			System.out.print("Case #" + ca + ": ");
			if(has) System.out.println("YES");
			else System.out.println("NO");
		}
	}
}