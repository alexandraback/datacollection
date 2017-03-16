package B;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class B {
	public static void main(String[] args) throws IOException {
		File f = new File("Input");
		Scanner sc;
		File output = new File("output");
		FileWriter fw= new FileWriter(output);
		try {
			sc = new Scanner(f);
			String line = sc.nextLine();
			int nbTest = Integer.parseInt(line);
			int nbNiveaux;
			int[][] t;
			Scanner sc2;
			int cpt = 0;
			int position;
			for (int i = 0; i < nbTest; i++) {
				cpt = 0;
				nbNiveaux = Integer.parseInt(sc.nextLine());
				int aAtteindre = 2 * nbNiveaux;
				int acquis = 0;
				t = new int[nbNiveaux][2];
				for (int j = 0; j < nbNiveaux; j++) {
					line = sc.nextLine();
					sc2 = new Scanner(line);
					t[j][0] = sc2.nextInt();
					//System.out.println(t[j][0]);
					t[j][1] = sc2.nextInt();
					//System.out.println(t[j][1]);
				}
				for (int j = 0; j < nbNiveaux; j++) {
					boolean droitePossible = false;
					int maxADroite = -1;
					while (acquis < aAtteindre && cpt != -1) {
						for (int k = 0; k < nbNiveaux && cpt != -1; k++) {
							//System.out.println(t[k][1] +" "+acquis);
							if (t[k][1] <= acquis) {
								if (t[k][0] == Integer.MAX_VALUE) {
									acquis++;
									cpt++;
									droitePossible = true;
									//System.out.println("1 etoile en plus a droite : " + acquis);
									if (acquis >= aAtteindre)
										break;
								} else {
									acquis = acquis + 2;
									//System.out.println("2 etoile en plus a droite" + acquis);
									cpt++;
									droitePossible = true;
									if (acquis >= aAtteindre)
										break;
								}
								t[k][0] = Integer.MAX_VALUE;
								t[k][1] = Integer.MAX_VALUE;

							}
						}
						/*System.out.println("**********");
						for (int z = 0; z < nbNiveaux; z++) {
							System.out.println(t[z][0]);
							System.out.println(t[z][1]);
						}
						System.out.println("**********");*/
						if (!droitePossible) {
							//System.out.println("oooo");
							maxADroite = -1;
							position = -1;
							for (int k = 0; k < nbNiveaux; k++) {
								if (t[k][0] <= acquis) {
									//System.out.println("MaxAdroite :" + maxADroite + ", t[k][1] : " + t[k][1]);
									if (t[k][1] >= maxADroite && t[k][1] != Integer.MAX_VALUE) {
										maxADroite = t[k][1];
										position = k;
										//System.out.println("MaxAdroite :" +k);
									}
								}
								
							}
							if (maxADroite == -1) {
								cpt=-1;
							}
							else {
								t[position][0] = Integer.MAX_VALUE;
								acquis++;
								cpt++;
								//System.out.println("acquis ?" + acquis);
							}
						}
						droitePossible = false;
					}
					
				}
				if (cpt == -1)
					fw.write("Case #" + (i+1) + ": Too Bad\n");
				else
					fw.write("Case #" + (i +1)+ ": "+ cpt+ "\n");
				System.out.println("Case " + i + " : "+ cpt);
			}
			fw.close();
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
}
