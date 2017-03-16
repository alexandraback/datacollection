import java.util.ArrayList;
import java.util.Scanner;

public class Problem1 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner input = new Scanner(System.in);
		int case2 = input.nextInt();input.nextLine();
		for(int a = 0; a < case2; a++){
			String in = input.nextLine();
			String output = solve(in, 'Z');
			System.out.print("Case #" + (a+1) + ":" + " ");
			System.out.println(output);
		}
	}

	private static String solve(String in, char CurrentChar) {
		if(CurrentChar == 'A'){
			return in;
		}
		StringBuilder prev = new StringBuilder();
		StringBuilder simulateLeft = new StringBuilder();
		StringBuilder simulateRight = new StringBuilder();
		int start2 = in.length();
		for(int a = 0; a < in.length(); a++){
			if(in.charAt(a) != CurrentChar){
				prev.append(in.charAt(a));
			}
			else{
				start2 = a;
				break;
			}
		}
		for(int a = start2; a < in.length(); a++){
			if(in.charAt(a) == CurrentChar){
				simulateLeft.append(in.charAt(a));
			}
			else{
				simulateRight.append(in.charAt(a));
			}
		}
		return simulateLeft.toString() + solve(prev.toString(), --CurrentChar) + simulateRight.toString();
	}

}
