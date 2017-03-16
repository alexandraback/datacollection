import java.io.BufferedWriter;
import java.io.File;
import java.io.IOException;
import java.nio.charset.StandardCharsets;
import java.nio.file.FileSystems;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.StandardOpenOption;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Scanner;

public class QA {
	public static float p[] = new float[100000];
	
	public static float cal(Scanner sc){
		int A = sc.nextInt();
		int B = sc.nextInt();
		
		for(int i=0; i<A; i++){
			p[i] = sc.nextFloat();
		}
		
		float enterRightAway = 1 + B + 1;
		
		float correctP = 1.0f;
		for(int i=0; i<A; i++){
			correctP *= p[i];
		}
		float keepTyping = correctP*(B-A+1) + (1.0f-correctP)*(B-A+1+B+1);
		
		float min = Math.min(enterRightAway, keepTyping);
	
		correctP = 1.0f;
		for(int i=1; i<A; i++){
			correctP *= p[i-1];
			float cur = (A-i) + correctP*(B-i+1) + (1.0f-correctP)*(B-i+1+B+1);
			min = Math.min(min, cur);
		}
		
		return min;
	}
	public static void main ( String [] args ) throws IOException
	{
		Scanner sc = new Scanner(new File("A-small-attempt0.in"));
		Path file = FileSystems.getDefault().getPath(".", "A-large-practice.out");
		BufferedWriter writer = Files.newBufferedWriter(file, StandardCharsets.US_ASCII, StandardOpenOption.CREATE);
		
		int t = sc.nextInt();
		sc.nextLine();
		for(int i=0; i<t; i++){
			String output = String.format("Case #%d: %.6f\n", i+1, cal(sc));
			writer.write(output);
		}
		sc.close();
		
		writer.flush();
		writer.close();
	}
}