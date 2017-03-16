import java.io.*;
import java.util.*;
import java.lang.*;

public class CodeJam2012R1A_B {
	public String calc(int N, int[] a, int[] b) {
		int star = 0;
		int play = 0;
		int[] done = new int[N];
		boolean updated = true;
		
		while(updated) {
			for(int i=0; i<N; i++) {
				if((done[i] == 0 && a[i]<=star && b[i]<=star)||(done[i] == 1 && b[i]<=star)) {
					star += 2-done[i];
					done[i]=2;
					play++;
					i=-1;
				}
			}
			updated = false;
			int index=-1;
			int max = 0;
			for(int i=0; i<N; i++) {
				if(done[i]==0 && a[i]<=star && b[i]>max) {
					max = b[i];
					index = i;
				}
			}
			if(index>=0) {
				star++;
				done[index]=1;
				play++;
				updated =true;
			}
		}
		
		for(int i=0; i<N; i++) {
			if(done[i]<2) return "Too Bad";
		}
		
		return String.valueOf(play);
	}
	
	public static void main(String[] args) {
		try{
//			(new CodeJam2012R1A_B()).exec("B-small.in", "2012R1A_B-small.out");
			(new CodeJam2012R1A_B()).exec("B-large.in", "2012R1A_B-large.out");
			}catch(Exception ex) {
				
			}
	}

	public final void exec(String inFileName, String outFileName) throws Exception{
		BufferedReader	inReader	= new BufferedReader(new FileReader(inFileName));
		PrintWriter		outWriter	= new PrintWriter(new BufferedWriter(new FileWriter(outFileName)));
		int caseNums=0;
		caseNums = Integer.parseInt(inReader.readLine());
		
		for(int i=0; i<caseNums; i++) {
			int N = Integer.valueOf(inReader.readLine());
			int[] a = new int[N];
			int[] b = new int[N];
			for(int j=0; j<N; j++) {
				String[] input = inReader.readLine().split(" ");
				a[j] = Integer.valueOf(input[0]);
				b[j] = Integer.valueOf(input[1]);
			}
			String outStr = calc(N, a, b);

			String fmtOutStr="Case #" + (i+1) + ": " + outStr;	
			outWriter.println(fmtOutStr);
			System.out.println(fmtOutStr);
		}

		outWriter.close();
		inReader.close();
	}
}
