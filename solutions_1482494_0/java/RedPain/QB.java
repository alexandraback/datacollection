import java.io.BufferedWriter;
import java.io.File;
import java.io.IOException;
import java.nio.charset.StandardCharsets;
import java.nio.file.FileSystems;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.StandardOpenOption;
import java.util.Scanner;

public class QB {
	public static int a[] = new int[1000];
	public static int b[] = new int[1000];
	public static int cal(Scanner sc){
		int result = 0;
		int N = sc.nextInt();
		int totalStar = 2*N;
		
		for(int i=0; i<N; i++){
			a[i] = sc.nextInt();
			b[i] = sc.nextInt();
		}
		
		int curStar = 0;
	
		boolean found = true;
		do{
			found = true;
			while(found){
				found = false;
		
				for(int i=0; i<N; i++){
					if(b[i] >= 0 && b[i] <= curStar){
						if(a[i] > -1){
							a[i] = -1;
							curStar++;
						}
						b[i] = -1;
						curStar++;
						found = true;
						result++;
						if(curStar == totalStar)
							return result;
					}
				}
			}
		
			for(int i=0; i<N; i++){
				if(a[i] >= 0 && a[i] <= curStar){
					a[i] = -1;
					curStar++;
					result++;
					found = true;
					if(curStar == totalStar)
						return result;
					break;
				}
			}
		} while(found);
		
		return -1;
	}
	public static void main ( String [] args ) throws IOException
	{
		Scanner sc = new Scanner(new File("B-small-attempt1.in"));
		Path file = FileSystems.getDefault().getPath(".", "B-small.out");
		BufferedWriter writer = Files.newBufferedWriter(file, StandardCharsets.US_ASCII, StandardOpenOption.CREATE);
		
		int t = sc.nextInt();
		for(int i=0; i<t; i++){
			int result = cal(sc);
			String output = null;
			if(result < 0)
				output = String.format("Case #%d: Too Bad\n", i+1);
			else
				output = String.format("Case #%d: %d\n", i+1, result);
			writer.write(output);
		}
		sc.close();
		
		writer.flush();
		writer.close();
	}
}