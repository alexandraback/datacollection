package Qualification;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;

public class MineSweeperMaster{
	public MineSweeperMaster(){	
	}
	public void MineSweeperMaster(String filename) throws NumberFormatException, NoSuchFieldException, SecurityException, IllegalArgumentException, IllegalAccessException, IOException{
		BufferedReader greyparse = new BufferedReader(new FileReader(filename));
		greyparse.readLine();
		PrintWriter writer = new PrintWriter("output.txt", "UTF-8");
		int thiscase = 1;
		String thisString;
	
		
		while(greyparse.ready()){
			thisString = "Case #" + thiscase + ":";
			String[] curr = greyparse.readLine().split(" ");
			Integer rows = Integer.valueOf(curr[0]);
			Integer columns = Integer.valueOf(curr[1]);
			Integer mines = Integer.valueOf(curr[2]);
			Integer free = rows*columns - mines;
			boolean pass = !((rows == 2 || columns == 2) && (free%2 == 1 && free !=1));
			if(free >=1 && (rows == 1 || columns == 1)){
				String newrow = "\n";
				if(rows == 1){
					newrow = "";
				}
				thisString += "\n" + "c";
				for(int i = 0; i < free-1; i++){
					thisString += newrow + "." ;
				}
				for(int i = 0; i < mines; i++){
					thisString += newrow + "*";
					
				}
			}
			else if((free == 1 || free == 4 || free == 6 || free >= 8) && pass){
				String[][] rect = new String[rows][columns];
				for(String[] r: rect){
					for(int i = 0; i < r.length; i++){
						r[i] = "*";
					}
				}
				if(free >=4){
					int freerows = free/columns;
					
					if(freerows < 2){
						for(int i = 0; i < 2; i++){
							for(int j = 0; j < free/2; j++){
								rect[i][j] = ".";
							}
						}
						if(free%2 == 1){
							
							rect[0][free/2 -1] = "*";
							rect[1][free/2 -1] = "*";
							for(int i = 0 ; i < 3; i++){
								rect[2][i] = ".";
								
							}
						}
						
					}
					else{
						for(int i = 0; i < freerows; i++){
							for(int j = 0; j < columns; j++){
								rect[i][j] = ".";
							}
						}
						for(int i = 0 ; i < free%columns; i++){
							rect[freerows][i] = ".";
							
						}
						if(free%columns == 1 ){
							rect[freerows][1] = ".";
							rect[freerows-1][columns-1] = "*";
							if(freerows == 2 ){
								rect[freerows][2] = ".";
								rect[freerows-2][columns-1] = "*";
							}
						}
						
						
					}
					
				}
				rect[0][0] = "c";
				for(String[] r: rect){
					thisString += "\n";
					for(String c: r){
						thisString += c;
					}
				}
			}
			else{
				thisString += "\nImpossible";
			}
			thiscase++;
			writer.println(thisString);
		}
		writer.close();
	}
	
	/**
	public static void main(String[] args) throws NumberFormatException, NoSuchFieldException, SecurityException, IllegalArgumentException, IllegalAccessException, IOException{
		MineSweeperMaster c = new MineSweeperMaster();
		c.MineSweeperMaster("src/Qualification/C-small-attempt4.in");
	}
	*/

}