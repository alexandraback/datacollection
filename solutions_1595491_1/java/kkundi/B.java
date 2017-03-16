import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.io.Writer;
import java.util.Scanner;


public class B {
	static String CASE = "Case #";
	static String N_L = System.getProperty("line.separator");
	
	static int T, N, S, p;
	
	public static void main(String[] args) {
		String input = "file/B-large.in";
		String output = "file/B-large.txt";
		
		run(input, output);
	}
	
	public static void run(String input, String output) {
		Scanner sc = null;
		Writer writer = null;
		StringBuilder result = new StringBuilder();
		
		try {
			sc = new Scanner(new FileInputStream(input));
			writer = new OutputStreamWriter(new FileOutputStream(output));
			
			T = sc.nextInt();
			
			for(int i = 1; i <= T; i++) {
				N = sc.nextInt();
				S = sc.nextInt();
				p = sc.nextInt();
				
				int total = 0;
				int curS = 0;
				for(int j = 0; j < N; j++) {
					int t = sc.nextInt();
					int min = t / 3;
					
					if(min >= p) {
						total++;
						continue;
					}
					
					if(t % 3 == 0) {
						if(curS >= S) {
							continue;
						}
						
						if(min+1 >= p && t >= 3) {
							curS++;
							total++;
						}
					} else {
						if(min+1 >= p) {
							total++;
							continue;
						}
						
						if(t % 3 == 2) {
							if(curS >= S) {
								continue;
							}
							
							if(min+2 >= p && t >= 2) {
								curS++;
								total++;
							}
						}
					}
				}
				
				result.append(CASE).append(i).append(": ").append(total);
				if(i != T) {
					result.append(N_L);
				}
				writer.write(result.toString());
				result.setLength(0);
			}
			writer.flush();
			
		} catch(IOException e) {
			e.printStackTrace();
		} finally {
			sc.close();
			try {
				writer.close();
			} catch (IOException e) {
				e.printStackTrace();
			}
		}
	}
}
