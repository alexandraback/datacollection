import java.util.*;
import java.math.*;

public class B {

	public static void main(String[] args){
		Scanner sc=new Scanner(System.in);
		
		int t=sc.nextInt();
		String s=sc.nextLine();
		for (int r=1;r<=t;r++){
		int n=sc.nextInt();
		int m=sc.nextInt();
		if (n>m){
			int temp=n;
			n=m;
			m=temp;
		}
		int k=sc.nextInt();
				
			System.out.println("Case #"+r+": "+min(n,m,k));
			
		}
	}

	private static int min(int n, int m, int k) {
		// TODO Auto-generated method stub
		int min=k;

		
		for (int i=2;i*i<=k;i++){
			int j=k/i;
			if (k % i!=0) j++;
			if (i<=n && j<=m) {
				if (i*j-4>=k) min=Math.min((i+j)*2-8,min);
				else min=Math.min((i+j)*2-8+(k-i*j+4),min);
			}
			int k1=k+4;
			j=k1/i;
			if (k1 % i!=0) j++;
			if (i<=n && j<=m) 
				 min=Math.min((i+j)*2-8,min);
		}
		
		return min;
	}

	
}
