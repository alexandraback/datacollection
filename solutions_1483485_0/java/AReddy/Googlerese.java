import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.Writer;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Scanner;



public class Googlerese{
	public static void main(String[] args) throws IOException{
		System.out.println("Enter number of Test Cases <= 30");
		String testCases;
		File inFile = new File("C:/Users/AbhilashR/Downloads/A-small-attempt0.in" ); 
		Scanner sc = new Scanner(inFile);
		//BufferedReader brTestCases = new BufferedReader(new InputStreamReader(System.in));
		//testCases = (String)brTestCases.readLine();
		testCases = sc.nextLine();
		Integer noOfTestCases = null;
		try{
			noOfTestCases = Integer.parseInt(testCases);
		}catch (NumberFormatException e){
			System.out.println("The entered value is not a Number");
		}
		ArrayList<String> inputData = new ArrayList<String>();
		for(int i =0;i<noOfTestCases;i++){
			//brTestCases = new BufferedReader(new InputStreamReader(System.in));
			//testCases = (String)brTestCases.readLine();
			testCases = sc.nextLine();
			inputData.add(testCases);
		}
		HashMap<String,String> relationForGooglerese = new HashMap<String, String>();
		relationForGooglerese.put("y", "a");
		relationForGooglerese.put("n", "b");
		relationForGooglerese.put("f", "c");
		relationForGooglerese.put("i", "d");
		relationForGooglerese.put("c", "e");
		relationForGooglerese.put("w", "f");
		relationForGooglerese.put("l", "g");
		relationForGooglerese.put("b", "h");
		relationForGooglerese.put("k", "i");
		relationForGooglerese.put("u", "j");
		relationForGooglerese.put("o", "k");
		relationForGooglerese.put("m", "l");
		relationForGooglerese.put("x", "m");
		relationForGooglerese.put("s", "n");
		relationForGooglerese.put("e", "o");
		relationForGooglerese.put("v", "p");
		relationForGooglerese.put("z", "q");
		relationForGooglerese.put("p", "r");
		relationForGooglerese.put("d", "s");
		relationForGooglerese.put("r", "t");
		relationForGooglerese.put("j", "u");
		relationForGooglerese.put("g", "v");
		relationForGooglerese.put("t", "w");
		relationForGooglerese.put("h", "x");
		relationForGooglerese.put("a", "y");
		relationForGooglerese.put("q", "z");
		Writer output = null;
		File outFile = new File("C:/Users/AbhilashR/Downloads/outPut.txt" );
		output = new BufferedWriter(new FileWriter(outFile));
		String text = "";
		for(int i=0;i<noOfTestCases;i++){
			String actualLine = getActualLine(inputData.get(i),relationForGooglerese);
			text = "Case #"+(i+1)+": "+actualLine+"\r\n";
			output.write(text);
			output.flush();
		}
		output.close();
	}
	private static String getActualLine(String inputLine,HashMap<String, String> relationInGooglerese){
		int size = inputLine.length();
		String actualLine = "";
		ArrayList<Object[]> lineObject = new ArrayList<Object[]>();
		for(int i =0;i<size;i++){
			Object[] tempObj = {inputLine.substring(i, i+1),"UNBLOCK"};
			lineObject.add(tempObj);
		}
		for(int i = 97;i<123;i++){
			for(int j = 0; j <size; j++){
				if(lineObject.get(j)[1].equals("UNBLOCK") && lineObject.get(j)[0].equals((String.valueOf(Character.toChars(i))))){
					lineObject.get(j)[0] = relationInGooglerese.get(lineObject.get(j)[0]);
					lineObject.get(j)[1] = "BLOCK";
				}
			}
		}
		for(int i =0;i<size;i++){
			actualLine = actualLine + lineObject.get(i)[0];
		}
		
		return actualLine;
	}
}