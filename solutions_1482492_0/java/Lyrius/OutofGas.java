import java.util.*;
import java.io.*;
import java.math.*;

public class OutofGas {
	
	static double eps = Math.pow(10, -8);
	

    static void preprocess() {
        
    }

    void solve(Scanner sc, PrintWriter pw) {
    	pw.println();
    	double D = sc.nextDouble();
		int N = sc.nextInt();
		int A = sc.nextInt();
		double acc;
		double[] time = new double[N];
		double[] position = new double[N];
		for(int i=0;i<N;i++){
			time[i]=sc.nextDouble();
			position[i]=sc.nextDouble();
		}
		for(int i=0;i<A;i++){
			acc = sc.nextDouble();
			double pos =0.0;
			int c=1;
			double vit =0.0;
			double t = 0.0;
			while(Math.abs(pos-D)>eps){
				System.out.println(t);
				if(c==N){
					double a = 0.5* acc;
					double b = vit;
					double d = pos-D;
					double rho = rho(a,b,d);
					System.out.println(rho);
					double t1 = solution1(a,b,d);
					System.out.println(t1);
					t+=t1;
					break;
				}
				double v0 = (position[c]-position[c-1])/(time[c]-time[c-1]);
				if(position[c]<=D){
					double a = 0.5* acc;
					double b = (vit-v0);
					double d = pos-position[c-1];
					double rho = rho(a,b,d);
					if(rho>=0){
						double t1 = solution1(a,b,d);
						double t2 = solution2(a,b,d);
						if(t1>eps&&t1<time[c]-time[c-1]||t2>eps&&t2<time[c]-time[c-1]||(Math.abs(pos-position[c])<eps&&vit>v0)){
							pos = position[c];
							vit = v0;
						}
						else{
							pos+=vit*(time[c]-time[c-1])+0.5*acc*(time[c]-time[c-1])*(time[c]-time[c-1]);
							vit +=acc * (time[c]-time[c-1]);
							System.out.println(pos);
						}	
					}
					t+=time[c]-time[c-1];
					c++;
				}
				else{
					double tt = (D-position[c-1])/v0;
					time[c]=tt;
					position[c]=D;
				}	
			}
			pw.println(t);
		}
        
    }
    public static double rho(double a, double b, double c)
    {
        return b*b - 4*a*c;
    }
    
    public static double solution1(double a, double b, double c)
    {
        return (-b + Math.sqrt( rho(a,b,c) ) ) / (2*a);
    }
    
    public static double solution2(double a, double b, double c)
    {
        return (-b - Math.sqrt( rho(a,b,c) ) ) / (2*a);
    }

    public static void main(String[] args) throws Exception {
        preprocess();
        
        Scanner sc = new Scanner(new FileReader("input.txt"));
        sc.useLocale(Locale.US);
        PrintWriter pw = new PrintWriter(new FileWriter("output.txt"));
        int caseCnt = sc.nextInt();
        for (int caseNum=0; caseNum<caseCnt; caseNum++) {
            System.out.println("Processing test case " + (caseNum + 1));
            pw.print("Case #" + (caseNum+1) + ": ");
            new OutofGas().solve(sc, pw);
        }
        pw.flush();
        pw.close();
        sc.close();
    }
}
