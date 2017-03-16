import java.io.File;
import java.io.FileWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

public class B {
	
	private int X,Y;
	private int[][] dir = {{0,1},{0,-1},{1,0},{-1,0}};
	private char[] dirch = {'N','S','E','W'};
	private List<Character> result;
	private int[][][] memo;
	
	private void goodluck() throws Exception {
		// ready variables
		String path = "/Users/teuskim/Documents/workspace/android-src/CodeJam/src/";
		int numberOfCases;
		memo = new int[500][210][210];
		
		// get file
		Scanner sc = new Scanner(new File(path+"B-small-attempt0.in.txt"));
		numberOfCases = sc.nextInt();
		
		// make output
		File file = new File(path+"B-small-attempt0.out.txt");
		if(file.exists() == false)
			file.createNewFile();
		FileWriter fw = new FileWriter(file);
		for(int casenum=0; casenum<numberOfCases; casenum++){
			
			X = sc.nextInt();
			Y = sc.nextInt();
			result = new ArrayList<Character>();
			for(int i=0; i<500; i++) for(int j=0; j<210; j++) Arrays.fill(memo[i][j], 0);
			
			solve(0,0,0);
			String res = "";
			for(char ch : result) res += ch;
			fw.write("Case #"+(casenum+1)+": "+res+"\n");
			print("Case #"+(casenum+1)+": "+res);
		}
		fw.close();
	}
	
	private int solve(int idx, int x, int y){
		if(idx == 500) return 2; // false
		if(x==X && y==Y) return 1; // true
		if(Math.abs(x)>100 || Math.abs(y)>100) return 2;
		if(memo[idx][x+100][y+100] == 2) return 2;
		
		int res = 2;
		for(int i=0; i<dir.length; i++){
			int nextx = x + (dir[i][0]*(idx+1));
			int nexty = y + (dir[i][1]*(idx+1));
			result.add(dirch[i]);
			if(solve(idx+1, nextx, nexty) == 1){
				res = 1;
				break;
			}
			result.remove(result.size()-1);
		}
		memo[idx][x+100][y+100] = res;
		return res;
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
