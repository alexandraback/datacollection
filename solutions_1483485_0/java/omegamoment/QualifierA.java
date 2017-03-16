package qualifiers;

import java.io.*;
import java.util.*;
import java.util.concurrent.*;

public class QualifierA {
	class Task implements Runnable {
		private int num;
		private String line;

		public Task(int num, String line) {
			this.num = num;
			this.line = line;
		}

		@Override
		public void run() {
			StringBuilder result = new StringBuilder();

			// BEGIN RESULT COMPUTATION
			// ------------------------------------------------------------

			for (char c : line.toCharArray()) {
				result.append(map.get(c));
			}

			// END RESULT COMPUTATION
			// ------------------------------------------------------------

			System.out.println(result);
			reportResult(num, result.toString());
		}
	}

	public static final int NUM_THREADS = 1;
	
	public static final String gline = "ejp mysljylc kd kxveddknmc re jsicpdrysi" +
										"rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd" +
										"de kr kd eoya kw aej tysr re ujdr lkgc jv";
	
	public static final String eline = "our language is impossible to understand" +
										"there are twenty six factorial possibilities" +
										"so it is okay if you want to just give up";

	private String file_name;
	private ArrayList<String> results;
	
	private HashMap<Character, Character> map;

	public QualifierA(String file_name) {
		this.file_name = file_name;
	}

	public ArrayList<String> calculate() throws IOException,
			InterruptedException {
		results = new ArrayList<String>();
		ThreadPoolExecutor tpe = new ThreadPoolExecutor(NUM_THREADS,
				NUM_THREADS, 2, TimeUnit.SECONDS,
				new LinkedBlockingQueue<Runnable>());
		FileReader fr = new FileReader(file_name);
		BufferedReader br = new BufferedReader(fr);
		String line = br.readLine();
		System.out.println("Header: " + line);
		String[] ints = line.split(" ");

		// BEGIN HEADER PARSING
		// --------------------------------------------------------------------

		int total_num = Integer.parseInt(ints[0]);
		map = new HashMap<Character, Character>();
		map.put('y', 'a');
		map.put('e', 'o');
		map.put('q', 'z');
		map.put('z', 'q');
		for (int i = 0; i < gline.length(); ++i) {
			map.put(gline.charAt(i), eline.charAt(i));
		}

		// END HEADER PARSING
		// --------------------------------------------------------------------

		for (int i = 0; i < total_num; ++i) {
			results.add("");

			// BEGIN READING CASE
			// ----------------------------------------------------------------

			line = br.readLine();
			tpe.execute(new Task(i, line));

			// END READING CASE
			// ----------------------------------------------------------------

		}

		br.close();
		fr.close();
		tpe.shutdown();
		tpe.awaitTermination(8, TimeUnit.MINUTES);
		return results;
	}

	public synchronized void reportResult(int num, String result) {
		results.set(num, result);
	}

	public static void main(String[] args) throws IOException,
			InterruptedException {
		long time0 = System.currentTimeMillis();
		if (args.length < 1) {
			System.out.println("Remember command line argument");
			System.exit(1);
		}
		QualifierA runner = new QualifierA(args[0]);
		ArrayList<String> results = runner.calculate();
		System.out.println("Run time: " + (System.currentTimeMillis() - time0)
				/ 1000 + "s\n");
		FileWriter fw = new FileWriter("results.txt");
		BufferedWriter bw = new BufferedWriter(fw);
		for (int i = 0; i < results.size(); ++i) {
			System.out.println("Case #" + (i + 1) + ": " + results.get(i));
			bw.write("Case #" + (i + 1) + ": " + results.get(i) + "\n");
		}
		bw.close();
		fw.close();
	}
}
