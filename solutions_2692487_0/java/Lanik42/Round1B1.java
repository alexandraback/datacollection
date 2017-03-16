import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Arrays;


public class Round1B1 {

	private static BufferedReader reader;
	private static BufferedWriter writer;
	private static int numCases;
	/**
	 * @param args
	 * @throws IOException 
	 */
	public static void main(String[] args) throws IOException {
		setupReader(args);
		setupWriter();
		
		String line = reader.readLine();
		if(line != null) {
			numCases = Integer.parseInt(line);
			String[] split = null;
			for (int i=0;i<numCases;i++) {
				split = reader.readLine().split(" ");
				int a = Integer.parseInt(split[0]);
				int opsRequired = 0;
				split = reader.readLine().split(" ");
				if (a==1) {
					opsRequired = split.length;
				}else {
				int[] motes = new int[split.length];
				for (int j = 0;j<split.length;j++) {
					motes[j] = Integer.parseInt(split[j]);
				}
				Arrays.sort(motes);
				int[] opsReqd = new int[motes.length];
				for (int j = 0; j<motes.length;j++) {
					
						opsReqd[j]=opsToConsume(a, motes[j]);
						for (int num = 0;num<opsReqd[j];num++){
							a+= a-1;
						}
						a+= motes[j];
					
				}
				int prev = 0;
				for (int j = motes.length-1;j>=0;j--) {
					motes[j]=Math.min(opsReqd[j]+ prev, motes.length-j);
					prev = motes[j];
							
				}
				System.out.println(Arrays.toString(motes));
				opsRequired = motes[0];
			}
				writer.write(String.format("Case #%d: %d\n", i+1,opsRequired));
			}
		}

		writer.close();
		reader.close();
	}

	private static int opsToConsume(int a, int i) {
		int ops = 0;
		if (a==1) {
			ops = 1;
		} else 
			while (a<=i) {
				a += a-1;
				ops++;
			}
		return ops;
	}

	private static void setupWriter() throws IOException {
		writer = new BufferedWriter(new FileWriter("D:\\Temp\\output.txt"));
		
	}

	private static void setupReader(String[] args) throws FileNotFoundException {
		if (args.length>0) {
			File file = new File(args[0]);
			if (file.exists())
				reader = new BufferedReader(new FileReader(file));
			else
				System.out.println("invalid In-file.");
		}

	}

}
