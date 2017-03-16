package gcj2013.round1a;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.PrintStream;
import java.util.Locale;
import java.util.StringTokenizer;

public class A {
	private static final String PROBLEM_SET = "small-0";
	private static final String DATA_FOLDER = A.class.getPackage()
			.getName().replace('.', '/');
	private static final String DATA_FILE_PREFIX = DATA_FOLDER + "/"
			+ A.class.getSimpleName() + "-" + PROBLEM_SET + ".";

	public A() {
		Locale.setDefault(Locale.US);
		BufferedReader reader = null;
		PrintStream writer = null;
		try {
			copyFilesToOutputFolder("src/"
					+ getClass().getName().replace('.', '/') + ".java");
			StringTokenizer st;
			reader = new BufferedReader(new FileReader(DATA_FILE_PREFIX + "in"));
			if ("test".equals(PROBLEM_SET))
				writer = System.out;
			else
				writer = new PrintStream(DATA_FILE_PREFIX + "out");

			int T = Integer.parseInt(reader.readLine());
			for (int t = 1; t <= T; t++) {
				st = new StringTokenizer(reader.readLine());
				double r = Double.parseDouble(st.nextToken());
				double c = - Double.parseDouble(st.nextToken());
				double a = 2;
				double b = 2 * r - 1;
				double k = (-b + Math.sqrt(b*b - 4 * a * c)) / (2 * a);
				
				writer.printf("Case #%d: %d\n", t, new Double(Math.floor(k)).longValue());
			}
		} catch (Exception ex) {
			ex.printStackTrace();
		} finally {
			try {
				if (reader != null)
					reader.close();
				if (writer != null)
					writer.close();
			} catch (Exception ex) {
				ex.printStackTrace();
			}
		}
	}

	private static void copyFilesToOutputFolder(String... paths)
			throws Exception {
		byte[] buffer = new byte[4096];
		int read;
		FileInputStream is = null;
		FileOutputStream os = null;
		File dataFolderFile = new File(DATA_FOLDER);
		for (String path : paths) {
			File sourceFile = new File(path);
			File outputFile = new File(dataFolderFile, sourceFile.getName());
			try {
				is = new FileInputStream(sourceFile);
				os = new FileOutputStream(outputFile);
				while ((read = is.read(buffer)) != -1) {
					os.write(buffer, 0, read);
				}
			} finally {
				if (is != null) {
					is.close();
					is = null;
				}
				if (os != null) {
					os.close();
					os = null;
				}
			}
		}
	}

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		new A();
	}

}
