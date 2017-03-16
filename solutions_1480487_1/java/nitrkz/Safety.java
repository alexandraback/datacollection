package edu.nitin.codejam.round1B;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.text.DecimalFormat;
import java.text.ParseException;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.Set;

public class Safety {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub

		int contestants = 0;
		int totalJudgeScore = 0;
		ArrayList<Integer> judgeScores = new ArrayList<Integer>();
		ArrayList<Double> audScores = new ArrayList<Double>();
		
		File fin = new File("src/files/a2.txt");
		File fout = new File("src/files/a3.txt");
		
		DecimalFormat df = new DecimalFormat("###.######");
			
		
		try {
			BufferedReader br = new BufferedReader(new FileReader(fin));
			BufferedWriter bw = new BufferedWriter(new FileWriter(fout));
			long num = Integer.parseInt(br.readLine());
			for(int k=1;k<=num;k++)
			{
				totalJudgeScore = 0;
				StringBuilder result = new StringBuilder();
				
				String text = br.readLine();
				String[] splits = text.split(" ");
				contestants = Integer.parseInt(splits[0]);
				for(int var = 1; var <= contestants; var++){
					judgeScores.add(Integer.parseInt(splits[var]));
					totalJudgeScore += Integer.parseInt(splits[var]);
				}
				System.out.println(totalJudgeScore);
				int thresholdContest = 0;
				float threshold = 0;
				Set<Integer> zero = new HashSet<Integer>();
				for(int var = 0; var < contestants; var++){
					double temp = (totalJudgeScore * 2) / contestants;
					double deficit = (temp - judgeScores.get(var));
					if(deficit < 0)	{
						thresholdContest++;
						threshold += judgeScores.get(var);
						zero.add(var);
					}
				}
				for(int var = 0; var < contestants; var++){
					double temp = 0;
					if(!zero.contains(var)){
						temp = 0;
						temp = (totalJudgeScore * 2 - threshold) / (contestants- thresholdContest);
						System.out.println("Before: "+temp+" "+judgeScores.get(var));
						temp = (temp - judgeScores.get(var))/totalJudgeScore;
						temp = temp*100;
					}
					temp = df.parse(df.format(temp)).doubleValue();
					System.out.println("After: "+temp);
					audScores.add(temp);
					System.out.println(temp);
					result.append(temp+" ");
				}
				
				bw.write("Case #"+k+": "+result.toString().substring(0, result.length()-1));
				bw.write("\n");
				
				judgeScores.clear();
				audScores.clear();
			}
			bw.flush();
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (NumberFormatException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (ParseException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
	}

}
