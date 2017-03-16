import java.util.Scanner;

public class PancakesRevenge {

	public static int count_flips(String S){
		char[] sym = {'-','+'};
		int cp = 0;
		int ans = 0;	
		int pos =  S.length()-1;
		while ((pos >= 0) && (S.charAt(pos)=='+')) { pos--;}
		while(pos >= 0)
		{
			while ((pos >= 0) && (S.charAt(pos)==sym[cp])) { pos--;}
			cp = (cp + 1) % 2;			
			ans++;
		}		
		return ans;
	}
	
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		for (int i=0; i < T; i++){
			String S = sc.next();
			System.out.println("Case #" + (i+1) +": " + count_flips(S));
		}
		sc.close();
	}
	
	
}
