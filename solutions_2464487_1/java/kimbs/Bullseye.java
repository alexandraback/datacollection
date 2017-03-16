import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.StringTokenizer;


public class Bullseye {
	
	public static String solve(long r, long t) {
		long start = 1;
		long end = 1;
		long mid = 0;
		long paint;
		
		while(true){
			paint = paintToN(r, 2*start);
			if (paint > t){
				end = start*2;
				break;
			}
			else if (paint == t){
				return (2*start) + "";
			}
			else{
				start = 2*start;
			}
		}
		
		while(true){
			if (start == end)
				return start+"";
			if ((start + 1) == end)
				return start+"";
			mid = (start + end)/2;
			paint = paintToN(r, mid);
			if (paint > t){
				end = mid;
			}
			else if (paint < t){
				start = mid;
			}
			else {
				return mid+"";
			}
		}
		
	}
	
	public static long paint(long r, long i){
		return (2*r + 1 + 4*(i-1));
	}
	
	public static long paintToN(long r, long n){
		return (2*n*n + (2*r-1)*n);
	}
	
	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int T = 0;
		String str = "";
		String result = "";
		
		File input = new File(args[0]);
		FileReader fileReader;
		BufferedReader br;
		
		File output = new File("output_bullseye.txt");
		BufferedWriter bw;

		StringTokenizer tokenizer;
		
		try {
			bw = new BufferedWriter(new FileWriter(output));
			
			fileReader = new FileReader(input);
			br = new BufferedReader(fileReader);
			str = br.readLine();
			
			T = Integer.parseInt(str);
			long r;
			long t;
			for (int i = 0; i < T; i++) {
				str = br.readLine();
				tokenizer = new StringTokenizer(str);
				r = Long.parseLong(tokenizer.nextToken());
				t = Long.parseLong(tokenizer.nextToken());
				result = solve(r, t);
				System.out.println(result);
				bw.write(String.format("Case #%d: %s\n", i+1, result));
			}
			
			fileReader.close();
			br.close();
			
			bw.close();
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
	}

}
