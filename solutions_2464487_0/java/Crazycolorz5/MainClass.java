import java.io.File;
import java.io.FileInputStream;
import java.io.FileWriter;
import java.io.IOException;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Scanner;


public class MainClass {

	public static void main(String[] args) {
		try {
			File f = new File("bullseye.in");
			File out = new File("bullseye.out");
			FileInputStream fin;
			Scanner sin = null;
			fin = new FileInputStream(f);
			FileWriter fout = new FileWriter(out);
			try {
				sin = new Scanner(fin);
				int numOfCases = sin.nextInt();
				for(int casenum = 0; casenum<numOfCases; casenum++)
				{
					long r = sin.nextLong();
					long t = sin.nextLong();
					long num = 0;
					while(t>=0)
					{
						t -= (2*r+1);
						r+=2;
						if(t>=0)
							num++;
					}
					try {
						fout.write("Case #" + (casenum+1) + ": " + num + "\n");
					} catch (IOException e1) {e1.printStackTrace();}
					finally {
						fout.flush();
					}
				}
			} finally {
				sin.close();
				fout.close();
			}
		} catch(IOException e) {}
	}

}
