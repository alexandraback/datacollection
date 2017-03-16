import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.StringTokenizer;


public class GoodLuck {

	/**
	 * @param args
	 */
	public static int R;
	public static int N =3,M=5 ,K=7;
	public static ArrayList<Integer> numList = new ArrayList<Integer>();
	static int[] products;


	public static String computeLine(String line) {
		numList.clear();
		//String result = "";
		StringTokenizer token = new StringTokenizer(line);
		for(int i=0; i<K; i++) {
			products[i] = Integer.parseInt(token.nextToken());
		}
		int[] count = new int[M+1];
		int temp;
		// find 3
		count[3] = getMaxCount(3);
		for(int i=0; i<count[3]; i++) {
			numList.add(3);
		}
		if(numList.size() == N) {
			return result2String();
		}
		// find 5
		count[5] = getMaxCount(5);
		for(int i=0; i<count[5]; i++) {
			numList.add(5);
		}
		if(numList.size() == N) {
			return result2String();
		}
		
		//find others
		int remainNum = N - numList.size();
		count[2] = getMaxCount(2);
		while(count[2] > remainNum) {
			numList.add(4);
			remainNum--;
			count[2] -= 2;
		}
		
		while (numList.size() < N) {
			numList.add(2);
		}
		return result2String();

	}
	
	public static int getMaxCount(int i) {
		int temp = 0;
		int result = 0;
		for(int j : products) {
			temp = 0;
			while (j % i == 0) {
				j/=i;
				temp++;
			}
			result = Math.max(temp, result);
		}
		
		return result;
	}
	
	public static String result2String() {
		String result = "";
		for(Integer i: numList) {
			result+=i;
		}
		return result;
	}
	public static void main(String[] args) throws IOException {


		// TODO Auto-generated method stub
		if(args.length != 2) {
			System.out.println("Usage: Dancing [input file] [output file].");
		}


		// input
		BufferedReader br = null;
		try {
			br = new BufferedReader(new FileReader(args[0]));
		} catch (FileNotFoundException e1) {
			e1.printStackTrace();
			return;
		}

		// output
		File outputFile = null;
		FileWriter fw = null;
		BufferedWriter bw = null;
		String content = new String();		
		String line = null;
		
		try {


			outputFile = new File(args[1]);

			// if file doesnt exists, then create it
			if (!outputFile.exists()) {
				outputFile.createNewFile();
			}

			fw = new FileWriter(outputFile.getAbsoluteFile());
			bw = new BufferedWriter(fw);



		} catch (IOException e) {
			e.printStackTrace();
		}




		br.readLine();
		StringTokenizer token = new StringTokenizer(br.readLine());
		R = Integer.parseInt(token.nextToken());
		N = Integer.parseInt(token.nextToken());
		M = Integer.parseInt(token.nextToken());
		K = Integer.parseInt(token.nextToken());
		products = new int[K];
		//		int M = 0;
		//		int N = 0;
		//			byte[][] initialState = null;
		//byte[][] initialState = currentState;

		content = "case #1:\n";
		for (int i=1; i <= R; i++) {
			line = br.readLine();
			content += computeLine(line) + "\n";

		}

		bw.write(content);
		bw.close();
		br.close();
	}
}
