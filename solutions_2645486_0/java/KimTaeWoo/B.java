import java.io.File;
import java.io.FileWriter;
import java.util.Scanner;

public class B {
	
	private int E,R,N;
	private int[] v;
	
	private void goodluck() throws Exception {
		// ready variables
		String path = "/Users/teuskim/Documents/workspace/android-src/CodeJam/src/";
		int numberOfCases;
		
		// get file
		Scanner sc = new Scanner(new File(path+"B-small-attempt0.in.txt"));
		numberOfCases = sc.nextInt();
		
		// make output
		File file = new File(path+"B-small-attempt0.out.txt");
		if(file.exists() == false)
			file.createNewFile();
		FileWriter fw = new FileWriter(file);
		for(int casenum=0; casenum<numberOfCases; casenum++){
			
			E = sc.nextInt();
			R = sc.nextInt();
			N = sc.nextInt();
			v = new int[N];
			for(int i=0; i<N; i++) v[i] = sc.nextInt();
			
			String result = ""+getResult(-1, E);
			fw.write("Case #"+(casenum+1)+": "+result+"\n");
			print("Case #"+(casenum+1)+": "+result);
		}
		fw.close();
	}
	
	private int getResult(int aidx, int e){
		if(aidx == N) return 0;
		
		int result = 0;
		for(int i=0; i<=e; i++){
			int nexte = e-i+R;
			if(nexte > E) nexte = E;
			int vv = 0;
			if(aidx >= 0) vv = v[aidx];
			result = Math.max(result, i*vv + getResult(aidx+1, nexte));
		}
		return result;
	}
	
	public static void main(String[] args){
		print("start!");
		try{
			
			new B().goodluck();
			
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
