import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.StringTokenizer;


public class Consonants {

	private String input;
	private int number;
	private int count;

	public Consonants(String s) {
		StringTokenizer st = new  StringTokenizer(s, " ");
		input = st.nextToken();
		number = Integer.parseInt(st.nextToken());
	}
	/**
	 * @param args
	 * @throws IOException 
	 * @throws NumberFormatException 
	 */
	public static void main(String[] args) throws NumberFormatException, IOException {
		FileWriter f = new FileWriter("output.out");
		BufferedWriter b = new BufferedWriter(f);
		
		FileReader f1 = new FileReader("A-small-attempt0 (1).in");
		BufferedReader b1 = new BufferedReader(f1);
		
		int cas = Integer.parseInt(b1.readLine());
		for (int i = 1; i <= cas; i++) {
			Consonants c = new Consonants(b1.readLine());
			c.find();
			System.out.println("Case #" + i + ": " + c.count);
			b.write("Case #" + i + ": " + c.count);
			b.newLine();
		}
		b.close();
		
		
	}

	private void find() {
		for (int j = 0; j <= input.length() - number; j++) {
			for(int i=0; i<= (input.length() - number - j); i++) {
				String sub = input.substring(j, input.length() - i);
				int t = 0;
				for(int k = 0; k<sub.length(); k++) {
					char c = sub.charAt(k);
					if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
						if (t >= number) {
							count ++;
							t = 0;
							break;
						}else {
							t = 0;
						}
					}
					else {
						t ++;
					}
				}
				if(t >= number) {
					count ++;
				}
			}
		}
	}

}
