import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.Scanner;


public class C1A {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		try{
			Scanner myFile = new Scanner(new FileReader("D://alon//programming//codejam2013//C1//A-small-attempt0.in")); //check!!!
			BufferedWriter out = new BufferedWriter(new FileWriter("D://alon//programming//codejam2013//C1//A-small-answers.txt")); //check!!!
			int T = myFile.nextInt();
			for(int t = 1; t<=T; t++){
				String name = myFile.next();
				int n = myFile.nextInt();
				int count = 0;
				for(int i = 0; i<name.length(); i++){
					for(int j = name.length(); j>i; j--){
						String st = name.substring(i, j);
						if(cunsecutive(st, n))
							count++;
					}
				}
				out.write("Case #"+t+": "+count+'\n');
				System.out.println("Case #"+t+": "+count);
			}
			out.close();
			myFile.close();
		}catch(FileNotFoundException e){
			System.out.println("file not found");
		}catch(Exception e){
			e.printStackTrace();
		}
	}
	
	public static boolean cunsecutive(String n, int num){
		int count = 0;
		for(int k = 0; k<n.length(); k++){
			char c = n.charAt(k);
			if((c != 'a')&&(c != 'e')&&(c != 'i')&&(c != 'o')&&(c != 'u'))
				count++;
			else
				count = 0;
			if(count == num)
				return true;
		}
		return false;
	}

}
