import java.io.File;
import java.util.Formatter;
import java.util.Scanner;

public class TaskA {
	public int caseNumber;
	Formatter output;
	Scanner input;
	final String file = "A-large.in";
	
	public TaskA(){
		caseNumber = 1;
		try{
			output = new Formatter("result.out");
			input = new Scanner(new File(file));
		}
		catch(Exception ex){
			displayMessage(ex.getMessage() + "/n");
		}
	}
	
	public void run(){
		int T = input.nextInt();
		int R, C, W, result;
		
		for (int i = 0; i < T; i++){
			R = input.nextInt();
			C = input.nextInt();
			W = input.nextInt();
			
			result = R*(C/W) + W;
			
			if(C % W == 0)
				result--;
			
			printCase(result + "");
		}
		
		closeOutput();
		closeInput();
		displayMessage("Done");
	}
	
	public void printCase(String msg, int n){
		output.format("Case #%d: %s\n", n, msg);
		System.out.printf("Case #%d: %s\n", n, msg);
	}
	
	public void printCase(String msg){
		output.format("Case #%d: %s\n", caseNumber, msg);
		System.out.printf("Case #%d: %s\n", caseNumber, msg);
		caseNumber++;
	}
	
	public void displayMessage(String message){
		System.out.print(message);
	}
	
	public void closeInput(){
		try{
			input.close();
			displayMessage("Input is closed\n");
		}
		catch(Exception ex){
			displayMessage(ex.getMessage() + "\n");
		}
	}
	
	public void closeOutput(){
		try{
			output.close();
			displayMessage("Output is closed\n");
		}
		catch(Exception ex){
			displayMessage(ex.getMessage() + "\n");
		}
	}
	
	public static void main(String[] args){
		TaskA app = new TaskA ();
		app.run();
	}
}