import java.io.*;
import java.util.Scanner;


public class GCJBlarge {
	
	
	public static void main(String args[]) throws FileNotFoundException, UnsupportedEncodingException{
		//Scanner scan = new Scanner(new File("C-small-practice.in"));
		GCJBlarge main = new GCJBlarge();
		main.answer();
	}
	
	
	public void answer()throws FileNotFoundException, UnsupportedEncodingException{
		//Scanner scan = new Scanner(System.in);
		Scanner scan = new Scanner(new File("B-large.in"));
		int cases = Integer.parseInt(scan.nextLine()); 
		PrintWriter writer = new PrintWriter("Blarge.out", "UTF-8");
		for(int i=1; i<=cases; i++){
			double C= scan.nextDouble();			
			double F= scan.nextDouble();
			double X= scan.nextDouble();
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
			writer.println("Case #"+i+": "+time);
			System.out.println("Case #"+i+": "+time);		
			
		}
		writer.close();
	}
	
	public double timetill(double rate, double goal, double cookies){
		return (goal-cookies)/rate;
	}
	
}
