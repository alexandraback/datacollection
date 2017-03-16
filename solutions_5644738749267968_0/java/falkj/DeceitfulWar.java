import java.io.FileReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;


public class DeceitfulWar {
	
	public static void main(String[] args) {
	    try {
	    	Scanner in = new Scanner(new FileReader("D:/input.txt"));
	    	PrintWriter writer = new PrintWriter("D:/output.txt", "UTF-8");
	    	int testCases = in.nextInt();
	    	for (int i = 1; i <= testCases; i++) {
	    		// set up data
	    		int size = in.nextInt();
	    		int scoreDeceitful = 0;
	    		int scoreWar = 0;
	    		// deceitful war
	    		List<Double> naomiBlocks = new ArrayList<Double>();
	    		List<Double> kenBlocks = new ArrayList<Double>();
	    		
	    		// war
	    		List<Double> naomiBlocks2 = new ArrayList<Double>();
	    		List<Double> kenBlocks2 = new ArrayList<Double>();
	    		
	    		// initialize blocks
	    		for (int j = 0; j < size; j++) {
	    			double temp = in.nextDouble();
	    			naomiBlocks.add(temp);
	    			naomiBlocks2.add(temp);
	    		}
	    		for (int j = 0; j < size; j++) {
	    			double temp = in.nextDouble();
	    			kenBlocks.add(temp);
	    			kenBlocks2.add(temp);
	    		}
	    		Naomi naomi = new Naomi(naomiBlocks, kenBlocks);
	    		Ken ken = new Ken(kenBlocks);
	    		
	    		
	    		// Naomi plays Deceitful War
	    		for(int j = 0; j < size; j++) {	
	    			double chosenNaomi = naomi.chooseDeceitfulBlock();
	    			double toldNaomi = naomi.sayChosenBlock();
	    			double chosenKen = ken.chooseBlock(toldNaomi);
	    			System.out.println("Chosen Naomi: " + chosenNaomi + "  Told Naomi: " + toldNaomi + " Chosen Ken: " + chosenKen);
	    			if(chosenNaomi > chosenKen) {
	    				scoreDeceitful++;
	    			}
	    		}
	    		
	    		naomi = new Naomi(naomiBlocks2, kenBlocks2);
	    		ken = new Ken(kenBlocks2);
	    		// TODO Naomi plays War optimally
	    		for(int j = 0; j < size; j++) {	
	    			double chosenNaomi = naomi.chooseWarBlock();
	    			double chosenKen = ken.chooseBlock(chosenNaomi);
	    	//		System.out.println("Chosen Naomi: " + chosenNaomi + "  Told Naomi: " + toldNaomi + " Chosen Ken: " + chosenKen);
	    			if(chosenNaomi > chosenKen) {
	    				scoreWar++;
	    			}
	    		}
	    		
	    		System.out.println();
	    		writer.println("Case #" + i + ": " + scoreDeceitful + " " + scoreWar);
	    	}
	    	writer.close();
	    	in.close();
	    } catch (Exception e) {
			e.printStackTrace();
		}
	}
}

class Naomi {
	private List<Double> blocks;
	private List<Double> kenBlocks;
	private double saidBlock = 0.0;
	
	Naomi(List<Double> blocks, List<Double> kenBlocks) {
		this.blocks = blocks;
		this.kenBlocks = kenBlocks;
		Collections.sort(this.blocks);
		Collections.sort(this.kenBlocks);
	}
	
	public double chooseDeceitfulBlock() {
		System.out.println("Naomi: " + this.blocks.toString());
		System.out.println("Ken: " + this.kenBlocks.toString());
		if(kenBlocks.get(kenBlocks.size() - 1) > blocks.get(blocks.size() - 1)) {
			saidBlock = kenBlocks.get(kenBlocks.size() - 1) - 0.0000001;
			return blocks.remove(0);
		} else {
			saidBlock = blocks.get(blocks.size() - 1);
			int i = 0;
			while(true) {
				if(kenBlocks.get(0) < blocks.get(i)) {
					return blocks.remove(i);
				}
				i++;
			}
			
		}
		
	}
	
	public double sayChosenBlock() {
		return saidBlock;
	}
	
	public double chooseWarBlock() {
		return blocks.remove(0);
	}
}

class Ken {
	
	private List<Double> blocks;
	
	Ken(List<Double> blocks) {
		this.blocks = blocks;
		Collections.sort(this.blocks);
	}
	
	public double chooseBlock(double toldNaomi) {
		for(int i = 0; i < blocks.size(); i++) {
			if(blocks.get(i) > toldNaomi)
				return blocks.remove(i);
		}
		return blocks.remove(0);
	}
}