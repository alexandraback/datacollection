import java.util.*;
import java.io.*;

public class NadC {
	
	public static void main(String[] args) throws IOException{
		
		File fileIn = new File("FILEIN.in");
		PrintWriter writer = new PrintWriter("FILEOUT.txt", "UTF-8");
		Scanner in = new Scanner(fileIn);
		int numCases = in.nextInt();
		
		for(int i = 0; i < numCases; i++){
			writer.printf("Case #%d: ", i+1);
			//writer.printf("Case #%d:\r\n", i+1);
			
			//BEGIN CODE HERE
			int C = in.nextInt();
			int noCoins = in.nextInt();
			int max = in.nextInt();
			int[] coins = new int[noCoins];
			for(int m = 0; m < noCoins; m++){
				coins[m] = in.nextInt();
			}
			ArrayList<Integer> unfound = new ArrayList<Integer>();
			ArrayList<Integer> found = new ArrayList<Integer>();
			for(int kn = 1; kn <= max; kn++){
				unfound.add(kn);
			}
			int check = 1;
			int maxCheck = (int) (Math.pow(2, noCoins) + 0.0001);
			while(check <= maxCheck){
				int sum = 0;
								System.out.println(check);
				for(int mk = 0; mk < noCoins; mk++){

				if ((check & (1 << mk)) != 0)
				{
					System.out.println("found a bit: " + mk);
				   sum += coins[mk];
				}
				}
				if(unfound.contains(sum)){
					unfound.remove(unfound.indexOf(sum));
					found.add(sum);
				}
				check++;
			}
			int added = 0;
			while(!unfound.isEmpty()){
				for(int qws : unfound){
					System.out.print(qws + " ");
				}
				System.out.println();
				int newCoin = unfound.get(0);
				added++;
				ArrayList<Integer> temp = new ArrayList<Integer>();
				for(int ed : found){
					if(unfound.contains(ed + newCoin)){
						unfound.remove(unfound.indexOf(ed + newCoin));
						temp.add(ed + newCoin);
					}
				}
				for(int qwed : temp){
					found.add(qwed);
				}
				unfound.remove(unfound.indexOf(newCoin));
				found.add(newCoin);
			}
			writer.println(added);
			//END CODE HERE
			
		}
		System.out.println("DONE");
		in.close();
		writer.close();
	}
}