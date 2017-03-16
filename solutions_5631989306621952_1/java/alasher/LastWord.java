import java.util.Scanner;

public class LastWord {
	
	public LastWord(Scanner f) {
		
		int cases = f.nextInt();
		for(int ii = 0; ii < cases; ii++) {
			
			String sequence = f.next();
			
			String ans = "" + sequence.charAt(0);
			
			for(int i = 1; i < sequence.length(); i++) {
				if(sequence.charAt(i) >= ans.charAt(0)) {
					ans = sequence.charAt(i) + ans;
				} else {
					ans = ans + sequence.charAt(i);
				}
			}
			
			System.out.printf("Case #%d: %s\n", ii+1, ans);
			
		}
		
		
	}
	
	
	public static void main(String[] args) {
		Scanner f = new Scanner(System.in);
		new LastWord(f);
		f.close();
	}

}
