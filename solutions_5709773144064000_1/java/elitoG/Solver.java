import java.io.BufferedReader;
import java.io.EOFException;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.text.DecimalFormat;


public class Solver {
	
	public static void main(String[] args) {
		Solver solver = new Solver();
		solver.readFromFile("src/B-large.in");
	}

	private int nb_case = 0;
	private double C = 0;
	private double F = 0;
	private double X = 0;
	
	private void solveACase() {
		boolean stop = false;
		double t1;
		double t2;
		double current_speed = 2;
		double total_time = 0;
		DecimalFormat df = new DecimalFormat("0.0000000");
		if (X <= C) {
			total_time = X / current_speed;
			String ti = df.format(total_time);
			System.out.println(ti.replace(',', '.'));
		} else {
			while (!stop) {
				t1 = X / current_speed;
				t2 = C / current_speed + X/(current_speed + F);
				if (t1 <= t2) {
					total_time += t1;
					stop = true;
				} else {
					total_time += C / (current_speed);
					current_speed += F;
				}
			}
			String ti = df.format(total_time);
			System.out.println(ti.replace(',', '.'));
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
	    				String three_case[] = new String[4];
	    				chaine = br.readLine();
	    				three_case = chaine.split(" ");
	    				System.out.print("Case #"+ i + ": ");
						C = Double.parseDouble(three_case[0]);
						F = Double.parseDouble(three_case[1]);
						X = Double.parseDouble(three_case[2]);
	    				solveACase();
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