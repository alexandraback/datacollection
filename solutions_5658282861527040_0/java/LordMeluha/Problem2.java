package Round1B;

import java.util.ArrayList;

import input.Input;

public class Problem2 {

static Input input;
	
	public static void main(String args[]){
		String fileName = "B-small-attempt1.in";
		input = new Input(fileName);
		int N = input.nextInt();
		
		for(int i=0 ; i<N; i++){
			System.out.println("Case #" + (i+1) + ": " + solve());
		}
	}

	private static String solve() {
		String answer = "";
		
		int A = input.nextInt();
		int B = input.nextInt();
		int K = input.nextInt();
		
		int count=0;
		for(int i =0 ; i< A ; i++){
			for(int j=0; j <B ; j++){
				int and = (i & j);
				if(and < K){
					count++;
				}
			}
		}
		
		return answer+count;
	}
}
