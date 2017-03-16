import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;


public class Googlers {
	public static void main(String args[])throws IOException{
		Scanner scan = new Scanner(new File(System.getProperty("user.dir")+"/input.in"));
		FileWriter file = new FileWriter("output.out");
		int n=Integer.parseInt(scan.nextLine());
		for(int j=0;j<n;j++){
			int numGooglers = scan.nextInt();
			int totalSurprising = scan.nextInt();
			int p = scan.nextInt();
			int[] totals = new int[numGooglers];
			for(int i=0;i<numGooglers;i++){
				totals[i]=scan.nextInt();
			}
			int[] totalsMinus = new int[numGooglers];
			for(int i=0;i<numGooglers;i++){
				totalsMinus[i]=totals[i]-p;
			}
			int max =0;
			int surprising=0;
			for(int i=0;i<numGooglers;i++){
				if(totalsMinus[i]>=0&&p-(int)Math.floor(totalsMinus[i]/2)<=2){
					max++;
					if(p-(int)Math.floor(totalsMinus[i]/2)==2)
						surprising++;
				}
			}
			while(surprising>totalSurprising){
				surprising--;
				max--;
			}
			file.write("Case #"+Integer.toString(j+1)+": "+Integer.toString(max)+"\r\n");
		}
		file.close();
	}
}
