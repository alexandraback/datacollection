package round1b;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.FileWriter;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class Problem2 {

	public static final String fileName="./round1b/"+"B-small-attempt0 (1).in";
	
	public static void main(String[] args) {
		ArrayList<String> values = new ArrayList<String>();;
		try {
		FileInputStream fis = new FileInputStream(fileName);
		BufferedReader br = new BufferedReader(new InputStreamReader(fis));
		long count = Long.parseLong(br.readLine());
		for(long i=0;i<count;i++)
			values.add(br.readLine());
		br.close();
		FileWriter fw = new FileWriter("./round1b/"+"prob2result.txt");
		BufferedWriter bw = new BufferedWriter(fw);
		for(int i=1;i<=values.size();i++) {
			bw.write("Case #"+i+": "+getSmallestDiff(values.get(i-1))+"\n");
			bw.flush();
		}
		bw.close();
		}catch(Exception e) {
			e.printStackTrace();
		}

	}
	
	public static String getSmallestDiff(String value) {
		String v1 = value.split(" ")[0];
		String v2 = value.split(" ")[1];
		ArrayList<String> v1possible = getAllPossibleNums(v1);
		ArrayList<String> v2possible = getAllPossibleNums(v2);
		int lowest=999999;
		String slowestPair="";
		for(int i=0;i<v1possible.size();i++) {
			for(int j=0;j<v2possible.size();j++) {
				if(Math.abs(Integer.valueOf(v1possible.get(i))-Integer.valueOf(v2possible.get(j)))<lowest) {
					lowest=Math.abs(Integer.valueOf(v1possible.get(i))-Integer.valueOf(v2possible.get(j)));
					slowestPair = v1possible.get(i)+" "+v2possible.get(j);
				}
			}
		}
		return slowestPair;
	}

	private static ArrayList<String> getAllPossibleNums(String v1) {
		ArrayList<String> nums = new ArrayList<String>();
		nums.add(v1);
		while(nums.get(0).matches(".*\\?.*")) {
			ArrayList<String> temp = new ArrayList<String>();
			for(String s:nums) {
				for(int i=0;i<10;i++) {
					temp.add(s.replaceFirst("\\?", i+""));
				}
			}
			nums.clear();
			nums.addAll(temp);
		}
		return nums;
	}


}
