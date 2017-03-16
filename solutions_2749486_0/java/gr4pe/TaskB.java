package template;

import util.InputParser;
import util.OutputGenerator;

public class TaskB {

	static final OutputGenerator og = new OutputGenerator();
	static final InputParser ip = new InputParser("input/B-small-attempt0.in", og);
	
	public static void main(String[] args) {
		
		ip.skip();
		while(true) {
			int[] arr = ip.ia();
			int x = arr[0], y = arr[1];
			
			String res = "";
			
			if(x>0)
				res += moveEast(x);
			if(x<0)
				res += moveWest(-x);
			if(y>0)
				res += moveNorth(y);
			if(y<0)
				res += moveSouth(-y);
			og.oCase(res);
		}
		
		

		
		
		
		
		
		
	}
	
	static final String moveNorth(int dist) {
		StringBuilder res = new StringBuilder();
		for(int i=0; i<dist; i++) {
			res.append("SN");
		}
		return res.toString();
	}
	
	
	static final String moveSouth(int dist) {
		StringBuilder res = new StringBuilder();
		for(int i=0; i<dist; i++) {
			res.append("NS");
		}
		return res.toString();
	}
	
	static final String moveEast(int dist) {
		StringBuilder res = new StringBuilder();
		for(int i=0; i<dist; i++) {
			res.append("WE");
		}
		return res.toString();
	}
	
	
	static final String moveWest(int dist) {
		StringBuilder res = new StringBuilder();
		for(int i=0; i<dist; i++) {
			res.append("EW");
		}
		return res.toString();
	}
}
