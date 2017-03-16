import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.io.Writer;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;


public class C {
	static String CASE = "Case #";
	static String N_L = System.getProperty("line.separator");
	
	static int T, A, B;
	
	public static void main(String[] args) {
		String input = "file/C-large.in";
		String output = "file/C-large.txt";
		
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
			
			int one 	= 10;
			int two 	= 100;
			int three 	= 1000;
			int four	= 10000;
			int five	= 100000;
			int six	= 1000000;
			
			for(int i = 1; i <= T; i++) {
				A = sc.nextInt();
				B = sc.nextInt();
				
				Set<Integer> set = new HashSet<Integer>();
				int total = 0;
				
				int mask = 1;
				if(A >= one) {
					if(A < two) {
						mask = one;
					} else if(A < three) {
						mask = two;
					} else if(A < four) {
						mask = three;
					} else if(A < five) {
						mask = four;
					} else if(A < six) {
						mask = five;
					} else {
						mask = six;
					}
					for(int j = A; j <= B; j++) {
						if(set.contains(j)) {
							continue;
						}
						set.add(j);
						int div = j / mask;
						int res = j - (mask * div);
						int target = res * 10 + div;
						while(j != target) {
							if(target >= A && target <= B && !set.contains(target)) {
								total++;
							}
							div = target / mask;
							res = target - (mask * div);
							target = res * 10 + div;
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
