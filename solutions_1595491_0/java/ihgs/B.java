package qualification;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintStream;

import common.FileTranslatorBasis;


public class B {
	
	int allOkLine;
	int surprisingOkLine;
	
	int allOkcount = 0;
	int surprisingOkcount = 0;
	
	int s;
	public void setS(int s){
		this.s = s;
	}
	public void setP(int p){
		allOkLine = p*3-2;
		surprisingOkLine = p*3-4;
		if(surprisingOkLine<=0){
			surprisingOkLine = 1;
		}
	}
	
	public void setT(int t){
		if(t>=allOkLine)
			allOkcount++;
		else if (t>=surprisingOkLine)
			surprisingOkcount++;
		
	}
	
	public int getAns(){
		int surprise = surprisingOkcount > s ? s : surprisingOkcount;
		return surprise + allOkcount;
	}
	
	
	public static void main(String[] args) throws FileNotFoundException {

		System.setOut(new PrintStream(new File("output.txt")));

		String fname = "B-small-attempt0.in.txt";
//		String fname = "B-large-attempt0.in.txt";
		FileTranslatorBasis ftb = FileTranslatorBasis.getInstance(fname);

		int num = ftb.getNumOfCase();
		for (int i = 0; i < num; i++) {
			int[] input = ftb.getIntDataArray();
			B b = new B();
			b.setS(input[1]);
			b.setP(input[2]);
			for(int j=0;j<input[0];j++){
				b.setT(input[j+3]);
			}
			System.out.println("Case #" + Integer.toString(i + 1) + ": "
					+ String.valueOf(b.getAns()));

		}

	}
	
}
