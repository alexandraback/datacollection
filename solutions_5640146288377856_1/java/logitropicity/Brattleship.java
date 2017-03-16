package competition;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;

public class Brattleship {
	public static void main(String[] args){
		Brattleship b = new Brattleship();
 		String folder = "C:\\Users\\VincentChoo\\"
		+ "Documents\\Java\\IO Material\\"
		+ "Google Code Jam\\2015\\1C\\";
 		
	  	try {
	  		b.go(new Filer(folder));
	  	} catch(IOException e){
	  		System.err.println(e);
	  	} 
 		
 		b.test();
	}
	
	void test(){
		int R = 2,
			C = 7,
			W = 3;
		int score = minGuaranteedScore(R, C, W);
		System.out.println(score);
	}
	
	void go(Filer f) throws IOException{
		BufferedReader reader = f.reader("A-large.in");
		BufferedWriter writer = f.writer("A-large.out");
		
		int numCases = Integer.parseInt(reader.readLine());
		for(int t = 1; t <= numCases; t++){
			int[] in = toArray(reader.readLine().split(" "));
			int num = minGuaranteedScore(in[0], in[1], in[2]);
			
			String out = "Case #"+t+": "+num;
			writer.write(out);
			writer.newLine();
		}
		
		reader.close();
		writer.close();
	}
	
	int[] toArray(String[] array){
		int[] out = new int[array.length];
		for(int i = 0; i < out.length; i++){
			out[i] = Integer.parseInt(array[i]);
		}
		return out;
	}
	
	int minGuaranteedScore(int R, int C, int W){
		//1 <= W <= C
		
		int score = (C/W)*R;
		
		if(W > 1){
			score += W;
			if(C%W == 0){
				//missile hit is on the edge of the graph
				score--;
			}
		}
		
		return score;
	}
}
