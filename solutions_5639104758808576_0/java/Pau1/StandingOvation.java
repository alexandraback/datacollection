import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;


public class StandingOvation {

	private void rwFile(String filename){
		try {
			FileReader fr = new FileReader(filename);
			BufferedReader br = new BufferedReader(fr);
			FileWriter fw = new FileWriter(new File("result.txt"));
			BufferedWriter bw = new BufferedWriter(fw);
			int count = Integer.parseInt(br.readLine());
			for(int i=1; i<=count; i++){
				String standingStr = br.readLine().split(" ")[1];
				char[] standingChar = standingStr.toCharArray();
				int[] standing = new int[standingChar.length];
				for(int j=0; j<standingChar.length; j++){
					standing[j] = standingChar[j]-'0';
				}
				int re = standingOvation(standing);
				bw.write("Case #"+i+": "+re+"\n");
			}
			bw.flush();
			bw.close();
			br.close();
			fr.close();
			fw.close();
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}
		catch(IOException e){
			e.printStackTrace();
		}
	}
		
	private int standingOvation(int[] standing){
		int add = 0;
		int sum = 0;
		for(int i=0; i<standing.length; i++){
			if(sum<i){
				add+= i-sum;
				sum += i-sum;
			}
			sum+= standing[i];
		}
		return add;
	}
	
	public static void main(String[] args){
		StandingOvation so = new StandingOvation();
		so.rwFile("A-small-attempt0.in.txt");
	}
}
