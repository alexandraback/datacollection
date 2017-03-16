import java.util.Scanner;


public class Pr4 {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int T, X, R, C;
		Scanner s = new Scanner(System.in);
		T = s.nextInt();
		for(int t=0; t<T; t++){
			X = s.nextInt(); 
			R = s.nextInt(); 
			C = s.nextInt();
			if(X==1){
				System.out.println("Case #"+(t+1)+": GABRIEL");
			}
			if(X==2){
				if(R*C%2 == 0) System.out.println("Case #"+(t+1)+": GABRIEL");
				else System.out.println("Case #"+(t+1)+": RICHARD");
			}
			if(X==3){
				if(R*C%3 == 0 && R>1 && C>1) System.out.println("Case #"+(t+1)+": GABRIEL");
				else System.out.println("Case #"+(t+1)+": RICHARD");
			}
			if(X==4){
				if(R*C%4 == 0 && R>2 && C>2) System.out.println("Case #"+(t+1)+": GABRIEL");
				else System.out.println("Case #"+(t+1)+": RICHARD");
			}
			if(X==5){
				if(R*C%5 == 0 && R>2 && C>2 && R+C!=8) System.out.println("Case #"+(t+1)+": GABRIEL");
				else System.out.println("Case #"+(t+1)+": RICHARD");
			}
			if(X==6){
				if(R*C%6 == 0 && R>3 && C>3) System.out.println("Case #"+(t+1)+": GABRIEL");
				else System.out.println("Case #"+(t+1)+": RICHARD");
			}
			if(X>6) System.out.println("Case #"+(t+1)+": RICHARD");
		}
			
	
	}

}
