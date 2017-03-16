import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;


public class DeceitfulWar {
	public static void main(String[] args) {
        String base = "/home/stefan/";
        String input = base + "D-small-attempt0.in";
        String output = base + "D-small-attempt0.out";
        
		try {
			Scanner scan = new Scanner(new FileReader(input));
			PrintWriter write = new PrintWriter(output);
			
			int n = scan.nextInt();
			scan.nextLine();
			
			for (int i = 1; i <= n; i++) {
				write.write("Case #" + i + ": ");
				test(scan, write);
			}
			
			scan.close();
			write.close();
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}
	}

	@SuppressWarnings("unchecked")
	private static void test(Scanner scan, PrintWriter write) {
		int N = scan.nextInt();
		// Naomi, Ken
		ArrayList<Double> Naomi = new ArrayList<Double>();
		ArrayList<Double> Ken = new ArrayList<Double>();
		
		for (int i = 0; i < N; i++) {
			Naomi.add(scan.nextDouble());
		}
		
		for (int i = 0; i < N; i++) {
			Ken.add(scan.nextDouble());
		}
		
		Collections.sort(Naomi);
		Collections.sort(Ken);
		
		ArrayList<Double> Naomi2 = (ArrayList<Double>) Naomi.clone();
		ArrayList<Double> Ken2 = (ArrayList<Double>) Ken.clone();
		
		int d = playDeceitfulWar(Naomi, Ken);
		int w = playWar(Naomi2, Ken2);
		
		write.write(d + " " + w + "\n");
		
	}

	private static int playWar(ArrayList<Double> naomi, ArrayList<Double> ken) {
		int naomiWon = 0;
		
		while(naomi.size() > 0){
			double nPlay = naomi.remove(0);
			
			int z = 0;
			for(int i=0;i<ken.size();i++){
				if(ken.get(i) > nPlay){
					z = i;
					break;
				}
			}
			
			double kPlay = ken.remove(z);
			
			if(nPlay > kPlay)
				naomiWon++;
		}
		
		return naomiWon;
	}

	private static int playDeceitfulWar(ArrayList<Double> naomi, ArrayList<Double> ken) {
		int naomiWon = 0;
		double nPlay, nDecPlay, kPlay;
		while(naomi.size() > 0){
			
			if(naomi.size() == 1){
				if(naomi.remove(0) > ken.remove(0))
					naomiWon++;
			} else {
				if(naomi.get(naomi.size()-1) > ken.get(ken.size()-1)){
					nPlay = naomi.remove(naomi.size()-1);
					nDecPlay = nPlay;
					kPlay = ken.remove(ken.size()-1);
				} else {
					nPlay = naomi.remove(0);
					nDecPlay = (ken.get(ken.size()-1) + ken.get(ken.size()-1)) / 2; 
					kPlay = ken.remove(ken.size()-1); 
				}
				
				if(nDecPlay > kPlay)
					naomiWon++;
			}
		}
		
		return naomiWon;
	}
}
