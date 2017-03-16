import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;

import verethragna.cjutils.FileProcessor;

/**
 * @author Verethragna
 */

public class A_Main {
	public static void main(String[] args) {
		FileProcessor fp = new FileProcessor(true);
		BufferedWriter out = null;
		try {
			out = new BufferedWriter(new FileWriter("C:\\Users\\Verethragna\\Desktop\\A.out"));
		} catch (IOException e) {}
		for(int i = 0; i < fp.cases; i++){
			String[] in = fp.getStringArray();
			long r = Long.valueOf(in[0]);
			long t = Long.valueOf(in[1]);
			int x = 0;
			
			do{
				x++;
				t = t - (2*r + 1);
				r += 2;
			} while(t >= 0);
			
			try {
				out.write("Case #" + (i+1) + ": " + (x-1) + "\n");
			} catch (IOException e) {}
		}
		try {
			out.close();
		} catch (IOException e) {}
	}
}
