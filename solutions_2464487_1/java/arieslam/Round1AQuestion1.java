import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.math.BigInteger;
import java.util.HashMap;
import java.util.StringTokenizer;


public class Round1AQuestion1 {
	public static void main(String[] args) {
		
		try{
			System.out.println(System.currentTimeMillis());
			FileInputStream fstream = new FileInputStream("C:\\Users\\Aries\\workspace\\Codejam\\inout\\A-large.in");
			DataInputStream in = new DataInputStream(fstream);
			BufferedReader br = new BufferedReader(new InputStreamReader(in));
			String strLine;
			
			FileWriter fostream = new FileWriter("C:\\Users\\Aries\\workspace\\Codejam\\inout\\A-large.out");
			BufferedWriter out = new BufferedWriter(fostream);
			
			strLine = br.readLine();
			Integer tt = Integer.parseInt(strLine);
			for (int i=0;i<tt;i++){
				String line1 = br.readLine();
				StringTokenizer st1 = new StringTokenizer(line1);
				BigInteger r = new BigInteger(st1.nextToken());
				BigInteger t = new BigInteger(st1.nextToken());
				
				BigInteger y = binarySearch(new BigInteger("1"), t, new BigInteger("1"), r, t);
				System.out.println("guess: "+y);
				System.out.println("Cal: "+cal(y,r,t));
				System.out.println("t: "+t);
				if (cal(y,r,t).compareTo(t)>0){
					y = y.subtract(new BigInteger("1"));
				}
						
				
				out.write("Case #"+(i+1)+": ");
				out.write(y.toString());
				out.newLine();
			}
			in.close();
			out.close();
			System.out.println(System.currentTimeMillis());
		}catch (Exception e){//Catch exception if any
			System.err.println("Error: " + e.getMessage());
		}
	}
	
	public static BigInteger binarySearch(BigInteger low, BigInteger high, BigInteger guess, BigInteger r, BigInteger t){
		System.out.println(low.toString()+" "+high.toString()+" "+guess.toString());
		BigInteger guessT = cal(guess, r, t);
		System.out.println("guess:"+guess);
		System.out.println("GuessT:"+guessT);
		System.out.println("t:"+t);
		
		if (guessT.compareTo(t)==0){
			return guess;
		} else if (guessT.compareTo(t)>0){
			high = guess;
		} else {
			low = guess;
		}
		guess = high.add(low).divide(new BigInteger("2"));
		if (guess.compareTo(high)==0 || guess.compareTo(low)==0){
			return guess;
		}	
		return binarySearch(low, high, guess, r, t);
	}
	public static BigInteger cal(BigInteger guess, BigInteger r, BigInteger t){
//		return  guess.multiply(r).multiply(new BigInteger("2")).add(
//				(
//						(guess.multiply(guess).multiply(new BigInteger("2")).subtract(guess)).divide(
//								new BigInteger("2")
//						)
//				)
//		);
//		return guess.multiply(r).multiply(new BigInteger("2")).add(guess.multiply(guess)).add(guess.multiply(new BigInteger("2")));
		return guess.multiply(r).multiply(new BigInteger("2")).add(guess.multiply(guess).multiply(new BigInteger("2"))).subtract(guess);
	}
}

