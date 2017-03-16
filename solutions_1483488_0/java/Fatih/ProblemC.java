import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class ProblemC {

	ProblemC() throws IOException {
		
		Scanner reader = new Scanner(new File("input.txt"));
		BufferedWriter writer = new BufferedWriter(new FileWriter("output.txt"));
		
		int cases = reader.nextInt();
		
		for(int i = 1; i <= cases; i++) {
			int A = reader.nextInt();
			int B = reader.nextInt();
			int mask = (int)Math.pow(10, (int)Math.log10(A));
			int count = 0;
			for(int j = A; j < B; j++) {
				int num = (j%mask)*10+j/mask;
				while(num!=j) {
					if(num>j && num <= B) ++count;
					num = (num%mask)*10+num/mask;
				}
			}			
			writer.write("Case #"+i+": "+count);
			writer.newLine();
		}
		
		reader.close();
		writer.close();
	}
	
	public static void main(String[] args) throws IOException {
		new ProblemC();
	}
}
