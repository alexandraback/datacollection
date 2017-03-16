import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;


public class Pogo {
	BufferedReader reader = null;
	BufferedWriter writer = null;
	
	String inputFileName = "B-small-attempt0.in";
	String outputFileName = "B-small-attempt0.out";
	
	public void loadDataFromFile(){

		try {
			//Define file reader
			reader = new BufferedReader(new FileReader(inputFileName));
			
			//Define file writer
			writer = new BufferedWriter(new FileWriter(outputFileName));
			
			String line = reader.readLine();
			int T = Integer.parseInt(line);
			
			for(int i=0;i<T;i++){		
				String indexString = reader.readLine();
				String []indexes = indexString.split(" ");
				int x = Integer.parseInt(indexes[0]);
				int y = Integer.parseInt(indexes[1]);
				
				String result = dumnJump(x, y);
				
				writer.write("Case #" + (i+1) + ": " + result + "\n");
			}
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}finally {
			try {
				reader.close();
				writer.close();
			} catch (IOException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}
	}
	
	/**
	 * dumnJump for the samll input, which jump in x, y direction separately. Create 1 unit in every Jump
	 * @param x
	 * @param y
	 * @return
	 */
	public String dumnJump(int x, int y){
		String result = "";
		String jumpUnit;
		if(x > 0){
			jumpUnit = "WE";
		} else {
			jumpUnit = "EW";
		}
		for(int i=0;i<Math.abs(x);i++){
			result += jumpUnit;
		}
		if(y > 0){
			jumpUnit = "SN";
		} else {
			jumpUnit = "NS";
		}
		for(int i=0;i<Math.abs(y);i++){
			result += jumpUnit;
		}
		return result;
	}
	
	public static void main(String []args){
		Pogo test = new Pogo();
		test.loadDataFromFile();
	}
}
