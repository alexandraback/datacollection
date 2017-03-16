import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Scanner;


public class Googlers {

	/**
	 * @param args
	 * @throws IOException 
	 */
	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		BufferedReader read=new BufferedReader(new InputStreamReader(System.in));
		String l;
		l=read.readLine();
		int a=Integer.parseInt(l);
		for (int i = 0; i < a; i++) {
			Scanner scn=new Scanner(read.readLine());
			int n=scn.nextInt();
			int s=scn.nextInt();
			int p=scn.nextInt();
			int sum=0;
			for (int j = 0; j < n; j++) {
				int m=scn.nextInt();
				if(m >= p+Math.max(0,(p-1)+(p-1)))
				{
					sum++;
					//System.out.println(m+"..");
				}else{
					if(s>0)
					{
						if(m>=p+Math.max(0,(p-2)+(p-2)))
						{
							s--;
							sum++;
							//System.out.println(m+" "+p);
						}
					}
				}
			}
			System.out.println("Case #"+(i+1)+": "+sum);
		}
	}

}
