import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class ProblemB {

	ProblemB() throws IOException {
		
		Scanner reader = new Scanner(new File("input.txt"));
		BufferedWriter writer = new BufferedWriter(new FileWriter("output.txt"));
		
		int cases = reader.nextInt();
		
		for(int i = 1; i <= cases; i++) {
			int n = reader.nextInt();
			int s = reader.nextInt();
			int p = reader.nextInt();
			int result = 0;
			for(int j = 0; j < n; j++) {
				int score = reader.nextInt();
				int max = (score+2)/3;
				if(max>=p)
					result++;
				else if(max==p-1 && score>1 && score<29 && score%3!=1 && s>0) {
					s--;
					result++;
				}
			}
			
			writer.write("Case #"+i+": "+result);
			writer.newLine();
		}
		
		reader.close();
		writer.close();
	}
	
	public static void main(String[] args) throws IOException {
		new ProblemB();
	}
}
