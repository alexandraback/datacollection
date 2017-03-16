import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Arrays;


public class MainClass {

	public static void main(String[] args) throws IOException, InterruptedException {
		BufferedReader fr = new BufferedReader(new FileReader(new File("input.txt")));
		FileWriter fw = new FileWriter(new File("result.txt"));
		String firstLine = fr.readLine();
		int nbCases = Integer.parseInt(firstLine);
		for (int i =0; i<nbCases; i++){

			String line = fr.readLine();
			final long N = Long.parseLong(line);
			
			long nbSteps = (N%10==0)?(getNbSteps(N-1)+1): getNbSteps(N);
			long counter = 0;
			
			
			fw.write("Case #"+(i+1)+": "+nbSteps+"\n");
			
		}
		fw.close();
		System.out.println("finished");
	}

	private static long getNbSteps(long N) {
		long nbSteps =0;
		
		long c =1;
		long lc =0;
		while (c*10<N){
			c*=10;
			lc++;
		}
		
		
		nbSteps = F(c,lc);
		
		long nbCh = lc+1;
		long lc1 = (nbCh+1)/2;
		long r1 = 1;
		for (int j =0; j<lc1; j++){
			r1*=10;
		}
		
		nbSteps+=N%r1;
		
		long n2 = N/r1;
		
		long reverseN2=0;
		while (n2!=0){
			reverseN2*=10;
			reverseN2+=n2%10;
			n2/=10;
			
		}
		if (reverseN2!=1){
			nbSteps+=reverseN2;
			
		}
		return nbSteps;
	}

	private static long F(long n,long lc) {
		if (n==1){
			return 0;
		}
		if (n==10){
			return 10;
		}
		long res = F(n/10,lc-1);
		long lc1 = (lc+1)/2;
		long lc2 = lc/2;
		long r1 = 1;
		long r2 = 1;
		for (int i =0; i<lc1; i++){
			r1*=10;
		}
		for (int i =0; i<lc2; i++){
			r2*=10;
		}
		
		return res+r1+r2-1;
	}

}
