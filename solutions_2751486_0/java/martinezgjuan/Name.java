import java.io.FileNotFoundException;
import java.util.Scanner;

public class Name {

	public static boolean isVowel(char ch) {
		ch = Character.toUpperCase(ch);
		return ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U';
	}

	private static String solve(Scanner sc) {
		String s = sc.next();
		int n =  sc.nextInt();
		int count = 0;
		
		for(int i =0; i<=s.length(); i++){
			for(int j =i+1;j<=s.length();j++){
				String sub = s.substring(i,j);
				int max = 0;
				int c = 0;
				for(int k=0; k<sub.length(); k++){
					if(!isVowel(sub.charAt(k))){
						c++;
						max = Math.max(max, c);
					} else {
						c = 0;
					}
				}
				if(max>=n){
					count++;
				}
			}
		}
		
		return count+"";
	}

    public static void main(String[] args) throws FileNotFoundException {
        Scanner in = new Scanner(System.in);
        //PrintWriter out = new PrintWriter(System.out);
        int T = in.nextInt();
        for (int i = 0; i < T; i++) {
            String s = "Case #" + (i + 1) + ": " + solve(in);
            System.out.println(s);
        }
    }

}
