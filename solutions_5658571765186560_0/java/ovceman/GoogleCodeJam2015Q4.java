import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;


public class GoogleCodeJam2015Q4 {

	ArrayList<String> inputLines = new ArrayList<String>();
	ArrayList<String> outputLines = new ArrayList<String>();
	private static final String PATH ="/Users/koichisakumoto/Documents/GoogleCodeJam/2015/Q4/";
	
	public static void main(String[] args) {
		GoogleCodeJam2015Q4 inst = new GoogleCodeJam2015Q4();
		//inst.getLines(PATH + "test.txt");
		inst.getLines(PATH + "D-small-attempt2.in.txt");
		//inst.getLines(PATH + "D-large.in.txt");
		inst.solveProblem();
		//inst.putLines(PATH + "answer_test.txt");
		inst.putLines(PATH + "answer_small_2.txt");
		//inst.putLines(PATH + "answer_large.txt");
	}

	private void solveProblem(){
		int currentLine = 0;
		int totalNum = Integer.parseInt(inputLines.get(currentLine++));
		
		for (int problemNum = 1; problemNum <= totalNum; problemNum++ ) {
			
			// input problem
			String[] XRC = inputLines.get(currentLine++).split(" ");
			int X = Integer.valueOf(XRC[0]);
			int R = Integer.valueOf(XRC[1]);
			int C = Integer.valueOf(XRC[2]);
			
			// solve problem
			int min = (R < C)? R : C;
			int max = (R > C)? R : C;
			boolean cond1 = (R * C) % X != 0;
			boolean cond2 = X > (min * 2);
			boolean cond3 = (X >= (R + C - 1)) && (R >= 2) && (C >= 2);
			boolean cond4 = X >= 7;
			boolean cond5 = (min == 2) && (max > 3) && (X >= max);
			String answer = (cond1 || cond2 || cond3 || cond4 || cond5)? "RICHARD" : "GABRIEL";

			// 解答を作る
			outputLines.add("Case #" + problemNum + ": " + answer);
		}
	}
	
	private void getLines(String fileName){
		try {
            FileReader in = new FileReader(fileName);
            BufferedReader br = new BufferedReader(in);
            String line;
            while ((line = br.readLine()) != null) {
            	inputLines.add(line);
            }
            br.close();
            in.close();
        } catch (IOException e) {
            System.out.println(e);
        }
	}
	
	private void putLines(String fileName){
		try {
			FileWriter out = new FileWriter(fileName); // new file
			BufferedWriter bw = new BufferedWriter(out);
            for ( String line : outputLines ){
            	bw.write(line + "\r\n");
            }
            bw.close();
            out.close();
        } catch (IOException e) {
            System.out.println(e);
        }
	}
	
	private int minIndex(int array[]){
		int min = 0;
		for(int i = 0; i < array.length; i++){
			if(array[min] > array[i]){
				min = i;
			}
		}
		return min;
	}
	
	private int minValue(int array[]){
		int index = minIndex(array);
		return array[index];
	}
	

}
