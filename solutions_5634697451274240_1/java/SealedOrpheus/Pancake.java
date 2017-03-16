import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

public class Pancake {
	
	public static void main(String args[])
	{
		try (BufferedReader br = new BufferedReader(new FileReader("D:\\B-large.in")))
		{
			FileWriter fileWriter =   new FileWriter("D:\\B-large.out");
			BufferedWriter bw =   new BufferedWriter(fileWriter);
			int loop = Integer.parseInt(br.readLine());
			String input;
			String output;
			boolean prev;
			boolean start;
			int flip;
			for(int i=1;i<=loop;i++){
				input=br.readLine();
				prev=false;
				start=false;
				flip=0;
				for(int j=0;j<input.length();j++){
					if(input.charAt(j)=='-'){
						start=true;
					}else{
						if(start){
							if(!prev){
								flip++;
							}else{
								flip+=2;

							}
						}
						prev=true;
						start=false;
					}
				}
				if(start){
					if(!prev){
						flip++;
					}else{
						flip+=2;
					}
				}
				output="Case #"+i+": "+flip;
				bw.write(output);
				bw.newLine();
			}				
			bw.close();
		} catch (IOException e) {
			e.printStackTrace();
		} 
	}
}
