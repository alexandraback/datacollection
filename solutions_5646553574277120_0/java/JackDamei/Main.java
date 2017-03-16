package round1C.C;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.FileWriter;
import java.io.InputStreamReader;


public class Main {

	public static void main(String[] args) {

		//String filename = "src/round1C/input-C";
		String filename = "src/round1C/C-small-attempt5";
		//String filename = "src/round1C/C-large-practice";

		FileInputStream file;
		int T;

		try {
			file = new FileInputStream(filename+".in");

			BufferedReader in = new BufferedReader(new InputStreamReader(file));


			T = Integer.parseInt(in.readLine());

			BufferedWriter bw = new BufferedWriter(new FileWriter(filename+".out"));

			for (int i=0; i<T; i++) {
				int ind = i+1;
				// parser
				String[] data = in.readLine().split(" ");
				int C = Integer.parseInt(data[0]);
				int D = Integer.parseInt(data[1]);
				int V = Integer.parseInt(data[2]);
				data = in.readLine().split(" ");
				int[] tab = new int[D];
				for (int j=0; j<D; j++)
					tab[j] = Integer.parseInt(data[j]);

				int res = 0;
				// calcul
				int tmp=1, j=0, somme=0;
				while (tmp <= V) {
					//System.out.println(tmp);
					boolean b = false;
					while (j<D && tab[j] <= tmp && !b) {
						somme+=tab[j];
						j++;
						b = true;
					}
					if (!b || somme<tmp) {
						res++;
						somme+=tmp;
						tmp *= C+1;
					} else {
						tmp = Math.max(somme, (C+1)*tab[j-1]);
					}
					
				}
				
				/*int tmp=1, j=0, somme=0;
				while (tmp <= V) {
					somme=0;
					boolean b = false;
					while (j<D && tab[j] <= tmp && !b) {
						somme+=tab[j];
						j++;
						b = true;
					}
					if (!b) {
						res++;
						somme+=tmp;
						tmp *= C+1;
					} else {
						tmp = Math.max((C+1)*tab[j-1], somme);
					}
				}*/
				
				System.out.println("Result "+i+": "+res);
				bw.write("Case #"+ind+": "+res+"\n");
			}
			bw.close();

			in.close();

		} catch (Exception e) {
			e.printStackTrace();
		}
	}

}
