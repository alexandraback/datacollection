import java.io.File;
import java.util.Formatter;
import java.util.Scanner;

public class TaskC_Small {
	public int caseNumber;
	Formatter output;
	Scanner input;
	final String file = "C-small-attempt2.in";
	
	public TaskC_Small(){
		caseNumber = 1;
		try{
			output = new Formatter("resultC.out");
			input = new Scanner(new File(file));
		}
		catch(Exception ex){
			displayMessage(ex.getMessage() + "/n");
		}
	}
	
	public void run(){
		int T = input.nextInt();
		int C, D, V;
		int[] coins;
		int result, temp;
		
		for (int i = 0; i < T; i++){
			C = input.nextInt();
			D = input.nextInt();
			V = input.nextInt();
			
			coins = new int[D];
			for (int j = 0; j < D; j++)
				coins[j] = input.nextInt();
			
			temp = 1;
			result = 0;
			
			while(temp + 1 < coins[0]){
				temp *= 2;
				result++;
			}
			
			if(temp == coins[0]){
				temp = temp*2 - 1;
			}
			else{
				temp = temp*2 - 1 + coins[0];
			}

			for(int j = 1; j < coins.length && temp < V; j++){
				while(coins[j] > temp + 1){
					temp += temp+1;
					result++;
				}
				
				temp = temp + coins[j];
			}
			
			while(temp < V){
				temp += temp + 1;
				result++;	
			}
			
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
		TaskC_Small app = new TaskC_Small ();
		app.run();
	}
}