import java.util.Scanner;


public class OminousOmino {

	public static void main(String[] args) {
		Scanner reader = new Scanner(System.in);
		int testCases = reader.nextInt();
		for(int t = 0; t < testCases; t++){
			int x = reader.nextInt();
			int r = reader.nextInt();
			int c = reader.nextInt();
			
			boolean answer = helper(x, r, c);
			if(answer){
				System.out.println("Case #" + (t+1) + ": GABRIEL");
			}else{
				System.out.println("Case #" + (t+1) + ": RICHARD");
			}
		}
		reader.close();

	}
	
	public static boolean helper(int x, int r, int c){
		if(r > c){
			int buff = r;
			r = c;
			c = buff;
		}
		if(x == 1){
			return true;
		}
		if(x == 2){
			return (r*c) % x == 0;
		}
		if(r == 1){
			return false;
		}
		if((r*c) % x != 0){
			return false;
		}
		if(x >= 4 && r == 2){
			return false;
		}
		return true;
	}

}
