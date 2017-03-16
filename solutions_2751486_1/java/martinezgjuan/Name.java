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
		long count = 0;
		
		int last = 0;
		
		int[] cons = new int[s.length()+2];
		
		for(int i =n-1; i<s.length(); i++){
			
			boolean good = true;
			
			if (i==n-1){
				String sub = s.substring(i-n+1,i+1);
				for(int k=0; k<sub.length(); k++){
					if(isVowel(sub.charAt(k))){
						good = false;
						if(k==0)
							cons[k] = 0;
						else 
							cons[k] = cons[k-1];
					} else {
						if(k==0)
							cons[k] = 1;
						else {
							cons[k] = cons[k-1]+1;
						}
					}
				}
			} else {
				
				if(isVowel(s.charAt(i))){
					good = false;
					cons[i] = cons[i-1];
				} else {
					if(i==0)
						cons[i] = 1;
					else {
						cons[i] = cons[i-1]+1;
					}
				}
				
				if(cons[i]-cons[i-n]>=n){
					good = true;
				} else {
					good = false;
				}
			}


			
			if(good){
				count+= ((i-n)-last+2)*(s.length()-i);
				last = i-n+2;
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
