import java.util.*;
import java.math.*;

public class A {
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		int total = s.nextInt();
		int current = 1;
		while (current <= total) {
			String line = s.next();
			String tokens[] = line.split("/");			
			long p = Long.parseLong(tokens[0]);
			long q = Long.parseLong(tokens[1]);
			
			double x = (p+0.0)/q;
			int result = getGen(x);
			
			System.out.printf("Case #%d: %s\n", (current++), 
					(result>40)?"impossible":result);			
		}
	}
	
	static int getGen(double x) {
		double d = 1;
		
		int result = 0;
		while (d > x) {
			result++;
			if (result > 40) return result;
			d /= 2;
		}
		int remain = 0;
		if (x != d) 
			remain = getGen(x-d);
		return (remain > 40) ? 41 : result;
	}
}
