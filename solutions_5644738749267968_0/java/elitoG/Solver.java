import java.io.BufferedReader;
import java.io.EOFException;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;



public class Solver {
	
	public static void main(String[] args) {
		Solver solver = new Solver();
		solver.readFromFile("src/D-small-attempt0.in");
	}

	private ArrayList<Double> n_woods = new ArrayList<Double>();
	private ArrayList<Double> k_woods = new ArrayList<Double>();
	private int nb_case = 0;
	
	
	@SuppressWarnings("unchecked")
	private void solveACase() {
		int war_point = 0;
		int d_war_point = 0;
		ArrayList<Double> c_n_woods = new ArrayList<>();
		c_n_woods = (ArrayList<Double>) n_woods.clone();
		ArrayList<Double> c_k_woods = new ArrayList<>();
		c_k_woods = (ArrayList<Double>) k_woods.clone();
		Collections.sort(n_woods);
		Collections.sort(k_woods);

		war_point = playGameWar(war_point, c_n_woods, c_k_woods);
		c_n_woods = (ArrayList<Double>) n_woods.clone();
		c_k_woods = (ArrayList<Double>) k_woods.clone();
		Collections.sort(c_n_woods);
		Collections.sort(c_k_woods);
		d_war_point = playGameDWar(d_war_point, c_n_woods, c_k_woods);
		System.out.println(d_war_point + " " + (n_woods.size()-war_point));
	}
	
	private int playGameWar(int w, ArrayList<Double> c_n, ArrayList<Double> c_k) {
		Collections.sort(c_n);
		Collections.sort(c_k);
		if (c_n.size() == 1) {
			if (c_n.get(0) < c_k.get(0)) {
				w++;
			} 
			return w;
		} else {
			int id = -1;
			for (int i = 0; i < c_n.size(); i++) {
				if (c_k.get(i) > c_n.get(0)) {
					id = i;
					break;
				}
			}
			if (id > -1) {
				w++;
				c_k.remove(id);
				c_n.remove(0);
				return playGameWar(w, c_n, c_k);
			} else {
				return w;
			}
		}
	}
	
	private int playGameDWar(int d, ArrayList<Double> c_n, ArrayList<Double> c_k) {
		if (c_n.size() == 1) {
			if (c_n.get(0) > c_k.get(0)) {
				d++;
			} 
			return d;
		} else {
			if ( c_n.get(0) > c_k.get(c_k.size()-1)) {
				d += c_n.size(); 
				return d;
				
			} else if (c_n.get(c_k.size()-1) > c_k.get(c_k.size()-1)) {
				int idx = c_k.size()-1;
				c_k.remove(idx);
				c_n.remove(idx);
				d++;
				return playGameDWar(d, c_n, c_k);
			} else {
				int idx = c_k.size()-1;
				c_k.remove(idx);
				c_n.remove(0);
				return playGameDWar(d, c_n, c_k);
			}
		}
	}
	
	public void readFromFile(String f) {
		BufferedReader br=null;
		String chaine = null;
		
	    try {
	    	try {
	    		br = new BufferedReader(new FileReader(f));
	    		nb_case = Integer.parseInt(br.readLine());
	    		if (nb_case > 0) {
	    			for (int i = 1; i <= nb_case; i++) {
	    				int nb_woods = Integer.parseInt(br.readLine());
	    				String woods[] = new String[nb_woods];
    					chaine = br.readLine();
    					woods = chaine.split(" ");
    					for (int j2 = 0; j2 < nb_woods; j2++) {
    						n_woods.add(Double.parseDouble(woods[j2]));
						}
    					chaine = br.readLine();
    					woods = chaine.split(" ");
    					for (int j2 = 0; j2 < nb_woods; j2++) {
    						k_woods.add(Double.parseDouble(woods[j2]));
						}
	    				System.out.print("Case #"+ i + ": ");
	    				solveACase();
	    				n_woods.clear();
	    				k_woods.clear();
					}
	    		}
       		} catch(EOFException e) {
       			br.close();
       		}
	    } catch(FileNotFoundException e) {
	    	System.out.println("fichier inconnu : " + f);
	    } catch(IOException e) {
	    	System.out.println("IO Exception");
	    }
	}

}