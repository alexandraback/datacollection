package codejam;
import java.io.IOException;
import java.util.Arrays;

public class A extends CodeJam {

	public A(String file) throws Exception {
		super(file);
	}
	
	@Override
	public Object processCase(int caseNumber) throws Exception {
		String[] split = readLine().split(" ");
		
		String name = split[0];
		int n = Integer.parseInt(split[1]);
		
		int lenght = name.length();
		
		char[] charArray = name.toCharArray();
		
		long resultCount = 0;
		
		for (int i = 0; i < lenght; i++) {
			int currentCount = 0;
			for (int j = i; j < lenght; j++) {
				if (charArray[j] != 'a' && charArray[j] != 'e' && charArray[j] != 'i' &&charArray[j] != 'o' && charArray[j] != 'u') {
					currentCount++;
					if (currentCount >= n) {
						resultCount+=lenght-j;
						break;
					}
				} else {
					currentCount = 0;
					if (n+j > lenght) break;
				}
//				System.out.println(name.substring(i, j+1)+" "+currentCount);
				
			}
		}
		return resultCount;
	}
	
	public static void main(String[] args) throws IOException,
			InterruptedException, Exception {
		new A("A-small-attempt0.in").start();
		
	}
	
	
}
