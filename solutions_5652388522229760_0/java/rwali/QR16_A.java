/**
 * 
 */
package codejam;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

/**
 * @author rohit
 *
 */
public class QR16_A {

	/**
	 * @param args
	 * @throws IOException 
	 */
	public static void main(String[] args) throws IOException {
		FileReader fr = new FileReader(new File("/home/rohit/Desktop/codejam/a/small.in"));
		BufferedReader br = new BufferedReader(fr);
		
		FileWriter fw = new FileWriter(new File("/home/rohit/Desktop/codejam/a/small.out"));
		BufferedWriter bw = new BufferedWriter(fw);
		
		int tc = Integer.valueOf(br.readLine().trim());
		for(int i=0;i<tc;i++){
			long n = Long.valueOf(br.readLine().trim());

			int [] d = new int[10];
			int j=1;
			for(;j<=1000;j++){
				List<Integer> t = tokenize(n*j);

				for(int k=0;k<t.size();k++){
					d[t.get(k)] = 1;
				}
				if(check(d)){
					break;
				}
			}

			if(j==1001)
				bw.write("Case #" + (i+1) + ": INSOMNIA");
			else
				bw.write("Case #" + (i+1) + ": " + n*j);

			bw.write("\n");

		}
		
		bw.close();
		br.close();
		fw.close();
		fr.close();
	}

	private static List<Integer> tokenize(long l) {
		
		List<Integer> ll = new ArrayList<Integer>();
		
		while(l>0){
			ll.add((int) (l%10));
			
			l /= 10; 
		}
		return ll;
	}

	private static boolean check(int[] d) {
		for(int i=0;i<d.length;i++){
			if(d[i]==0)
				return false;
		}
		return true;
	}

}
