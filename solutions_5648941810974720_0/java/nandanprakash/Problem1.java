package round1b;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.FileWriter;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class Problem1 {

	public static final String fileName="./round1b/"+"A-small-attempt3.in";
	
	public static void main(String[] args) {
		ArrayList<String> values = new ArrayList<String>();;
		try {
		FileInputStream fis = new FileInputStream(fileName);
		BufferedReader br = new BufferedReader(new InputStreamReader(fis));
		long count = Long.parseLong(br.readLine());
		for(long i=0;i<count;i++)
			values.add(br.readLine());
		br.close();
		FileWriter fw = new FileWriter("./round1b/"+"prob1.txt");
		BufferedWriter bw = new BufferedWriter(fw);
		for(int i=1;i<=values.size();i++) {
			bw.write("Case #"+i+": "+getLastWord(values.get(i-1))+"\n");
			bw.flush();
		}
		bw.close();
		}catch(Exception e) {
			e.printStackTrace();
		}

	}
	
	public static String getLastWord(String value) {
		ArrayList<Integer> nums = new ArrayList<Integer>();
		String result="";
		value=found(value, nums, "ZERO",0);
		value=found(value, nums, "TWO",2);
		value=found(value, nums, "FOUR",4);
		value=found(value, nums, "SIX",6);
		value=found(value, nums, "SEVEN",7);
		value=found(value, nums, "EIGHT",8);
		value=found(value, nums, "ONE",1);
		value=found(value, nums, "THREE",3);
		value=found(value, nums, "FIVE",5);
		value=found(value, nums, "NINE",9);
		
		Collections.sort(nums);
		for(int n:nums)
			result+=n+"";
		if(value.length()>0)
			System.out.println(value);
		return result;
	}

	private static String found(String value, ArrayList<Integer> nums,String chars,int num) {
		String backup = new String(value);
		boolean present = true;
		//boolean presentOnce = false;
		while(present) {
		backup=new String(value);
		for(char c:chars.toCharArray())
			if(!value.contains(c+"")) {
				present = false;
				break;
			}
			else
				value=value.replaceFirst(c+"", "");
		if(present) {
			nums.add(num);
			//presentOnce = true;
		}
		}
			return backup;
	}

}
