import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.Scanner;


public class C1C {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		try{
			Scanner myFile = new Scanner(new FileReader("D://alon//programming//codejam2013//C1//C-small-attempt1.in")); //check!!!
			BufferedWriter out = new BufferedWriter(new FileWriter("D://alon//programming//codejam2013//C1//C-small-answers1.txt")); //check!!!
			int T = myFile.nextInt();
			for(int t = 1; t<=T; t++){
				int[] wall = new int[401];
				for(int i = 0; i<401; i++)
					wall[i] = 0;
				int count = 0;
				int N = myFile.nextInt();
				Tribe[] tribes = new Tribe[N];
				for(int i = 0; i<N; i++)
					tribes[i] = new Tribe(myFile.nextInt(), myFile.nextInt(), myFile.nextInt(), myFile.nextInt(), myFile.nextInt(), myFile.nextInt(), myFile.nextInt(), myFile.nextInt());
				boolean attacks = true;
				while(attacks){
					boolean attackers = false;
					int min = tribes[0].getD();
					int[] minInd = new int[N];
					for(int j=0; j<N; j++)
						minInd[j] = 0;
					for(int i = 0; i<N; i++){
						if(tribes[i].willAttack()){
							if(min == tribes[i].getD()){
								minInd[i]++;
								attackers = true;
							}
							if(min > tribes[i].getD()){
								for(int j=0; j<N; j++)
									minInd[j] = 0;
								minInd[i]++;
								min = tribes[i].getD();
								attackers = true;
							}	
						}
					}
					if(!attackers)
						attacks = false;
					else{
						int[] sMax = new int[401];
						for(int i = 0; i<401; i++){
							sMax[i] = 0;
						}
						for(int i = 0; i<N; i++){
							boolean succeded = false;
							if(minInd[i] != 0){
								int[] att = tribes[i].attack();
								for(int j = att[0]; j<= att[1]; j++){
									if(wall[j] < att[2])
										succeded = true;
									if(sMax[j] < att[2])
										sMax[j] = att[2];
								}
								if(succeded)
									count++;
							}
						}
						for(int i = 0; i<401; i++){
							if(sMax[i] > wall[i])
								wall[i] = sMax[i];
						}
					}
				}
				System.out.println("Case #"+t+": "+count);
				out.write("Case #"+t+": "+count+'\n');
			}
			out.close();
			myFile.close();
		}catch(FileNotFoundException e){
			System.out.println("file not found");
		}catch(Exception e){
			e.printStackTrace();
		}
	}

}
