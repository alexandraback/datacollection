import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.util.Scanner;


public class SolutionB {
	private static int testcase = 0;
	private static String inputFile = "C:\\GCJ-Input-Output\\input.txt";
	private static String outputFile = "C:\\GCJ-Input-Output\\output.txt";
	private static BufferedWriter writer = null;
	public static void main(String[] args)throws Exception {
		
		Scanner scanner = new Scanner(new File(inputFile));
		writer = new BufferedWriter(new FileWriter(new File(outputFile)));
		int tcCount = scanner.nextInt();
		StringBuilder sb = null;
		for(int i=0;i<tcCount;i++){
			int rows = scanner.nextInt();
			int cols = scanner.nextInt();
			int[][] input = new int[rows][cols];
			for(int j=0;j<rows;j++){
				for(int k=0;k<cols;k++){
					input[j][k] = scanner.nextInt();
				}
			}
			process(input);
		}
		writer.flush();
		writer.close();
	}
	public static void process(int[][] input)throws Exception{
		/*
		System.out.println("------  "+(testcase+1)+" ---------");
		for(int r=0;r<input.length;r++){
			for(int c=0;c<input[0].length;c++){
				System.out.print(input[r][c]+ " ");
			}
			System.out.println();
		}
		*/
		if(input.length==1 || input[0].length==1){
			writeOutput(true);
						return;
			
		}
		for(int r=0;r<input.length;r++){
			for(int c=0;c<input[0].length;c++){
				if(input[r][c]==1){
					if(!isValid(input,r,c)){
						writeOutput(false);
			//			System.out.println("--------------------------------------------------");
						return;
					}
				}
			}
		}
		writeOutput(true);
		//System.out.println("--------------------------------------------------");
	}
	private static boolean isValid(int[][] input,int r,int c){
		
		boolean flag = true;
		StringBuffer sb = new StringBuffer();
		int currVal = input[r][c];
		boolean hasBigNumInRow = false;
		boolean hasBigNumInCol = false;
		for(int i=0;i<input.length;i++){
			if(input[i][c]>currVal){
				hasBigNumInCol = true;break;
			}
		}
		for(int i=0;i<input[0].length;i++){
			if(input[r][i]>currVal){
				hasBigNumInRow = true;break;
			}
		}
		if(hasBigNumInCol && hasBigNumInRow){
			return false;
		}else{
			return true;
		}
		/*
		sb.append(((r-1)<0?"f":input[r-1][c]==2?"t":"f")).append("~");
		sb.append(((c+1)>input[0].length-1?"f":input[r][c+1]==2?"t":"f")).append("~");
		
		sb.append(((r+1)>input.length-1?"f":input[r+1][c]==2?"t":"f")).append("~");
		sb.append(((c-1)<0?"f":input[r][c-1]==2?"t":"f")).append("~");
		
		sb.append(((r-1)<0?"f":input[r-1][c]==2?"t":"f")).append("~");
		
		if(sb.indexOf("t~t")>-1){
			return false;
		}else{
			return true;
		}
		*/
	}
	public static void writeOutput(boolean result) throws Exception{
		writer.write("Case #"+ ++testcase+": "+(result?"YES":"NO")+"\n");
		//System.out.println("Case #"+ ++testcase+": "+(result?"YES":"NO")+"\n");
	}

}
