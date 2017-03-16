package codejam2015;
import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.HashMap;
import java.util.Scanner;

public class ProblemC {

	public static void main(String[] args) throws NumberFormatException, IOException {
		FileWriter writer = new FileWriter("C:\\Users\\mchang\\workspace\\Google Code Jam\\src\\output.txt");
		String filename = "C:\\Users\\mchang\\workspace\\Google Code Jam\\src\\input.txt";
		try {
			BufferedReader br = new BufferedReader(new FileReader(filename));
			int numCases = Integer.parseInt(br.readLine());
			HashMap<String, String> table = new HashMap<String, String>();
			table.put("11", "1");
			table.put("1i", "i");
			table.put("1j", "j");
			table.put("1k", "k");
			table.put("1-1", "-1");
			table.put("1-i", "-i");
			table.put("1-j", "-j");
			table.put("1-k", "-k");
			table.put("-11", "-1");
			table.put("-1i", "-i");
			table.put("-1j", "-j");
			table.put("-1k", "-k");
			table.put("-1-1", "1");
			table.put("-1-i", "i");
			table.put("-1-j", "j");
			table.put("-1-k", "k");
			table.put("i1", "i");
			table.put("ii", "-1");
			table.put("ij", "k");
			table.put("ik", "-j");
			table.put("i-1", "-i");
			table.put("i-i", "1");
			table.put("i-j", "-k");
			table.put("i-k", "j");
			table.put("-i1", "-i");
			table.put("-ii", "1");
			table.put("-ij", "-k");
			table.put("-ik", "j");
			table.put("-i-1", "i");
			table.put("-i-i", "-1");
			table.put("-i-j", "k");
			table.put("-i-k", "-j");
			table.put("j1", "j");
			table.put("ji", "-k");
			table.put("jj", "-1");
			table.put("jk", "i");
			table.put("j-1", "-j");
			table.put("j-i", "k");
			table.put("j-j", "1");
			table.put("j-k", "-i");
			table.put("-j1", "-j");
			table.put("-ji", "k");
			table.put("-jj", "1");
			table.put("-jk", "-i");
			table.put("-j-1", "j");
			table.put("-j-i", "-k");
			table.put("-j-j", "-1");
			table.put("-j-k", "i");
			table.put("k1", "k");
			table.put("ki", "j");
			table.put("kj", "-i");
			table.put("kk", "-1");
			table.put("k-1", "-k");
			table.put("k-i", "-j");
			table.put("k-j", "i");
			table.put("k-k", "1");
			table.put("-k1", "-k");
			table.put("-ki", "-j");
			table.put("-kj", "i");
			table.put("-kk", "1");
			table.put("-k-1", "k");
			table.put("-k-i", "j");
			table.put("-k-j", "-i");
			table.put("-k-k", "-1");

			for (int caseNum = 1; caseNum <= numCases; caseNum++) {
				String line = br.readLine();
				Scanner sc = new Scanner(line);
				int l = Integer.parseInt(sc.next());
				int x = Integer.parseInt(sc.next());
				line = br.readLine();
				if(l*x < 3){
					printAnswer("NO", caseNum, writer);
					continue;
				} else if(l*x == 3){
					if(line.equals("ijk")){
						printAnswer("YES", caseNum, writer);
					} else {
						printAnswer("NO", caseNum, writer);
					}
					continue;
				}

				String partialProduct = "1";
				for(int i = 0; i < l; i++){
					partialProduct = table.get(partialProduct + line.charAt(i));
				}
				String totalProduct = "1";
				for(int i = 0; i < x; i++){
					totalProduct = table.get(totalProduct + partialProduct);
				}
				if(totalProduct != "-1"){
					printAnswer("NO", caseNum, writer);
					continue;
				}
				String value = "1";
				String total = "";
				for(int i = 0; i < x; i++){
					total += line;
				}
				while(true){
					if(value.equals("i") || total.length() == 0) break;
					value = table.get(value + total.charAt(0));
					total = total.substring(1);
				}
				if(!value.equals("i")){
					printAnswer("NO", caseNum, writer);
				} else {
					value = "1";
					while(true){
						if(value.equals("j") || total.length() == 0) break;
						value = table.get(value + total.charAt(0));
						total = total.substring(1);
					}
					if(value.equals("j")){
						printAnswer("YES", caseNum, writer);
					} else {
						printAnswer("NO", caseNum, writer);
					}
				}
			}
			br.close();
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		writer.close();
	}

	public static void printAnswer(String answer, int caseNumber,
			FileWriter writer) throws IOException {
		writer.write("Case #" + caseNumber + ": " + answer + "\n");
	}
}
