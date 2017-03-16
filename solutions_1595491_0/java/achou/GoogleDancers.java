import java.io.BufferedReader;
import java.io.DataInputStream;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.util.ArrayList;


public class GoogleDancers {
	
	public static void main(String[] args){
		
		try{
			// Open the file that is the first 
			// command line parameter
			FileInputStream fstream = new FileInputStream(args[0]);
			// Get the object of DataInputStream
			DataInputStream in = new DataInputStream(fstream);
			BufferedReader br = new BufferedReader(new InputStreamReader(in));
			String strLine;
			//Read File Line By Line
			int numTest = Integer.parseInt(br.readLine());
			for(int i = 0; i < numTest; i ++){
				String str = br.readLine();
				String numbers[] = str.split(" ");
				int num = Integer.parseInt(numbers[0]);
				ArrayList<Integer> scoreIntegers = new ArrayList<Integer>();
				for(int sc = 3; sc < numbers.length; sc++){
					scoreIntegers.add(new Integer(numbers[sc]));
				}
				int surpriseScorers= Integer.parseInt(numbers[1]);
				int bestScore= Integer.parseInt(numbers[2]);
				int currentSurpriseScorers = 0;
				int currentBestScorers = 0;
				int answer = 0;
				ArrayList<JudgeScoreTuple> canBeTurnedToSurprise = new ArrayList<JudgeScoreTuple>();
				ArrayList<JudgeScoreTuple> canBeTurnedToBestScore = new ArrayList<JudgeScoreTuple>();
				
				ArrayList<JudgeScoreTuple> tupleScores = bestResult(scoreIntegers);
				for(JudgeScoreTuple tuple : tupleScores){
					JudgeScores jsNonSurprise = tuple.getNonSurprise();
					if(jsNonSurprise!=null){
						if(jsNonSurprise.getMaxScore() >= bestScore){
							currentBestScorers ++;
							if(tuple.getSurprise()!=null){
								canBeTurnedToSurprise.add(tuple);
							}
						}
					}
					else{
						if(tuple.getSurprise().getMaxScore() >= bestScore){
							currentBestScorers++;
						}
						currentSurpriseScorers++;
					}
					if(!canBeTurnedToSurprise.contains(tuple)){
						JudgeScores jsSurprise = tuple.getSurprise();
						if(jsSurprise!=null){
							if(jsSurprise.getMaxScore()>=bestScore){
								canBeTurnedToBestScore.add(tuple);
							}
						}
					}
					
				}
				
				if(currentSurpriseScorers == surpriseScorers){
					answer = currentBestScorers;
				}
				
				
				if(currentSurpriseScorers < surpriseScorers){
					answer = currentBestScorers + Math.min(surpriseScorers, canBeTurnedToBestScore.size());
				}
				
				int x = i + 1;
				System.out.println("Case #" + x + ": " + answer);
				
				
			}
			//Close the input stream
			in.close();
		}catch (Exception e){//Catch exception if any
			System.err.println("Error: " + e.getMessage());
		}
		
		
	}
	
	public static ArrayList<JudgeScoreTuple> bestResult(ArrayList<Integer> scoreIntegers){
		ArrayList<JudgeScoreTuple> possibleJudgeScores = new ArrayList<JudgeScoreTuple>();
		for(Integer i : scoreIntegers){
			int sumJudgeScore = i.intValue();
			JudgeScores jc1 = null; 
			JudgeScores jc2 = null;
			if(sumJudgeScore % 3 == 0){
				jc1 = new JudgeScores(sumJudgeScore/3, sumJudgeScore/3, sumJudgeScore/3);
				if(sumJudgeScore/3 + -1 >=0 && sumJudgeScore/3 + 1 <= 10)
					jc2 = new JudgeScores(sumJudgeScore/3 -1 , sumJudgeScore/3, sumJudgeScore/3 + 1, true);
			}
			if(sumJudgeScore % 3 == 1){
				if(sumJudgeScore/3 + -1 >=0 && sumJudgeScore/3 + 1 <= 10){
					jc1 = new JudgeScores(sumJudgeScore/3, sumJudgeScore/3, sumJudgeScore/3 + 1);
					jc2 = new JudgeScores(sumJudgeScore/3 +1 , sumJudgeScore/3 + 1, sumJudgeScore/3 -1, true);
				}
			}
			if(sumJudgeScore % 3 == 2){
				if(sumJudgeScore/3 + 1 <= 10)
					jc1 = new JudgeScores(sumJudgeScore/3 +1 , sumJudgeScore/3 + 1, sumJudgeScore/3 );
				if(sumJudgeScore/3 + 2 <= 10)
					jc2 = new JudgeScores(sumJudgeScore/3, sumJudgeScore/3, sumJudgeScore/3 + 2, true);
				
			}
			possibleJudgeScores.add(new JudgeScoreTuple(jc1, jc2));
		}
		
		return possibleJudgeScores;
	}
	
	
}

