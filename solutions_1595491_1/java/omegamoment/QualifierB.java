package qualifiers;

import java.io.*;
import java.util.*;
import java.util.concurrent.*;

public class QualifierB {
	class Task implements Runnable {
		private int num;
		private String line;

		public Task(int num, String line) {
			this.num = num;
			this.line = line;
		}

		@Override
		public void run() {
			String result = null;

			// BEGIN RESULT COMPUTATION
			// ------------------------------------------------------------

			String[] split_line = line.split(" ");
			int num_googlers = Integer.parseInt(split_line[0]);
			int num_surprising = Integer.parseInt(split_line[1]);
			int best_points = Integer.parseInt(split_line[2]);
			int count = 0;
			for (int j = 0; j < num_googlers; ++j) {
				int total_points = Integer.parseInt(split_line[j + 3]);
				total_points -= best_points;
				if (total_points < 0) {
					continue;
				}
				if (best_points * 2 - 2 <= total_points) {
					++count;
					continue;
				}
				if (num_surprising > 0) {
					if ((best_points - 2) * 2 <= total_points && total_points <= (best_points + 2) * 2) {
						++count;
						--num_surprising;
					}
				}
			}
			
			result = String.valueOf(count);

			// END RESULT COMPUTATION
			// ------------------------------------------------------------

			System.out.println(result);
			reportResult(num, result);
		}
	}

	public static final int NUM_THREADS = 4;

	private String file_name;
	private ArrayList<String> results;

	public QualifierB(String file_name) {
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
		QualifierB runner = new QualifierB(args[0]);
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
