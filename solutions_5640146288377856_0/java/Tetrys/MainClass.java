package codejam_round1C_pblmA;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

public class MainClass {
	static BufferedReader fr;
	static int nbCase=0;
	
	static int C;
	static int R;
	static int W;
	
	static int[] solution;
	
	public static void main(String[] args) throws IOException {
		parseAndSolve();
		write();
	}
	
	static void parseAndSolve() throws IOException{
		
		fr = new BufferedReader(new FileReader(new File("input.txt")));
		
		String firstLine = fr.readLine();
		nbCase= Integer.parseInt(firstLine);
		
		solution=new int[nbCase];
		
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
		R= Integer.parseInt(line[0]);
		C= Integer.parseInt(line[1]);
		W= Integer.parseInt(line[2]);
	}

	static void solveCase(int c){
		int lineCross=(C+W-1)/W;
		int space=(C-lineCross)/(lineCross+1);
		int finition=2*space;
		int addSpace=(C-lineCross)-((lineCross+1)*space);
		if(addSpace==lineCross){
			finition+=1;
		}
		finition=Math.max(finition, W-1);
		solution[c]=lineCross*R+finition;
	}
}
