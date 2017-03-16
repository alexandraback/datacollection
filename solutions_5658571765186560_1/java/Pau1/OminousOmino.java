import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.HashMap;
import java.util.Map;


public class OminousOmino {
	Map<String,String> cache = new HashMap<String,String>();
	private void rwFile(String filename){
		try {
			FileReader fr = new FileReader(filename);
			BufferedReader br = new BufferedReader(fr);
			FileWriter fw = new FileWriter(new File("result1.txt"));
			BufferedWriter bw = new BufferedWriter(fw);
			fillCache();
			int count = Integer.parseInt(br.readLine());
			for(int i=1; i<=count; i++){
				String orgStr = br.readLine();
				String[] org = orgStr.split(" ");
				int[] nums = new int[org.length];
				for(int j=0; j<nums.length; j++){
					nums[j] = Integer.parseInt(org[j]);
				}
				int X = nums[0], R = nums[1], C = nums[2];
				boolean ans = false;
			    if (X >= 7)
			        ans = false;
				else if (X > R && X > C)
			        ans = false;
			    else if( R * C % X != 0)
			        ans = false;
			    else if( (X + 1) / 2 > Math.min(R, C))
			        ans = false;
			    else if( X == 1 || X == 2 || X == 3)
			        ans = true;
			    else if( X == 4)
			        ans = Math.min(R, C) > 2;
			    else if( X == 5)
			        ans = !(Math.min(R, C) == 3 && Math.max(R, C) == 5);
			    else if( X == 6)
			        ans = Math.min(R, C) > 3;
				
			    
			    String re = "GABRIEL";
			    if(!ans){
					re = "RICHARD";
				}
				bw.write("Case #"+i+": "+re+"\n");
				bw.flush();
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
	
	
	private void fillCache(){
		cache.put("4 2 2","true");
		cache.put("4 2 4","true");
		cache.put("4 4 2","true");
		cache.put("4 1 4", "true");
		cache.put("4 4 1", "true");
		cache.put("3 1 3", "true");
		cache.put("3 3 1", "true");
	}
	
	public static void main(String[] args){
		OminousOmino test = new OminousOmino();
		test.rwFile("D-large.in.txt");
	}
}
