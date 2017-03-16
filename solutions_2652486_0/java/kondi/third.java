import java.io.File;
import java.io.FileWriter;
import java.util.Arrays;
import java.util.Random;
import java.util.Scanner;


public class third {

	/**
	 * @param args
	 * @throws Exception 
	 */
	static int [] pow = new int [8];
	public static void main(String[] args) throws Exception { 
			Scanner sc = new Scanner(new File("in.txt"));
			pow[0]=1;
			pow[1] = 2;
			pow[2] = 4;
			pow[3] = 8;
			pow[4] = 16;
			pow[5] = 32;
			pow[6] = 64;
			Random r = new Random();
			FileWriter out = new FileWriter(new File("out.txt"));
			int T = new Integer(sc.nextLine());
			for(int i = 1 ; i < T+1 ; i++)
			{
				int res=0;
				int R = sc.nextInt();
				int N = sc.nextInt();
				int M = sc.nextInt();
				int K = sc.nextInt();
				
				
				System.out.println("Case #"+i+": "+res);
				out.write("Case #1:\n");
				
				for(int j = 0; j < R ; j++)
				{
					int[] num = new int[4];
					for(int z= 0; z < K ; z++)
					{
						int h = sc.nextInt();
						//5
						if(h%125==0)
							num[3] = Math.max(num[3] ,3);
						else if(h%25 == 0)
							num[3] = Math.max(num[3] ,2);
						else if(h%5 == 0)
							num[3] = Math.max(num[3] ,1); 
						//3
						if(h%27==0)
							num[2] = Math.max(num[2] ,3); 
						else if(h%9 == 0)
							num[2] = Math.max(num[2] ,2); 
						else if(h%3 == 0)
							num[2] = Math.max(num[2] ,1); 
						//2
						if(h%64==0)
							num[1] = Math.max(num[1] ,6); 
						else if(h%32 == 0)
							num[1] = Math.max(num[1] ,5); 
						else if(h%16 == 0)
							num[1] = Math.max(num[1] ,4); 
						else if(h%8==0)
							num[1] = Math.max(num[1] ,3); 
						else if(h%4 == 0)
							num[1] = Math.max(num[1] ,2); 
						else if(h%2 == 0)
							num[1] = Math.max(num[1] ,1); 
						  
					}
					System.out.println(Arrays.toString(num));
					
					int left = 3;
					for(int m = 0; m < num[3] ; m++)
					{	out.write("5");left--;}
					for(int m = 0; m < num[2] ; m++)
					{	out.write("3");left--;}
					while(left < num[1]){
						out.write("4");
						left--;
						num[1]-=2;						
					}
					while(num[1]>0 && left>0){
						out.write("2");
						left--; 
						num[1]--;
					} 
					String [] wr = new String[]{"3","5","4","2"};
					while(num[1] == 0 && left>0)
					{
						out.write(wr[r.nextInt(4)]);
						left--;
					}
						
					while(left>0){
						out.write("2");
						left--; 
					} 
					out.write("\n");
				}
				
				
				try{ sc.nextLine();}
				catch(Exception e){}

			}
			out.flush();
			sc.close();
			out.close(); 
	}

}
