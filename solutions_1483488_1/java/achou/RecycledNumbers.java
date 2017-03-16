import java.io.BufferedReader;
import java.io.DataInputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.util.ArrayList;


public class RecycledNumbers {

	public static void main(String[] args){
		try{
			// Open the file that is the first 
			// command line parameter
			FileInputStream fstream = new FileInputStream(args[0]);
			// Get the object of DataInputStream
			DataInputStream in = new DataInputStream(fstream);
			BufferedReader br = new BufferedReader(new InputStreamReader(in));
			String strLine;
			//Read File Line By Line
			int numTest = Integer.parseInt(br.readLine());
			for(int i = 0; i < numTest; i ++){
				String str = br.readLine();
				String numbers[] = str.split(" ");
				int count = recycledNumbers(Integer.parseInt(numbers[0]),Integer.parseInt(numbers[1]));
				int x = i + 1;
				System.out.println("Case #" + x + ": " + count);
				
			}
			//Close the input stream
			in.close();
		}catch (Exception e){//Catch exception if any
			System.err.println("Error: " + e.getMessage());
		}
		
		
	}
	
	public static int recycledNumbers(int min, int max){
		int digits = Integer.toString(min).length();
		int current = min;
		int count = 0;
		while(current <= max){
			ArrayList<Integer> newNumbers = new ArrayList<Integer>();
			for(int i = 1; i < digits; i++){
				String movedDigits = Integer.toString(current).substring(i);
				String remainingDigits;
				if(i == 1){
					remainingDigits = Character.toString(Integer.toString(current).charAt(0));
				}
				else{
					remainingDigits = Integer.toString(current).substring(0,i);
				}
				int newNumber = Integer.parseInt(movedDigits + remainingDigits);
				if(newNumber != current && newNumber <= max && newNumber >= min ){
					boolean alreadyExists = false;
					for(Integer no : newNumbers){
						if(no.intValue() == newNumber){
							alreadyExists = true;
						}
					}
					if(!alreadyExists){
						if(current < newNumber){
							count ++;
							//System.out.println("(" + current + "," + newNumber + ")");
							newNumbers.add(new Integer(newNumber));
						}
					}
				}
				
			}
			current++;
		}
		
		return count;
	}
	
}




