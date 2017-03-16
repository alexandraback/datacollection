import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.math.BigInteger;


public class B2013_1C {
	public static String CASE = "Case #";
	public static String S = ": ";
	public static void main(String[] args) throws IOException {
		FileReader f = null;
		BufferedReader b = null;

		f = new FileReader(args[0]);
		b = new BufferedReader(f);
		
		int cnt = Integer.valueOf(b.readLine());
		for (int i = 0; i< cnt;i++) {
			String[] str = b.readLine().split(" ");
			BigInteger fromX = new BigInteger(str[0]);
			BigInteger fromY = new BigInteger(str[1]);
			StringBuilder sb = new StringBuilder();
			
			long num = 1;
			while(true) {
				if (fromX.longValue()!=0) {
					if (fromX.subtract(BigInteger.valueOf(num)).longValue() >= 0) {
						sb.append("E");
						fromX = fromX.subtract(BigInteger.valueOf(num));
						num++;
					} else {
						sb.append("W");
						fromX = fromX.add(BigInteger.valueOf(num));
						num++;
					}
				}
				if (fromY.longValue()!=0) {
					if (fromY.subtract(BigInteger.valueOf(num)).longValue() >= 0) {
						sb.append("N");
						fromY = fromY.subtract(BigInteger.valueOf(num));
						num++;
					} else {
						sb.append("S");
						fromY = fromY.add(BigInteger.valueOf(num));
						num++;
					}
				}
				if (fromX.longValue()==0 &&fromY.longValue()==0) {
					break;
				}
			}
			
			
			System.out.println(CASE+(i+1)+S+sb.toString());
		}

	}
}
