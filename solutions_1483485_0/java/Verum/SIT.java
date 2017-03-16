import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.PrintWriter;
import java.util.Scanner;


public class SIT {
	static void log(String fs, Object... args) {
		System.err.println(String.format(fs, args));
	}


	public static void main(String[] args) throws FileNotFoundException {
		String filename = "src/data/A-small-attempt0.in";
		Scanner sc = 
				new Scanner(
						new FileInputStream(
								new File(filename)));
		PrintWriter pw = 
				new PrintWriter(
						new FileOutputStream(
								new File(filename + ".result")));
		
		String convert = "ynficwlbkuomxsevzpdrjgthaq";

		int N = sc.nextInt();
		sc.nextLine();
		for (int task = 1; task <= N; task++) {
			String s = sc.nextLine();
			log("%s", s);
			
			StringBuilder sb = new StringBuilder();
			for (char c : s.toCharArray()) {
				if (c != ' ') {
					int d = convert.indexOf(c);
					if (d == -1)
						sb.append('*');
					else
						sb.append((char)(d+'a'));
					
				}
				else
					sb.append(' ');
			}
			log("%s", sb.toString());
			log("");
			
			pw.println(String.format("Case #%d: %s", task, sb.toString()));
		}
	
		pw.close();
	}
}
