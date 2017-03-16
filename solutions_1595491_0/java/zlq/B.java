import java.util.*;
import java.io.*;

public class B{
	void solve() throws FileNotFoundException{
		File fin = new File("data.in");
		File fout = new File("data.out");
		Scanner cin = new Scanner(fin);
		PrintWriter cout = new PrintWriter(fout);
		
		int T, n, s, p;
		T = cin.nextInt();
		for(int k = 0; k < T; k++){
			n = cin.nextInt(); s = cin.nextInt(); p = cin.nextInt();
			int [] num = new int[n];
			for(int i = 0; i < n; i++)  num[i] = cin.nextInt();
			int ans = 0;
			for(int i = 0; i < n; i++){
				if(num[i]/3>=p || (num[i]%3>0 && num[i]/3+1>=p)){
					ans++;
					continue;
				}
				if(num[i]%3==2 && num[i]/3+2>=p && s>0){
					s--;
					ans++;
				}
				if(num[i]%3==0 && num[i]/3+1>=p && num[i]/3>0 && s>0){
					s--;
					ans++;
				}
			}
			cout.printf("Case #%d: %d\n", k+1, ans);
		}
		
		cout.flush();
	}
	public static void main(String [] args) throws Exception{
		B test = new B();
		test.solve();
	}
}












