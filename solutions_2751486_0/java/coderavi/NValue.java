package googlecodejam2013;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.Reader;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.Set;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class NValue {

	static Set<String>  vowels = new HashSet<String>();
	static int  offset = 1000000;
	static Pattern p = Pattern.compile(".*[aeiou]+.*");
	public static String getNValue(String input, int n){
		BigInteger count = new BigInteger("0");
		HashSet<Long> countSet = new HashSet<Long>();
		int len = input.length();
		for(int i =0; i <= len-n; i++){
			String subStr = input.substring(i, i+n);
			Matcher matcher =p.matcher(subStr);
	        if(!matcher.matches()){
	        	fillSet(i, i+n, len, countSet);
	        	//BigInteger c = new BigInteger(""+(i+1)).multiply(new BigInteger(""+(len-i-n+1)));
	        	//count = count.add(c);
	        }
		}
		return countSet.size()+"";
	}
	
	public static void fillSet(int left, int right, int max, HashSet<Long> set){
		for(int i =0; i <= left; i++){
			for(int j= right; j <= max; j++){
				long key = i*offset + j;
				set.add(key);
			}
		}
	}
	
	public static void main(String[] argv) {
		try {
			long startTime = System.currentTimeMillis();
			Reader reader = new FileReader("C:\\Users\\AvinashS\\Desktop\\google\\nval\\small.in");
			BufferedReader bufReader = new BufferedReader(reader);
			String x = bufReader.readLine();
			int numOfTestCases = Integer.parseInt(x);
			int count = 0;
	
			File file = new File("C:\\Users\\AvinashS\\Desktop\\google\\nval\\small.out");
			FileWriter writer = new FileWriter(file);
			for(count =1; count<= numOfTestCases; count++) {
				String input = bufReader.readLine();
				//	ArrayList<Integer> secondLine = getIntegerList(bufReader.readLine());
				String output = getNValue(input.split(" ")[0], Integer.parseInt(input.split(" ")[1]))+"";
				writer.write("Case #" + count + ": " + output+"\n");
				System.out.println("Case #" + count + ": " + output);
			}
			writer.close();
			System.out.println("Total time = " + (System.currentTimeMillis() - startTime));
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
	private static ArrayList<Integer> getIntegerList(String s) {
		ArrayList<Integer> intList = new ArrayList<Integer>();
		String[] strArr = s.split(" ");
		for (String str : strArr) {
			intList.add(Integer.parseInt(str.trim()));
		}
		return intList;
	}

	
}
