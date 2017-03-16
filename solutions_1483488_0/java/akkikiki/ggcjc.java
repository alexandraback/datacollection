import java.util.*; 
import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;
//SRM525
public class ggcjc {
	static boolean dp[] = new boolean[1000];
	
	public static int store(int t, int N, int M){
		int answer = 0;
		if(t / 1000 >= 1){// 4 digits
			int one = (t%1000) * 10 + t/1000;
			if(one <= M && one >= N && one != t && !dp[one]){
				answer++;
			}
			one = (t%100) * 100 + t/100;
			if(one <= M && one >= N && one != t && !dp[one]){
				answer++;
			}
			one = (t%10)*1000 + t/10;
			if(one <= M && one >= N && one != t && !dp[one]){
				answer++;
			}
		}
		else if(t / 100 >= 1){ // 3digits
			int one = (t % 100) * 10 + t/100;
			if(one <= M && one >= N && one != t && !dp[one]){
				answer++;
			}
			one = (t % 10) * 100 + t/10;
			if(one <= M && one >= N && one != t && !dp[one]){
				answer++;
			}
		}
		else if(t / 10 >= 1){ // 2digits
			int one = (t % 10) * 10 + t/10;
			if(one <= M && one >= N && one != t && !dp[one]){
				answer++;
			}
		}
		else{ // 1 digit	
		}
		dp[t] = true;
		return answer;
	}
	
	public static void main(String[] args) throws FileNotFoundException { 
		
		int answer = 0;
		Scanner scan = new Scanner(System.in);
		int max = scan.nextInt();
		
		for(int i = 1; i <= max; i++){
			for(int j = 0; j < 1000; j++){
				dp[j] = false;
			}
			int N = scan.nextInt();
			int M = scan.nextInt();
			for(int j = N; j <= M; j++){
				answer = answer + store(j, N, M);
			}
			System.out.println("Case #" + i + ": " + answer);
			answer = 0;
		}
	} 
	
}
