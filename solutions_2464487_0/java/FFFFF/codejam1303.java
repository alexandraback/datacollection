import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.math.BigInteger;
import java.util.HashSet;
import java.util.Set;


public class codejam1303 {

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
            	double r = Double.parseDouble(splitResult[0]);
            	double t = Double.parseDouble(splitResult[1]);
            	long rl = Long.parseLong(splitResult[0]);
            	long tl = Long.parseLong(splitResult[1]);
            	getResult(r,t,rl,tl,i+1, out);

            }
            bufRead.close();
            out.close();
	}

	private static void getResult(double r, double t, long rl, long tl, int caseCount, BufferedWriter out) {
		//System.out.println(r+" " +t);
		if(r>=4.0E10||t>=4.0E10){
			double upper = (t>900000000)?900000000:t;
			double lower = 0;
			while(upper - lower > 1){
				double mid = (upper+lower)/2;
				if(ifSmaller(mid,r,t)){
					lower = mid;
				}
				else{
					upper = mid;
					//System.out.println("!!!"+upper);
				}
				//System.out.println(mid+" "+upper+" "+lower);
			}
			long temp = (long)lower;
			long result = (lower-temp>=0.5)?temp+1:temp;
			try {
				out.write("Case #"+caseCount+": "+result+'\n');
			} catch (IOException e) {
				e.printStackTrace();
			}
		}
		else{
			long upper = (tl>900000000)?900000000:tl;
			long lower = 0;
			while(upper - lower > 1){
				long mid = (upper+lower)/2;
				if(ifSmallerLong(mid,rl,tl)){
					lower = mid;
				}
				else{
					upper = mid;
					//System.out.println("!!!"+upper);
				}
				//System.out.println(mid+" "+upper+" "+lower);
			}
			try {
				out.write("Case #"+caseCount+": "+lower+'\n');
			} catch (IOException e) {
				e.printStackTrace();
			}
		}
		
		//System.out.println("Case #"+caseCount+": "+count);
	}
	public static boolean ifSmaller(double n, double r, double t){
		double result = 2*n*n-n+2*r*n-t;
		//System.out.println("!!!"+result);
		if(result<=0)
			return true;
		return false;
	}
	public static boolean ifSmallerLong(long n, long r, long t){
		double result = 2*n*n-n+2*r*n-t;
		//System.out.println("!!!"+result);
		if(result<=0)
			return true;
		return false;
	}
}
