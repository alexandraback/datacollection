package round1A;

import java.io.*;
import java.util.*;
import java.util.concurrent.*;

public class Round1AB {
	class Task implements Runnable {
		private int num;
		private int num_levels;
		private int[] for1;
		private int[] for2;

		public Task(int num, int num_levels, int[] for1, int[] for2) {
			this.num = num;
			this.num_levels = num_levels;
			this.for1 = for1;
			this.for2 = for2;
		}

		@Override
		public void run() {
			String result = null;

			// BEGIN RESULT COMPUTATION
			// ------------------------------------------------------------

			if (num == 29) {
				int q = 1;
				++q;
			}
			int min_tries = tryLevel(0, 0, new boolean[num_levels], new boolean[num_levels]);
			if (min_tries < Integer.MAX_VALUE) {
				result = String.valueOf(min_tries);
			}
			else {
				result = "Too Bad";
			}

			// END RESULT COMPUTATION
			// ------------------------------------------------------------

			System.out.println(num + ": " + result);
			reportResult(num, result);
		}
		
		public int tryLevel(int num_stars, int num_tries, boolean[] got1, boolean[] got2) {
			if (num_stars == 2 * num_levels) {
				return num_tries;
			}
			boolean found = false;
			int min_tries = Integer.MAX_VALUE;
			for (int level = 0; level < num_levels; ++level) {
				if (!got2[level] && !got1[level] && num_stars >= for2[level]) {
					found = true;
					got1[level] = true;
					got2[level] = true;
					int total_tries = tryLevel(num_stars + 2, num_tries + 1, got1, got2);
					if (total_tries < min_tries) {
						min_tries = total_tries;
					}
					got1[level] = false;
					got2[level] = false;
				}
			}
			if (found && min_tries < Integer.MAX_VALUE) {
				return min_tries;
			}
			for (int level = 0; level < num_levels; ++level) {
				if (!got2[level] && got1[level] && num_stars >= for2[level]) {
					found = true;
					got2[level] = true;
					int total_tries = tryLevel(num_stars + 1, num_tries + 1, got1, got2);
					if (total_tries < min_tries) {
						min_tries = total_tries;
					}
					got2[level] = false;
				}
			}
			if (found && min_tries < Integer.MAX_VALUE) {
				return min_tries;
			}
			for (int level = 0; level < num_levels; ++level) {
				if (!got1[level] && num_stars >= for1[level]) {
					found = true;
					got1[level] = true;
					int total_tries = tryLevel(num_stars + 1, num_tries + 1, got1, got2);
					if (total_tries < min_tries) {
						min_tries = total_tries;
					}
					got1[level] = false;
				}
			}
			return min_tries;
		}
	}

	public static final int NUM_THREADS = 1;

	private String file_name;
	private ArrayList<String> results;

	public Round1AB(String file_name) {
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

		// END HEADER PARSING
		// --------------------------------------------------------------------

		for (int i = 0; i < total_num; ++i) {
			results.add("");

			// BEGIN READING CASE
			// ----------------------------------------------------------------

			line = br.readLine();
			int num_levels = Integer.parseInt(line);
			int[] for1 = new int[num_levels];
			int[] for2 = new int[num_levels];
			for (int j = 0; j < num_levels; ++j) {
				line = br.readLine();
				String[] split_line = line.split(" ");
				for1[j] = Integer.parseInt(split_line[0]);
				for2[j] = Integer.parseInt(split_line[1]);
			}
			tpe.execute(new Task(i, num_levels, for1, for2));

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
		Round1AB runner = new Round1AB(args[0]);
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
