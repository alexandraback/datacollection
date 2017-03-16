package codejam_standing_ovation;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

public class MainClass {
	
	static int nbCase=0;
	static int[] maximums;
	static int[][] nbShy;
	
	static int[] solution;
	
	public static void main(String[] args) throws IOException {
		parse();
		solve();
		write();
	}
	
	static void parse() throws IOException{
		BufferedReader fr = new BufferedReader(new FileReader(new File("input.txt")));
		String firstLine = fr.readLine();
		nbCase= Integer.parseInt(firstLine);
		
		maximums=new int[nbCase];
		solution=new int[nbCase];
		nbShy=new int[nbCase][1001];
		
		for(int c=0;c<nbCase;c++){
			String line=fr.readLine();
			maximums[c]=Integer.parseInt(line.split(" ")[0]);
			
			String numbers=line.split(" ")[1];
			for (int s=0;s<=maximums[c];s++){
				nbShy[c][s]=Integer.parseInt(numbers.substring(s,s+1));
			}
		}
		
		fr.close();
	}
	
	static public void  write() throws IOException{
		FileWriter fw = new FileWriter(new File("output.txt"));
		for(int c=0;c<nbCase;c++){
			fw.write("Case #"+(c+1)+": "+(solution[c])+"\n");
		}
		fw.close();
	}
	
	static void solve(){
		for (int c=0;c<nbCase;c++){
			int standingPeople=0;
			int friends=0;
			
			for (int s=0;s<=maximums[c];s++){
				int missingPeople=0;
				if(standingPeople<s){
					missingPeople=s-standingPeople;
				}
				friends+=missingPeople;
				standingPeople+=missingPeople;
				standingPeople+=nbShy[c][s];
			}
			
			solution[c]=friends;
		}
	}
}
