import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.*;

public class Recycle {
	
	public int count(int start, int end) {
		int count = 0;
		HashSet<Integer> numbers = new HashSet<Integer>();
		int numDigits = (int)Math.log10(start) + 1;
		
		for(int i = start; i <= end; i++) {
			HashSet<Integer> rotations = getRotations(i, numDigits);
			for(int r : rotations) {
				if(numbers.contains(r)) {
					count++;
				}
			}
			numbers.add(i);
		}
		
		
		return count;
	}
	
	
	public HashSet<Integer> getRotations(int input, int numDigits) {
		HashSet<Integer> result = new HashSet<Integer>();
		for(int i = 0; i < numDigits - 1; i++) {
			int power = (int)Math.pow(10, i+1);
			int edge = input % power;
			result.add( (input - edge) / power + edge * (int)Math.pow(10, numDigits - i - 1) );
		}
		
		return result;
	}
	
	public static void main(String args[]) {
		Recycle c = new Recycle();
		String result[] = null;
		
		
		try {
			Scanner sc = new Scanner(new FileInputStream("C:/Users/Administrator/Downloads/C-large.in"));
			String line = sc.nextLine().trim();
			int cases = Integer.parseInt(line);
			result = new String[cases];
			for(int i = 0; i < cases; i++) {
				line = sc.nextLine().trim();
				String temp[] = line.split(" ");
				int start = Integer.parseInt(temp[0]);
				int end = Integer.parseInt(temp[1]);
			
				result[i] = "Case #" + (i+1) + ": " + c.count(start, end);
			}
			
		} catch(Exception e) {
			e.printStackTrace();
		}
		
		try {
			 FileWriter fstream = new FileWriter("C:/out.txt");
			 PrintWriter out = new PrintWriter(fstream);
			 
			 for(int i = 0; i < result.length; i++) {
				 out.println(result[i]);
			 }
			 out.close();
		}catch(Exception e) {
			e.printStackTrace();
		}
	}
}
