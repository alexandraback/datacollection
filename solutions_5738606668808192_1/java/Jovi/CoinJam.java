import java.io.BufferedWriter;
import java.io.IOException;
import java.math.BigInteger;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.nio.file.StandardOpenOption;
import java.util.ArrayList;
import java.util.List;

public class CoinJam {
	
	private static int n = 32;
	private static int j = 500;
	
	public static void main(String[] args) throws IOException {
		primeList.add(BigInteger.valueOf(2));
		
		List<String> coinJams = new ArrayList<>(j);
		for (int i = 0; coinJams.size() < j; i++) {
			String jam = generateCoinJam(i, n);
			List<Integer> coinJam2 = isCoinJam(jam);
			if (!coinJam2.isEmpty()) {
				String validJam = jam;
				for (Integer integer : coinJam2) {
					validJam += " " + integer;
				}
				coinJams.add(validJam);
				System.out.println("found jam " + coinJams.size());
			}
		}
		BufferedWriter writer = Files.newBufferedWriter(Paths.get("J:\\dev\\eclipse\\imports\\outputCoinJamLarge.txt"),
				StandardOpenOption.CREATE, StandardOpenOption.WRITE);
		writer.write("Case #1:");
		for (String string : coinJams) {
			writer.newLine();
			writer.write(string);
		}
		writer.flush();
		writer.close();
	}

	private static String generateCoinJam(int i, int l) {
		String string = Integer.toString(i, 2);
		while (string.length() < l - 2) {
			string = "0" + string;
		}
		return "1" + string + "1";
	}

	public static List<BigInteger> primeList = new ArrayList<>();
	
	public static List<Integer> isCoinJam(String number) {
		List<Integer> ntd = new ArrayList<>();
		for (int i = 2; i <= 10; i++) {
			BigInteger n = new BigInteger(number, i);
			if (n.isProbablePrime(100)) {
				return new ArrayList<>();
			} else {
				BigInteger p = primeList.get(0);
				boolean foundNonTrivialDivider = false;
				int z = 1;
				BigInteger divide = n.divide(BigInteger.valueOf(5));
				while (p.compareTo(divide) == -1 && !foundNonTrivialDivider) {
					if (n.remainder(p).compareTo(BigInteger.ZERO) == 0) {
						ntd.add(p.intValue());
						foundNonTrivialDivider = true;
					}else{
						if(primeList.size() > z){
							p = primeList.get(z);
							z++;
						}else{
							if(primeList.size() > 1000000){
								return new ArrayList<>();
							}
							z = Integer.MAX_VALUE;
							p = p.nextProbablePrime();
							primeList.add(p);
						}
					}
				}
				if (!foundNonTrivialDivider) {
					return new ArrayList<>();
				}
			}
		}
		return ntd;
	}
}
