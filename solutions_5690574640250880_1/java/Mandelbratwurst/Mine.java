package problems;

import io.FrontJam;

public class Mine {
	FrontJam problemSet;

	int r;
	int c;
	int m;
	


	
	public Mine(String file){
		problemSet = new FrontJam(file, 1);
	}
	
	public void closeProblems(){
		problemSet.closeFileOut();
	}
	
	public void solveSet(){
		for(int i = 0; i <problemSet.getNumberOfCases();i++){
			loadNextProblem();
			boolean solvable = solve();
			String answer = "\n";
			
			if(solvable){
				answer += gen();
				validate(answer);
			}
			else{
				answer += "Impossible";
			}
			
			
			problemSet.answerCurrentProblem(answer+"");
		}
		problemSet.closeFileOut();
	}
	
	public void validate(String in){
		//check dimensions
		in = in.substring(1);
		String split[] = in.split("\n");
		if(split[0].length() != c){
			System.out.println("ERROR - INCORRECT COL");
		}
		if(split.length != r){
			System.out.println("ERROR - INCORRECT ROW");
		}
		
		//count mines
		int count = 0;
		for(int i = 0; i < r; i ++){
			for(int j = 0; j < c; j ++){
				if(split[i].charAt(j) == '*'){
					count++;
				}
			}
		}
		if(count != m){
			System.out.println("ERROR - INCORRECT MINES");
		}
		
	}
	
	public String smallBoard(){
		String out = "";
		int mineCount = 0;
		mineCount+=m;
		if(c == 1){
			for(int i = 0; i < r - 1; i ++){
				if(mineCount>0){
					out += "*\n";
					mineCount--;
				}
				else{
					out += ".\n";
				}
			}
			out += "c";
			return out;
		}
		else{
			for(int i = 0; i < c - 1; i ++){
				if(mineCount>0){
					out += "*";
					mineCount--;
				}
				else{
					out += ".";
				}
			}
			out += "c";
			return out;
		}
	}
	
	public String gen(){
		int total = r * c;
		int empty = total - m;
		int mineCount = 0;
		int rowCount = 0;
		mineCount+=m;
		//generate the board
		String board = "";
		String row = "";
		
		//special case 1 row or col
		if(r == 1 || c == 1){
			return smallBoard();
		}
		
		//mark the mines
		while(mineCount > 0){
			row = "";
			//for each row
				
				//special case where only two rows remain
				if(rowCount >= r - 2){
					//place half the mines and print twice
					//for each column
					for(int j = 0; j < c; j++){
						if(mineCount>0){
							row += "*";
							mineCount = mineCount-2;
						}
						else{
							row += ".";
						}

					}
					row+="\n";
					board+=row;
					row = row.substring(0, row.length()-2);
					row+="c";
					board+=row;
					return board;
				}
						
			
				//special case where we need to skip a row
				if((mineCount+1)==c){
					//special special case where we are skipping at the 3rd from last line
					if((empty-1)%c==0){
						//if that point is the 3rd from last row
						if((empty-1)/c==2){
							//for each column
							for(int j = 0; j < c - 3; j++){
								row += "*";
								mineCount--;
							}
							row += ".";
							row += ".";
							row += ".";
							row += "\n";
							board += row;
							rowCount++;
							
							//for each column
							row = "*";
							mineCount--;
							for(int j = 0; j < c - 1; j++){
								row += ".";
							}
							row+="\n";
							board += row;
							rowCount++;
							row = "";
							//for each column
							row = "*";
							mineCount--;
							for(int j = 0; j < c - 2; j++){
								row += ".";
							}
							row+="c";
							board += row;
							rowCount++;
							return board;
						}
					}
					
					//for each column
					for(int j = 0; j < c - 2; j++){
						row += "*";
						mineCount--;
					}
					row += ".";
					row += ".";
					row += "\n";
					board += row;
					rowCount++;
			
					//for each column
					row = "*";
					mineCount--;
					for(int j = 0; j < c - 1; j++){
						row += ".";
					}
					row+="\n";
					board += row;
					rowCount++;
					row = "";
				}
				
				//special case where we have one left over going to the second line
				if(mineCount == 6 && r-rowCount == 3 && c >= 5){
					row = "**";
					for(int i = 0; i < c-2;i++){
						row+= ".";
					}
					row+="\n";
					board+= row;
					board+= row;
					row = "**";
					for(int i = 0; i < c-3;i++){
						row+= ".";
					}
					row+="c";
					board+= row;
					return board;
				}
				
				
				
				if(mineCount>0){
				//fill a full row with mines
				//for each column
				for(int j = 0; j < c; j++){
					if(mineCount > 0){
						row += "*";
						mineCount--;
					}
					else{
						row += ".";
					}
					
				}
				row+="\n";
				board+=row;
				row ="";
				rowCount++;
				}
			
		}
		
		//fill rest with empty
		//for each row remain
		
		for(int i = 0; i < r-rowCount-1;i++){
			row = "";
			//for each col
			for(int j = 0; j < c; j++){
				row += ".";				
			}
			row+="\n";
			board+=row;
			
		}
		
		row ="";
		for(int i = 0; i < c-1;i++){
			row+=".";
		}
		row+="c";
		board+=row;
		
		return board;
	}
	
	public boolean solve(){
		if(m==0){
			return true;
		}
		
		//special case - one row or col always works
		if(r == 1 || c == 1){
			return true;
		}
		
		int total = r * c;
		int empty = total - m;
		
		if(empty == 1){
			return true;
		}
		
		//these can never work
		if(empty == 2 || empty == 3 || empty == 5 || empty == 7){
			return false;
		}
		
		//if there are only two rows remaining then odd # of empty blocks fail
		if(r == 2){
			if(empty%2==1){
				return false;
			}
		}
		
		//like previous case but with col
		if(c == 2){
			if(empty%2==1){
				return false;
			}
		}
		
		//special case - not always a failure
		if(empty < c*2){
			//true;
		}
		
		//if you have to skip a row at the 3rd row from the bottom it's impossible
		//if you have to skip a row at some point
		if((empty-1)%c==0){
			//if that point is the 3rd from last row
			if((empty-1)/c==2){
				if(c==3){
					return false;
					
				}
				return true;
			}
		}
		//if you have to skip at the 3rd from bottom then you need to  fill it

		return true;
	}
	
	
	
	
	
	public void loadNextProblem(){
		String prob = problemSet.getNextProblem();
		prob = prob.substring(0, prob.length()-1);
		String splitSet[] = prob.split(" ");
		r = Integer.parseInt(splitSet[0]);
		c = Integer.parseInt(splitSet[1]);
		m = Integer.parseInt(splitSet[2]);
		
		
	}
}
