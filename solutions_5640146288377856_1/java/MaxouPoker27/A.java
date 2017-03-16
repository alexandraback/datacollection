package round1C_LADERNIERECHANCE;

import java.io.File;
import java.io.PrintWriter;
import java.util.Locale;
import java.util.Scanner;
import java.util.concurrent.Callable;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.Future;

public class A {

	int R, C, W;

	public A(Scanner in) {
		R = in.nextInt();
		C = in.nextInt();
		W = in.nextInt();
	}



	public String solve(){
		int res = 0;
		if(R > 1){
			res += (C / W) * R;
			res -= 1;
		}
		else{
			res += (C / W) - 1;
		}
		if(C % W != 0) res++;
		res += W;
		return res+"";
	}

	@SuppressWarnings("unchecked")
	public static void main(String[] args) throws Exception {
		String filename = "A-large";
		Locale.setDefault(Locale.US);
		Scanner in = new Scanner(new File(filename + ".in"));
		PrintWriter out = new PrintWriter(new File(filename + ".teub"));

		int nbTests = in.nextInt();
		in.nextLine();
		int nbThreads = Runtime.getRuntime().availableProcessors() + 1;

		ExecutorService pool = Executors.newFixedThreadPool(nbThreads);
		Future<String> resultat[] = new Future[nbTests];
		for(int n = 1; n <= nbTests; n++){
			final A test = new A(in);
			final int numTest = n;
			resultat[n - 1] = pool.submit(new Callable<String>() {
				@Override
				public String call() throws Exception {
					String solution = test.solve();
					return "Case #"+numTest+": " + solution;	
				}
			});

		}
		for(int i = 0; i < nbTests; i++){
			out.println(resultat[i].get());
		}
		in.close();
		out.close();
		pool.shutdown();
	}
}
