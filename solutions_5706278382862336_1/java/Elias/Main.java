import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.math.BigInteger;
import java.util.Scanner;


public class Main {

	public static void main (String[] args) throws IOException {
		new Main();
	}
	
	public Main() throws IOException {
		Scanner in = new Scanner(new File("A-large.in"));
		//Scanner in = new Scanner(new File("A-test.txt"));
		BufferedWriter out = new BufferedWriter(new FileWriter("A-large.txt"));
		
		BigInteger b = new BigInteger("2");
		b = b.pow(40);
		
		int amountOfTasks = in.nextInt();
		for (int task = 0; task < amountOfTasks; task++) {
			String s = in.next();
			String[] breuk = s.split("/");
			BigInteger teller = new BigInteger(breuk[0]);
			BigInteger noemer = new BigInteger(breuk[1]);
			BigInteger gcd = teller.gcd(noemer);
			teller = teller.divide(gcd);
			noemer = noemer.divide(gcd);
			BigInteger rest = b.mod(noemer);
			if (!rest.toString().equals("0")) {
				out.write("Case #" + (task+1) + ": impossible");
				out.newLine();
			} else {
				int answer = 0;
				while (true) {
					if (noemer.compareTo(teller) <= 0) break;
					else {
						teller = teller.multiply(new BigInteger("2"));
						answer++;
					}
				}
				out.write("Case #" + (task+1) + ": " + answer);
				out.newLine();
			}
		}
		
		out.close();
		in.close();
	}
}
