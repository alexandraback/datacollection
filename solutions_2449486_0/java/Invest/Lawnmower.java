
public class Lawnmower {

	public String isPossiblePattern(int[][] grass) {
		
		for (int i = 0; i < grass.length; i++) {
			for (int j = 0; j < grass[0].length; j++) {
				
				boolean hor = false;
				boolean ver = false;
				for (int k = 0; k < grass[0].length; k++) {
					if (grass[i][k] > grass[i][j]) hor = true;
				}
				for (int l = 0; l < grass.length; l++) {
					if (grass[l][j] > grass[i][j]) ver = true;
				}
				if (hor && ver) return "NO";
			}
		}
		return "YES";
	}
}
