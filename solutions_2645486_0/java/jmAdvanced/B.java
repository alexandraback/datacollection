package codejam;

import java.io.BufferedReader;
import java.io.DataInputStream;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.io.PrintWriter;

public class B {

	
	public static void main(String[] args) throws NumberFormatException,
			IOException {
		try {
			System.setIn(new FileInputStream(args[0]));
			System.setOut(new PrintStream(new FileOutputStream(args[1])));
		} catch (Exception e) {
			throw new RuntimeException(e);
		}
		DataInputStream in = new DataInputStream(System.in);
		BufferedReader br = new BufferedReader(new InputStreamReader(in));
		PrintWriter out = new PrintWriter(System.out);

		int numCase = Integer.parseInt(br.readLine());

		for (int i = 1; i <= numCase; i++) {
			System.out.print("Case #"+i+": ");
			run(br, out);
		}
	}

	public static void run(BufferedReader br, PrintWriter out)
			throws NumberFormatException, IOException {

		String[] tmp=getTokens(br);
		
		int initial=Integer.parseInt(tmp[0]);
		int regain=Integer.parseInt(tmp[1]);
		
		tmp=getTokens(br);
		boolean doAll=false;
		
		if(initial==regain)
			doAll=true;
		
		
		int[] arr=new int[tmp.length];
		for(int i=0;i<tmp.length;i++)
			arr[i]=Integer.parseInt(tmp[i]);

		int sum=0;
		if(doAll){
			for(int i=0;i<tmp.length;i++)
				sum=sum+arr[i];
			
			sum=sum*regain;
		}
		else{
			int max=0;
			for(int i=0;i<tmp.length;i++)
				if(max<arr[i])
					max=arr[i];
			
			for(int i=0;i<tmp.length;i++){
				if(arr[i]==max)
					continue;
				sum=sum+arr[i];
			}
			
			sum=sum*regain;
			sum=sum+max*initial;
			
		}
			
			
		System.out.println(sum);
		
	}

	
	
	public static String[] getTokens(BufferedReader br) throws IOException {
		return br.readLine().split("\\s+");
	}
	/*
	 * public static float calculate(float[] Data){
	 * 
	 * }
	 */
	
}
