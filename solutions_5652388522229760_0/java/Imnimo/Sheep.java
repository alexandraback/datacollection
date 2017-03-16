import java.io.File;
import java.util.Scanner;


public class Sheep {
	public static void main(String[] args) throws Exception {
		
		Scanner s = new Scanner(new File("A-small-attempt0.in"));
		String cLine = s.nextLine();
		int cases = Integer.parseInt(cLine);
		for(int c = 1;c<=cases;c++) {
			int base = Integer.parseInt(s.nextLine());
			long answer = getLastNum(base);
			if(answer == -1) {
				System.out.println("Case #" + c + ": INSOMNIA");
			} else {
				System.out.println("Case #" + c + ": " + answer);
			}
		}
		
	}
	public static long getLastNum(long base) {
		
		if(base == 0) {
			return -1;
		}
		
		boolean[] soFar = new boolean[10];
		
		//long base = 1692;
		int mult = 0;
		while(!isFinished(soFar)) {
			mult++;
			updateDigits(soFar,base*mult);
		}
		return base*mult;
	}
	public static boolean isFinished(boolean[] soFar) {
		boolean result = true;
		for(Boolean b : soFar) {
			result &= b;
		}
		return result;
	}
	public static void updateDigits(boolean[] soFar, long n) {
		while(n>0) {
			int digit = (int)(n%10);
			soFar[digit] = true;
			n/=10;
		}
	}
}
