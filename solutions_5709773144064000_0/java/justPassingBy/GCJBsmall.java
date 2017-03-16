import java.io.*;
import java.util.Scanner;


public class GCJBsmall {
	
	
	public static void main(String args[]) throws FileNotFoundException, UnsupportedEncodingException{
		//Scanner scan = new Scanner(new File("C-small-practice.in"));
		GCJBsmall main = new GCJBsmall();
		main.answer();
	}
	
	
	public void answer()throws FileNotFoundException, UnsupportedEncodingException{
		//Scanner scan = new Scanner(System.in);
		Scanner scan = new Scanner(new File("B-small-attempt0.in"));
		int cases = Integer.parseInt(scan.nextLine()); 
		PrintWriter writer = new PrintWriter("B.out", "UTF-8");
		for(int i=1; i<=cases; i++){
			//String[] size = scan.nextLine().split(" ");
			double C= scan.nextDouble();			
			double F= scan.nextDouble();
			double X= scan.nextDouble();
			//scan.nextLine();
			//System.out.println(C + " "+F+" "+X);
			double cookies =0;
			double currentRate = 2.0;
			double time=0.0;
			double timestep =0.0;
			while(cookies<X){
				if(X<=C){
					time += timetill(currentRate, X, cookies);
					break;
				}else{
					timestep = timetill(currentRate, C, cookies);
					cookies += timestep*currentRate;
					time+=timestep;
					if(timetill(currentRate, X, cookies)>timetill(currentRate+F, X, cookies-C)){
						cookies -= C;
						currentRate+=F;
					}else{
						time+=timetill(currentRate, X, cookies);
						break;
					}
				}				
			}
			
			//Integer.parseInt(size[0]);
			//scan.nextInt();
			
			
			
			writer.println("Case #"+i+": "+time);
			System.out.println("Case #"+i+": "+time);
			//System.out.println("Case #"+i+": "+"YES");				
			
		}
		writer.close();
	}
	
	public double timetill(double rate, double goal, double cookies){
		return (goal-cookies)/rate;
	}
	
}
