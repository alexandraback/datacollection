package recyclednumbers;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.HashMap;

public class RecycledNumbers {

	
	public static void main(String[] args) throws IOException {
		BufferedReader br=new BufferedReader(new FileReader(new File("./recyclednumbers/c-small-attempt0.in")));
		BufferedWriter bw=new BufferedWriter(new FileWriter(new File("./recyclednumbers/small.out")));
		
		int numberOfCase=Integer.parseInt(br.readLine());
		
		StringBuilder out=new StringBuilder();
		
		for(int i=1;i<=numberOfCase;i++){
			out.append("Case #"+i+": ");
			int count=0;
			String input=br.readLine();
			int start=Integer.parseInt(input.substring(0,input.indexOf(" ")));
			int end=Integer.parseInt(input.substring(input.indexOf(" ")+1));
			
			for(int j=start;j<=end;j++){
				ArrayList<Integer>list=new ArrayList<Integer>();
				
				int n=10;
				while(j>=n){
					int last=j%n;
					int first=j/n;
					
					int recycle=last*(int)Math.pow(10, String.valueOf(first).length())+first;
					
					if(recycle>j && recycle<=end){
						if(!list.contains(recycle)){
							count++;
							list.add(recycle);
						}
					}
					
					n*=10;
				}
				
				
				
			}				
				
			
			
			out.append(count);
			if(i<numberOfCase)
				out.append("\n");
		}
		
		bw.write(out.toString());
		bw.close();
		br.close();

	}

	
	
}
