import java.io.BufferedWriter;
import java.io.IOException;
import java.math.BigInteger;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.nio.file.StandardOpenOption;
import java.util.ArrayList;
import java.util.List;
import java.util.stream.Collectors;

public class CountingSheep {

	public static void main(String[] args) throws IOException {
		List<String> readAllLines = Files.readAllLines(Paths.get("J:\\dev\\eclipse\\imports\\A-large.in"));
		BufferedWriter writer = Files.newBufferedWriter(Paths.get("J:\\dev\\eclipse\\imports\\outputSheepLarge.txt"),
				StandardOpenOption.CREATE, StandardOpenOption.WRITE);
		for (int i = 1; i < readAllLines.size(); i++) {
			String string = readAllLines.get(i);
			String count = count(Integer.valueOf(string));
			if (count.equals("-1"))
				count = "INSOMNIA";
			if (i != 1)
				writer.newLine();
			writer.write("Case #" + i + ": " + count);

		}
		writer.flush();
		writer.close();
	}

	public static String count(int integer) {
		if (integer == 0) {
			return "-1";
		}
		List<String> digitList = getDigitList();
		BigInteger u = BigInteger.valueOf(integer);
		BigInteger c = BigInteger.valueOf(1);
		BigInteger i = u;
		do {
			i = u.multiply(c);
			c = c.add(BigInteger.ONE);
			String string = i.toString();
			digitList = digitList.stream().filter(d -> !string.contains(d)).collect(Collectors.toList());
		} while (!digitList.isEmpty());
		return i.toString();
	}

	private static List<String> getDigitList() {
		List<String> s = new ArrayList<>();
		for (int i = 0; i < 10; i++) {
			s.add(Integer.valueOf(i).toString());
		}
		return s;
	}

}
