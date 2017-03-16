package codejam;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;

public class TheLastWord {
	private static BufferedReader br = null;
	private static BufferedWriter bw = null;
	public static void main(String[] args) throws Exception {
		br = new BufferedReader(new FileReader("A-large.in"));
		bw = new BufferedWriter(new FileWriter("result.txt"));
		int size = Integer.parseInt(br.readLine());
		String line = "";
		int index = 0;
		while((line = br.readLine())!= null ){
			index++;
			char[] chars = line.toCharArray();
			StringBuilder sb = new StringBuilder(chars[0]+"");
			for(int i=1;i<chars.length;i++){
				if(chars[i]>=sb.charAt(0)){
					sb.insert(0, chars[i]+"");
				}else{
					sb.append(chars[i]+"");
				}
			}
			System.out.println(sb.toString());
			bw.write("Case #"+index+": "+sb.toString());
			bw.newLine();
		}
		if(bw != null){
			bw.close();			
		}
		if(br != null){
			br.close();
		}
	}
}
