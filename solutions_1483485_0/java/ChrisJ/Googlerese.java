import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;


public class Googlerese {

	private static final String table =
		/*  abcdefghijklmnopqrstuvwxyz */
		   "yhesocvxduiglbkrztnwjpfmaq";
	
	private static char translate(char c) {
		if(c >= 'a' && c <= 'z') {
			return table.charAt(c - 'a');
		} else {
			return c;
		}
	}
	
	private static String translate(String s) {
		StringBuilder res = new StringBuilder();
		
		for(int i=0; i<s.length(); i++) {
			res.append(translate(s.charAt(i)));
		}
		
		return res.toString();
	}
	
	public static void main(String[] args) throws IOException {
		for(char j='a'; j<'z'; j++) {
			if(!table.contains(Character.toString(j))) {
				System.out.println("! " + ((char)j));
			}
		}
		
		BufferedReader in = new BufferedReader(new FileReader(args[0]));
		PrintWriter out = new PrintWriter(args[1]);
		
		// number of testcases
		in.readLine();
		int idx = 1;
		
		String l;
		while((l = in.readLine()) != null) {
			out.println("Case #" + idx + ": " + translate(l));
			idx++;
		}
		
		out.close();
	}

}
