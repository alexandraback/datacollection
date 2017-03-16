import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;


public class roun1_1 {
	public static void main(String[] args) throws IOException {
		ArrayList<String> data = new ArrayList<String>(read("D:/A-small-attempt0.in"));
		String[] nums = new String[Integer.valueOf(data.get(0))];
		for(int i =0, size = Integer.valueOf(data.get(0));i<size;i++){
	//		System.out.println(data.get(i+1));
			nums[i] = findNum(data.get(i+1));
	//		System.out.println(nums[i]);
		}
		write("D:/output.txt", nums);
	}
	public static String findNum(String line){
		HashMap<Character, Integer> all = new HashMap<Character, Integer>();
		all.put('g', 0);
		all.put('x', 0);
		all.put('u', 0);
		all.put('w', 0);
		all.put('z', 0);
		all.put('o', 0);
		all.put('t', 0);
		all.put('f', 0);
		all.put('s', 0);
		all.put('i', 0);
		for (char c: line.toLowerCase().toCharArray()){
			if (all.containsKey(c)){
				all.put(c, (all.get(c)+1));
			}
		}
		
		String num = new String("");
		
		for (int i = 0,size = all.get('z');i < size;i++){
			num = num + "0";
		}
		for (int i = 0,size = (all.get('o') - all. get('f') - all.get('w') - all.get('z'));i < size;i++){
			num = num + "1";
		}
		for (int i = 0,size = all.get('w');i < size;i++){
			num = num + "2";
		}
		for (int i = 0,size = (all.get('t') - all.get('g') - all.get('w'));i < size;i++){
			num = num + "3";
		}
		for (int i = 0,size = all.get('u');i < size;i++){
			num = num + "4";
		}
		for (int i = 0,size = (all.get('f') - all.get('u'));i < size;i++){
			num = num + "5";
		}
		for (int i = 0,size = all.get('x');i < size;i++){
			num = num + "6";
		}
		for (int i = 0,size = (all.get('s') - all.get('x'));i < size;i++){
			num = num + "7";
		}
		for (int i = 0,size = all.get('g');i < size;i++){
			num = num + "8";
		}
		for (int i = 0,size = (all.get('i') - all.get('g') - all.get('x') - (all.get('f') - all.get('u')));i < size;i++){
			num = num + "9";
		}
		return num;
	}
	
	
	
	
	
    public static List<String> read(String location) {
    	List<String> data = new ArrayList<String>();
        BufferedReader br = null;
        try {
            File file = new File(location);
            br = new BufferedReader(new FileReader(file));
            String line;
            while ((line = br.readLine()) != null) {
               // System.out.println(line);
                data.add(line);
            }
        } catch (IOException e) {
            e.printStackTrace();
        } finally {
            try {
                br.close();
            } catch (IOException e) {
            }
        }
        return data;
    }
    
    public static void write(String location, String[] nums) throws IOException {
    	FileWriter fw = new FileWriter(location);
    	BufferedWriter bw = new BufferedWriter(fw);
    	for(int i =0, size = nums.length; i<size;i++){
    		bw.write("Case #"+(i+1)+": "+ nums[i] +"\n");
    		System.out.println("Case #"+(i+1)+": "+ nums[i]);
    	}
    	bw.flush();
    }
}
