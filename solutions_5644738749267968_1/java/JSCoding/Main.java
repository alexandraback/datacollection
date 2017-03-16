import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

/**
 * Main Class
 * Solves all Google Code Jam Tasks.
 * @author Jones
 */
public class Main {

	/**
	 * @param args
	 */
	public static void main(String[] args) throws IOException {
		// read input file and prepare buffered writer
		Scanner sc = new Scanner(new File("D-large.in"));
		BufferedWriter wr = new BufferedWriter(new FileWriter("D-large.out"));
		
		// get the number of test cases
		int noCases = sc.nextInt();

		for(int i=0; i<noCases; i++) {
			int scWar = 0;
			int scDWar = 0;
			int n = sc.nextInt();
			ArrayList<Double> blocksAL = new ArrayList<Double>();
			ArrayList<Double> blocksBL = new ArrayList<Double>();
			ArrayList<Double> blocksBL2 = new ArrayList<Double>();
			
			sc.nextLine();
			String strA = sc.nextLine();
			String strB = sc.nextLine();
			
			String[] helperA = new String[n];
			String[] helperB = new String[n];
			helperA = strA.split(" ");
			helperB = strB.split(" ");
			
			for(int x = 0; x < n; x++){
				blocksAL.add(Double.parseDouble(helperA[x]));
				blocksBL.add(Double.parseDouble(helperB[x]));
				blocksBL2.add(Double.parseDouble(helperB[x]));
			}
			//blocks have been processed
			
			// regular war
			for(int t = 0; t < n; t++){
				double chosenNaomi = blocksAL.get(t);
				int idxSmallest = 0;
				double valSmallest = blocksBL.get(0);
				int idxBeatable = 0;
				double valBeatable = 0;
				boolean beatableFound = false;
				
				for(int m = 0; m < blocksBL.size(); m++){
					if(valSmallest > blocksBL.get(m)){
						idxSmallest = m;
						valSmallest = blocksBL.get(m);
					}
					
					if(blocksBL.get(m) > chosenNaomi && (beatableFound == false || blocksBL.get(m) < valBeatable)){
						idxBeatable = m;
						valBeatable = blocksBL.get(m);
						beatableFound = true;
					}
				}
				
				if(beatableFound == true){
					blocksBL.remove(idxBeatable);
				}else{
					blocksBL.remove(idxSmallest);
					if(valSmallest < chosenNaomi)
						scWar++;
				}
			}
			
			Collections.sort(blocksAL);
			Collections.sort(blocksBL2);

			// dwar
			for(int x = 0; x < n; x++){
				double nSmallest= blocksAL.get(0);
				double kSmallest = blocksBL2.get(0);
				double nBiggest = blocksAL.get( (blocksAL.size() - 1) );
				double kBiggest = blocksBL2.get( (blocksBL2.size() - 1) );
				
				if(nSmallest > kSmallest){
					if(nBiggest > kBiggest){
						// beat it
						scDWar++;
						blocksBL2.remove((blocksBL2.size() - 1));
						blocksAL.remove((blocksAL.size() - 1));
					}else{
						blocksAL.remove(0);
						blocksBL2.remove((blocksBL2.size() - 1));
					}
				}else{
					if(kBiggest < nSmallest){
						scDWar++;
					}
					
					blocksAL.remove(0);
					blocksBL2.remove((blocksBL2.size() - 1));
				}
			}
			
			wr.write("Case #" + (i+1) + ": " + scDWar + " " + scWar);
			wr.newLine();
		}
		wr.close();
	}

}
