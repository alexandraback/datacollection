import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.HashMap;
import java.util.Iterator;


public class R1Q2 {
	public static HashMap<String, String> wordMap;
	
	public static void main(String []args) throws NumberFormatException, IOException{
		BufferedReader bf = new BufferedReader(new FileReader(new File("input")));
		BufferedWriter bw = new BufferedWriter(new FileWriter(new File("output")));
		int num = Integer.parseInt(bf.readLine());
		for (int i = 1 ; i<=num; i++){
			int maxnum = 0;
			String line = bf.readLine();
			String[] argss =line.split(" ");
			int people = Integer.parseInt(argss[0]);
			int sup = Integer.parseInt(argss[1]);
			int p = Integer.parseInt(argss[2]);
			int []points = new int[people];
			int already = 0;
			int poss = 0;
			for (int j = 0; j < people; j++){
				points[j] = Integer.parseInt(argss[j+3]);
				if ((points[j]+2)/3 >= p) already++;
				else if ((points[j]+4)/3 >= p && points[j] >=p){
					poss ++;
				}
			}
			maxnum = already + (poss > sup?sup:poss);
			bw.write("Case #"+i+": "+maxnum+"\n");
		}
		bf.close();
		bw.close();
	}
}
