package round1c.pb;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.PrintWriter;

public class Solution {
	public static void main(String[] args) {
		try{
			BufferedReader reader = new BufferedReader(new FileReader(new File("in.txt")));
			PrintWriter writer = new PrintWriter(new File("out.txt"));
			String s = reader.readLine();
			int total = Integer.parseInt(s.trim());

			for(int i = 0; i < total; i++){
				String str = reader.readLine();
				String[] strs = str.split(" ");
				String res = cal(Integer.parseInt(strs[0].trim()), Integer.parseInt(strs[1].trim()));
				System.out.println("Case #" + (i+1) + ": " + res);
				writer.println("Case #" + (i+1) + ": " + res);
			}
			
			writer.close();
		} catch(Exception e){
			e.printStackTrace();
		}
	}
	
	public static String cal(int x, int y){
		StringBuilder ans = new StringBuilder();
		while(x != 0){
			if(x > 0) {
				ans.append("WE");
				x--;
			} else {
				ans.append("EW");
				x++;
			}
		}
		while(y != 0){
			if(y > 0) {
				ans.append("SN");
				y--;
			} else {
				ans.append("NS");
				y++;
			}
		}
		return ans.toString();
	}
}
