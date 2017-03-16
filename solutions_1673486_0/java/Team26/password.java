import java.util.*;
import java.io.*;

public class password {
    public static void main(String[] args) throws Throwable {
	BufferedReader f=new BufferedReader(new FileReader("password.in"));
	PrintWriter out=new PrintWriter(new BufferedWriter(new FileWriter("password.out")));
	StringTokenizer st=new StringTokenizer(f.readLine());
	int cases=Integer.parseInt(st.nextToken());
	for(int test=1;test<=cases;test++) {
	    st=new StringTokenizer(f.readLine());
	    int a=Integer.parseInt(st.nextToken());
	    int b=Integer.parseInt(st.nextToken());
	    double[] prob=new double[a];
	    st=new StringTokenizer(f.readLine());
	    for(int i=0;i<a;i++) {
		prob[i]=Double.parseDouble(st.nextToken());
		}
	    double min=Double.POSITIVE_INFINITY;
	    double[] prob2=new double[a+1];
	    prob2[0]=1;
	    for(int i=0;i<a;i++) {
		prob2[i+1]=prob2[i]*prob[i];
		}
	    min=Math.min(min,b+2); //press enter
	    for(int i=0;i<=a;i++) { //press backspace i times
		double p1=prob2[a-i]*(2*i+b-a+1);
		double p2=(1-prob2[a-i])*(2*i+2*b-a+2);
		min=Math.min(min,p1+p2);
		}
	    out.println("Case #"+test+": "+min);
	    }
	out.close();
	f.close();
	}
    }