import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Arrays;


public class MainClass {

	public static void main(String[] args) throws IOException, InterruptedException {
		BufferedReader fr = new BufferedReader(new FileReader(new File("input.txt")));
		FileWriter fw = new FileWriter(new File("result.txt"));
		String firstLine = fr.readLine();
		int nbCases = Integer.parseInt(firstLine);

		for (int i =0; i<nbCases; i++){

			String nLine = fr.readLine();
			int nTables = Integer.parseInt(nLine);
			nLine = fr.readLine();
			String[] sTables = nLine.split(" ");
			int tobj =-1;
			int tMin = Integer.MAX_VALUE;
			while(tMin>tobj){
				tobj ++;
				tMin = Integer.MAX_VALUE;
				for (int nbInterrupt =0; nbInterrupt<tobj; nbInterrupt++){
					ArrayList<Integer> tables = new ArrayList<Integer>();
					for (int t =0; t<nTables; t++){
						tables.add(Integer.parseInt(sTables[t]));
					}
					for (int interr =0; interr<nbInterrupt; interr++){

						int indMax = (getIndexMax(tables));
						int pmax = tables.get(indMax);
						tables.set(indMax, tobj-nbInterrupt);
						tables.add(pmax-tobj+nbInterrupt);
						
					}
					int indMax = (getIndexMax(tables));
					int pmax = tables.get(indMax);
					tMin = Math.min(pmax+nbInterrupt,tMin);
				}
				
				
				
			}
			

			
			
			fw.write("Case #"+(i+1)+": "+(tobj)+"\n");
			
		}
		fw.close();
		System.out.println("finished");
	}

	private static int getIndexMax(ArrayList<Integer> tables) {
		int res =0;
		int max =0;
		int ind =0;
		for (Integer i:tables){
			if (i>max){
				max =i;
				res = ind;
			}
				
				ind++;
		}
		return res;
	}
}
