import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;


public class ProblemC {

	public static void main(String args[]) throws Exception{
		File file = new File("data/C-large-1.in");
		BufferedReader reader = new BufferedReader(new FileReader(file));
		int numberOfTestcase = Integer.parseInt(reader.readLine());
		
		double max = 1;
		for (int i = 0; i < numberOfTestcase; i++){
			String line = reader.readLine();
			String[] elements = line.split(" ");
			double A = Double.parseDouble(elements[0]);
			double B = Double.parseDouble(elements[1]);
			if (B > max){
				max = B;
			}
		}
		reader.close();
		
		List<Double> good = new ArrayList<Double>();
		double limit =  Math.sqrt(max) + 1;
		for (long i = 1 ; i <= limit; i ++){
			if (isPalindrome(i) && isPalindrome(i * i)){
				good.add(1.0 * i * i);
			}
		}
		
		reader = new BufferedReader(new FileReader(file));
		reader.readLine();
		for (int i = 0; i < numberOfTestcase; i++){
			String line = reader.readLine();
			String[] elements = line.split(" ");
			double A = Double.parseDouble(elements[0]);
			double B = Double.parseDouble(elements[1]);

			int count = 0;
			for (Double number : good){
				if (number >= A && number <= B){
					count++;
				}
			}
			System.out.println("Case #" + (i + 1) + ": " + count);
			
		}
		reader.close();
		
	}

	public static boolean isPalindrome(String str) {
		return str.equals(new StringBuilder(str).reverse().toString());
	}
	
	public static boolean isPalindrome(long number) {
		return isPalindrome(Long.toString(number));
	}
}
