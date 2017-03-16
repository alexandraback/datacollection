package deceitfulWar;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;

public class DeceitfulWar {

	public static void main(String[] args) {
		try{
		String fileName = "C:\\Users\\Beez\\CodeJam2014\\D-large.in";
		String outName = "C:\\Users\\Beez\\CodeJam2014\\D-out.txt";
		BufferedReader in = new BufferedReader(new FileReader(fileName));
		int t = Integer.parseInt(in.readLine());
		String answer[] = new String[t];
		for(int i = 0; i < t; i++){
			int amount = Integer.parseInt(in.readLine());
			double naomi[] = new double[amount];
			double ken[] = new double[amount];
			String line = in.readLine();
			for(int j = 0; j < amount; j++){
				naomi[j] = Double.parseDouble(line.split(" ")[j]);
			}
			line = in.readLine();
			for(int j = 0; j < amount; j++){
				ken[j] = Double.parseDouble(line.split(" ")[j]);
			}
			double n[] = naomi.clone();
			double kn[] = ken.clone();
			int ifTrue = 0;
			int ifLie = 0;
			//if honest
			for(int j = 0; j < amount; j++){
				int nChosen = j;
				int kChosen = -1;
				for(int k = 0; k < amount; k++){
					if(ken[k] != 0){
						if(ken[k] > naomi[nChosen]){
							if(kChosen == -1 || ken[k] < ken[kChosen]){
								kChosen = k;
							}
						}
					}
				}
				if(kChosen == -1){
					for(int k = 0; k < amount; k++){
						if(kChosen == -1 || (ken[k] < ken[kChosen] && ken[k] != 0)){
							kChosen = k;
						}
					}
				}
				if(naomi[nChosen] > ken[kChosen]){
					ifTrue++;
				}
				naomi[nChosen] = 0;
				ken[kChosen] = 0;
			}
			//if lie
			naomi = n.clone();
			ken = kn.clone();
			for(int j = 0; j < amount; j++){
				int nChosen = j;
				int kChosen = -1;
				for(int k = 0; k < amount; k++){
					if(ken[k] != 0){
						if(ken[k] < naomi[nChosen]){
							if(kChosen == -1 || ken[k] > ken[kChosen]){
								kChosen = k;
							}
						}
					}
				}
				if(kChosen == -1){
					for(int k = 0; k < amount; k++){
						if(kChosen == -1 || (ken[k] > ken[kChosen] && ken[k] != 0)){
							kChosen = k;
						}
					}
				}
				if(naomi[nChosen] > ken[kChosen]){
					ifLie++;
				}
				naomi[nChosen] = 0;
				ken[kChosen] = 0;
			}
			
			answer[i] = "Case #" + (i + 1) + ": " + ifLie + " " + ifTrue;
		}
		in.close();
		PrintWriter out = new PrintWriter(new FileWriter(outName));
		for(int i = 0; i < t; i++){
			out.println(answer[i]);
		}
		out.close();
		}catch(Exception e){
			System.out.println("Error running program");
			e.printStackTrace();
		}

	}

}
