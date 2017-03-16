package round1A;

import java.io.*;
import java.util.*;
import java.util.concurrent.*;

public class Round1AA {
	class Task implements Runnable {
		private int num;
		private int num_typed;
		private int total_chars;
		private double[] probs;

		public Task(int num, int num_typed, int total_chars, double[] probs) {
			this.num = num;
			this.num_typed = num_typed;
			this.total_chars = total_chars;
			this.probs = probs;
		}

		@Override
		public void run() {
			String result = null;

			// BEGIN RESULT COMPUTATION
			// ------------------------------------------------------------

			// finish as is
			double success_prob = 1.0;
			for (double prob : probs) {
				success_prob *= prob;
			}
			int num_if_success = total_chars - num_typed + 1;
			double best_expected =
					num_if_success * success_prob + (num_if_success + total_chars + 1) * (1.0 - success_prob);
			
			// press enter immediately
			double expected = total_chars + 2;
			if (expected < best_expected) {
				best_expected = expected;
			}
			
			// backspace some number of times
			for (int back_to = num_typed - 1, num_back = 1; back_to > 0; --back_to, ++num_back) {
				success_prob /= probs[back_to];
				num_if_success = total_chars - num_typed + 2 * num_back + 1;
				expected = num_if_success * success_prob + (num_if_success + total_chars + 1) * (1.0 - success_prob);
				if (expected < best_expected) {
					best_expected = expected;
				}
			}
			result = String.valueOf(best_expected);

			// END RESULT COMPUTATION
			// ------------------------------------------------------------

			System.out.println(result);
			reportResult(num, result);
		}
	}

	public static final int NUM_THREADS = 1;

	private String file_name;
	private ArrayList<String> results;

	public Round1AA(String file_name) {
		this.file_name = file_name;
	}

	public ArrayList<String> calculate() throws IOException,
			InterruptedException {
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
		results = new ArrayList<String>(total_num);

		// END HEADER PARSING
		// --------------------------------------------------------------------

		for (int i = 0; i < total_num; ++i) {
			results.add("");

			// BEGIN READING CASE
			// ----------------------------------------------------------------

			line = br.readLine();
			String[] split_line = line.split(" ");
			int num_typed = Integer.parseInt(split_line[0]);
			int total_chars = Integer.parseInt(split_line[1]);
			line = br.readLine();
			split_line = line.split(" ");
			double[] probs = new double[num_typed];
			for (int j = 0; j < num_typed; ++j) {
				probs[j] = Double.parseDouble(split_line[j]);
			}
			tpe.execute(new Task(i, num_typed, total_chars, probs));

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
		Round1AA runner = new Round1AA(args[0]);
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
