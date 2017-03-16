import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Collection;
import java.util.HashSet;
import java.util.Iterator;
import java.util.Set;




public class RecycleNumber {


	String[] result = new String[9000];
	int testCases = 0;

	private static int shift(int in, int shift){
		int mul = 1;
		for(int k = 1; k <= shift; k++){
			mul *= 10;
		}
		int l = in%mul;
		if(l == 0) return -1;
		int mid = in/mul;
		int c = Integer.valueOf(l+""+mid);
		return c;
	}
	public static void main(String[] args)throws Exception{
		RecycleNumber bp = new RecycleNumber();
		InputVectorSequenceRecycleNumber iv = InputVectorSequenceRecycleNumber.readFileToCreateInputVector(true);

		bp.testCases = Integer.parseInt(iv.inp[0][0]);

		for(int n = 0 ; n < bp.testCases; n++){
			int lowerbound = Integer.parseInt(iv.inp[n+1][0]);
			int upperbound = Integer.parseInt(iv.inp[n+1][1]);
			int count = 0;

			for(int i = lowerbound; i <= upperbound; i++){
				Set<Integer> unique = new HashSet<Integer>();
				for(int j = 1 ; j < String.valueOf(i).length(); j++){
					int y = shift(i, j);
					if(y == -1) continue;
					if(y > i && y <= upperbound && !unique.contains(y)){
						unique.add(y);
						count++;
					}
				}
			}

			bp.result[n] = "Case #"+(n+1)+":"+" "+count;
		}

		bp.outputFile();
	}




	public void outputFile() throws IOException{
		FileWriter fos = new FileWriter ("C:/workspace/googleCJ/google/input/c.txt");
		BufferedWriter bw = new BufferedWriter(fos);
		for(int i =0; i< testCases; i++){
			bw.write(result[i]);
			bw.write("\r\n");
		}
		bw.close();

	}

}

class InputVectorSequenceRecycleNumber{
	private static int DATA_LENGTH = 9000;
	public int lines = -1;
	public String[][] inp = new String[DATA_LENGTH][];
	String[] result = new String[DATA_LENGTH];

	private InputVectorSequenceRecycleNumber(){

	}

	public static InputVectorSequenceRecycleNumber readFileToCreateInputVector(boolean splitLineBySpace) throws IOException{

		BufferedReader br = new BufferedReader(new FileReader ("C:/workspace/googleCJ/google/input/b.txt"));
		String str = null;
		InputVectorSequenceRecycleNumber iv = new InputVectorSequenceRecycleNumber();

		while ((str = br.readLine()) != null) {
				iv.lines++;
		        iv.inp[iv.lines] = process(str, splitLineBySpace);
		}

		return iv;
	}

	private static String[] process(String str, boolean splitLineBySpace) {
		String[] ret = null;
		if(splitLineBySpace){
			ret = str.split("\\ ");
		}else{
			ret = new String[]{str};
		}
	 return ret;
	}


}
