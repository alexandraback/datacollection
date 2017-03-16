import java.util.Scanner;
public class Main {
	
	public static void main(String[] args) {
		Scanner S=new Scanner(System.in);
		int T,i,X,R,C,G;
		T=S.nextInt();
		for(int k=1;k<=T;k++)
		{
			X=S.nextInt();
			R=S.nextInt();
			C=S.nextInt();
			G=R*C;
	
			if(X==1)
			{
				System.out.println("Case #"+k+": "+"GABRIEL");
				
			}
			
			
			if(X==2)
			{
				if(R%2==0 || C%2==0)
				{
					System.out.println("Case #"+k+": "+"GABRIEL");
					
				}
				else
				{
					System.out.println("Case #"+k+": "+"RICHARD");
				
				}
			}
			
			if(X==3)
			{
				if(R==1 || C==1)
				{
					System.out.println("Case #"+k+": "+"RICHARD");
				}
				else if(R==3 || C==3)
				{
					System.out.println("Case #"+k+": "+"GABRIEL");
				}
				else
				{
					System.out.println("Case #"+k+": "+"RICHARD");
				}
			}
			
			if(X==4)
			{
				
				if((R==3 && C==4) || (R==4 && C==3) || (R==4 && C==4))
				{
					System.out.println("Case #"+k+": "+"GABRIEL");
				}
				else
				{
					System.out.println("Case #"+k+": "+"RICHARD");
				}
			}
			
			
			
		}
	}
}
