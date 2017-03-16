package gcj2013;

import java.io.*;

public class ProblemB {
	BufferedReader br;
	BufferedWriter bw;
	
	public ProblemB(BufferedReader br, BufferedWriter bw) {
		this.br = br;
		this.bw = bw;
	}
	
	public void exec()
		throws IOException{
		
		String[] strs;
		
		B_lawn lawn;
		
		int num, row, col;
		int i,j,k;
		
		// read 1st line (Number of Testcase)
		num = Integer.parseInt(br.readLine());

		//read Each Testcase
		for(i=1; i<=num; i++){
			
			//read Each Parameters of Testcase
			strs = br.readLine().split(" ");
			row  = Integer.parseInt(strs[0]);
			col  = Integer.parseInt(strs[1]);
			
			//initialize Variables
			lawn = new B_lawn(row, col);
			
			//read Target Pattern
			for(j=0; j<row; j++){
				strs = br.readLine().split(" ");
				for(k=0; k<col; k++){
					lawn.set(j, k, Integer.parseInt(strs[k]));
				}
			}
			
			//check Pattern
			if(lawn.chk()){
				bw.write("Case #" + i + ": YES" + "\n");
			}
			else{
				bw.write("Case #" + i + ": NO" + "\n");
			}
		}
		
		br.close();
		bw.close();
	}
}
