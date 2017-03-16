import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.math.BigInteger;
import java.util.HashSet;
import java.util.Set;


public class codejam1304 {

	public static void main(String[] args) throws IOException{
		readFile();
	}

	public static void readFile() throws IOException{
			FileWriter fstream = new FileWriter("out.txt");
			BufferedWriter out = new BufferedWriter(fstream);
            FileReader input = new FileReader("in.txt");
            BufferedReader bufRead = new BufferedReader(input);	
            String line = bufRead.readLine();
            int caseCount = Integer.parseInt(line);
            for(int i = 0; i < caseCount; i++){
            	line = bufRead.readLine();
            	String[] splitResult = line.split(" ");
            	long E = Long.parseLong(splitResult[0]);
            	long R = Long.parseLong(splitResult[1]);
            	int N = Integer.parseInt(splitResult[2]);
            	line = bufRead.readLine();
            	splitResult = line.split(" ");
            	long[] values = new long[N];
            	for(int j = 0; j< N; j++){
            		values[j] = Long.parseLong(splitResult[j]);
            	}
            	getResult(E,R,N,values, out, i+1);

            }
            bufRead.close();
            out.close();
	}

	private static void getResult(long e, long r, int n, long[] values,
			BufferedWriter out, int caseCount) {
		long currentE = e;
		long result = 0;
		for(int i = 0; i<n; i++){
			long current = values[i];
			int hasBig = hasBigger(current, values, i);
			if(hasBig<0){
				result+=current*currentE;
				currentE=0;
			}
			else{
				/*long canUse = currentE + r - e;
				if(canUse>0){
					//canUse = (canUse>e)?e:canUse;
					canUse = (canUse>currentE)?currentE:canUse;
					result += current*canUse;
					currentE -= canUse;
				}*/
				long canUse = currentE + r*(hasBig-i)-e;
				if(canUse>0){
					canUse = (canUse>currentE)?currentE:canUse;
					result += current*canUse;
					currentE -= canUse;
				}
			}
			currentE+=r;
			System.out.println(currentE);
		}
		try {
			out.write("Case #"+caseCount+": "+result+'\n');
		} catch (IOException haha) {
			haha.printStackTrace();
		}
	}

	private static int hasBigger(long current, long[] values, int index) {
		for(int i = index+1; i<values.length; i++){
			if(values[i]>current)
				return i;
		}
		return -1;
	}

}
