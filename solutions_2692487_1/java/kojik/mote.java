import java.io.BufferedOutputStream;
import java.io.BufferedReader;
import java.io.File;
import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintStream;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Iterator;
import java.util.List;

public class mote {

	public static void main(String[] args) throws IOException {
		File iFile = new File("mote.in");
		BufferedReader in= new BufferedReader(new FileReader(iFile));
		
		File oFile = new File("mote.out");
		FileOutputStream fos = new FileOutputStream(oFile);
		BufferedOutputStream bos = new BufferedOutputStream(fos);
		PrintStream out = new PrintStream(bos);
		
		int numTest = Integer.parseInt(in.readLine());
		
		for(int i=1; i<=numTest; i++){
			String[] testArgs = in.readLine().split(" ");
			BigInteger A = new BigInteger(testArgs[0]);
			
			String[] motes_str = in.readLine().split(" ");
			List<Integer> motes = new ArrayList<Integer>();
			for(int j=0; j<motes_str.length; ++j){
				motes.add(Integer.parseInt(motes_str[j]));
			}
			Collections.sort(motes);
			int answer = solve(A, motes);
			
			String line = "Case #"+i+": "+answer;
			out.println(line);
			System.out.println(line);
		}
		
		in.close();
		out.close();
	}
	
	static BigInteger one = BigInteger.valueOf(1);
	
	private static int solve(BigInteger A, List<Integer> motes){
		if(A.equals(one)){
			return motes.size();
		}
		
		int num_added = 0;
		int maxOps = motes.size();
		while(true){
			//try to solve as much as possible
			Iterator<Integer> it = motes.iterator();
			while(it.hasNext()){
				BigInteger next = BigInteger.valueOf(it.next());
				if( A.compareTo(next) <= 0){
					break;
				}else{
					A = A.add(next);
					it.remove();
				}
			}
			if(motes.size()<=1){
				return num_added+motes.size();
			}
			
			maxOps = Math.min(num_added+motes.size(), maxOps);
			
			A = A.add(A).subtract(one);
			++num_added;
			if(num_added >= maxOps){
				return maxOps;
			}
		}
	}
	
}
