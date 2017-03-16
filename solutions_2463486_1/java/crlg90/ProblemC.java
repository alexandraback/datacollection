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
		String fileName = "C-large-1";
		BufferedReader br = new BufferedReader(new FileReader(fileName + ".in"));
		BufferedWriter bw = new BufferedWriter(
				new FileWriter(fileName + ".out"));
		ArrayList<Long> fairSquare = new ArrayList<Long>();
		for (long i=1; i<=10000000; i++){
			if (checkPalin(""+i)){
				long sq = i*i;
				if (checkPalin(""+(sq))){
					fairSquare.add(sq);
					System.out.println(sq);
				}
			}
		}
		System.out.println(fairSquare.size());
		int t = Integer.valueOf(br.readLine());
		for (int i=1; i<=t; i++){
			String linea = br.readLine();
			Scanner scanner = new Scanner(linea);
			long a,b;
			a = scanner.nextLong();
			b = scanner.nextLong();
			long cont = 0;
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
