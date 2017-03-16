import java.util.Scanner;
import java.util.Vector;

class Main{
	private static Vector<Long> vc;
	
	private static int f(long N){
		for(int i=0;i<vc.size();i++){
			if(vc.get(i) > N)
				return i;
		}
		return vc.size();
	}

	private static boolean isPalindrome(long N){
		String str = Long.toString(N);
		int a = 0,b=str.length()-1;
		while(a < b){
			if(str.charAt(a) != str.charAt(b))
				return false;
			a++;
			b--;
		}
		
		return true;
	}

	public static void main(String args[]){
		Scanner in = new Scanner(System.in);
		vc = new Vector<Long>();
		
		for(long i=1;i<=1e7;i++){
			if(isPalindrome(i) && isPalindrome(i*i)){
				vc.add(i*i);
				//System.out.println(i*i);
			}
		}
		//System.out.println(vc.size());

		int nc = in.nextInt();
		long A,B,ans,ans2;
		for(int i=1;i<=nc;i++){
			A = in.nextLong();
			B = in.nextLong();

			ans = f(B) - f(A-1);

			System.out.printf("Case #%d: %d\n",i,ans);
		}
	}
}