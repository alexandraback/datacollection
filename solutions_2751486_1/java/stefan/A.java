import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;


public class A {
	public static final String FILENAME = "A-large";
	public static void main(String[] args) throws IOException {
		BufferedReader in = new BufferedReader(new FileReader("src/"+FILENAME+".in"));
		BufferedWriter out = new BufferedWriter(new FileWriter("src/"+FILENAME+".out"));
		Scanner s = new Scanner(in);
		int T = s.nextInt();
		s.nextLine();
		
		char[] vs = {'a', 'e', 'i', 'o', 'u'};
		boolean[] vmap = new boolean[26];
		for (int i = 0; i < vs.length; i++) {
			vmap[(int) vs[i]-97] = true;
		}
		
		for(int i = 1; i <= T; i++) {
			String w = s.next().toLowerCase();
			int n = s.nextInt();
			boolean[] v = new boolean[w.length()];
			for (int j = 0; j < v.length; j++) {
				v[j] = vmap[(int) w.charAt(j) - 97];
			}
			
			long ret = 0;
			int lasts = -1;
			int curr = 0;
			for (int j = v.length-1; j >= 0; j--) {
				if(!v[j]) {
					curr++;
				}
				else {
					curr = 0;
				}
				if(curr >= n) {
					lasts = j;
				}
				
				if(lasts > -1) {
					ret += v.length - (lasts + n - 1); 
				}
			}
			
			
			out.write("Case #"+i+": "+ret+"\n");
		}
		in.close();
		out.close();
	}
}
