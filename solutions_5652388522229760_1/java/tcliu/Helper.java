package codejam.util;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintStream;
import java.nio.file.Paths;
import java.util.Scanner;

public class Helper {

	final Class<?> clazz;
	final String[] args;
	
	public Helper(Class<?> clazz, String[] args) {
		this.clazz = clazz;
		this.args = args;
	}
	
	public Scanner getScanner() {
		File dataDir = Paths.get("data", clazz.getPackage().getName().replace('.', '/')).toFile();
		File inputFile = new File(dataDir, (args.length > 0 ? args[0] : clazz.getSimpleName()) + ".in");
		try {
			InputStream is = inputFile.isFile() ? new FileInputStream(inputFile) : System.in;
			Scanner sc = new Scanner(is);
			return sc;
		} catch (IOException e) {
			return null;
		}
	}
	
	public PrintStream getPrintStream() {
		File dataDir = Paths.get("data", clazz.getPackage().getName().replace('.', '/')).toFile();
		if (!dataDir.isDirectory()) {
			dataDir.mkdirs();
		}
		File outputFile = new File(dataDir, (args.length > 0 ? args[0] : clazz.getSimpleName()) + ".out");
		try {
			return new PrintStream(new FileOutputStream(outputFile)) {

				@Override
				public PrintStream printf(String format, Object... args) {
					System.out.printf(format, args);
					return super.printf(format, args);
				}

			};
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
	}

}
