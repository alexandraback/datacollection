import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.StringTokenizer;


public class ProbA {
	
	static class contestant {
		int order;
		double score;
		double percent;
		
		public contestant(int order, double score){
			this.order = order;
			this.score = score;
			percent = 0;
		}
		
	}
	
	public static String solve(int n, int scores[]) {
		String result = "";
		contestant array[] = new contestant[n];
		double min = 1000;
		contestant temp = null;
		int index = 0;
		double totalScore = 0;
		
		for (int i = 0; i < n; i++){
			array[i] = new contestant(i, scores[i]);
			totalScore += scores[i];
		}
		
		for (int i = 0; i < n; i++){
			min = 1000;
			for (int j = i; j < n; j++){
				if (array[j].score < min){
					min = array[j].score;
					index = j;
				}
			}
			temp = array[i];
			array[i] = array[index];
			array[index] = temp;
		}
		
		double currPercent = 1;
		
		for (int i = 0; i < n - 1; i++){
			double diff = (array[i + 1].score - array[i].score)*(i+1);
			double percent = diff/totalScore < currPercent ? diff/totalScore : currPercent;
			currPercent -= percent;
			percent = percent / (i+1);
			
			for (int j = 0; j <= i; j++){
				array[j].percent += percent;
				array[j].score += percent*totalScore;
			}
			
			if (currPercent <= 0.0){
				break;
			}
		}
		
		if (currPercent > 0){
			double percent = currPercent/n;
			for (int i = 0; i < n; i++){
				array[i].percent += percent;
				array[i].score += percent * totalScore;
			}
		}
		
		for (int i = 0; i < n; i++){
			for (int j = 0; j < n; j++){
				if (array[j].order == i){
					result += array[j].percent*100 + " ";
					break;
				}
			}
		}
		
		return result;
	}
	
	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int T = 0;
		String str = "";
		
		File input = new File(args[0]);
		FileReader fileReader;
		BufferedReader br;
		
		File output = new File("output_A.txt");
		BufferedWriter bw;

		StringTokenizer tokenizer;
		
		try {
			bw = new BufferedWriter(new FileWriter(output));
			
			fileReader = new FileReader(input);
			br = new BufferedReader(fileReader);
			str = br.readLine();
			
			T = Integer.parseInt(str);
			
			for (int i = 0; i < T; i++) {
				str = br.readLine();
				tokenizer = new StringTokenizer(str);
				
				int n;
				int scores[];
				
				n = Integer.parseInt(tokenizer.nextToken());
				scores = new int[n];
				
				for (int j = 0; j < n; j++){
					scores[j] = Integer.parseInt(tokenizer.nextToken());
				}
				
				bw.write(String.format("Case #%d: %s\n", i+1, solve(n, scores)));
			}
			
			fileReader.close();
			br.close();
			
			bw.close();
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
	}

}
