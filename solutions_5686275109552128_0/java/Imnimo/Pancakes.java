import java.io.File;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;


public class Pancakes {
	public static void main(String[] args) throws Exception {
		
		Scanner s = new Scanner(new File("B-small-attempt3.in"));
		
		int numCases = Integer.parseInt(s.nextLine());
		for(int currentCase = 1;currentCase<=numCases;currentCase++) {
			int numDiners = Integer.parseInt(s.nextLine());
			String plateSizes = s.nextLine();
			String[] platesStrings = plateSizes.split("\\s+");
			ArrayList<Integer> plates = new ArrayList<Integer>();
			for(int i = 0;i<numDiners;i++) {
				plates.add(Integer.parseInt(platesStrings[i]));
			}
			//System.out.println(plates);
			System.out.println("Case #" + currentCase + ": " + smallestTime(plates));
		}
	}
	
	static int[] splits = new int[]{0,1,1,1,2,2,3,3,4,3,3};
	
	public static int smallestTime(ArrayList<Integer> plates) {
		//System.out.println(plates);
		if(plates.size()==0) {
			return 0;
		}
		
		ArrayList<Integer> platesAfterMinute = new ArrayList<Integer>();
		for(Integer i : plates) {
			if(i>1)
			platesAfterMinute.add(i-1);
		}
		int eatingTime = 1+smallestTime(platesAfterMinute);
		
		int splittingTime = Integer.MAX_VALUE;
		
		
			
		Collections.sort(plates);
		if(plates.get(plates.size()-1)>3) {
			int biggest = plates.remove(plates.size()-1);
			int split = splits[biggest];
			int remainder = biggest - split;
			//System.out.println(plates + " splitting " + biggest + " into " + split + " and " + remainder);
			//System.exit(1);
			plates.add(split);
			plates.add(remainder);
			splittingTime = 1+smallestTime(plates);
		}
		return Math.min(eatingTime,splittingTime);
	
		
	}
	
	
	/*public static int smallestTime(ArrayList<Integer> plates) {
		//System.out.println(plates);
		if(plates.size()==0) {
			return 0;
		}
		
		ArrayList<Integer> platesAfterMinute = new ArrayList<Integer>();
		for(Integer i : plates) {
			if(i>1)
			platesAfterMinute.add(i-1);
		}
		int eatingTime = 1+smallestTime(platesAfterMinute);
		
		int splittingTime = Integer.MAX_VALUE;
		HashSet<Integer> sizesSplit = new HashSet<Integer>();
		for(int index = 0;index<plates.size();index++) {
			if(plates.get(index)>3 && !sizesSplit.contains(plates.get(index))) {
				sizesSplit.add(plates.get(index));
				
				for(int splitSize = 1;splitSize<=plates.get(index)/2;splitSize++) {
				
					ArrayList<Integer> platesAfterSplit = new ArrayList<Integer>();
					for(int i = 0;i<plates.size();i++) {
						if(i==index) {
							platesAfterSplit.add(splitSize);
							platesAfterSplit.add(plates.get(i)-splitSize);
						} else {
							platesAfterSplit.add(plates.get(i));
						}
					}
					int result = 1+smallestTime(platesAfterSplit);
					if(result<splittingTime) splittingTime=result;
					if(plates.size()==1)
					System.out.println(plates + " Splitting " + plates.get(index) + " into " + splitSize + " gives " + result + " => " + splits[plates.get(index)]);
				}
			}
		}
		
		return Math.min(eatingTime, splittingTime);
		
	}*/
	
	/*public static int smallestTime(ArrayList<Integer> plates) {
		Collections.sort(plates);
		int result = 0;
		while(plates.get(plates.size()-1)>3) {
			
			int largest = plates.remove(plates.size()-1);
			int split = largest/2;
			int remainder = largest - split;
			System.out.println("Splitting " + largest + " into " + split + " and " + remainder);
			plates.add(split);
			plates.add(remainder);
			Collections.sort(plates);
			result++;
		}
		result+=plates.get(plates.size()-1);
		return result;
		
		
	}*/
}
