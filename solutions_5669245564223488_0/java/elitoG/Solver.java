import java.io.BufferedReader;
import java.io.EOFException;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.text.DecimalFormat;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashSet;
import java.util.Iterator;
import java.util.Vector;

public class Solver {
	
	public static void main(String[] args) {
		Solver solver = new Solver();
		solver.readFromFile("src/B-small-attempt1.in");
	}

	private int nb_case = 0;
	String cars[];
	ArrayList<String> output_train;
	int nb_cars;
	int nb_valid_train = 0;
	
	
	ArrayList<ArrayList<String>> game;

	
	private void solveACase() {
		 Arrangement arrangement = null; 
	        int num = 0;
	        ArrayList<String> strs = new ArrayList<String>(); 
            num = nb_cars; 
	        for(int i = 0; i < num; i ++){
	        	String xx=cars[i].replaceAll("(?s)(.)(?=.*\\1)", ""); 
	            strs.add(xx);  
	        } 
	        arrangement = new Arrangement(strs.toArray(new String[]{})); 
	        output_train = arrangement.sort();
	        nb_valid_train = 0;
	        for (int i = 0; i < output_train.size(); i++) {
	        	//System.out.println(output_train.get(i));
				if (isValidTrain(output_train.get(i))) {
					nb_valid_train++;
				}
			}
	        System.out.println(new DecimalFormat(",###").format(nb_valid_train));// 299,792,458 
		
	}
	
	private boolean isValidTrain(String train) {
		int train_length = train.length();
		boolean is_valid = true;
		for (int i = 0; i < train_length; i++) {
			char l1 = train.charAt(i);
			for (int j = i+1; j < train_length; j++) {
				char l2 = train.charAt(j);
				if (l1 == l2 && (j - i > 1) && (train.charAt(j-1) != l1) ) {
					return false;
				}
			}
		}
		return is_valid;
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
	    				nb_cars = Integer.parseInt(br.readLine());
	    				cars = new String[nb_cars];
	    				chaine = br.readLine();
	    				cars = chaine.split(" ");
	    				System.out.print("Case #"+ i + ": ");
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