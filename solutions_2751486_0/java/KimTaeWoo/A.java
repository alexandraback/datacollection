import java.io.File;
import java.io.FileWriter;
import java.util.Scanner;

public class A {
	
	private String name,vowels;
	private int n;
	
	private void goodluck() throws Exception {
		// ready variables
		String path = "/Users/teuskim/Documents/workspace/android-src/CodeJam/src/";
		int numberOfCases;
		vowels = "aeiou";
		
		// get file
		Scanner sc = new Scanner(new File(path+"A-small-attempt0.in.txt"));
		numberOfCases = sc.nextInt();
		
		// make output
		File file = new File(path+"A-small-attempt0.out.txt");
		if(file.exists() == false)
			file.createNewFile();
		FileWriter fw = new FileWriter(file);
		for(int casenum=0; casenum<numberOfCases; casenum++){
			
			name = sc.next();
			n = sc.nextInt();
			
			String result = ""+solve();
			fw.write("Case #"+(casenum+1)+": "+result+"\n");
			print("Case #"+(casenum+1)+": "+result);
		}
		fw.close();
	}
	
	private int solve(){
		int result = 0;
		for(int i=0; i<name.length(); i++){
			for(int j=i; j<name.length(); j++){
				if(isValid(i, j)) result++;
			}
		}
		return result;
	}
	
	private boolean isValid(int si, int ei){
		if(ei-si+1 < n) return false;
		int cnt = 0;
		for(int i=si; i<=ei; i++){
			if(vowels.indexOf(name.charAt(i)) == -1) cnt++;
			else cnt = 0;
			if(cnt >= n) return true;
		}
		return false;
	}
	
	public static void main(String[] args){
		print("start!");
		try{
			
			new A().goodluck();
			
		}catch(Exception e){
			e.printStackTrace();
		}
		print("end!");
	}
	
	
	/**********************
	 * code for debugging *
	 **********************/
	
	public void check(boolean isRight, String log){
		if(isRight == false){
			print("exit: "+log);
			System.exit(0);
		}
	}
	
	public static void print(String str){
		System.out.println(str);
	}
	
	public static void print(int[] arr){
		if(arr == null) print("null");
		else{
			String str = "[";
			if(arr.length > 0){
				for(int i=0; i<arr.length; i++) str += arr[i]+",";
				str = str.substring(0, str.length()-1);
			}
			str += "]";
			print(str);
		}
	}
}
