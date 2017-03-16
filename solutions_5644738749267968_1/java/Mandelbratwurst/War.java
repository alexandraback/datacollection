package problems;

import java.util.ArrayList;
import java.util.Collections;

import io.FrontJam;

public class War {
	FrontJam problemSet;

	int n = 0;
	
	
	ArrayList<Double> naomi;
	ArrayList<Double> ken;
	
	
	public War(){
		problemSet = new FrontJam("C:\\Users\\M\\Downloads\\A-small-practice (3).in", 3);

	}

	
	public War(String file){
		problemSet = new FrontJam(file, 3);
	}
	
	public void closeProblems(){
		problemSet.closeFileOut();
	}
	
	public void solveSet(){
		for(int i = 0; i <problemSet.getNumberOfCases();i++){
			loadNextProblem();
			String answer = solve();
			problemSet.answerCurrentProblem(answer+"");
		}
		problemSet.closeFileOut();
	}
	
	public String solve(){
		//solve deceitful then naive
		int naive = solveNaive();
		int deceit4 = solveDeceit5();

		
		return ""+deceit4 + " "+naive;
	}
	
	public int solveNaive(){
		//just pick any from Naomi and the smallest block greater than naomi's for ken
		//or if ken can't beat her pick the smallest in inventory
		int naomiScore = 0;
		int offset = 0;
		for (int i = 0; i < n ; i++){
			//pick next largest for naomi
			double Cn = naomi.get(i);
			
			if(Cn < ken.get(i-offset)){
				//select this one, ken gains a point
				//naomi gains nothing
			}
			else{
				//select smallest block for ken, offset by 1 
				//to simulate removing a block from the end
				offset ++;
				//naomi wins a point
				naomiScore ++;
			}
			
		}
		
		return naomiScore;
	}

	
	public int solveNaive2(){
		//just pick any from Naomi and the smallest block greater than naomi's for ken
		//or if ken can't beat her pick the smallest in inventory
		int naomiScore = 0;
		int offset = 0;
		
		Collections.reverse(ken);
		for (int i = 0; i < n ; i++){
			//pick next largest for naomi
			double Cn = naomi.get(i);
			
			if(Cn < ken.get(i-offset)){
				//select this one, ken gains a point
				//naomi gains nothing
			}
			else{
				//select smallest block for ken, offset by 1 
				//to simulate removing a block from the end
				offset ++;
				//naomi wins a point
				naomiScore ++;
			}
			
		}
		Collections.reverse(ken);
		
		return naomiScore;
	}
	
	
	
	public int solveDeceit4(){
		int offset = 0;
		double Bn = naomi.get(0); //naomi's biggest
		double Ck = ken.get(n-1); //ken smallest
		for(int i = 0; i<n; i++){
			double Cn = naomi.get(n-i-1); //naomi's next smallest
			double Bk = ken.get(i); //ken's next biggest
			
			if(Cn<Ck || Bn<Bk){
				offset++;
			}
			else{
				i = n;
			}
		}
		
		return solveNaiveOffset(offset);
	}
	
	
	public int solveDeceit5(){
		int offset = 0;
		double Bn = naomi.get(0); //naomi's biggest
		double Ck = ken.get(n-1); //ken smallest
		for(int i = 0; i<n; i++){
			double Cn = naomi.get(n-i-1); //naomi's next smallest
			double Bk = ken.get(i); //ken's next biggest
			
			if(Cn<Ck || Bn<Bk){
				offset++;
			}
			else{
				i = n;
			}
		}
		
		return solveNaiveOffset5(offset);
	}
	public int solveNaiveOffset5(int off){
		int points = 0;
		int koffset = 0;
		ArrayList<Double> shortN = new ArrayList<Double>();
		ArrayList<Double> shortK = new ArrayList<Double>();
		for(int i = 0; i < n-off;i ++){
			shortN.add(naomi.get(i));
			shortK.add(ken.get(i+off));
		}
		
		//smallest to largest, lie giant if bigger, lie just under k biggest if smaller
		//that is: if N > K +1 pt, N < K offset ken by +1
		for(int i = 0; i < n-off;i++){
			if(shortN.get(n-off-1-i) > shortK.get(n-off-1-i+koffset)){
				points++;
			}
			else{
				koffset++;
			}
		}
		
		
		return points;
	}
	
	
	
	public int solveNaiveOffset(int off){
		//just pick any from Naomi and the smallest block greater than naomi's for ken
		//or if ken can't beat her pick the smallest in inventory
		//shorten arrays by off
		ArrayList<Double> shortN = new ArrayList<Double>();
		ArrayList<Double> shortK = new ArrayList<Double>();
		for(int i = 0; i < n-off;i ++){
			shortN.add(naomi.get(i));
			shortK.add(ken.get(i+off));
		}
		
		Collections.reverse(shortK);
		
		int naomiScore = 0;
		int offset = 0;
		for (int i = 0; i < n-off ; i++){
			//pick next largest for naomi
			double Cn = shortN.get(i);
			
			
			
			if(Cn < shortK.get(i-offset)){
				//select this one, ken gains a point
				//naomi gains nothing
			}
			else{
				//select smallest block for ken, offset by 1 
				//to simulate removing a block from the end
				offset ++;
				//naomi wins a point
				naomiScore ++;
			}
			
		}
		
		return naomiScore;
		
		
	}
	

	
	
	public void loadNextProblem(){
		String prob = problemSet.getNextProblem();
		String splitSet[] = prob.split("\n");
		//first line is n
		n = Integer.parseInt(splitSet[0]);
		naomi = new ArrayList<Double>();
		ken = new ArrayList<Double>();
		//naomi blocks
		String splitblocks[] = splitSet[1].split(" ");
		for(int i = 0; i < n; i++){
			naomi.add(Double.parseDouble(splitblocks[i]));
		}
		
		//ken blocks
		splitblocks = splitSet[2].split(" ");
		for(int i = 0; i < n; i++){
			ken.add(Double.parseDouble(splitblocks[i]));
		}
		Collections.sort(ken);
		Collections.sort(naomi);
		
		Collections.reverse(ken);
		Collections.reverse(naomi);
	}
	

}
