import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;


public class GoogleCodeJam2015Q3 {

	ArrayList<String> inputLines = new ArrayList<String>();
	ArrayList<String> outputLines = new ArrayList<String>();
	private static final String PATH ="/Users/koichisakumoto/Documents/GoogleCodeJam/2015/Q3/";
	
	public static void main(String[] args) {
		GoogleCodeJam2015Q3 inst = new GoogleCodeJam2015Q3();
		//inst.getLines(PATH + "test.txt");
		inst.getLines(PATH + "C-small-attempt1.in.txt");
		//inst.getLines(PATH + "C-large.in.txt");
		inst.solveProblem();
		//inst.putLines(PATH + "answer_test.txt");
		inst.putLines(PATH + "answer_small_1.txt");
		//inst.putLines(PATH + "answer_large.txt");
	}
	
	final private static int I = 2;
	final private static int J = 3;
	final private static int K = 4;

	private void solveProblem(){
		int currentLine = 0;
		int totalNum = Integer.parseInt(inputLines.get(currentLine++));
		
		for (int problemNum = 1; problemNum <= totalNum; problemNum++ ) {
			
			// input problem
			String[] LX = inputLines.get(currentLine++).split(" ");
			long L = Long.valueOf(LX[0]);
			long X = Long.valueOf(LX[1]);
			String q_string = inputLines.get(currentLine++);
			int[] q_array = new int[q_string.length()];
			for(int i = 0; i < q_array.length; i++){
				switch(q_string.charAt(i)){
				case 'i':
					q_array[i] = I;
					break;
				case 'j':
					q_array[i] = J;
					break;
				case 'k':
					q_array[i] = K;
					break;
				default:
					System.out.println("ERROR!!");
					return;
				}
			}
			
			// solve problem
			
			// check multiplication
			int q_int = 1;
			for(int i = 0; i < q_array.length; i++){
				q_int = mul(q_int, q_array[i]);
			}
			int q_pow = q_int;
			for(long i = 1; i < X; i++){
				q_pow = mul(q_pow, q_int);
			}
			boolean mul_OK = q_pow == -1;
			
			// check forward
			long forward_index = check_forward(q_array, X);
			
			// check backward
			long backward_index = check_backward(q_array, X);
			
			String answer = (mul_OK && (0 <= forward_index) && (forward_index < backward_index))? "YES" : "NO";

			// 解答を作る
			outputLines.add("Case #" + problemNum + ": " + answer);
		}
	}
	
	private void getLines(String fileName){
		try {
            FileReader in = new FileReader(fileName);
            BufferedReader br = new BufferedReader(in);
            String line;
            while ((line = br.readLine()) != null) {
            	inputLines.add(line);
            }
            br.close();
            in.close();
        } catch (IOException e) {
            System.out.println(e);
        }
	}
	
	private void putLines(String fileName){
		try {
			FileWriter out = new FileWriter(fileName); // new file
			BufferedWriter bw = new BufferedWriter(out);
            for ( String line : outputLines ){
            	bw.write(line + "\r\n");
            }
            bw.close();
            out.close();
        } catch (IOException e) {
            System.out.println(e);
        }
	}
	
	private int maxIndex(int array[]){
		int max = 0;
		for(int i = 0; i < array.length; i++){
			if(array[max] < array[i]){
				max = i;
			}
		}
		return max;
	}
	
	private int maxValue(int array[]){
		int index = maxIndex(array);
		return array[index];
	}
	
	private int minIndex(int array[]){
		int min = 0;
		for(int i = 0; i < array.length; i++){
			if(array[min] > array[i]){
				min = i;
			}
		}
		return min;
	}
	
	private int minValue(int array[]){
		int index = minIndex(array);
		return array[index];
	}
	
	// i: 2
	// j: 3
	// k: 4
	private int unsigned_mul(int q1, int q2){
		if(q1 == 1) return q2;
		if(q2 == 1) return q1;
		if(q1 == I){
			if(q2 == I)	return -1;
			if(q2 == J)	return K;
			if(q2 == K) return -J;
			return 0;
		} 
		if (q1 == J){
			if(q2 == I)	return -K;
			if(q2 == J)	return -1;
			if(q2 == K) return I;
			return 0;
		}
		if (q1 == K){
			if(q2 == I)	return J;
			if(q2 == J)	return -I;
			if(q2 == K) return -1;
			return 0;
		}
		
		return 0;
	}
	
	private int mul(int q1, int q2){
		int sign_q1 = (q1 > 0)? +1 : -1;
		int sign_q2 = (q2 > 0)? +1 : -1;
		int ans = unsigned_mul(Math.abs(q1), Math.abs(q2));
		return ans * sign_q1 * sign_q2;
	}

	private long check_forward(int q_array[], long x){
		int q_int = 1;
		for(long i = 0; i < x; i++){
			for(int j = 0; j < q_array.length; j++){
				q_int = mul(q_int, q_array[j]);
				if(q_int == I) return i*q_array.length + j;
			}
		}
		return -1;
	}
	
	private long check_backward(int q_array[], long x){
		int q_int = 1;
		for(long i = 0; i < x; i++){
			for(int j = q_array.length-1; j >= 0; j--){
				q_int = mul(q_array[j], q_int);
				if(q_int == K) return (x-i-1)*q_array.length + j;
			}
		}
		return -1;
	}
	
}
