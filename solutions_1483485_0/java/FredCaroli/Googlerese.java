import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStreamReader;


public class Googlerese {
	
	private static String in;
	private static BufferedReader buf;
	private static int cases;
	private static char[] decode = {'y', 'h', 'e', 's', 'o', 'c', 'v', 'x', 'd', 'u', 'i', 'g', 'l', 'b', 'k', 'r', 'z', 't', 'n', 'w', 'j', 'p', 'f', 'm', 'a', 'q'};
	private static File arquivo = new File("output.txt");
	private static FileOutputStream fos;
	
	public static void main(String[] args) {
		try {
			fos = new FileOutputStream(arquivo);
		} catch (FileNotFoundException e1) {
			e1.printStackTrace();
			System.exit(0);
		} 
		
		
		buf = new BufferedReader(new InputStreamReader(System.in));
		try {
			in = buf.readLine();
			cases = Integer.parseInt(in);
		} catch (IOException e) {
			e.printStackTrace();
			System.exit(0);
		}
		
		for(int i = 1; i <= cases; i++) {
			String result = new String();
			try {
				in = buf.readLine();
			} catch (IOException e) {
				e.printStackTrace();
				System.exit(0);
			}
			
			for (int j = 0; j < in.length(); j++) {
				if (in.charAt(j) != 32)
					result += decode[in.charAt(j) - 'a'];
				else 
					result += ' ';
			}
			
			try {
				String res = "Case #" + i + ": " + result + System.getProperty("line.separator");
				fos.write(res.getBytes());
			} catch (IOException e) {
				e.printStackTrace();
				System.exit(0);
			}
		
		}
		
	}

}
