import java.util.*;
import java.math.*;

public class C {

	public static void main(String[] args){
		Scanner sc=new Scanner(System.in);
		
		int t=sc.nextInt();
		
		for (int r=1;r<=t;r++){
			int n=sc.nextInt();
			sc.nextLine();
			boolean [][] mat=new boolean[n][n];
			String[] s=new String[n];
			
			s=sc.nextLine().split(" ");
			Arrays.sort(s);

			System.out.println("Case #"+r+": "+ans(s));
		}
	}

	private static int ans(String[] s) {
		// TODO Auto-generated method stub
		int n=s.length;
		for (int i=0;i<n-1;i++)
			if (s[i].charAt(s[i].length()-1)>s[i+1].charAt(0)) return 0;
		
		int k=1;
		int j=1;
		int ans=1;
		for (int i=0;i<n;i++){
			if (i>0 && s[i].charAt(s[i].length()-1)==s[i-1].charAt(0)) {
				j++;
				ans=(ans*j) % 1000000007;
			}
			else j=1;
			
			if (i<n-1 && s[i].charAt(s[i].length()-1)<s[i+1].charAt(0)) {
				k++;
				ans=(ans*k) % 1000000007;
			}
		}
		
		return ans;
	}

	
}
