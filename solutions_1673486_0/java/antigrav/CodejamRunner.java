package codejam2;

import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.Date;
import java.util.Scanner;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.TimeUnit;

public abstract class CodejamRunner {
	public static final int NUM_WORKERS = 4;
	public static final int TIMEOUT_MINUTES = 10;
	
	// Default behavior is to get number of test cases that follow
	public int preparse(Scanner s) {
		String line = s.nextLine();
		return new Scanner(line).nextInt();
	}
	
	public abstract CodejamCase parseCase(Scanner s);
	
	public void run(String[] args) {
		Date start = new Date();
		// Set up worker threads
		ExecutorService es = Executors.newFixedThreadPool(args.length > 0 ? NUM_WORKERS : 1);
		
		// Read in file one test at a time and put in work queue
		try {
			Scanner s = new Scanner(new FileInputStream(args.length > 0 ? args[0] : "sample"));
			PrintStream o = args.length > 0 ? 
					new PrintStream(new FileOutputStream(args[0]+ ".output")) :
					System.out;

			final CodejamCase[] tests;
			int numTests = preparse(s);
			if (numTests == -1) {
				ArrayList<CodejamCase> t = new ArrayList<CodejamCase>();
				CodejamCase c;
				while (true) {
					c = parseCase(s);
					if (c == null)
						break;
					t.add(c);
				}
				tests = t.toArray(new CodejamCase[0]);
				numTests = tests.length;
			}
			else {			
				tests = new CodejamCase[numTests];
				for (int i = 0; i < numTests; i++)
					tests[i] = parseCase(s);
			}
			
			for (int i = 0; i < numTests; i++) {
				final int id = i;
				es.execute(new Runnable() {
					@Override
					public void run() {
						tests[id].compute();
						System.err.print(id + " ");
					}
				});
			}

			// Wait until work queue is empty
			try {
				es.shutdown();
				if (!es.awaitTermination(TIMEOUT_MINUTES, TimeUnit.MINUTES)) {
					System.err.println("Timeout! " + es.shutdownNow().size() + " tests incomplete.");
				}
			} catch (InterruptedException e) {
				System.err.println("Interrupted!");
				e.printStackTrace();
			}

			// Output results
			for (int i = 0; i < numTests; i++) {
				o.println("Case #" + (i+1) + ": " + tests[i].getOutput());
			}
			o.close();
				
		} catch (IOException e) {
			System.err.println("IO error!");
			e.printStackTrace();
		}

		System.err.println("\nExecution time: " + (new Date().getTime() - start.getTime()) + "(ms)");
		System.exit(0);
	}
	
	public static String padInt(int num, int len) {
		String s = "00000000000" + String.valueOf(num);
		return s.substring(s.length()-4);
	}
	
	public static int lcm(int ax, int ay) {
		if (ax == 0 || ay == 0)
			return 0;
		return ax*ay/gcd(ax, ay);
	}

	public static int gcd(int x, int y) {
		if (y == 0)
			return x;
		else 
			return gcd(y, x%y);

	}

}
