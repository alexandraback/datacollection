import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.Writer;
import java.util.Arrays;
import java.util.StringTokenizer;


public class Osmos {

	static long[] sizes;
	static long motSize;
	
	static int process(int count, long  ms, int poz) {
		if(poz >= sizes.length)
			return count;
		if(ms > sizes[poz]) {
			return process(count, ms + sizes[poz], poz+1);
		}
	//	if(ms + ms-1 > sizes[poz]) {
		if(ms > 1)	
			return Math.min(count+ sizes.length-poz, process(count+1, ms + ms-1, poz));
		else
			return count+ sizes.length-poz;
		//	}
	//	else {
	//		return Math.min(count+ sizes.length-poz, process(count+1, ms + ms-1, poz));
	//	}
	}
	
	public static void main(String[] args) throws IOException {
		BufferedReader input =  new BufferedReader(new FileReader("c:\\tmp\\in.txt"));
		BufferedWriter output = new BufferedWriter(new FileWriter("c:\\tmp\\out.txt"));
		
		int t = Integer.parseInt(input.readLine());
		for(int i=1;i<=t;++i) {
			StringTokenizer st = new StringTokenizer(input.readLine());
			motSize = Long.parseLong(st.nextToken());
			int arraySize = Integer.parseInt(st.nextToken());
			sizes = new long[arraySize];
			
			st = new StringTokenizer(input.readLine());
			for(int j=0;j<arraySize;++j)
				sizes[j] = Long.parseLong(st.nextToken());
			
			Arrays.sort(sizes);
			
			int res = process(0, motSize, 0);
			
			output.write("Case #"+new Integer(i)+ ": "+new Integer(res));
			output.newLine();
		}
		
		input.close();
		output.close();
	}

}
