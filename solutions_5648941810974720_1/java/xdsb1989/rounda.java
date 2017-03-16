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


public class rounda {
	public static void main(String[] args) throws IOException {
		ArrayList<String> data = new ArrayList<String>(read("C:/Users/Administrator/Desktop/A-small-attempt0.in"));
		String[] number = new String[Integer.valueOf(data.get(0))];
		for(int i =0, size = Integer.valueOf(data.get(0));i<size;i++){
			number[i] = countNumber(data.get(i+1));
		}
		write("C:/Users/Administrator/Desktop/out_a.txt", number);
	}
	public static String countNumber(String line){
		HashMap<Character, Integer> count = new HashMap<Character, Integer>();
		count.put('g', 0);
		count.put('x', 0);
		count.put('u', 0);
		count.put('w', 0);
		count.put('z', 0);
		count.put('o', 0);
		count.put('t', 0);
		count.put('f', 0);
		count.put('s', 0);
		count.put('i', 0);
		for (char c: line.toLowerCase().toCharArray()){
			if (count.containsKey(c)){
				count.put(c, (count.get(c)+1));
			}
		}
		
		String num = new String("");
		for (int i = 0,size = count.get('z');i < size;i++){
			num = num + "0";
		}
		for (int i = 0,size = (count.get('o') - count. get('u') - count.get('w') - count.get('z'));i < size;i++){
			num = num + "1";
		}
		for (int i = 0,size = count.get('w');i < size;i++){
			num = num + "2";
		}
		for (int i = 0,size = (count.get('t') - count.get('g') - count.get('w'));i < size;i++){
			num = num + "3";
		}
		for (int i = 0,size = count.get('u');i < size;i++){
			num = num + "4";
		}
		for (int i = 0,size = (count.get('f') - count.get('u'));i < size;i++){
			num = num + "5";
		}
		for (int i = 0,size = count.get('x');i < size;i++){
			num = num + "6";
		}
		for (int i = 0,size = (count.get('s') - count.get('x'));i < size;i++){
			num = num + "7";
		}
		for (int i = 0,size = count.get('g');i < size;i++){
			num = num + "8";
		}
		for (int i = 0,size = (count.get('i') - count.get('g') - count.get('x') - (count.get('f') - count.get('u')));i < size;i++){
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
