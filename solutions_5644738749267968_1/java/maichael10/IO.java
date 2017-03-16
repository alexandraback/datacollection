/**
 * 
 */
package general;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;

/**
 * @author michael
 *
 */
public class IO {

	public static BufferedReader loadFile(String fileName) throws FileNotFoundException {
		File file = new File("./data/" + fileName + ".in");
		FileInputStream fis = new FileInputStream(file);
		BufferedReader red = new BufferedReader(new InputStreamReader(fis));
		return red;
	}

	public static PrintWriter openFile(String fileName) throws FileNotFoundException {
		File file = new File("./data/" + fileName + ".out");
		if (file.exists()) file.delete();
		FileOutputStream fos = new FileOutputStream(file);
		PrintWriter wr = new PrintWriter(fos, true);
		return wr;
	}

	public static Object[] openIO(String fileName) throws IOException {

		
		return new Object[] { loadFile(fileName) , openFile(fileName)};
	}
}
