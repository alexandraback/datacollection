import java.io.IOException;
import java.util.Arrays;
import java.util.Locale;
import java.util.Scanner;

public class Consonants {
	
	private void processInput() throws IOException {
		Scanner in = new Scanner(System.in);
		
		int T = in.nextInt();

		for (int testCase = 1; testCase <= T; testCase++) {
	        String L = in.next();
	        int n = in.nextInt();
	        
			
			int res = go(L, n);

			System.out.printf(Locale.ENGLISH, "Case #%d: %d\n", testCase, res);			
		}
		
		in.close();
	}
	
	private int go(String L, int n) {
	    int res = 0;
	    String vowels = "aeiou";
	    
	    int len = L.length();
	    
	    for (int i = 0; i < len; i++) {
	        for (int j = i; j < len; j++) {
	            int glen = 0;
	            boolean found = false;
	            for (int k = i; k <= j; k++) {
	                char c = L.charAt(k);
	                if (vowels.indexOf(c) == -1) {
	                    glen++;
	                } else {
	                    if (glen >= n) {
	                        found = true;
	                        break;
	                    }
	                    glen = 0;
	                }
	            }
                if (found || glen >= n) {
                    res++;
//                    System.out.println(L.substring(i, j + 1));
                }
	        }
	    }
	    

		return res;
	}

	public static void main(String[] args) throws Exception {
		Consonants main = new Consonants();
		main.processInput();
	}
}
