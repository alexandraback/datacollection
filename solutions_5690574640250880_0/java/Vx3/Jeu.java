
public class Jeu {

	private boolean grid[][]; 
	private final int initialLongueur;
	private final int initialLargeur;
	private final int minesInitial;
	private int mines;
	private int longueur;
	private int largeur;
	
	public Jeu(String string) {
		String[] split = string.split(" ");
		grid = new boolean[Integer.valueOf(split[0])][Integer.valueOf(split[1])];
		mines = Integer.valueOf(split[2]);
		longueur = Integer.valueOf(split[0]);
		largeur = Integer.valueOf(split[1]);
		initialLongueur = longueur;
		initialLargeur = largeur;
		minesInitial = mines;
	}
	
	public String compute() {
		if (initialLongueur != 1 && initialLargeur != 1) {
			if (initialLongueur * initialLargeur - mines == 2 || initialLongueur * initialLargeur - mines == 0) {
				return "Impossible";
			}
		}
		if (mines == 0) {
			return this.toString();
		}
		int a;
		while ((a = remplirLigne()) == 1) {
		}
		if (a == -1) {
			return "Impossible";
		}
		
		return this.toString();
	}

	// true remplir la même colonne, false la ligne
	public boolean sens() {
		if (longueur > largeur) {
			return false;
		}
		return true;
	}
	
	public int[] trouveProchaineCaseVide() {
		for (int i = 0; i < initialLongueur; i++) {
			for (int j = 0; j < initialLargeur; j++) {
				if (grid[i][j] == false) {
					int[] m = new int[2];
					m[0] = i;
					m[1] = j;
					return m;
				}
			}
		}
		return null;
	}
	
	public int[] inverseDeProchaineCaseVide() {
		for (int j = 0; j < initialLargeur; j++) {
			for (int i = 0; i < initialLongueur; i++) {
				if (grid[i][j] == false) {
					int[] m = new int[2];
					m[0] = i;
					m[1] = j;
					return m;
				}
			}
		}
		return null;
	}
	
	public int remplirLigne() {
		boolean sens = sens();
		if (sens == false) {
			int[] x = trouveProchaineCaseVide();
			int iC = x[0];
			int jC = x[1];
			for (int j = jC; j < initialLargeur; j++) {
				grid[iC][j] = true;
				mines --;
				if (mines == 0) {
					// vérification des bords
					if (j == initialLargeur - 2) {
						// on déplace la derniere etoile
						grid[iC][j] = false;
						int[] y = inverseDeProchaineCaseVide();
						int iD = y[0];
						int jD = y[1];
						grid[iD][jD] = true;
						if (iD == initialLongueur - 2 || jD == initialLargeur - 2) {
							return -1;
						}
						
						return 0;
					}
					return 0;
				}
			}
			longueur--;
			return 1;
		} else {
			int[] x = trouveProchaineCaseVide();
			int iC = x[0];
			int jC = x[1];
			for (int i = iC; i < initialLongueur; i++) {
				grid[i][jC] = true;
				mines --;
				if (mines == 0) {
					if (i == initialLongueur - 2) {
						// on déplace la derniere etoile
						grid[i][jC] = false;
						int[] y = trouveProchaineCaseVide();
						int iD = y[0];
						int jD = y[1];
						grid[iD][jD] = true;
						if (jD == initialLargeur - 2 || iD == initialLongueur - 2) {
							return -1;
						}
						
						return 0;
					}
					
					return 0;
				}
			}
			largeur--;
			return 1;
		}
	}
	
	@Override
	public String toString() {
		StringBuilder s = new StringBuilder("");
		for (int i = 0; i < initialLongueur ; i++) {
			for (int j = 0; j < initialLargeur ; j++) {
				if (i == initialLongueur - 1 && j == initialLargeur - 1) {
					s.append("c");
				} else if (grid[i][j] == false) {
					s.append(".");
				} else {
					s.append("*");
				}
			}
			if (i != initialLongueur - 1) {
				s.append(System.lineSeparator());
			}
		}
		return s.toString();
		
	}
	
}
