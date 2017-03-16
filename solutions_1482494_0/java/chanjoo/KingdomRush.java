package codejam;

public class KingdomRush extends Solver {

	public static void main(String...args) {
		KingdomRush solver = new KingdomRush();
//		solver.solveSample();
		solver.solveSmall(1);
	}
	
	public KingdomRush() {
		super('B');
	}
	
	@Override
	public String evaluate() {
		Stage[] stages = new Stage[in.nextInt()];
		for(int i=0; i<stages.length; i++) {
			stages[i] = new Stage(in.nextInt(), in.nextInt());
		}
		
		int play = 0;
		int power = 0;
		while(true) {
			int earn = 0;
			for(Stage stage: stages) {
				earn = stage.playFor2(power);
				if(earn>0) break;
			}
			if(earn>0) {
				play++;
				power+=earn;
				continue;
			}
			
			for(Stage stage: stages) {
				earn = stage.replayFor1(power);
				if(earn>0) break;
			}
			if(earn>0) {
				play++;
				power+=earn;
				continue;
			}
			
			for(Stage stage: stages) {
				earn = stage.playFor1(power);
				if(earn>0) break;
			}
			if(earn>0) {
				play++;
				power+=earn;
				continue;
			}
			
			for(Stage stage: stages) {
				if(!stage.complete()) {
					play = -1;
					break;
				}
			}
			break;
		}
		
		return play<0?"Too Bad":String.valueOf(play);
	}
	
	class Stage {
		int t1, t2, r;
		public Stage(int one, int two) {
			t1 = one;
			t2 = two;
			r=0;
		}
		
		public int replayFor1(int power) {
			if(r==1) {
				if(power>=t2) {
					r = 2;
					return 1;
				}
			}
			return 0;
		}
		
		public int playFor1(int power) {
			if(r==0) {
				if(power>=t1) {
					r = 1;
					return 1;
				}
			}
			return 0;
		}
		
		public int playFor2(int power) {
			if(r==0) {
				if(power>=t2) {
					r = 2;
					return 2;
				}
			}
			return 0;
		}
		
		public boolean complete() {
			return r==2;
		}
	}
}
