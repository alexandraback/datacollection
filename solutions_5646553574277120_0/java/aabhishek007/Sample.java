import java.io.File;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.Scanner;


public class Sample {	
	
	public static final String INPUT_FILE = "C-small-attempt0.in";
	public static final String OUTPUT_FILE = "output_C-small.txt";
	
	public static final String CASE_STRING_BEFORE = "Case #";
	public static final String CASE_STRING_AFTER = ": ";
	
	Scanner scanner = null;
	File outputFile;
	PrintStream pout = null;
	int totalTests;
	int testNo;
	//DecimalFormat formatter = new DecimalFormat("#0.0000000");
	
	//ArrayList<Integer> plates = null;
	int maxCoins;
	int maxValue;
	int nExistingDeno;
	ArrayList<Integer> existingDeno;
	ArrayList<Integer> combinedDeno;
	boolean[] used;
	int newDemoCount;
	
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
		maxCoins = 0;
		maxValue = 0;
		nExistingDeno = 0;
		existingDeno = new ArrayList<Integer>();
		combinedDeno = new ArrayList<Integer>();
		newDemoCount = 0;
	}
	
	private void read_input(){
		maxCoins = scanner.nextInt();
		nExistingDeno = scanner.nextInt();
		maxValue = scanner.nextInt();
		
		for(int i = 0;i<nExistingDeno;i++){
			existingDeno.add(scanner.nextInt());
		}
		
		combinedDeno.addAll(existingDeno);
	}
	
	private void solve_print(){
		
		for(int deno = 1; deno<=maxValue;deno++){
			checkNAddDeno(deno);
		}
		
		pout.print(CASE_STRING_BEFORE + testNo + CASE_STRING_AFTER);
		pout.println(""+newDemoCount);
	}
	
	private boolean checkNAddDeno(int deno){
		
		if(combinedDeno.contains(deno)){
			return true;
		}
		
		if(deno == 1 || deno == 2){
			combinedDeno.add(deno);
			Collections.sort(combinedDeno);
			newDemoCount++;
			return true;
		}
		
		used = new boolean[combinedDeno.size()+2];
		
		boolean status = compute_recursively(deno, 0);
		if(!status){
			combinedDeno.add(deno);
			Collections.sort(combinedDeno);
			newDemoCount++;
		}
			
		return true;
		
	}
	
	private boolean compute_recursively(int deno, int startIndex) {
		int count = deno;
		
		int exisitingIndex = combinedDeno.indexOf(deno);
		if(exisitingIndex>=0 && !used[exisitingIndex]){
			return true;
		}
		
		
		
		boolean status = false;
		
		for(int i=startIndex;i<combinedDeno.size() && !used[i];i++){
			int removedDeno = combinedDeno.get(i);
			
			if(removedDeno>deno){
				return false;
			}
			count = deno;
			count -= removedDeno;
			used[i] = true;
			status = compute_recursively(count, i+1);
			used[i] = false;
			if(status){
				return true;
			}
			
		}
		
		return false;
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
