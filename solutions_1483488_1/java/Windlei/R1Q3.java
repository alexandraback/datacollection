import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Iterator;


public class R1Q3 {
	public static HashMap<String, String> wordMap;
	
	public static void main(String []args) throws NumberFormatException, IOException{
		BufferedReader bf = new BufferedReader(new FileReader(new File("input")));
		BufferedWriter bw = new BufferedWriter(new FileWriter(new File("output")));
		int num = Integer.parseInt(bf.readLine());
		String aString = "123";
		
		for (int i = 1 ; i<=num; i++){
			int nums = 0;
			String line = bf.readLine();
			String[] argss =line.split(" ");
			int small = Integer.parseInt(argss[0]);
			int large = Integer.parseInt(argss[1]);
			HashSet<Integer> already = new HashSet<Integer>();
			for (int j = small; j< large; j++){
				if (j<10) continue;
				already.clear();
				already.add(j);
				String temp = String.valueOf(j);
				for (int k = 1; k < temp.length(); k++){
					int m = k;
					int newnum  = j/(int)(Math.pow(10, temp.length()-k));
					newnum+= (j%(int)(Math.pow(10, temp.length()-k)))*Math.pow(10, k);
					if (!already.contains(newnum)&&newnum<=large&&newnum>=small&&newnum>j){
						nums++;
						already.add(newnum);
					}
				}
			}
			System.out.println(i);
			bw.write("Case #"+i+": "+nums+"\n");
		}
		bf.close();
		bw.close();
	}
}
