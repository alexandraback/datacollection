import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.math.BigInteger;


public class qt21 {
	public static void test9(BufferedReader in) throws NumberFormatException, IOException {
		File out = new File("out.txt");
		FileWriter fw = new FileWriter(out);
		BufferedWriter bw = new BufferedWriter(fw);
		
		int cases = Integer.parseInt(in.readLine());
		for (int j=1;j<=cases;j++) {
			bw.write("Case #"+j+": ");
			String[] tmp = in.readLine().split(" ");
			double r = new BigInteger(tmp[0]).doubleValue();
			double t = new BigInteger(tmp[1]).doubleValue();
			double ans = Math.sqrt(t/2.0+Math.pow(r/2.0-1/4.0, 2))+1/4.0-r/2.0+0.000000001;
			bw.write((long)ans+"\n");
		}		
		in.close();
		bw.close();
	}	
	
	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		File conf = new File("A.in");
		FileReader fr=new FileReader(conf);
		BufferedReader in=new BufferedReader(fr);
		test9(in);
	}
}
