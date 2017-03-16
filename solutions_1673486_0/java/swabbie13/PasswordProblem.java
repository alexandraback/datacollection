import java.io.File;
import java.io.FileNotFoundException;
import java.util.HashSet;
import java.util.Scanner;


public class PasswordProblem {
	public static void main(String[] args){
		Scanner in;
		try {
			in = new Scanner(new File("A-small-attempt0 (3).in"));
			solve(in);
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}

	}
	public static void solve(Scanner in){
		int cases =in.nextInt();
		for(int i = 1; i<=cases; i++){
			int alreadyTyped = in.nextInt();
			int total = in.nextInt();
			double[] prob = new double[alreadyTyped];
			for(int j =0; j<alreadyTyped;j++){
				prob[j] = in.nextDouble();
			}
			double cost = total+2; //delete and redo
			for(int k=0; k<alreadyTyped; k++){
				double totalProb =1;
				for(int d =0; d<=k; d++){
					totalProb*=prob[d];
				}
				double tempCost = totalProb*((alreadyTyped-(k+1))*2+(total-alreadyTyped)+1) +(1-totalProb)*(((alreadyTyped-(k+1))*2+(total-alreadyTyped)+1)+total+1);
				//System.out.println(tempCost);
				cost = Math.min(cost, tempCost);
				
			}
			System.out.println("Case #" +i+": "+(cost));
		}
			
			
		}
		
	
	
}
