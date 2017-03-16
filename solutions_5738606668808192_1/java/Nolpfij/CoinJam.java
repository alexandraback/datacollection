import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Scanner;
import java.util.TreeMap;


public class CoinJam {
	public static void main(String[] args){
		File a = new File("C-small.in");
		Scanner input = null;
		try {
			input = new Scanner(a);
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		//Scanner input = new Scanner(System.in);
		
		File b = new File("C-output.txt");
		FileWriter fw = null;
		try {
			fw = new FileWriter(b);
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
		int number = input.nextInt();
		input.nextLine();
		int cases = number;
		// generate polynomials divisible by (x+1)
		int[] factors = {3,4,5,6,7,8,9,10,11};
		
		while(number > 0){
			int n = input.nextInt();
			int j = input.nextInt();
			
			String[] results = new String[j];
			
			boolean[] coin = new boolean[n];
			coin[n-2] = true;
			coin[n-1] = true;
			coin[0] = true;
			coin[1] = true;
			for (int i = 2; i < n-2; i ++){
				coin[i] = false;
			}
			
			int counter = 0;
			boolean[] count = new boolean[(n-4)/2];
			while (counter < j){
				generateCount(counter,count, n);
				changeCoin(count,coin);
				
				results[counter] = generateCoin(coin);
				counter++;
			}
			
			try {
				fw.write("Case #1: \n");
				for (int i = 0; i < results.length; i++){
					fw.write(results[i] + " ");
					for (int k = 0; k < factors.length; k++){
						fw.write(factors[k] + " ");
					}
					fw.write("\n");
				}
				
			} catch (IOException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
			number--;
		}
		
		try {
			fw.close();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}

	private static void generateCount(int counter, boolean[] count, int size) {
		int sub = (int) Math.pow(2, (size-4)/2 - 1);
		int c = 0;
		while (sub >= 1){
			if (counter >= sub){
				counter -= sub;
				count[c] = true;
			} else {
				count[c] = false;
			}
			sub /=2;
			c++;
		}
	}

	private static void changeCoin(boolean[] count, boolean[] coin) {
		for (int i = 0; i < count.length; i++){
			coin[2*i + 2] = count[i];
			coin[2*i + 3] = count[i];
		}
	}
	
	private static String generateCoin(boolean[] coin) {
		String s = "";
		for(int i = 0; i < coin.length; i ++){
			if(coin[i]){
				s += "1";
			} else {
				s += "0";
			}
		}
		return s;
	}

	private static void print(boolean[] coin) {
		for(int i = 0; i < coin.length; i ++){
			if(coin[i]){
				System.out.print(1);
			} else {
				System.out.print(0);
			}
		}
		System.out.print("\n");
	}
}
