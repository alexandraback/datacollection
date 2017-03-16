package codejam_pancake;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

public class MainClass {
	static int nbCase=0;
	static int[] solution;
	static int[] nbDinners;
	static int[][] pancakes;
	
	public static void main(String[] args) throws IOException {
		parse();
		solve();
		write();
	}
	
	static void parse() throws IOException{
		BufferedReader fr = new BufferedReader(new FileReader(new File("input.txt")));
		String firstLine = fr.readLine();
		nbCase= Integer.parseInt(firstLine);
		
		solution=new int[nbCase];
		nbDinners=new int[nbCase];
		pancakes=new int[nbCase][1001];
		
		for(int c=0;c<nbCase;c++){
			String line=fr.readLine();
			nbDinners[c]=Integer.parseInt(line);
			String[] pan=fr.readLine().split(" ");
			for(int d=0;d<nbDinners[c];d++){
				pancakes[c][d]=Integer.parseInt(pan[d]);
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
			int maxPile=0;
			for(int d=0;d<nbDinners[c];d++){
				if(pancakes[c][d]>maxPile){
					maxPile=pancakes[c][d];
				}
			}
			
			int bestScore=maxPile;
			int bestPile=maxPile;
			
			while (bestPile>1){
				int goalPile=bestPile-1;
				int newMaxPile=0;
				int nbCut=0;
				
				for (int d=0;d<nbDinners[c];d++){
					int cut=((pancakes[c][d]+goalPile-1)/goalPile);
					cut-=1;
					int pile=(pancakes[c][d]+cut)/(cut+1);
					nbCut+=cut;
					if(pile>newMaxPile){
						newMaxPile=pile;
					}
				}
				
				int score=nbCut+newMaxPile;
				bestPile=newMaxPile;
				if(score<bestScore){
					bestScore=score;
				}
			}
			
			solution[c]=bestScore;
		}
	}

}
