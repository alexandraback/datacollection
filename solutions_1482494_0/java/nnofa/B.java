import java.io.*;
import java.util.*;
public class B{
	public static void main(String[] args){
	  try{
		String inputFile = "B-small-attempt1.in";
		String outputFile = "B-small-attempt1.out";
		Scanner sc = new Scanner(new File(inputFile));
        FileWriter fwStream = new FileWriter( outputFile );
        BufferedWriter bwStream = new BufferedWriter( fwStream );
        PrintWriter pwStream = new PrintWriter( bwStream );
		int numCase = sc.nextInt();
		for(int i = 0; i < numCase; i++){
			int answer = 0;
			int numStar = 0;
			int numLevel = sc.nextInt();
			System.out.println("numLevel = " + numLevel);
			int[][] starNeed = new int[numLevel][2];
			int[][] starNeed2 = new int[2][numLevel];
			boolean[][] completed = new boolean[numLevel][2];
			for(int j = 0; j < numLevel; j++){
				starNeed[j][0] = sc.nextInt(); 
				starNeed2[0][j] = starNeed[j][0]; 
				starNeed[j][1] = sc.nextInt();
				starNeed2[1][j] = starNeed[j][1];
				completed[j][0] = false;
				completed[j][1] = false;
			}
			Arrays.sort(starNeed2[0]);
			Arrays.sort(starNeed2[1]);
			boolean impossible = false;
			int j = 0; int k = 0;
			for(j = 0,k = 0; j < starNeed2[0].length || numStar < 2 * numLevel;){
				//System.out.println("numStar = " + numStar);
				if(starNeed2[1][j] <= numStar){
					int cnt = 0;
					//System.out.println("masuk sini");
					for(int l = 0; l < completed.length; l++){
						if(completed[l][0] == false && completed[l][1] == false && starNeed2[1][j] == starNeed[l][1] ){
							numStar+=2;
							cnt++;
							completed[l][1] = true;
							answer++;
							//System.out.println("level " + l + " completed");
						}
						if(completed[l][0] == true && completed[l][1] == false && starNeed2[1][j] == starNeed[l][1] ){
							numStar++;
							cnt++;
							completed[l][1] = true;
							answer++;
							//System.out.println("level " + l + " completed");
						}
					}
					j+=cnt;
				}
				else if(starNeed2[0][j] <= numStar){
					int cnt = 0;
					for(int l = 0; l < completed.length; l++){
						if(completed[l][0] == false && completed[l][1] == false && starNeed2[0][k] == starNeed[l][0]){
							numStar++;
							cnt++;
							completed[l][0] = true;
							answer++;
							break;
						}
					}
					k+=cnt;
					if(cnt == 0){
						impossible = true; break;
					}
				}
				else{
					impossible = true;
					break;
				}
			}
			if(impossible)
			pwStream.printf("Case #"+(i+1)+ ": TOO BAD");
			else
			pwStream.printf("Case #"+(i+1)+ ": %d", answer);
			pwStream.println();
		}
		pwStream.close();
		sc.close();
		}
	  catch(Exception e){e.printStackTrace();}
	}
	
}