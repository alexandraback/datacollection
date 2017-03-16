import java.io.File;
import java.io.FileWriter;
import java.util.Scanner;
import java.io.IOException;

public class Password {
	public static void main(String[] args)throws IOException {
		Scanner scan = new Scanner(new File(System.getProperty("user.dir")+"/input.in"));
		FileWriter file = new FileWriter("output.out");
		int n=Integer.parseInt(scan.nextLine());
		for(int i=0;i<n;i++){
			int a = scan.nextInt();
			int b = scan.nextInt();
			double[] prob = new double[a];
			for(int j=0;j<a;j++){
				prob[j]=scan.nextDouble();
			}
			double enter = b+2;
			double perfect = 1;
			for(int j=0;j<a;j++){
				perfect*=prob[j];
			}
			double keep = b-a+1+(1-perfect)*(b+1);
			double min = Math.min(keep, enter);
			for(int j=1;j<a;j++){
				double no_error = 1;
				for(int k=0;k<a-j;k++){
					no_error*=prob[k];
				}
				double temp = 2*j+b-a+1+(1-no_error)*(b+1); 
				min = Math.min(temp, min);
				System.out.println(j);
			}
			file.write("Case #"+Integer.toString(i+1)+": "+Double.toString(min)+"\r\n");
		}
		file.close();
	}

}
