import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class RecycledNumbers {
	public static void main(String args[])throws IOException{
		Scanner scan = new Scanner(new File(System.getProperty("user.dir")+"/input.in"));
		FileWriter file = new FileWriter("output.out");
		int n=scan.nextInt();
		for(int j=0;j<n;j++){
			int a = scan.nextInt();
			int b = scan.nextInt();
			int recycled=0;
			for(int i=a;i<b+1;i++){
				String s = Integer.toString(i);
				while((s.substring(1)+s.substring(0,1)).compareTo(Integer.toString(i))!=0){
					s=s.substring(1)+s.substring(0,1);
					if(Integer.parseInt(s)>=a&&Integer.parseInt(s)<=b)
						recycled++;
				}
			}
			file.write("Case #"+Integer.toString(j+1)+": "+Integer.toString(recycled/2)+"\r\n");
		}
		file.close();
	}
}
