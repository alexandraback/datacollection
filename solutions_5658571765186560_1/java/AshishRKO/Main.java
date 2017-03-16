import java.util.Scanner;
public class Main 
{
	public static void main(String[] args) {
		Scanner S=new Scanner(System.in);
		int T,X,R,C,k;
		boolean flag;
		T=S.nextInt();
		for(k=1;k<=T;k++)
		{
			X=S.nextInt();
			R=S.nextInt();
			C=S.nextInt();
			flag=true;
			
			if(X>=7)
				flag=false;
			
			else if(X>R && X>C)
				flag=false;
			else if(R * C % X != 0)
				flag=false;
			else if(((X + 1)/2) > Math.min(R, C))
				flag=false;
			else if(X==1 || X==2 || X==3)
				flag=true;
			else if(X==4)
				flag=(Math.min(R,C)>2);
			else if(X==5)
				flag = !(Math.min(R, C) == 3 && Math.max(R, C) == 5);
			else if(X==6)
				flag = (Math.min(R, C) > 3);
					
	            
			
			if(flag==true)
				System.out.println("Case #"+k+": GABRIEL");
			else
				System.out.println("Case #"+k+": RICHARD");
		}
	}
}
