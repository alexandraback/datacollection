package codejam_nomino;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

public class MainClass {
	static int nbCase=0;
	static int[] row;
	static int[] col;
	static int[] x;
	
	static boolean[] solution;
	
	public static void main(String[] args) throws IOException {
		parse();
		solve();
		write();
	}
	
	static void parse() throws IOException{
		BufferedReader fr = new BufferedReader(new FileReader(new File("input.txt")));
		String firstLine = fr.readLine();
		nbCase= Integer.parseInt(firstLine);
		
		row=new int[nbCase];
		col=new int[nbCase];
		x=new int[nbCase];
		solution=new boolean[nbCase];
		
		for(int c=0;c<nbCase;c++){
			String line=fr.readLine();
			x[c]=Integer.parseInt(line.split(" ")[0]);
			row[c]=Integer.parseInt(line.split(" ")[1]);
			col[c]=Integer.parseInt(line.split(" ")[2]);
			
		}
		
		fr.close();
	}
	
	static public void  write() throws IOException{
		FileWriter fw = new FileWriter(new File("output.txt"));
		for(int c=0;c<nbCase;c++){
			fw.write("Case #"+(c+1)+": ");
			if(solution[c]){
				fw.write("GABRIEL\n");
			}
			else{
				fw.write("RICHARD\n");
			}
		}
		fw.close();
	}
	
	static void solve(){
		for (int c=0;c<nbCase;c++){
			switch (x[c]){
				case 1:
					solution[c]=true;
					break;
				case 2:
					if(row[c]*col[c]%2==0) {
						solution[c]=true;
					}
					else {
						solution[c]=false;
					}
					break;
				case 3:
					if(row[c]*col[c]%3==0
						&&(row[c]>=3||col[c]>=3)
						&&row[c]>=2&&col[c]>=2){
							solution[c]=true;
					}
					else{
						solution[c]=false;
					}
					break;
				case 4:
					if(row[c]*col[c]%4==0
						&&(row[c]>=4||col[c]>=4)
						&&row[c]>=3&&col[c]>=3){
							solution[c]=true;
					}
					else{
						solution[c]=false;
					}
					break;
				case 5:
					if(row[c]*col[c]%5==0
						&&(row[c]>=5||col[c]>=5)
						&&row[c]>=3&&col[c]>=3){
							solution[c]=true;
					}
					else{
						solution[c]=false;
					}
					break;
				case 6:
					if(row[c]*col[c]%6==0
						&&(row[c]>=6||col[c]>=6)
						&&row[c]>=4&&col[c]>=4){
							solution[c]=true;
					}
					else{
						solution[c]=false;
					}
					break;
				default:
					solution[c]=false;
					break;
			}
		}
	}
}
