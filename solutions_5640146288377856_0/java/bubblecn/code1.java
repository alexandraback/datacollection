import java.util.*;
public class cj_2 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc=new Scanner(System.in);
		int t=0;
		int n=sc.nextInt();
		while(t<=n){
			t++;
			int R=sc.nextInt();
			int C=sc.nextInt();
			int W=sc.nextInt();
			int result=0;
			if(2*W>=C)
				result=Math.min(W+1,C);
			else 
				if(C%W==0)
					result=C/W+(W-1);
				else
					result=C/W+W;
			System.out.println("Case #"+t+": "+result);
				
		}		
	}

}
