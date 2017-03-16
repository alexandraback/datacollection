package commons;

public class Problem {
	int jackets, pants, shirts, repeat;
	long maxCombinations;
	
	public Problem (int nJackets, int nPants, int nShirts, int nPairRepeat) {
		this.jackets = nJackets;
		this.pants = nPants;
		this.shirts = nShirts;
		this.repeat = nPairRepeat;
	}
	
	public Result execute () {
		Result res = new Result();
		
		int s = 1;
		for (int j = 1; j <= jackets; j++) {
			for (int p = 1; p <= pants; p++) {
				for (int k = 0; k < repeat; k++) {
					res.addOutfit(j,p,s);
					s++;
					if (s > shirts) 
						break;
				}
			}
		}
		
		
		
		return res;
	}
}
