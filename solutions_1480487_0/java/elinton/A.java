package codejam;
import java.io.IOException;

public class A extends CodeJam {

	public A(String file) throws Exception {
		super(file);
		
	}

	@Override
	public Object processCase(int caseNumber) throws Exception {
		int[] numbers = readIntArray();
		
		double x = 0;
		
		double s = numbers.length-1;
		
		for (int i = 1; i < numbers.length; i++) {
			x+= numbers[i];	
			
		}
		
		StringBuilder result = new StringBuilder();
		
		for (int i = 1; i < numbers.length; i++) {
			double j = numbers[i];
			
			//Ji+X*Yi => Yi = -Ji/X
			
			double y = (1d - j/x)/(s-1d)*100d;
			if (i > 1) {
				result.append(' ');
			}
			result.append(y);
			
		}
		return result.toString();
	}

	public static void main(String[] args) throws IOException,
			InterruptedException, Exception {
		new A("A-small-attempt0.in").start();
	}
	
	
}
