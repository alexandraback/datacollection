package problems;

import io.FrontJam;

import java.util.HashMap;

public class Cook {
	FrontJam problemSet;

	double c = 0.0;
	double f = 0.0;
	double x = 0.0;
	
	double rate = 2.0; //rate starts at 2
	double time = 0.0;
	
	
	public Cook(){
		problemSet = new FrontJam("C:\\Users\\M\\Downloads\\A-small-practice (3).in", 1);

	}

	
	public Cook(String file){
		problemSet = new FrontJam(file, 1);
	}
	
	public void closeProblems(){
		problemSet.closeFileOut();
	}
	
	public void solveSet(){
		for(int i = 0; i <problemSet.getNumberOfCases();i++){
			loadNextProblem();
			double answer = solve();
			problemSet.answerCurrentProblem(answer+"");
		}
		problemSet.closeFileOut();
	}
	
	public double solve(){
		boolean won = false;
		while(!won){
			if(timeTilWin() < timeTilFarmWin()){
				return time + timeTilWin();
			}
			else{
				time += timeTilFarm();
				rate += f;
			}
		}
		
		return time;
	}
	
	
	public double timeTilFarm(){
		return c / rate;
	}
	
	public double timeTilWin(){
		return x / rate;
	}
	
	public double timeTilFarmWin(){
		return (c/rate)+(x/(rate+f));
	}
	
	
	public void loadNextProblem(){
		String prob = problemSet.getNextProblem();
		String splitSet[] = prob.split(" ");
		c = Double.parseDouble(splitSet[0]);
		f = Double.parseDouble(splitSet[1]);
		x = Double.parseDouble(splitSet[2]);
		 rate = 2.0; //rate starts at 2
		 time = 0.0;
		
	}
}
