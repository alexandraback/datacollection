package googleJam;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collection;
import java.util.Collections;
import java.util.Scanner;

public class ProblemD {
	public static void main(String[] args){
		String filename = "src/input.txt";
		String output = "src/output.txt";
		String answer = "";
		
		try {
			Scanner scan = new Scanner(new File(filename));
			int a = scan.nextInt();
			for(int i = 0; i < a; i++){
				int b = scan.nextInt();
				int score1 = 0;
				int score2 = 0;
				ArrayList<Double> arr1 = new ArrayList<Double>();
				ArrayList<Double> arr2 = new ArrayList<Double>();
				for(int j = 0; j < b; j++){
					arr1.add(scan.nextDouble());
				}
				for(int j = 0; j < b; j++){
					arr2.add(scan.nextDouble());
				}
				
				Collections.sort(arr1);
				Collections.sort(arr2);
				ArrayList<Double> arry1 = new ArrayList<Double>(arr1);
				ArrayList<Double> arry2 = new ArrayList<Double>(arr2); 
				for(int j = 0; j < b; j++){
					double p1 = arr1.get(0);
					double p2 = arr2.get(0);
					arr1.remove(0);
					for(int k = arr2.size()-1; k >= 0; k--){
						if(arr2.get(k) > p1){
							p2 = arr2.get(k);
						}else{
							break;
						}
					}
					arr2.remove(p2);
					if (p1 > p2){
						score1++;
					}
				}
				
				for(int j = 0; j < b; j++){
					if(arry1.get(0) < arry2.get(0)){
						arry1.remove(0);
						arry2.remove(arry2.size()-1);
					}else{
						arry1.remove(0);
						arry2.remove(0);
						score2++;
					}
					
				}
				
				answer += "Case #" + (i+1) + ": " + score2 + " " +score1 + "\n";
			}
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}
		
		try {
			PrintWriter writer = new PrintWriter(new File(output));
			writer.print(answer);
			writer.close();
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}
		
	}
}
