import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Scanner;
import java.util.Set;




public class Inheritance {


	String[] result = new String[9000];
	int testCases = 0;

	static class Chain{
		Chain(int th, int size){
			this.th = th;
			connection = new int[size];
			connected = new ArrayList<Set<Integer>>(size);
			for(int k =0 ; k < size; k++){
				connected.add(k, new HashSet<Integer>());
			}
		}

		int th;
		int[] connection = null;
		Set<Integer> visited = new HashSet<Integer>();
		List<Set<Integer>> connected = null;

		public boolean test(List<Chain> l){
			if(this.connection!= null && this.connection.length < 2) return false;

			Chain current = this;
			for(int ind = 0; ind < current.connection.length; ind++){
				int to = current.connection[ind];
					for(Chain a: l){

						if(a.th == to){
							iterate(a, l, ind);
							for(int m = 0; m < ind; m++){
								for(Integer y : this.connected.get(ind)){
									if(this.connected.get(m).contains(y)){
										return true;

									}
								}
							}
						}
					}
			}
			return false;
		}

		private boolean iterate(Chain current, List<Chain> l, int ind){
			this.connected.get(ind).add(current.th);
			for(int to: current.connection){
				for(Chain a: l){
					if( a.th == to){
						iterate(a, l, ind);
					}
				}
			}
			return false;
		}

	}


	public static void main(String[] args)throws Exception{

		Inheritance bp = new Inheritance();
		InputVector iv = InputVector.readFileToCreateInputVector(false);

		bp.testCases = Integer.parseInt(iv.inp[0][0]);
		Scanner aLine;
		int testCaseLength = 0;
		for(int n = 0 ; n < bp.testCases; n++){
			aLine = new Scanner(iv.inp[n+testCaseLength+1][0]);
			int A = aLine.nextInt();
			List<Chain> all= new ArrayList<Chain>(A);

			for(int i = 0 ; i < A; i++){
				Scanner l = new Scanner(iv.inp[n+testCaseLength+2+i][0]);
				int loop = l.nextInt();

				Chain c = new Chain(i+1, loop);
				for(int k = 0; k <loop; k++){
					c.connection[k] = l.nextInt();
				}
				all.add(c);
			}

			String res = "No";
			for(Chain x :all){

				if(x.test(all) == true){
					res = "Yes";
					break;
				}


			}


			bp.result[n] = "Case #"+(n+1)+":"+" "+res;
			testCaseLength+=A;
		}

		bp.outputFile();
	}


	public void outputFile() throws IOException{
		FileWriter fos = new FileWriter ("C:/workspace/googleCJ/google/input/x1.txt");
		BufferedWriter bw = new BufferedWriter(fos);
		for(int i =0; i< testCases; i++){
			bw.write(result[i]);
			bw.write("\r\n");
		}
		bw.close();

	}


	private static class InputVector{
		private static int DATA_LENGTH = 9000;
		public int lines = -1;
		public String[][] inp = new String[DATA_LENGTH][];

		private InputVector(){

		}

		public static InputVector readFileToCreateInputVector(boolean splitLineBySpace) throws IOException{

			BufferedReader br = new BufferedReader(new FileReader ("C:/workspace/googleCJ/google/input/x.txt"));
			String str = null;
			InputVector iv = new InputVector();

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
}


