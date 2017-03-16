import java.util.Scanner;


public class Omino_Small {

	public static void main(String[] args) {
		Scanner read= new Scanner(System.in);
		
		int T,X,R,C;
		
		T=read.nextInt();
		for(int i=0;i<T;i++){
			X=read.nextInt();
			R=read.nextInt();
			C=read.nextInt();
			if(((R*C)%X)!=0){
				int x=i+1;
				System.out.println("Case #"+x+": RICHARD");
			}else if((X-1)>R||(X-1)>C){
				int x=i+1;
				System.out.println("Case #"+x+": RICHARD");
				
			}else{
				int x=i+1;
				System.out.println("Case #"+x+": GABRIEL");
			}
			
		}
	}

}
