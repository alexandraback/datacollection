import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;


public class DeceitfulWar {

	public static void main(String[] args) {
		Scanner input=new Scanner(System.in);
		int trials=input.nextInt();
		for(int trial=0;trial<trials;trial++){
			int blockCount=input.nextInt();
			ArrayList<Double> nai=new ArrayList<Double>();
			ArrayList<Double> ken=new ArrayList<Double>();
			for(int i=0;i<blockCount;i++){
				nai.add(input.nextDouble());
			}
			for(int i=0;i<blockCount;i++){
				ken.add(input.nextDouble());
			}
			Collections.sort(nai);
			Collections.sort(ken);
			ArrayList<Double> nBackup=new ArrayList<Double>();
			ArrayList<Double> kBackup=new ArrayList<Double>();
			for(double d:ken)kBackup.add(d);
			for(double d:nai)nBackup.add(d);
			
			Collections.reverse(ken);
			int dScore=0;
			int movesLeft=blockCount;
			while(movesLeft>0){
				
				double kenMax=ken.get(0);
				ken.remove(kenMax);
				double naiMin=nai.get(0);
				double naiMax=nai.get(nai.size()-1);
				if(kenMax<naiMax){
					nai.remove(naiMax);
					dScore++;
				}else
				if(kenMax<naiMin){
					nai.remove(naiMin);
					dScore++;
				}
				movesLeft--;
			}

			nai=nBackup;
			ken=kBackup;
			Collections.reverse(nai);
			int nScore=blockCount;
			movesLeft=blockCount;
			while(movesLeft>0){
				
				double naiMax=nai.get(0);
				nai.remove(naiMax);
				double kenMin=ken.get(0);
				double kenMax=ken.get(ken.size()-1);
				if(naiMax<kenMax){
					ken.remove(kenMax);
					nScore--;
				}else
				if(naiMax<kenMin){
					ken.remove(kenMin);
					nScore--;
				}
				movesLeft--;
			}
			System.out.println("Case #"+(trial+1)+": "+dScore+" "+nScore);
		}
		input.close();
	}

}
