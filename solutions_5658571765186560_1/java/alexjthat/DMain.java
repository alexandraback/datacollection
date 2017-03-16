import java.util.*;
public class DMain {
	
	public static void main(String[] args){
		
		Scanner in = new Scanner(System.in);
		
		int cases = in.nextInt();
		
		for(int i = 0;i<cases;i++){
			System.out.print("Case #");
			System.out.print(i+1);
			System.out.print(": ");
			int X = in.nextInt();
			int R = in.nextInt();
			int C = in.nextInt();
			if(R<C){
				int temp = R;
				R = C;
				C = temp;
			}
			//R always larger
			if((R*C)%X != 0){
				System.out.println("RICHARD");
			}
			else if(X==1 || X==2){
				System.out.println("GABRIEL");
			}
			else if(X==3){
				if(C<2){
					System.out.println("RICHARD");
				}
				else{
					System.out.println("GABRIEL");
				}
			}
			else if(X==4){
				if(C<=2){
					System.out.println("RICHARD");
				}
				else if(C<4 && R<4){
					System.out.println("RICHARD");					
				}
				else{
					System.out.println("GABRIEL");
				}
			}
			else if(X==5){
				if(R<5 || C<3){
					System.out.println("RICHARD");
				}
				else if(C>3){
					System.out.println("GABRIEL");
				}
				else if(R>5){
					System.out.println("GABRIEL");
				}
				else{
					System.out.println("RICHARD");
				}
			}
			else if(X==6){
				if(R<6 || C<=3){
					System.out.println("RICHARD");
				}
				else{
					System.out.println("GABRIEL");
				}
			}
			else //if X=>7, can force a 1-hole..
				System.out.println("RICHARD");
		}
	}
}
