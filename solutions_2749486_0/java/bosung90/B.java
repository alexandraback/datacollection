import java.util.Scanner;

public class B {

	static Scanner scan;
	
	public static void main(String[] args) {
		scan = new Scanner(System.in);
		int T = scan.nextInt();
		int caseNum = 0;
		while(caseNum<T){
			caseNum++;

			int X = scan.nextInt();
			int Y = scan.nextInt();
			
			String ans = "";
			
			if(X>0){
				for(int i=0; i<X; i++){
					ans += "WE";
				}
			}
			else if (X<0){
				X = -X;
				for(int i=0; i<X; i++)
					ans += "EW";
			}
			
			if(Y>0){
				for(int i=0; i<Y; i++){
					ans += "SN";
				}
			}
			else if (Y<0){
				Y = -Y;
				for(int i=0; i<Y; i++)
					ans += "NS";
			}			
			
			System.out.println("Case #"+(caseNum)+": "+ans);
		}
	}

}
