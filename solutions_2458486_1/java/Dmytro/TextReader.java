

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;

public class TextReader {
	
	static public String read(String filename) throws IOException
	{
		String str = null;
		BufferedReader br = new BufferedReader(new FileReader(filename));
		try {
			StringBuilder sb = new StringBuilder();
			String line = br.readLine();
	        while (line != null) {
	            sb.append(line);
	            sb.append('\n');
	            line = br.readLine();
	        }
	        str = sb.toString();
		} finally {
			br.close();	
		}
		return str;
	}
}
