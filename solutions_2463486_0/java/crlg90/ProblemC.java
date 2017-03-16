import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.ArrayList;
import java.util.Scanner;


public class ProblemC {

	/**
	 * @param args
	 */
	public static void main(String[] args) throws Exception{
		String fileName = "C-small-attempt0";
		BufferedReader br = new BufferedReader(new FileReader(fileName + ".in"));
		BufferedWriter bw = new BufferedWriter(
				new FileWriter(fileName + ".out"));
		ArrayList<Integer> fairSquare = new ArrayList<Integer>();
		for (int i=1; i<=32; i++){
			if (checkPalin(""+i)){
				int sq = i*i;
				if (checkPalin(""+(sq))){
					fairSquare.add(sq);
				}
			}
		}
		int t = Integer.valueOf(br.readLine());
		for (int i=1; i<=t; i++){
			String linea = br.readLine();
			Scanner scanner = new Scanner(linea);
			int a,b;
			a = scanner.nextInt();
			b = scanner.nextInt();
			int cont = 0;
			for (int j=0; j<fairSquare.size(); j++){
				if (fairSquare.get(j)>=a && fairSquare.get(j)<=b){
					cont++;
				}
			}
			bw.write("Case #"+i+": "+cont+'\n');
		}
		br.close();
		bw.close();
		
	}

	private static boolean checkPalin(String string) {
		String rev = "";
		for (int i=string.length()-1; i>=0; i--){
			rev+= string.charAt(i);
		}
		return string.equals(rev);
	}

}
