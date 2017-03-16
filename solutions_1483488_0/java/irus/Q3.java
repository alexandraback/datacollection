package cg.y2012.Q3;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.HashSet;
import java.util.Set;

public class Q3 {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		
		 BufferedWriter out = null;
		try {
			String newLine = System.getProperty("line.separator");
		    out = new BufferedWriter(new FileWriter(args[0]+".output"));
		    BufferedReader b = new BufferedReader(new FileReader(args[0]));
		    int number_of_test_cases = Integer.parseInt(b.readLine().split(" ")[0]);
		    for( int tc = 0; tc < number_of_test_cases; tc++) {
		    	int[] data = convertToInt(b.readLine());
		    	int A = data[0];
		    	int B = data[1];
		    	Set<String> s = new HashSet<String>();
				int count = 0;
				for (int n = A; n <= B; n++) {
					for (int m : getRecycled(n)) {
						if(m> n  && m <= B){
							count++;
//							if(tc < number_of_test_cases-1)
//								if(!s.add("(" + n + "," + m + ")"))
//									System.out.println("(" + n + "," + m + ")");
						}
					}
				}
			    out.write("Case #"+(tc+1)+": "+count+newLine);
			}
		} catch (IOException e) {
			System.out.println("Exception : "+e);
		}
		finally {
			if(out != null){
				try {
					out.close();
				} catch (IOException e) {
					e.printStackTrace();
				}
			}
		}
	}
	
	private static Set<Integer> getRecycled(int A){
		String a = Integer.toString(A);
		Set<Integer> r = new HashSet<Integer>();
		String temp="";
		for(int i =a.length();i>0;i--){
			temp = a.charAt(i-1)+temp;
			String x = temp+a.substring(0, i-1);
			r.add(Integer.parseInt(x));
		}
		return r;
	}
	
	private static boolean isRecycled(int A, int B){
		String a = Integer.toString(A);
		String b = Integer.toString(B);
		String temp="";
		for(int i =a.length();i>0;i--){
			temp = a.charAt(i-1)+temp;
			String x = temp+a.substring(0, i-1);
			if(x.equals(b)){
				return true;
			}
		}
		return false;
	}
	
	private static int[] convertToInt(String line){
		String data[] = line.split(" ");
		int[] rtn = new int[data.length];
		for(int i=0;i< data.length ;i++){
			rtn[i]=Integer.parseInt(data[i].trim());
		}
		return rtn;
	}
	
}