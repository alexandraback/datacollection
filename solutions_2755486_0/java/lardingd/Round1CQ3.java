package qualifierFun;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class Round1CQ3 {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		try {
			PrintWriter out = new PrintWriter(new FileWriter("output1c3.txt")); 
			BufferedReader in  = new BufferedReader(new FileReader("input.txt"));
			int answer =1;
			String strLine = in.readLine();
			int totalCases = Integer.parseInt(strLine);
			for(int i = 0; i < totalCases; i++) {
				strLine = in.readLine();
				String inputs[] = strLine.split(" ");
				int tribeNum = Integer.parseInt(inputs[0]);
				List<Tribe> tribes = new ArrayList<Tribe>();
				for(int j = 0; j < tribeNum; j++) {
					strLine = in.readLine();
					inputs = strLine.split(" ");
					Tribe tribe = new Tribe(Integer.parseInt(inputs[0]),
							Integer.parseInt(inputs[1]),
							Integer.parseInt(inputs[2]),
							Integer.parseInt(inputs[3]),
							Integer.parseInt(inputs[4]),
							Integer.parseInt(inputs[5]),
							Integer.parseInt(inputs[6]),
							Integer.parseInt(inputs[7]));
					tribes.add(tribe);
				}
				int fails = getFails(tribes);
				System.out.print(String.format("Case #%s: %s\n", answer, fails));
				out.write(String.format("Case #%s: %s\n", answer, fails));
				answer++;
			}
			out.close();
			in.close();
		} catch (FileNotFoundException e) {
			System.out.println("I'd want to know");
		} catch (IOException e) {
			System.out.println("I'd want to know io");
		}
		System.out.println("done");
	}
	
	private static int getFails(List<Tribe> tribes) {
		Wall wall = new Wall();
		int failures = 0;
		boolean anAttack = true;
		while (anAttack) {
			anAttack = false;
			for(Tribe tribe: tribes) {
				if(tribe.totalAttacks > 0) {
					anAttack = true;
				}
				if (wall.hits(tribe)) {
					failures ++;
				}
			}
			for(Tribe tribe: tribes) {
				wall.applyHeight(tribe);
				tribe.applyDay();
			}
		}
		return failures;
	}
	
	private static class Wall {
		//small range can use hashmap for simpleness (use every .5 to not deal with bounds)
		private static Map<Double, Integer> locToHeight;
		
		public Wall() {
			locToHeight = new HashMap<Double, Integer>();
		}
		
		public boolean hits(Tribe tribe) {
			if(!tribe.attacks()) {
				return false;
			}
			int start = tribe.curStart; 
			int end = tribe.curEnd;
			int height = tribe.startAttack;
			for(double i = start; i<= end;i += .5) {
				Integer cur = locToHeight.get(i);
				if (cur == null || cur < height) {
					return true;
				}
			}
			return false;
		}
		
		public void applyHeight(Tribe tribe) {
			if(!tribe.attacks()) {
				return;
			}
			int start = tribe.curStart; 
			int end = tribe.curEnd;
			int height = tribe.startAttack;
			for(double i = start; i<= end;i +=.5) {
				Integer cur = locToHeight.get(i);
				if (cur == null || cur < height) {
					locToHeight.put(i, height);
				}
			}
		}
	}
	
	private static class Tribe {
		int startDay;
		int totalAttacks;
		int curStart;
		int curEnd;
		int startAttack;
		int daysBetween;
		int travel;
		int strengthChange;
		
		int currentDay;
		public Tribe(int startDay, int totalAttacks, int curStart, int curEnd,
				int startAttack, int daysBetween, int travel, int strengthChange) {
			super();
			this.startDay = startDay;
			this.totalAttacks = totalAttacks;
			this.curStart = curStart;
			this.curEnd = curEnd;
			this.startAttack = startAttack;
			this.daysBetween = daysBetween;
			this.travel = travel;
			this.strengthChange = strengthChange;
			
			this.currentDay = 0;
		}
		
		public void applyDay() {
			if(currentDay < startDay) {
			}
			else if ((currentDay - startDay) % daysBetween == 0) {
				//there was an attack
				if(totalAttacks != 0) {
					totalAttacks--;
					curStart += travel;
					curEnd += travel;
					startAttack += strengthChange;
				}
				
			}
			currentDay ++;
			return;
		}
		
		public boolean attacks() {
			return (totalAttacks > 0) && (currentDay >= startDay) && ((currentDay - startDay) % daysBetween == 0);
		}
	}

}
