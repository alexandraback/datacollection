package knucle.y2011;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;

public class A {

	public static void main(String[] args) throws Exception {
		
		FileReader fr = new FileReader("A-large-practice.in");
		BufferedReader br = new BufferedReader(fr);
		
		BufferedWriter bw = new BufferedWriter(new FileWriter("output.txt"));

		int currentCase = 1;
		int caseNum = Integer.parseInt(br.readLine());
		
		for(currentCase=1; currentCase<=caseNum; currentCase++){
			String line = br.readLine();
				
			String[] inputs = line.split(" ");
			int stepNum = Integer.parseInt(inputs[0]);
			
			Robot orangeRobot = new Robot();
			Robot blueRobot = new Robot();
			
			for(int i=0; i<stepNum; i++){
				String color = inputs[i*2+1];
				int buttonPosition = Integer.parseInt(inputs[i*2+2]);
				
				if(color.equals("B")){
					blueRobot.doTask(buttonPosition);
					
					int orangeTurn = orangeRobot.getCurrentTurn();
					if(blueRobot.getCurrentTurn() <= orangeTurn){
						blueRobot.setCurrentTurn(orangeTurn + 1);
					}
				} else if(color.equals("O")){
					orangeRobot.doTask(buttonPosition);

					int blueTurn = blueRobot.getCurrentTurn();
					if(orangeRobot.getCurrentTurn() <= blueTurn){
						orangeRobot.setCurrentTurn(blueTurn + 1);
					}
				}
			}
			
			bw.write("Case #");
			bw.write(Integer.toString(currentCase));
			bw.write(": ");
			bw.write(Integer.toString(Math.max(orangeRobot.getCurrentTurn(), blueRobot.getCurrentTurn())));
			bw.write('\n');
		}
		
		br.close();
		bw.close();
	}
	
	private static class Robot {
		int position = 1;
		int currentTurn = 0;
		
		int getTurnToFinishTask(int currentTask){
			return Math.abs(currentTask - position) + 1;
		}
		
		void doTask(int task){
			int turnToFinishTask = getTurnToFinishTask(task);
			currentTurn += turnToFinishTask;
			position = task;
		}
		
		public int getCurrentTurn() {
			return currentTurn;
		}
		
		public void setCurrentTurn(int currentTurn) {
			this.currentTurn = currentTurn;
		}
	}

}
