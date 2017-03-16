import java.io.File;
import java.io.FileWriter;
import java.math.BigDecimal;
import java.util.Scanner;

public class A {
	
	private long r,t;
	
	private void goodluck() throws Exception {
		// ready variables
		String path = "/Users/teuskim/Documents/workspace/android-src/CodeJam/src/";
		int numberOfCases;
		
		// get file
		Scanner sc = new Scanner(new File(path+"A-large.in.txt"));
		numberOfCases = sc.nextInt();
		
		// make output
		File file = new File(path+"A-large.out.txt");
		if(file.exists() == false)
			file.createNewFile();
		FileWriter fw = new FileWriter(file);
		for(int casenum=0; casenum<numberOfCases; casenum++){
			
			r = sc.nextLong();
			t = sc.nextLong();
			
			String result = ""+getResult();
			fw.write("Case #"+(casenum+1)+": "+result+"\n");
			print("Case #"+(casenum+1)+": "+result);
		}
		fw.close();
	}
	
	private long getResult(){
		BigDecimal a = new BigDecimal(2);
		BigDecimal b = new BigDecimal(2*r-1);
		BigDecimal c = new BigDecimal(-t);
		BigDecimal four = new BigDecimal(4);
		BigDecimal mone = new BigDecimal(-1);
		
		BigDecimal tmp = b.multiply(b).subtract(a.multiply(four).multiply(c));
		tmp = BigDecimal.valueOf(Math.sqrt(tmp.doubleValue()));
		BigDecimal res = b.multiply(mone).add(tmp).divide(four);
		long tres = res.longValue()+100;
		
		while(2*tres*tres + (2*r-1)*tres > t){
			tres--;
		}
		return tres;
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
