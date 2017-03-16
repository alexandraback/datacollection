package r2;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.HashSet;

public class B {
	
	public static final String INPUT = "A.in";
	public static final String OUTPUT = "output.txt";
	public static void main(String[] args) throws IOException{
		BufferedReader br = new BufferedReader(new FileReader(new File(INPUT)));
		BufferedWriter bw = new BufferedWriter(new FileWriter(new File(OUTPUT)));
		int caseNum = Integer.parseInt(br.readLine());
		String line = "";
		
		for (int i = 0; i <caseNum; i++){
			int n =Integer.parseInt(br.readLine());
			line = br.readLine();
			String[] items = line.split(" ");
			String result = "";
			ArrayList<ArrayList<String>> r = permute(items);
			int count = 0;
			for (ArrayList<String> each : r){
				StringBuilder  sb = new StringBuilder();
				for (String ee: each){
					sb.append(ee);
				}
				if (isValid(sb.toString()))  count++;
				
			}
			
			result = "" + count;
			bw.write("Case #"+ (i+1) + ": " + result + "\n");
			System.out.println("Case #"+ (i+1) + ": " + result + "\n");
		}
		bw.close();
		br.close();
		
	}
	public static boolean isValid(String a){
//		System.out.println(a);
		char c = a.charAt(0);
		HashSet<Character> set = new HashSet<Character>();
		set.add(c);
		for (int i = 0 ; i < a.length(); i++){
			if (a.charAt(i) == c) continue;
			if (set.contains(a.charAt(i))) return false;
			set.add(a.charAt(i));
			c = a.charAt(i);
		}
//		System.out.println(a);
		return true;
	}
	
	public static ArrayList<ArrayList<String>> permute(String[] num) {
        ArrayList<ArrayList<String>> result = new ArrayList<ArrayList<String>>();
        if (num.length == 0) return result;
        return permuteHelper(num,0);
    }
    
    public static ArrayList<ArrayList<String>> permuteHelper(String[] num, int i){
        ArrayList<ArrayList<String>> result = new ArrayList<ArrayList<String>>();
        if (i == num.length-1){
            ArrayList<String> array = new ArrayList<String>();
            array.add(num[i]);
            result.add(array);
            return result;
        } else {
            ArrayList<ArrayList<String>> small = permuteHelper(num,i+1);
            for (ArrayList<String> each : small){
                for (int index = 0; index < each.size(); index++){
                    ArrayList<String> tmp = new ArrayList<String>(each);
                    tmp.add(index,num[i]);
                    result.add(tmp);
                }
                ArrayList<String> tmp = new ArrayList<String>(each);
                tmp.add(num[i]);
                result.add(tmp);
            }
            return result;
        }
    }

}
