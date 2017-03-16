import java.io.*;
import java.util.Scanner;


public class Omino {
	public Omino() {
		Scanner in = new Scanner(System.in);
		int tests = in.nextInt();
		for(int t = 1; t<=tests; t++){
			int x = in.nextInt();
			int small = in.nextInt();
			int large = in.nextInt();
			String ans = solve(x, small, large);
			System.out.printf("Case #%d: %s\n", t, ans);
		}
	}
	String solve(int x, int small, int large){
		String ans = "GABRIEL";
		if(large < small){
			int tmp = small;
			small = large;
			large = tmp;
		}
		
		if((small*large)%x != 0)
			ans = "RICHARD";
		else if(x > large)
			ans = "RICHARD";
		else if(small == 1){
			if(x > 2)
				ans = "RICHARD";
		}else if(small == 2){
			if(x > 3)
				ans = "RICHARD";
		}else if(small == 3){
			if(x > 5)
				ans = "RICHARD";
		}else{
			if(x > 6)
				ans = "RICHARD";
		}
		return ans;
	}
	public static void main(String[] args) throws FileNotFoundException {
		System.setIn(new FileInputStream(new File("D-large.in")));
		System.setOut(new PrintStream(new File("D-large.out")));
		new Omino();
	}
}
