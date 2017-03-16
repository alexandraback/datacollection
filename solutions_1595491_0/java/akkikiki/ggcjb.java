import java.util.*; 
import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;
//SRM525
public class ggcjb {
	static int counter = 0;
	static int dp[][] = new int[3][3];
	
	public static int store(int t, int p){
		int divided = t/3;
		
		int a = divided,b = divided,c = divided;
		int remain = t % 3;
		if(remain == 2){
			a++;
			b++;
		}
		if(remain == 1){
			a++;
		}
		dp[counter][0] = a;
		dp[counter][1] = b;
		dp[counter][2] = c;
		//System.out.println(a);
		//System.out.println(b);
		//System.out.println(c);
		//System.out.println(p);
		counter++;
		if(a >= p || b >= p || c >= p){
			return 1;
		}
		return 0;
	}
	
	public static int check(int N, int s, int p){
		int supply = 0;
		for(int i = 0; i < N; i++){
			if(dp[i][0] < p && s > 0){
				dp[i][0]++;
				dp[i][1]--;
				if(dp[i][0] < p ||dp[i][0] - dp[i][1] > 2 || dp[i][1] < 0){
					continue;
				}
				else{
					supply++;
					s--;
				}
			}
		}
		//System.out.println(supply);
		return supply;
	}
	
	public static void main(String[] args) throws FileNotFoundException { 
		int answer = 0;
		Scanner scan = new Scanner(System.in);
		int max = scan.nextInt();

		
		//int dp[][] = new int[3][3];
		
		for(int i = 1; i <= max; i++){
			int N = scan.nextInt();
			int s = scan.nextInt();
			int p = scan.nextInt();
			for(int j = 1; j <= N; j++){
				int n = scan.nextInt();
				answer = answer + store(n, p);
			}
			int supply = check(N, s, p);
			//System.out.println(supply);
			answer = answer + supply;
			System.out.println("Case #" + i + ": " + answer);
			counter = 0;
			answer = 0;
		}
	} 
	
}
