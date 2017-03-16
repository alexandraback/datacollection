import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.HashMap;
import java.util.Map;

public class DancingWithGooglers {

	public static void main(String[] args) throws IOException {
		String msg = "";
		BufferedReader br = null;
		String sCurrentLine = null;
		Map<String, String> map = new HashMap<String, String>();
		br = new BufferedReader(new FileReader("test"));
		sCurrentLine = br.readLine();
		int x = 0;
		if (sCurrentLine != null) {
			while ((sCurrentLine = br.readLine()) != null) {
				int qualifiedGooglers = 0;
				msg = "";
				String[] eachTestCase = sCurrentLine.split(" ");
				int noOfGooglers = Integer.parseInt(eachTestCase[0]);
				int noOfSurprises = Integer.parseInt(eachTestCase[1]);
				int minReqd = Integer.parseInt(eachTestCase[2]);
				int[] googlersPoint = new int[noOfGooglers];
				int k = 0;
				for (int i = 3; i < eachTestCase.length; i++) {
					int j = Integer.parseInt(eachTestCase[i]);
					googlersPoint[k++] = j;
				}
				for (int i = 0; i < noOfGooglers; i++) {
					if (googlersPoint[i] == 0) {
						if (minReqd == 0)
							qualifiedGooglers++;
					} else if ((googlersPoint[i] + 2) / 3 >= minReqd) {
						qualifiedGooglers++;
					} else if (noOfSurprises > 0) {
						if ((googlersPoint[i] + 4) / 3 >= minReqd) {
							qualifiedGooglers++;
							noOfSurprises--;
						}

					}
				}
				x++;
				msg += "Case #" + x + ": " + qualifiedGooglers;
				System.out.println(msg);
			}
		}

	}
}
