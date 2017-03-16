/**
 * 
 */
package codejam2013;

import java.io.File;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

/**
 * @author 61410516
 *
 */
public class Osmos{
	static String inpPath = "C:/Users/61410516/Downloads/a.in";	//Enter the input file path
	static String outPath = "C:/Rough/a.out";	//Enter the output file path
	
	public static void main(String[] args) {
		
		try{
			Scanner sc= new Scanner(new File(inpPath));	//new File(inpPath)
			PrintWriter out = new PrintWriter(new File(outPath));
			int cases = sc.nextInt();
			for(int t=1;t<=cases;t++){
				solve(t,sc,out);
			}
			out.flush();
			out.close();
		}catch(Exception ex){ex.printStackTrace();}
		
	}
	
	public static void solve(int t,Scanner sc, PrintWriter out){
		
		int size = sc.nextInt();
		int n = sc.nextInt();
		int[] motes = new int[n];
		for(int i=0;i<n;i++)
			motes[i] = sc.nextInt();
		Arrays.sort(motes);
		int operations = 0;
		int max = 0;
		for(int i=0;i<n;i++){
			if(motes[i]<size)
				size+=motes[i];
			else{ 
				if(max == 0) 
					max = n-i;	// Maximum possible result
				int temp = 0;
				//Attempt absorption
				while(temp<n-i){
					size += size-1;
					temp++;
					if(size > motes[i]){
						size += motes[i];
						operations += temp;
						temp = -1;
						break;
					}
				}
				//Can't absorb
				if(temp != -1){
					operations += n-i;
					break;
				}
			}
		}
		out.println("Case #"+t+": "+(operations<max ? operations:max));
	}

}
