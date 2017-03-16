package codejam_ijk;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

public class MainClass {
	static int nbCase=0;

	
	static boolean[] solution;
	
	static int[][] mult={{0,0,0,0,0},{0,1,2,3,4},{0,2,-1,4,-3},{0,3,-4,-1,2},{0,4,3,-2,-1}};
	
	public static void main(String[] args) throws IOException {
		parseAndSolve();
		write();
	}
	
	static void parseAndSolve() throws IOException{
		BufferedReader fr = new BufferedReader(new FileReader(new File("input.txt")));
		String firstLine = fr.readLine();
		nbCase= Integer.parseInt(firstLine);
		
		solution=new boolean[nbCase];
		
		for(int c=0;c<nbCase;c++){
			//System.out.println("Case"+c);
			long x;
			int l;
			String sequence;
			
			//parse
			String line=fr.readLine();
			l=Integer.parseInt(line.split(" ")[0]);
			x=Long.parseLong(line.split(" ")[1]);
			sequence=fr.readLine();
			
			//solve
			
			//check i
			boolean okI=false;
			int seqIndexI=0;
			int seqRepeatI=0;
			int valI=1;
			
			while(!okI&&seqRepeatI<4&&seqRepeatI<x){
				switch (sequence.charAt(seqIndexI)){
					case 'i':
						valI=multiply(valI,2);
						break;
					case 'j':
						valI=multiply(valI,3);
						break;
					case 'k':
						valI=multiply(valI,4);
						break;
				}
				if(valI==2){
					okI=true;
				}
				else{
					seqIndexI++;
					if(seqIndexI==l){
						seqRepeatI++;
						seqIndexI=0;
					}
				}
			}
			if(!okI){
				//System.out.println("i not ok "+seqRepeatI+" "+seqIndexI);
				solution[c]=false;
				continue;
			}
			//System.out.println("i ok "+seqRepeatI+" "+seqIndexI);
			
			//check j
			boolean okJ=false;
			int seqIndexJ=seqIndexI+1;
			int seqRepeatJ=0;
			int valJ=1;
			
			if(seqIndexJ==l){
				seqRepeatJ++;
				seqIndexJ=0;
			}
			
			while(!okJ&&seqRepeatJ<5&&seqRepeatJ+seqRepeatI<x){
				switch (sequence.charAt(seqIndexJ)){
					case 'i':
						valJ=multiply(valJ,2);
						break;
					case 'j':
						valJ=multiply(valJ,3);
						break;
					case 'k':
						valJ=multiply(valJ,4);
						break;
				}
				if(valJ==3){
					okJ=true;
				}
				else{
					seqIndexJ++;
					if(seqIndexJ==l){
						seqRepeatJ++;
						seqIndexJ=0;
					}
				}
			}
			if(!okJ){
				//System.out.println("j not ok "+seqRepeatJ+" "+seqIndexJ);
				solution[c]=false;
				continue;
			}
			//System.out.println("j ok "+seqRepeatJ+" "+seqIndexJ);
			
			//check k
			int seqIndexK=seqIndexJ+1;
			int seqRepeatK=(int)((x-(seqRepeatJ+seqRepeatI+1))%4)+1;
			int valK=1;
			//System.out.println("k: "+seqRepeatK);
			
			if(seqIndexK==l){
				seqRepeatK--;
				seqIndexK=0;
			}
			

			while(seqRepeatK>0){
				switch (sequence.charAt(seqIndexK)){
					case 'i':
						valK=multiply(valK,2);
						break;
					case 'j':
						valK=multiply(valK,3);
						break;
					case 'k':
						valK=multiply(valK,4);
						break;
				}
				seqIndexK++;
				if(seqIndexK==l){
					seqRepeatK--;
					seqIndexK=0;
				}
			}
			if(valK==4){
				//System.out.println("k ok ");
				solution[c]=true;
			}
			else{
				//System.out.println("k not ok ");
				solution[c]=false;
			}
		}
		
		fr.close();
	}
	
	static public void  write() throws IOException{
		FileWriter fw = new FileWriter(new File("output.txt"));
		for(int c=0;c<nbCase;c++){
			fw.write("Case #"+(c+1)+": ");
			if(solution[c]){
				fw.write("YES\n");
			}
			else{
				fw.write("NO\n");
			}
		}
		fw.close();
	}
	
	static int multiply(int a, int b){
		int sign=1;
		if(a<0){
			a=-a;
			sign=-sign;
		}
		if(b<0){
			b=-b;
			sign=-sign;
		}
		return sign*mult[a][b];
	}
	
}
