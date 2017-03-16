package Round_1B;

import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class Lottery {
	public static void main(String[] args) 
	{
		try{
			String readFrom = "1B/B-small-attempt0.in";
			Scanner sc = new Scanner(new File(readFrom));
			FileWriter out = new FileWriter(new File("1B/B-small-attempt0.out"));
			
			int testCases = sc.nextInt();
			int A,B,K;
			for(int t=1; t<=testCases; t++)
			{
				A = sc.nextInt();
				B = sc.nextInt();
				K = sc.nextInt();
				
				int count = 0;
				
				for(int a = 0; a<A; a++){
					for(int b = 0; b<B; b++){
						for(int k=0; k<K; k++){
							if((a & b) == k){
								count ++;
							}
						}
					}
				}
				
				String res = "Case #" + t + ": " + count;
				System.out.println(res);
				out.write(res + "\n");
			}

			out.close();
		}catch(IOException e)
		{
			System.out.println("IO error");
		}

	}
}
