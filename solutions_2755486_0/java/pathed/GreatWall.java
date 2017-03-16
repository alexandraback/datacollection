package se.pathed.codejam.GreatWall;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.PriorityQueue;


public class GreatWall {
	public BufferedReader getInputReader(String fileName) throws FileNotFoundException{
		String dataFolder = "C:\\Users\\Patrik\\workspaces\\codejam\\Practis\\data\\";
		File f = new File(dataFolder + fileName);
		FileReader fReader = new FileReader(f);
		BufferedReader reader = new BufferedReader(fReader);
		
		return reader;
	}
	
	public PrintWriter getOutputWriter(String fileName) throws FileNotFoundException{
		String dataFolder = "C:\\Users\\Patrik\\workspaces\\codejam\\Practis\\data\\";
		File outputFile = new File(dataFolder + fileName);
		if( outputFile.exists()) outputFile.delete();
		return new PrintWriter(outputFile);
	}
	
	public static void main(String args[]) throws Exception{
		new GreatWall().run();
	}
	
	static class Problem{
		Tribes[] tribes;
	}
	static class Tribes {
		int days,numAttacks, west,east,s,deltaDays,deltaP,deltaS;
		int nextAttack;
		
	}
	
	Problem parseProblem(BufferedReader r) throws IOException {
		Problem p = new Problem();
		int tCount = Integer.parseInt(r.readLine());
		p.tribes = new Tribes[tCount];
		for(int i = 0; i < tCount; i++){
			Tribes t = new Tribes();
			String[] line = r.readLine().split(" ");
			t.days = Integer.parseInt(line[0]);
			t.numAttacks = Integer.parseInt(line[1]);
			t.west = Integer.parseInt(line[2]);
			t.east = Integer.parseInt(line[3]);
			t.s = Integer.parseInt(line[4]);
			t.deltaDays = Integer.parseInt(line[5]);
			t.deltaP = Integer.parseInt(line[6]);
			t.deltaS = Integer.parseInt(line[7]);
			
			p.tribes[i] = t;
		}
		return p;
	}

	private void run() throws IOException {
		BufferedReader reader = getInputReader("C-small-attempt0.in");
		PrintWriter output = getOutputWriter("out.txt");
		int c = Integer.parseInt(reader.readLine());
		for(int i = 0; i < c; i++){
			Problem p = parseProblem(reader);
			int res = solve(p);
			String answer = "Case #" + (i+1) + ": " + res;
			System.out.println(answer);
			output.println(answer);
		}
		output.flush();
		output.close();
	}
	
	int[] wall = new int[1000000];
	public int getIndex(int x){
		return x + 10000;
	}
	int successfullAttacks = 0;
	
	private int solve(Problem p) {
		successfullAttacks = 0;
		wall = new int[1000000];
		PriorityQueue<Tribes> attackQueue = new PriorityQueue<>(p.tribes.length,comp);
		for(Tribes t : p.tribes){
			attackQueue.add(t);
		}
//		System.out.println("Lengt of queue: " + attackQueue.size());
		while(true){
			ArrayList<Tribes> list = new ArrayList<Tribes>(); 
			ArrayList<Tribes> success = new ArrayList<Tribes>();
			
			Tribes tF = attackQueue.poll();
			if( tF == null) return successfullAttacks;
			
			int attackDay = tF.days;
			list.add(tF);
			while(attackQueue.peek() != null && attackQueue.peek().days == attackDay){
				list.add(attackQueue.poll());
			}
			
			// Check successfull attack
			
			for( Tribes t : list){
//				System.out.println("West="+ t.west + "East=" + t.east);
//				System.out.println("Attacking on day: " + t.days + " at " + t.west + " - " + t.east + " at hight: "+ t.s);
				
				for(int i = t.west; i < t.east; i++){
					if(wall[getIndex(i)] < t.s){
//						System.out.println("Success " + i);
						success.add(t);
						break;
					}
				}
			}
//			System.out.println("Success completed");
			successfullAttacks += success.size();
			// Repair the wall
			for( Tribes t : success ){
				for(int i = t.west; i < t.east; i++){
					if(wall[getIndex(i)] < t.s){
						wall[getIndex(i)] = t.s;
					}
				}
			}
			
			// Update attacks
			for(Tribes t : list){
				if(t.numAttacks > 1) {
					t.numAttacks -=1;
					t.days += t.deltaDays;
					t.east += t.deltaP;
					t.west += t.deltaP;
					t.s  += t.deltaS;
					attackQueue.add(t);
				}
			}
		}
	}
	
	private String getWall() {
		StringBuilder sb = new StringBuilder();
		for(int i = 0; i < 15; i++) {
			sb.append("," + wall[i]);
		}
		return sb.toString();
	}

	Comparator<Tribes> comp = new Comparator<GreatWall.Tribes>() {
		
		@Override
		public int compare(Tribes o1, Tribes o2) {
			return o1.days - o2.days;
		}
	};
}
