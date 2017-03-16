package gcj2013.round1a;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.PrintStream;
import java.util.Arrays;
import java.util.Comparator;
import java.util.Locale;
import java.util.StringTokenizer;

public class B {
	private static final String PROBLEM_SET = "large-0";
	private static final String DATA_FOLDER = B.class.getPackage().getName()
			.replace('.', '/');
	private static final String DATA_FILE_PREFIX = DATA_FOLDER + "/"
			+ B.class.getSimpleName() + "-" + PROBLEM_SET + ".";

	public B() {
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
				long E = Long.parseLong(st.nextToken());
				long R = Long.parseLong(st.nextToken());
				int N = Integer.parseInt(st.nextToken());
				final long[] v = new long[N];
				Integer[] ids = new Integer[N];
				st = new StringTokenizer(reader.readLine());
				for(int i = 0; i < N; i++) {
					v[i] = Long.parseLong(st.nextToken());
					ids[i] = i;
				}
				
				Arrays.sort(ids, new Comparator<Integer>() {

					@Override
					public int compare(Integer o1, Integer o2) {
						return Long.compare(v[o2.intValue()], v[o1.intValue()]);
					}
					
				});
				
				long[] maximum = new long[N];
				long[] minimum = new long[N];
				Arrays.fill(maximum, E);
				long max = 0;
				
				for(int id : ids) {
					//System.out.println(Math.max(0, maximum[id] - minimum[id]));
					max += v[id] * Math.max(0, maximum[id] - minimum[id]);
					for(int i = id + 1; i < N; i++) {
						maximum[i] = Math.min(E, Math.min(maximum[i], minimum[id] + R * (i - id)));
					}
					for(int i = id - 1; i >= 0; i--) {
						minimum[i] = Math.max(0, Math.max(minimum[i], maximum[id] - R * (id - i)));
					}
					//System.out.println(Arrays.toString(maximum));
					//System.out.println(Arrays.toString(minimum));
					//System.out.println();
				}
				
				writer.printf("Case #%d: %d\n", t, max);
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
		new B();
	}

}
