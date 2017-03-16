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
				String re = "GABRIEL";
				if((nums[0]>nums[1]*nums[2])
						||(nums[1]*nums[2])%nums[0]!=0
						|| cache.containsKey(orgStr)){
					re = "RICHARD";
				}
				if(i == count){
					bw.write("Case #"+i+": "+re);
				}
				else{
					bw.write("Case #"+i+": "+re+"\n");
				}
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
		test.rwFile("D-small-attempt1.in.txt");
	}
}
