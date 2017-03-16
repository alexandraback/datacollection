import java.io.File;
import java.util.Arrays;
import java.util.Scanner;


public class Pancakes {
	public static void main(String[] args) throws Exception{
		
		
	
		
		Scanner s = new Scanner(new File("B-large.in"));
		int numCases = Integer.parseInt(s.nextLine());
		
		
		
		for(int c = 1;c<=numCases;c++) {
			String stackString = s.nextLine();
		//	System.out.println("==========\nWorking on " + stackString);
			boolean[] stack = new boolean[stackString.length()];
			for(int i = 0;i<stack.length;i++) {
				stack[i] = (stackString.charAt(i)=='+');
			}
			int answer = getFlips(stack);
			System.out.println("Case #" + c + ": " + answer);
		}
		
		
	}
	
	public static int getFlips(boolean[] stack) {

		for(int i = stack.length-1;i>=0;i--) {
			if(!stack[i]) {
				if(stack[0]) {
					
					
					int maxSad = 0;
					boolean[] bestPreflip = null;
					for(int preFlipIndex = 0;preFlipIndex<i;preFlipIndex++) {
						boolean[] candidate = flip(preFlipIndex,stack);
						if(!candidate[0]) {
							int numSad = countSad(candidate);
							if(numSad>maxSad) {
								maxSad = numSad;
								bestPreflip = candidate;
							}
						}
					}
					
					
					return 1 + getFlips(bestPreflip);
				}
				
				return 1+getFlips(flip(i,stack));
			}
		}
		return 0;
	}
	public static int countSad(boolean[] stack) {
		int result = 0;
		for(int i = 0;i<stack.length;i++) {
			if(!stack[i]) result++;
		}
		return result;
	}
	
	public static boolean[] flip(int index, boolean[] stack) {
		//System.out.println("Flipping " + Arrays.toString(stack) + " from " + index);
		boolean[] result = new boolean[stack.length];
		for(int i = 0;i<=index;i++) {
			result[i] = !stack[index-i];
		}
		for(int i = index+1;i<stack.length;i++) {
			result[i] = stack[i];
		}
		return result;
	}
	
}
