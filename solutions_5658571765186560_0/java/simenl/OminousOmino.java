import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.Scanner;


public class OminousOmino {
	static String filename = "D-small-attempt1";
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
		
		return true;
	}
}
