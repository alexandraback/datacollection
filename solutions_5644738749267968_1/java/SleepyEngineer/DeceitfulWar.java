package deceitfulWar;

import java.util.*;
import java.io.*;


public class DeceitfulWar {
	int res1;
	int res2;

	
	
	boolean allBigger(List<Double> firstBlocks1, List<Double> secondBlocks1){
		List<Double> secondBlocks2 = new ArrayList<Double>(secondBlocks1);
		Collections.reverse(secondBlocks2);
		int numBigger=0;
		for(int k = 0;k<firstBlocks1.size();k++){
				if (firstBlocks1.get(k) > secondBlocks2.get(k)){
					numBigger ++;
			}
		}
		if (numBigger == 0){
			//System.out.println("They are smaller!");
			return false;
		} else if (numBigger == firstBlocks1.size()){
			//System.out.println("They are all bigger!");
			return true;
		} else {
			//System.out.println("some are bigger: " + numBigger);
			return false;
		}
	}
	
	void Deceit(List<Double> firstBlocks, List<Double> secondBlocks){
		res1 = 0;
		List<Double> firstBlocks1 = new ArrayList<Double>(firstBlocks);
		List<Double> secondBlocks1 = new ArrayList<Double>(secondBlocks);
		
		Iterator<Double> i = firstBlocks1.iterator();
		
		
		Collections.reverse(secondBlocks1);
		
		while (i.hasNext()){
			i.next();
			//System.out.println("firstBlocks:" + firstBlocks1.toString());
			//System.out.println("secondBlocks:" + secondBlocks1.toString());
			if(allBigger(firstBlocks1,secondBlocks1)){
				res1 = firstBlocks1.size();
				//System.out.println("Deceit: " + res1);
				break;
			} else {
				i.remove();
				secondBlocks1.remove(0);
			}
		}
	}
	
	void War(List<Double> firstBlocks, List<Double> secondBlocks){
		Iterator<Double> i = firstBlocks.iterator();
		Iterator<Double> j = secondBlocks.iterator();
		res2 = 0;
		
		while (i.hasNext()){
			Double first = i.next();
			//System.out.println("firstBlocks:" + firstBlocks.toString());
			//System.out.println("secondBlocks:" + secondBlocks.toString());
			if(first > secondBlocks.get(secondBlocks.size()-1)){
				//System.out.println("first, " + first + " is greater than last of second, " + secondBlocks.get(secondBlocks.size()-1) + ", so  WarResult = " + (res2+1)); 
				i.remove();
				secondBlocks.remove(0);
				res2 ++;
			} else {
				while (j.hasNext()){
					Double second = j.next();
					if( second > first){
						//System.out.println("Second, " + second + " is greater than first, " + first + ", so WarResult = " + res2); 
						i.remove();
						j.remove();
						break;
					}
				}
			}
		}
	}
	
	void solve(List<Double> firstBlocks, List<Double> secondBlocks){
		
		Deceit(firstBlocks,secondBlocks);
		War(firstBlocks,secondBlocks);
		
	}

	public void doMain() throws Exception {
		Scanner fr = new Scanner(new FileReader("src/deceitfulWar/D-large.in"));
		PrintWriter fw = new PrintWriter(new FileWriter("src/deceitfulWar/D-large.out"));
		
		int caseCnt = fr.nextInt();
		
		long time = System.currentTimeMillis();
		
		for (int caseNum=1; caseNum <= caseCnt; caseNum++) {
			
			int arraySize = fr.nextInt();
			List<Double> firstBlocks = new ArrayList<>();
			List<Double> secondBlocks = new ArrayList<>();
			
			for(int i=0;i<arraySize;i++){
				firstBlocks.add(fr.nextDouble());
			}
			
			for(int i=0;i<arraySize;i++){
				secondBlocks.add(fr.nextDouble());
			}
			Collections.sort(firstBlocks);
			Collections.sort(secondBlocks);
			solve(firstBlocks,secondBlocks);
			
			fw.println("Case #" + caseNum + ": " + res1 + " " + res2);
			
			System.out.println("Finished " + caseNum + " in " + (System.currentTimeMillis() - time) + "ms.\n");
		}
		
		fw.flush();
		fw.close();
		fr.close();
	}
	
	public static void main(String[] args) throws Exception {
		(new DeceitfulWar()).doMain();
	}
}
