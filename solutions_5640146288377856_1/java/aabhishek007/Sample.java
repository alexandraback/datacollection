import java.io.File;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.Scanner;


public class Sample {	
	
	public static final String INPUT_FILE = "A-large.in";
	public static final String OUTPUT_FILE = "output_A-large.txt";
	
	public static final String CASE_STRING_BEFORE = "Case #";
	public static final String CASE_STRING_AFTER = ": ";
	
	Scanner scanner = null;
	File outputFile;
	PrintStream pout = null;
	int totalTests;
	int testNo;
	//DecimalFormat formatter = new DecimalFormat("#0.0000000");
	
	//ArrayList<Integer> plates = null;
	int row;
	int col;
	int width;
	int turn;
	
	public static void main(String argv[]){
		
		Sample cards = new Sample();
		cards.setup();
		
		cards.start();
		
		cards.exit();
		
	}
	
	private void start(){
		totalTests = scanner.nextInt();
		
		for(int i=1;i<=totalTests;i++){
			testNo = i;
			reset();
			read_input();
			solve_print();
		}
	}
	
	private void reset(){
		//plates = new ArrayList<Integer>();
		row = 0;
		col = 0;
		width = 0;
		turn = 0;
	}
	
	private void read_input(){
		row = scanner.nextInt();
		col = scanner.nextInt();
		width = scanner.nextInt();
	}
	
	private void solve_print(){
		
		solve_row1();
		if(row>1){
			row--;
			int misses = col/width;
			int missTurns = misses * row;
			turn += missTurns;
		}
		
		
		
		pout.print(CASE_STRING_BEFORE + testNo + CASE_STRING_AFTER);
		
		pout.println(""+turn);
	}
	
	private void solve_row1(){
		turn = col/width;
		turn += (width-1);
		
		if(col%width == 0){
			// no action required
		}else{
			turn++;
		}
	}
	
	private int compute_recursively() {
		return 0;
	}
	
//	public class IntegerComparator implements Comparator<Integer> {
//
//	    @Override
//	    public int compare(Integer o1, Integer o2) {
//	        return o2.compareTo(o1);
//	    }
//	}
	
	private void setup(){
		try {
			scanner = new Scanner(new File(INPUT_FILE));
			outputFile = new File(OUTPUT_FILE);
			
			if(outputFile.exists()){
				outputFile.delete();
			}
			
			outputFile.createNewFile();
			
			pout = new PrintStream(outputFile);
			
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
	
	private void exit(){
		scanner.close();
		pout.flush();
		pout.close();
		
	}
}
