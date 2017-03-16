import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.HashMap;
import java.util.Map;

public class RecycledNumbers {
	public static void main(String[] args) {
		int cases = 0, a = 0, b = 0, answer = 0;

		String in = "C-large";
		
		try {
			BufferedReader br = readFile(new FileReader(in + ".in"));
			FileWriter fstream = new FileWriter(in + ".out");
			BufferedWriter out = new BufferedWriter(fstream);
			
			String inline;
			int i = 0;
			while ((inline = br.readLine()) != null) {
				if (i++ == 0) {
					cases = Integer.parseInt(inline);
				} else {
					String result = "Case #" + (i - 1) + ": ";
					String[] input = inline.trim().split(" ", 2);
					answer = 0;
						
					a = Integer.parseInt(input[0].trim());
					b = Integer.parseInt(input[1].trim());
					
					if (b > 10) {
						int sub = 0;
						Map<String, Object> map = new HashMap<String, Object>();
						for (int n=a; n<=b; n++) {
							if (n < 10) {n = 10; continue;}
							
							String sn	= String.valueOf(n);
							sub			= sn.length();
							int m		= 0;
							
							for (int o=0; o<sub-1; o++) {
								String m1 = sn.substring((sub-1) - o);
								String m2 = sn.substring(0, (sub-1) - o);
								
								m = Integer.parseInt(m1 + m2);
								
								if (m > n 
										&& m <= b
										&& !map.containsKey(n + "," + m)) {
									//System.out.println(n + "," + m);
									map.put(n + "," + m, n + "," + m);
									answer++;
								}
								
							}
						}
					}
					
					writeOutput(result + answer, out);
				}
			}
			out.close();
		} catch(Exception e) {
			e.printStackTrace();
		}
	}
	
	private static BufferedReader readFile(FileReader in) throws FileNotFoundException {
		return new BufferedReader(in);
	}
	
	private static void writeOutput(String text, BufferedWriter out) throws IOException {
		out.write(text);
		out.write("\n");
	}
}
