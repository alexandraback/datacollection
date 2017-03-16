import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.LinkedList;
import java.util.Queue;


public class A {

	public static void main(String[] args) throws IOException {

//		String inputFile = "input_A.txt";
		String inputFile = "A-small-attempt1 (1).in";
//		String inputFile = "A-large-practice.in";
//		String inputFile = "C-large.in";
		String outputFile = "output_A.txt";
		FileInputStream fstream = new FileInputStream(inputFile);
		BufferedReader br = new BufferedReader(new InputStreamReader(fstream));

		PrintWriter writer = new PrintWriter(outputFile, "UTF-8"); //result
		
		String strLine;
		strLine = br.readLine();
		int T = Integer.parseInt(strLine);
		
		for( int i = 0;i<T;i++){
			int R, C, W;
			strLine = br.readLine();
			String[] strArray = strLine.split(" ");
			R = Integer.parseInt(strArray[0]);
			C = Integer.parseInt(strArray[1]);
			W = Integer.parseInt(strArray[2]);
			
			int result = worker(R,C,W);
//			long result = worker4((int)N);
			String result_str ="Case #"+(i+1)+ ": " +  result; 

			
			writer.println(result_str);
			System.out.println(result_str);
		}
	
		//Close the input stream
		br.close();
		writer.close();
	}
	public static int worker(int R, int C, int W){
		int r = 0;
		if(W == 1){
			return R*C;
		}
		r = r + C/W * R;
		if(C%W == 0){
			r = r + W-1;
		}else{
			r = r + W;
		}
		
		
		
		return r;
	}
	

}
