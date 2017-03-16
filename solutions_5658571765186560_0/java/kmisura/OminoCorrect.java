package com.ominous;

public class OminoCorrect {
	private int x;
	private int r;
	private int c;
	
	public OminoCorrect(String line){
		String tokens[] = line.split(" ");
		x = Integer.parseInt(tokens[0]);
		r = Integer.parseInt(tokens[1]);
		c = Integer.parseInt(tokens[2]);
	}
	
	public boolean richardWins(){
		if(x>7) return true;
		if(!((r*c)%x == 0)) return true;
		if(existsTooLargeOmino()) return true;
		if(x == 1) return false;
		if(x == 2 && (r%2 == 0 || c%2==0)) return false;
		
		return richardWinsByGraphSearch();
	}
	
	private boolean existsTooLargeOmino() {
		return (x>r && x>c) || x/2 > r || x/2 > c;
	}
	
	private boolean richardWinsByGraphSearch(){
		if (r == c) {
			return x > r;
		}
		
		int rows = Math.max(r, c);
		int cols = Math.min(r,c);
		
		int hmax = x - cols + 1;
		if (hmax < cols) {
			return false;
		}
		
		for (int h1 = 0; h1 <= hmax - 1; h1++) {
			for (int h2 = 0; h2 <= Math.min(x-cols-h1,hmax - 1 - h1); h2++) {
				for (int t = h1; t < x - cols; t++) {
					int b = x - cols - t;
					if(b < h2){
						break;
					}
					if(!isSolveable(t, rows-h1-h2-1)){
						return true;
					}
				}
			}
		}
		
		return false;
	}
	
	private boolean isSolveable(int t, int yRange) {
		int cols = Math.min(r, c);

		for (int y = 0; y < yRange; y++) {
			if ((t + y * cols) % x == 0) {
				return true;
			}
		}
		return false;
	}
}
