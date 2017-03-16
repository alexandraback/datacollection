import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.*;

public class SurpScores {
	
	public int count(int[] scores, int p, int surprises) {
		int countSurp = 0;
		int countNonSurp = 0;
		int minSurpScore = p + (p-2) + (p-2);
		int minNonSurpScore = minSurpScore + 2;
		if(p < 2) {
			minSurpScore = minNonSurpScore = p; 
		}
		
		for(int i = 0; i < scores.length; i++) {
			if(scores[i] >= minNonSurpScore) countNonSurp++;
			else if(scores[i] >= minSurpScore) countSurp++;
		}
		
		return countNonSurp + Math.min(surprises, countSurp);
	}
	
	
	public static void main(String args[]) {
		SurpScores c = new SurpScores();
		String result[] = null;
		
		
		try {
			Scanner sc = new Scanner(new FileInputStream("C:/Users/Administrator/Downloads/B-small-attempt0.in"));
			String line = sc.nextLine().trim();
			int cases = Integer.parseInt(line);
			result = new String[cases];
			for(int i = 0; i < cases; i++) {
				line = sc.nextLine().trim();
				String temp[] = line.split(" ");
				int players = Integer.parseInt(temp[0]);
				int surprises = Integer.parseInt(temp[1]);
				int p = Integer.parseInt(temp[2]);
				int scores[] = new int[players];
				
				for(int j = 0; j < players; j++) {
					scores[j] = Integer.parseInt(temp[j + 3]);
				}
				result[i] = "Case #" + (i+1) + ": " + c.count(scores, p, surprises);
			}
			
		} catch(Exception e) {
			e.printStackTrace();
		}
		
		try {
			 FileWriter fstream = new FileWriter("C:/out.txt");
			 PrintWriter out = new PrintWriter(fstream);
			 
			 for(int i = 0; i < result.length; i++) {
				 out.println(result[i]);
			 }
			 out.close();
		}catch(Exception e) {
			e.printStackTrace();
		}
	}
}
