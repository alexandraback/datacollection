import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Scanner;


public class numbers {
	public static void main(String[] args) {
		numbers number = new numbers();
         number.readFile("test.txt");
	}

	public void readFile(String filename){
	int i = 1;
	BufferedReader reader = null;
	try {
		reader = new BufferedReader(new 
				FileReader(filename));
	} catch (FileNotFoundException e) {
		e.printStackTrace();
	}
	String newLine;
		try {
			newLine = reader.readLine();
			while ((newLine = reader.readLine()) != null) {
				evalline(newLine,i);
				i++;
			}
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	
	}
	
	public void evalline(String line,int casenum){
		Scanner sc = new Scanner(line);
		boolean valid = false;
		int n = sc.nextInt();
		int sum = 0;
		int num;
		int[] min = new int[2];
		min[0] = -1;
		min[1] = -1;
		ArrayList <Integer> score = new ArrayList<Integer>();
		ArrayList <Integer> fracs = new ArrayList<Integer>();
		ArrayList <Integer> subscore = new ArrayList<Integer>();
		System.out.print("Case #" + casenum + ": ");
		while(sc.hasNextInt()){
			num = sc.nextInt();
			score.add(num);
			sum += num;
		}
		int len = score.size();
		int sublen = score.size();
		double scoreneeded = ((double) (2*sum)) / ((double) (len));
		
		double frac;
		
		for(int s : score){
			subscore.add(s);
		}
		double nscoreneeded = scoreneeded;
		while(valid == false){
			valid = true;
			int sub = 0;
			for(int i = 0; i < len; i++){
			   int s = subscore.get(i);
			   if (s > scoreneeded){
				   sublen -=1;
				   sub += s;
				   nscoreneeded = (((double) (2*sum)) - ((double) sub)) / ((double) (sublen));
				   valid = false;
				   subscore.set(i, -1);
			   }
			}
			scoreneeded = nscoreneeded;
		}
		
		for(int s : subscore){
			if(s<0){
				frac = 0.;
			}
			else{
				frac = (scoreneeded - (double) s) / ((double) sum);
			}
			if (frac <= 0){
				System.out.print(0. + " ");
			}
			else{
			System.out.print (frac*100 + " ");
			}
		}
		System.out.println("");
			
		
	}
}
	
