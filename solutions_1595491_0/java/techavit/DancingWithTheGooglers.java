package dancingwiththegooglers;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

public class DancingWithTheGooglers {

	
	public static void main(String[] args) throws IOException {
		

		BufferedReader br=new BufferedReader(new FileReader(new File("./dancingwiththegooglers/b-small-attempt1.in")));
		BufferedWriter bw=new BufferedWriter(new FileWriter(new File("./dancingwiththegooglers/small1.out")));
		
		int numberOfCase=Integer.parseInt(br.readLine());
		
		StringBuilder out=new StringBuilder();
		
		for(int i=1;i<=numberOfCase;i++){
			int count=0;
			out.append("Case #"+i+": ");
			
			String[]input=br.readLine().split(" ");
			
			int surprising=Integer.parseInt(input[1]);
			int goal=Integer.parseInt(input[2]);
			int googlers=Integer.parseInt(input[0]);
			for(int j=3;j<3+googlers;j++){
				
				int result=check(Integer.parseInt(input[j]),goal,surprising);
				if(result==0){
					count++;
					surprising--;
				}
				if(result==1)
					count++;
				
					
				
			}
			
			
			
			out.append(count);
			if(i<numberOfCase)
				out.append("\n");			
			
			
		}
		bw.write(out.toString());
		br.close();
		bw.close();
		

	}
	
	/*
	 * return  1 - possible to achieve goal and is not surprising
	 *         0 - possible to achieve goal and is surprising
	 *         -1 - impossible to achieve goal
	 */
	public static int check(int totalScore,int goal,int surprising){
		
		if(totalScore<goal)
			return -1;
		
		int r=totalScore%3;
		int max=-1;
		if(r==0)
			max=totalScore/3;
		if(r==1)
			max=(int)Math.ceil(totalScore/3.0);
		if(r==2)
			max=(int)Math.ceil(totalScore/3.0);
		
		if(max<goal)
			if(surprising==0)
				return -1;
			else{
				if(totalScore>=goal+(goal-2)+(goal-2))
					return 0;
				else
					return -1;
			}
		else
			return 1;
		
	}

}
