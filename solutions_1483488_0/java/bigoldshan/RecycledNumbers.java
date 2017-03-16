import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.PrintWriter;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;


public class RecycledNumbers {
	
	public static void main(String[] argv) throws Exception {
//		Scanner s = new Scanner(System.in);
		Scanner s = new Scanner(new FileInputStream("RecycledNumbers/C-small-attempt0.in"));
		PrintWriter pw = new PrintWriter(new FileOutputStream("RecycledNumbers/C-small-attempt0.out"));
//		PrintWriter pw = new PrintWriter(System.out);
		
		int T = s.nextInt();
		for(int i=1;i<=T;i++) {
			int A = s.nextInt();
			int B = s.nextInt();
			Set<Integer> checked = new HashSet<Integer>();
			int numDigit = Integer.toString(A).length();
			int pairs = 0;
			for(int j = A; j<=B; j++) {
				if(checked.contains(j)) continue;
				checked.add(j);
				int[] digits = new int[numDigit];
				for(int k = 0;k < numDigit;k++) {
					digits[k] = (j / powers[k]) - (j / powers[k+1])*10;
				}
//				System.out.println(Arrays.toString(digits));
				int count =0;
				for(int k =1; k< numDigit;k++ ){
					shift(digits);
					int newnum = 0;
					for(int l=0;l<numDigit;l++) {
						newnum += digits[l]*powers[l];
					}
					if(!checked.contains(newnum)) {
						checked.add(newnum);
						if(newnum >= A && newnum <=B) {
							count++;
						}
					}
				}
				if(count >= 1) {
					pairs += (count+1)*(count)/2;
				}				
			}
			pw.println("Case #" + i +": " + pairs);
			System.out.println("Case #" + i +":" +pairs);
		}
		pw.flush();
		pw.close();
	}
	static int[] powers = new int[8];

	static 
	{
		for(int j=0;j<powers.length;j++) {
			powers[j] = pow(10,j);	
		}

	}
	static int pow(int a, int b) {
		if(b == 1) return a;
		if(b == 0) return 1;
		if(b%2 == 0) {
			int r = pow(a,b/2);
			return r*r;
		} else {
			return pow(a,b-1)*a;
		}
	}
	private static void shift(int[] digits) {
		int tmp = digits[0];
		for(int i=0;i<digits.length-1;i++) {
			digits[i] = digits[i+1];
		}
		digits[digits.length-1] = tmp;
	}

}
