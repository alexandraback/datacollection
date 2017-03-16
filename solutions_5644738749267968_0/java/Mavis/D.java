import java.io.*;
import java.util.*;
import java.math.*;

//         java -jar cj.jar test.txt
//         java -jar cj.jar A-small.practice.in.txt > as.txt
//         java -jar cj.jar A-large.practice.in.txt > al.txt

public class D {
	
	public static void main(String[] args){
		assert(args.length == 1);
		parseTXT(args[0]);
	}
	
	private static void parseTXT(String file){
 		try{
			BufferedReader infile = new BufferedReader(new FileReader(file));
			int T = Integer.parseInt(infile.readLine()); // number of test cases
			for(int i = 0; i < T; i++){
				//parse test case to get input data for getReult function
				int n = Integer.parseInt(infile.readLine());
				ArrayList<Double> naomi = new ArrayList<Double>();
				String[] s = infile.readLine().split("\\s+");
				for(int j = 0; j < n; j++){
					naomi.add(Double.parseDouble(s[j]));
				}
				Collections.sort(naomi);
				
				ArrayList<Double> ken = new ArrayList<Double>();
				s = infile.readLine().split("\\s+");
				for(int j = 0; j < n; j++){
					ken.add(Double.parseDouble(s[j]));
				}
				Collections.sort(ken);
				
				// print result
				int id = i+1;
				int res1 = n-getWar(n, ken, naomi);
				int res2 = getWar(n, naomi, ken);
				System.out.println("Case #" + id + ": " + res1 + " " + res2);
				
			}
			infile.close();
		}catch(IOException e){
			System.err.println("check input file " + file );
		}
	}
	
	private static int getDeci(int n, ArrayList<Double> naomi, ArrayList<Double> ken){
		double curn, curk = ken.get(0);
		int i;
		for(i = 0; i < n; i++){
			curn = naomi.get(i);
			if(curn < curk) continue;
			else break;
		}
		return n-i;
	}
	
	private static int getWar(int n, ArrayList<Double> naomi, ArrayList<Double> ken){
		int j = 0, count = 0;
		double curn;
		for(int i = 0; i < n; i++){
			curn = naomi.get(i);
			while(j < n && ken.get(j) < curn) j++;
			if(j == n) return n - count;
			count++;
			j++;
		}
		return n - count;
	}

}








