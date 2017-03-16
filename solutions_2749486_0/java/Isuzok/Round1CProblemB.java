import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.DataInputStream;
import java.io.FileInputStream;
import java.io.FileWriter;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.LinkedList;
import java.math.*;


public class Round1CProblemB {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Round1CProblemB hi = new Round1CProblemB();
	}
	
	public Round1CProblemB(){
		parser();
	}

	public void parser(){
		try{
			FileInputStream fstream = new FileInputStream("B-small-attempt1.in");
			//FileInputStream fstream = new FileInputStream("textfile.txt");
			DataInputStream in = new DataInputStream(fstream);
			BufferedReader br = new BufferedReader(new InputStreamReader(in));
			
			FileWriter outstream = new FileWriter("output.txt");
			BufferedWriter out = new BufferedWriter(outstream);
			
			int length = Integer.parseInt(br.readLine());
			String split[];
			for(int i = 0; i < length; ++i){
				split = br.readLine().split(" ");
				//Get N and M
				int goalX = Integer.parseInt(split[0]);
				int goalY = Integer.parseInt(split[1]);
				
				int x = 0;
				int y = 0;
				int numberOfStepsToMove = 1;
				String moveStr = "";
				while(x != goalX || y != goalY){
					
					if(x != goalX){
						if(stepsLeft(goalX, x) > numberOfStepsToMove){
							if(goalX > x){
								moveStr += "E";
								x += numberOfStepsToMove;
								numberOfStepsToMove++;
							} else{
								moveStr += "W";
								x -= numberOfStepsToMove;
								numberOfStepsToMove++;
							}
						} else{
							if(stepsLeft(goalY, y) > numberOfStepsToMove){
								
							} else {
								if(goalX > x){
									moveStr += "WE";
									x++;
									numberOfStepsToMove += 2;
								} else{
									moveStr += "EW";
									x--;
									numberOfStepsToMove += 2;
								}
							}
						}
					}
					
					if(y != goalY){
						if(stepsLeft(goalY, y) > numberOfStepsToMove){
							if(goalY > y){
								moveStr += "N";
								y += numberOfStepsToMove;
								numberOfStepsToMove++;
							} else{
								moveStr += "S";
								y -= numberOfStepsToMove;
								numberOfStepsToMove++;
							}
						} else{
							if(goalY > y){
								moveStr += "SN";
								y++;
								numberOfStepsToMove += 2;
							} else{
								moveStr += "NS";
								y--;
								numberOfStepsToMove += 2;
							}
						}
					}
				}
				
//				int x1 = 0;
//				int y1 = 0;
//				int steps = 1;
//				
//				for(int i1 = 0; i1 < moveStr.length(); ++i1){
//					if(moveStr.charAt(i1) == 'N'){
//						y1 += steps;
//						steps++;
//					} else if(moveStr.charAt(i1) == 'S'){
//						y1 -= steps;
//						steps++;
//					} else if(moveStr.charAt(i1) == 'E'){
//						x1 += steps;
//						steps++;
//					} else if(moveStr.charAt(i1) == 'W'){
//						x1 -= steps;
//						steps++;
//					}
//				}
//				
//				System.out.println(x1 + " " + y1);
				
				System.out.println("Case #" + (i+1) + ": " + moveStr);
				out.write("Case #" + (i+1) + ": " + moveStr);
				out.newLine();
				out.flush();
				
			}
		}
		catch(Exception e){
			System.err.println("Error: " + e.getMessage());
			System.out.println("Bah!");
			e.printStackTrace();
		}
	}
	
	private int stepsLeft(int goal, int pos){
		if(goal < 0){
			if(pos <= goal){
				return (goal-pos);
			}
			else{
				return (goal-pos)*-1;
			}
		} else {
			if(pos <= goal){
				return (goal-pos);
			}
			else{
				return (goal-pos)*-1;
			}
		}
	}
}
