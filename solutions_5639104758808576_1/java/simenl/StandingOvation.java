import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.Scanner;


public class StandingOvation {
	public static void main(String[] args) throws FileNotFoundException{
		System.setIn(new FileInputStream("A-large.in"));
		System.setOut(new PrintStream("A-large.out"));
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		for(int casee = 1 ; casee<=t ; casee++){
			System.out.print("Case #" + casee + ": ");
			int smax = sc.nextInt();
			String s = sc.next();
			System.out.println(solve(s));
		}
	}
	public static int solve(String s){
		int ans = 0;
		int cnt = 0;
		for(int i = 0; i < s.length(); i++){
			if(cnt < i){
				ans++;
				cnt++;
			}
			cnt += s.charAt(i)-'0';
		}
		return ans;
	}
}
