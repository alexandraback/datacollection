package codejam_round1C_pblmB;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

public class MainClass {
	static BufferedReader fr;
	static int nbCase=0;
	
	static int K;
	static int L;
	static int S;
	
	static String keybord;
	static String target;
	
	static double[] solution;
	
	public static void main(String[] args) throws IOException {
		parseAndSolve();
		write();
	}
	
	static void parseAndSolve() throws IOException{
		
		fr = new BufferedReader(new FileReader(new File("input.txt")));
		
		String firstLine = fr.readLine();
		nbCase= Integer.parseInt(firstLine);
		
		solution=new double[nbCase];
		
		for(int c=0;c<nbCase;c++){
			parseCase(c);
			solveCase(c);
		}
		
		fr.close();
	}
	
	
	
	static public void  write() throws IOException{
		FileWriter fw = new FileWriter(new File("output.txt"));
		for(int c=0;c<nbCase;c++){
			fw.write("Case #"+(c+1)+": "+solution[c]+"\n");
		}
		fw.close();
	}
	
	static void parseCase(int c) throws IOException{
		String[] line = fr.readLine().split(" ");
		K= Integer.parseInt(line[0]);
		L= Integer.parseInt(line[1]);
		S= Integer.parseInt(line[2]);
		
		keybord=fr.readLine();
		target=fr.readLine();
	}

	static void solveCase(int c){
		int maxBanana=0;
		int minOverlap=L;
		for (int i=1;i<target.length();i++){
			String sub=target.substring(i);
			if(target.startsWith(sub)){
				minOverlap=i;
				break;
			}
		}
		maxBanana=(S-L)/minOverlap+1;
		
		double averageBanana=0;
		double wordProb=1;
		for(int i=0;i<target.length();i++){
			double letterProb=0;
			for(int j=0;j<keybord.length();j++){
				if(target.charAt(i)==keybord.charAt(j)){
					letterProb+=1.d/keybord.length();
				}
			}
			if(letterProb==0){
				solution[c]=0;
				return;
			}
			wordProb*=letterProb;
		}
		
		averageBanana=wordProb*(S-L+1);
		solution[c]=maxBanana-averageBanana;
	}
}
