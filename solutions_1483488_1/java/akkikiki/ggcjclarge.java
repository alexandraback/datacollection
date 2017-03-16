import java.util.*; 
import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;
//SRM525
public class ggcjclarge {
	static boolean dp[] = new boolean[2000000];
	
	public static int store(int t, int N, int M){
		int answer = 0;
		
		if(t / 1000000 >= 1){// 7 digits
			int one = (t%1000000) * 10 + t/1000000;
			if(one <= M && one >= N && one != t && !dp[one]){
				answer++;
			}
			int two = (t%100000) * 100 + t/100000;
			if(two <= M && two >= N && two != t && !dp[two] && two != one){
				answer++;
			}
			int three = (t%10000)*1000 + t/10000;
			if(three <= M && three >= N && three != t && !dp[three] && three != one && three != two){
				answer++;
			}
			int four = (t%1000)*10000 + t/1000;
			if(four <= M && four >= N && four != t && !dp[four] && four != one && four != two && four != three){
				answer++;
			}
			int five = (t%100)*100000 + t/100;
			if(five <= M && five >= N && five != t && !dp[five] && five != one && five != two && five != three && five != four){
				answer++;
			}
			int six = (t%10)*1000000 + t/10;
			if(six <= M && six >= N && six != t && !dp[six] && six != one && six != two && six != three && six != four && six != five){
				answer++;
			}
		}
		
		else if(t / 100000 >= 1){// 6 digits
			int one = (t%100000) * 10 + t/100000;
			if(one <= M && one >= N && one != t && !dp[one]){
				answer++;
			}
			int two = (t%10000) * 100 + t/10000;
			if(two <= M && two >= N && two != t && !dp[two] && two != one){
				answer++;
			}
			int three = (t%1000)*1000 + t/1000;
			if(three <= M && three >= N && three != t && !dp[three] && three != one && three != two){
				answer++;
			}
			int four = (t%100)*10000 + t/100;
			if(four <= M && four >= N && four != t && !dp[four] && four != one && four != two && four != three){
				answer++;
			}
			int five = (t%10)*100000 + t/10;
			if(five <= M && five >= N && five != t && !dp[five] && five != one && five != two && five != three && five != four){
				answer++;
			}
		}
		
		else if(t / 10000 >= 1){// 5 digits
			int one = (t%10000) * 10 + t/10000;
			if(one <= M && one >= N && one != t && !dp[one]){
				answer++;
			}
			int two = (t%1000) * 100 + t/1000;
			if(two <= M && two >= N && two != t && !dp[two] && two != one){
				answer++;
			}
			int three = (t%100)*1000 + t/100;
			if(three <= M && three >= N && three != t && !dp[three] && three != one && three != two){
				answer++;
			}
			int four = (t%10)*10000 + t/10;
			if(four <= M && four >= N && four != t && !dp[four] && four != one && four != two && four != three){
				answer++;
			}
		}
		else if(t / 1000 >= 1){// 4 digits
			int one = (t%1000) * 10 + t/1000;
			if(one <= M && one >= N && one != t && !dp[one]){
				answer++;
			}
			int two = (t%100) * 100 + t/100;
			if(two <= M && two >= N && two != t && !dp[two] && two != one){
				answer++;
			}
			int three = (t%10)*1000 + t/10;
			if(three <= M && three >= N && three != t && !dp[three] && three != one && three != two){
				answer++;
			}
		}
		else if(t / 100 >= 1){ // 3digits
			int one = (t % 100) * 10 + t/100;
			if(one <= M && one >= N && one != t && !dp[one]){
				answer++;
			}
			int two = (t % 10) * 100 + t/10;
			if(two <= M && two >= N && two != t && !dp[two] && two != one){
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
			for(int j = 0; j < 2000000; j++){
				dp[j] = false;
			}
			int N = scan.nextInt();
			int M = scan.nextInt();
			for(int j = N; j < M; j++){
				answer = answer + store(j, N, M);
			}
			System.out.println("Case #" + i + ": " + answer);
			answer = 0;
		}
	} 
	
}
