import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.DataInputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileWriter;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;


public class Problem1 {

	public static void main(String[] args){
		List<List<Double>> res = new ArrayList<List<Double>>();
		try {
			FileInputStream fstream = new FileInputStream("A-small-attempt2.in");
			DataInputStream in = new DataInputStream(fstream);
			BufferedReader br = new BufferedReader(new InputStreamReader(in));
			int cases = Integer.valueOf(br.readLine());
			for(int i = 0; i < cases; i++) {
				String line = br.readLine();
				String[] tokens = line.split(" ");
				int[] votes = new int[tokens.length-1];
				for(int j = 1; j < tokens.length; j++)
					votes[j-1] = Integer.valueOf(tokens[j]);
				res.add(solve(votes));
			}
			in.close();
		} catch (Exception e) {
			System.err.println("Error: " + e.getMessage());
		}
		
		try {
			// Create file
			File fout = new File("out.txt");
			FileWriter fstream = new FileWriter(fout);
			BufferedWriter out = new BufferedWriter(fstream);
			for (int i = 0; i < res.size(); i++){
				out.write("Case #" + (i+1) + ": ");
				for(Double d : res.get(i))
					out.write(d + " ");
				out.newLine();
			}
			// Close the output stream
			out.close();
		} catch (Exception e) {// Catch exception if any
			System.err.println("Error: " + e.getMessage());
		}
	}
	
	private static List<Double> solve(int[] votes){
		int sum = 0;
		for(int vote : votes)
			sum += vote;
		int secondSum = sum;
		int counter = votes.length;
		double[] tmp = new double[votes.length];
		byte[] marked = new byte[votes.length];
		
		boolean found = false;
		do {
		found = false;
		if(sum == 0){
			for(int i = 0; i < votes.length; i++)
				if(marked[i] == 0)
					tmp[i] = (1./counter)*100;
		} else {
			for(int i = 0; i < votes.length; i++){
				if(marked[i] == 0){
					double x = ((double)(secondSum + sum - counter*votes[i]))/
									(counter*sum)*100;
					if(x < 0) {
						tmp[i] = 0;
						counter--;
						secondSum -= votes[i];
						found = true;
						marked[i] = 1;
					}
					else
						tmp[i] = x;
				}
			}
		}
		} while(found);
		
		List<Double> res = new ArrayList<Double>();
		for(double d : tmp)
			res.add(d);
		return res;
	}
	
}
