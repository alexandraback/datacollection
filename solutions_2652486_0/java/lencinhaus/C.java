package gcj2013.round1a;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.PrintStream;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Locale;
import java.util.Map;
import java.util.Set;
import java.util.StringTokenizer;

public class C {
	private static final String PROBLEM_SET = "small1-0";
	private static final String DATA_FOLDER = C.class.getPackage()
			.getName().replace('.', '/');
	private static final String DATA_FILE_PREFIX = DATA_FOLDER + "/"
			+ C.class.getSimpleName() + "-" + PROBLEM_SET + ".";
	
	int[][] choices = new int[20][3];
	Map<Integer, Set<Integer>> products = new HashMap<Integer, Set<Integer>>();

	public C() {
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
			
			int curr = 0;
			for(int i1 = 2; i1 <= 5; i1++) {
				for(int i2 = i1; i2 <= 5; i2++) {
					for(int i3 = i2; i3 <= 5; i3++) {
						choices[curr][0] = i1;
						choices[curr][1] = i2;
						choices[curr][2] = i3;
						Set<Integer> prods = new HashSet<Integer>();
						prods.add(1);
						prods.add(i1);
						prods.add(i2);
						prods.add(i3);
						prods.add(i1 * i2);
						prods.add(i1 * i3);
						prods.add(i2 * i3);
						prods.add(i1 * i2 * i3);
						products.put(curr, prods);
						curr++;
					}
				}
			}
			
			reader.readLine();
			st = new StringTokenizer(reader.readLine());
			int R = Integer.parseInt(st.nextToken());
			int[] asd = new int[7];
			writer.println("Case #1:");
			for(int i = 0; i < R; i++) {
				st = new StringTokenizer(reader.readLine());
				for(int j = 0; j < 7; j++) {
					asd[j] = Integer.parseInt(st.nextToken());
				}
				for(int k = 0; k < 20; k++) {
					Set<Integer> prods = products.get(k);
					boolean good = true;
					for(int j = 0; j < 7; j++) {
						if(!prods.contains(asd[j])) {
							good = false;
							break;
						}
					}
					
					if(good) {
						for(int j = 0; j < 3; j++) {
							writer.print(choices[k][j]);
						}
						writer.println();
						break;
					}
				}
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
		new C();
	}

}
