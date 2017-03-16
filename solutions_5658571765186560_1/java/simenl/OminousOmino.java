import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.Scanner;


public class OminousOmino {
	static String filename = "D-large";
	static Scanner sc;
	
	public static void main(String[] args) throws FileNotFoundException{
		System.setIn(new FileInputStream(filename + ".in"));
		System.setOut(new PrintStream(filename + ".out"));
		sc = new Scanner(System.in);
		int t = sc.nextInt();
		for(int casee = 1 ; casee<=t ; casee++){
			System.out.print("Case #" + casee + ": ");
			if(solve()){
				System.out.println("GABRIEL");
			}
			else{
				System.out.println("RICHARD");
			}
		}
	}
	public static boolean solve(){
		int X = sc.nextInt();
		int R = sc.nextInt();
		int C = sc.nextInt();
		if(R < C){
			R +=C;
			C = R-C;
			R -=C;
		}
		if((R*C)%X != 0){
			return false;
		}
		if(X > R){
			return false;
		}
		if(X > 2*C){
			return false;
		}
		if(X > 6){
			return false;
		}
		if(X == 4 && C == 2){
			return false;
		}
		if(X == 5 && C == 3){
			if(!possible(X, 2, 2, R) || !possible(X, 3, 1, R)){
				return false;
			}
		}
		if(X == 6 && C == 3){
			return false;
		}
		
		return true;
	}
	private static boolean possible(int X, int left, int right, int R) {
		for(int i = 0; i < R-3; i++){
			if((3*i + left)%X == 0 && ((R-(i+3))*3 + right)%X == 0){
				return true;
			}
		}
		return false;	
	}
}
