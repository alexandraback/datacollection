import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;


public class DeceitfulWar {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int numCases = in.nextInt();
		int caseN;
		int nBlocks;
		float naomi[];
		float ken[];
		float naomih[];
		float kenh[];
		try{
			PrintWriter writer = new PrintWriter("C:\\Users\\christopher.j.olson\\Desktop\\DeceitfulWar_large.txt");

			for (caseN = 1; numCases > 0; numCases--, caseN++) {
				nBlocks = in.nextInt();
				naomi = new float[nBlocks];
				ken = new float[nBlocks];
				naomih = new float[nBlocks];
				kenh = new float[nBlocks];
				
				for(int i = 0;i < nBlocks; i++){
					naomi[i] = in.nextFloat();
					naomih[i] = naomi[i];
				}
				
				for(int i = 0;i < nBlocks; i++){
					ken[i] = in.nextFloat();
					kenh[i] = ken[i];
				}
				
				writer.print("Case #" + caseN + ": ");
				writer.println(solveDeceit(naomi, ken) + " "+solveHonest(naomih, kenh));
			}
			writer.flush();
			writer.close();
		}catch(Exception e){
			System.out.println("Error");
			e.printStackTrace();
		}
	}
	
	public static int solveDeceit(float[] naomi, float[] ken){
		int points = 0;
		Arrays.sort(naomi);
		Arrays.sort(ken);
		
		for(int i=0; i < naomi.length; i++){
			if(naomi[i] < ken[i]){
				//naomi's smallest block can't possibly beat Ken's
				//get rid of Ken's highest and Naomi's lowest
				//i.e. Tell Ken your block is just under his highest to force it
				//     Actually play lowest
				naomi[i] = -1.0f;
				ken[ken.length -1] = -1.0f;
			}else{
				//Naomi's lowest is larger than ken's smallest
				// Naomi tells block that is larger than Ken's largest forcing him to lose
				// Ken, knowing he will lose, plays his smallest
				// Naomi in turn plays smallest
				naomi[i] = -1.0f;
				ken[i] = -1.0f;
				++points; // naomi wins
			}
			Arrays.sort(naomi);
			Arrays.sort(ken);
		}
		
		return points;
	}
	
	public static int solveHonest(float[] naomi, float[] ken){
		int points = 0;
		Arrays.sort(naomi);
		Arrays.sort(ken);
		int np = 0;
		int kp = 0;
		for(int i=0; i < naomi.length; i++){
			kp = np = i;
			for(int j = naomi.length-1; j>=i; --j){
				if(naomi[j] < 0){

					break;
				}
				if(naomi[j] < ken[ken.length-1]){
					np = j; //play first 
					while(j >= i && naomi[j] > ken[Math.max(0,ken.length-2)]){
						np = j;
						--j;
					}
					break;
				}
			}

			for(int j = i; j < ken.length; ++j){
				//System.out.println(i+":"+j+":"+np);
				if(ken[j] > naomi[np]){
					kp = j;
					break;
				}
			}
			//System.out.println(naomi[np] +":"+ ken[kp]);
			if(naomi[np] > ken[kp]){
				++points;
			}
			naomi[np] = -1;
			ken[kp] = -1;
			Arrays.sort(naomi);
			Arrays.sort(ken);
		}
		
		return points;
	}

}
