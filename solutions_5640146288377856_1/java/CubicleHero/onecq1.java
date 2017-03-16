import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;


public class onecq1 {
	public static void main(String[] args){
		readFromFile();
	}
	public static void readFromFile(){
		Scanner scanner;
		try {
			scanner = new Scanner(new File("A-large.in"));
			int noofTests = scanner.nextInt();
			int i=0;
			while(i<noofTests){
				int output = 0;				
				int R = scanner.nextInt();
				int C = scanner.nextInt();
				int W = scanner.nextInt();
				for(int k = 0; k< R;k++){
					for(int j = 0; j<C ; j+=W)
						output++;
				}
				output += (W -1);
				System.out.println("Case #" + (i+1) + ": " + output);
				i++;
			}
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
	}
}
