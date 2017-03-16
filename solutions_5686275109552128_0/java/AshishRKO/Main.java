import java.util.Scanner;
public class Main {
static int a[]=new int[1205];
	public static void main(String[] args) {
		Scanner S=new Scanner(System.in);
		int T,step=0,n,i,j,max1 = 0,min1,sum;
		T=S.nextInt();
		String str,s;
		for(int k=1;k<=T;k++)
		{
			n=S.nextInt();
			max1=-100;
			for(i=0;i<n;i++)
			{
				a[i]=S.nextInt();
				max1=Math.max(max1,a[i]);
			}
			min1=max1;
			
			for(i = 1 ; i <= max1 ; i++) 
			{
	            sum = i ;
	            for(j = 0 ; j < n ; j++) 
	            {
	                if( a[j] > i ) 
	                {
	                    if( a[j]%i == 0 )
	                        sum += (a[j]/i-1) ;
	                    else
	                        sum += (a[j]/i) ;
	                }
	            }
	            min1 = Math.min(min1,sum);
	            
			}
			System.out.println("Case #"+k+": "+min1);
		}
	}
}
