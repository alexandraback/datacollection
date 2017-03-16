package Jam2014.Round1B;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.Stack;


public class Problem2 {

	public static void main(String[] args) {
		try {
			//String file = "problem_b_test";
			String file = "B-small-attempt0";
			//String file = "B-large";
			FileReader fr = new FileReader(file + ".in");
			BufferedReader br = new BufferedReader(fr);
			FileWriter fw = new FileWriter(file + ".out");
			BufferedWriter bw = new BufferedWriter(fw);
			String line;
			line = br.readLine();
			int cases = Integer.parseInt(line);
			String words[];
			for(int i=0; i<cases; i++) {
				line = br.readLine();
				words = line.split(" ");
				long A = Integer.parseInt(words[0]);
				long B = Integer.parseInt(words[1]);
				long K = Integer.parseInt(words[2]);
				bw.write("Case #" + (i+1)+": " + count(A,B,K));
				bw.write("\n");
			}
			br.close();
			bw.close();
		} catch(Exception e) {
			e.printStackTrace();
		}
	}
	
	public static long count(long A, long B, long K) {
		long c = 0;
		for(long i=0; i<A; i++) {
			for(long j=0; j<B; j++) {
				long t = i&j;
				if(t < K) c++; 
			}
		}
		return c;
	}
}
