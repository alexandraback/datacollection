import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Random;
import java.util.Scanner;

public class jamcoin {
	public static void main(String[] args) throws FileNotFoundException {
		Scanner scan = new Scanner(System.in);
		PrintWriter out = new PrintWriter(new File("jamcoin.out"));
		
		int T = scan.nextInt();
		int  N = scan.nextInt(), J = scan.nextInt();
		
		HashMap<String, ArrayList<Integer>> map = new HashMap<>();
		
		while(map.size()!=J){
			String s = getRand(N);
			if(map.containsKey(s))continue;
			ArrayList<Integer> list =new ArrayList<>();
			
			boolean valid = true;
			for(int i=2;i<=10;i++){
				BigInteger a = new BigInteger(s, i);
				if(a.isProbablePrime(1000))valid=false;
			}
			if(!valid)continue;
			
			for(int i=2;i<=10;i++){
				BigInteger a = new BigInteger(s,i);
				
				valid = false;
				for(int j=3;j<100_000;j++){
					if(a.remainder(new BigInteger(Integer.toString(j))).equals(BigInteger.ZERO)){
						list.add(j);
						valid=true;
						break;
					}
				}
				if(!valid)break;
			}
			if(!valid)continue;
			
			map.put(s, list);
		}
		
		out.println("Case #1:");
		for(String s : map.keySet()){
			out.print(s+" ");
			for (int i : map.get(s))out.print(i+" ");
			out.println();
		}
		out.close();
	}
	
	private static String getRand(int N) {
		StringBuilder s = new StringBuilder("1");
		Random r = new Random();
		for(int i=1;i<N-1;i++){
			s.append((r.nextInt(2)==0)?"0":"1");
		}
		s.append("1");
		return s.toString();
	}
}	
