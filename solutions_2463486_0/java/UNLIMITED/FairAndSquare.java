import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.math.BigInteger;
import java.net.URL;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;


public class FairAndSquare {

	public static void main(String[] args) throws IOException {
		Scanner reader = new Scanner(new File(new URL(FairAndSquare.class.
				getResource("."), "../input/C-small-attempt4.in").getPath()));
		BufferedWriter writer = new BufferedWriter(new FileWriter(new URL(FairAndSquare.class.
				getResource("."), "../output/C-small-attempt4.out").getPath()));
		int numZeros = 2;
		StringBuilder sb = new StringBuilder("1");
		for(int i = 0; i < numZeros; i++)
			sb.append("0");	
		BigInteger MAX_NUM = new BigInteger(sb.toString());
		
		//pre-compute
		List<BigInteger> fas = new ArrayList<BigInteger>();
		for(BigInteger i = BigInteger.ONE; i.compareTo(MAX_NUM) <= 0; i = i.add(BigInteger.ONE)){
			if(isPa(i) && isPa(i.pow(2))){
				fas.add(i.pow(2));
				System.out.println(i.pow(2));
			}
		}
		int numOfCases = reader.nextInt();
		reader.nextLine();
		for(int i = 1; i <= numOfCases; i++){
			String[] range = reader.nextLine().split(" ");
			BigInteger lo = new BigInteger(range[0]);
			BigInteger hi = new BigInteger(range[1]);
			int count = 0;
			for(int j = 0; j < fas.size(); j++){
				if(fas.get(j).compareTo(lo) >=0 && fas.get(j).compareTo(hi) <=0){
					count ++;
				}
			}
			writer.write("Case #" + i + ": " + count + "\n");
		}
		reader.close();
		writer.close();
	}
	
	public static boolean isPa(BigInteger bi){
		String s = bi.toString();
		for(int i =0; i < s.length() / 2; i++){
			if(s.charAt(i) != s.charAt(s.length() - i - 1))
				return false;
		}
		return true;
	}

}
