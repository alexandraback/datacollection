import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;




public class DanceScore {


	String[] result = new String[9000];
	int testCases = 0;

	public static void main(String[] args)throws Exception{
		DanceScore bp = new DanceScore();
		InputVectorSequenceDance iv = InputVectorSequenceDance.readFileToCreateInputVector(true);

		bp.testCases = Integer.parseInt(iv.inp[0][0]);

		for(int n = 0 ; n < bp.testCases; n++){
			int dancer = Integer.parseInt(iv.inp[n+1][0]);
			int surprise = Integer.parseInt(iv.inp[n+1][1]);
			int cutoff = Integer.parseInt(iv.inp[n+1][2]);
			int solution = 0;

			for(int i = 0; i < dancer; i++){
				int total = Integer.parseInt(iv.inp[n+1][3+i]);
				if(total == 0){
					if(cutoff == 0)solution++;
					continue;
				}
				int base = total /3 ;
				int offset = total %3;
				if(offset == 0){
					if(base >= cutoff) solution++;
					else if (base+1 >= cutoff && surprise > 0){ solution++; surprise--;}
				}else if(offset == 1){
					if(base >= cutoff) solution++;
					else if(base+1 >= cutoff)solution++;
				}else if(offset == 2){
					if(base >= cutoff) solution++;
					else if(base+1 >= cutoff)solution++;
					else if(base+2 >= cutoff && surprise > 0){ solution++; surprise--;}
				}

			}

			bp.result[n] = "Case #"+(n+1)+":"+" "+solution;
		}

		bp.outputFile();
	}




	public void outputFile() throws IOException{
		FileWriter fos = new FileWriter ("C:/workspace/googleCJ/google/input/b.txt");
		BufferedWriter bw = new BufferedWriter(fos);
		for(int i =0; i< testCases; i++){
			bw.write(result[i]);
			bw.write("\r\n");
		}
		bw.close();

	}

}

class InputVectorSequenceDance{
	private static int DATA_LENGTH = 9000;
	public int lines = -1;
	public String[][] inp = new String[DATA_LENGTH][];
	String[] result = new String[DATA_LENGTH];

	private InputVectorSequenceDance(){

	}

	public static InputVectorSequenceDance readFileToCreateInputVector(boolean splitLineBySpace) throws IOException{

		BufferedReader br = new BufferedReader(new FileReader ("C:/workspace/googleCJ/google/input/a.txt"));
		String str = null;
		InputVectorSequenceDance iv = new InputVectorSequenceDance();

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
