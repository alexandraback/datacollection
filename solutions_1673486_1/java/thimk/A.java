import java.util.*;

public class A
{
    public static void main(String[] args)
    {
	double p[] = new double[100001];
	int A, B;
	int T;

	Scanner in = new Scanner(System.in);
	T = in.nextInt();
	int caseno = 0;

	while(caseno < T){
	    caseno++;

	    A = in.nextInt();
	    B = in.nextInt();

	    p[0] = 1;
	    for(int i = 1; i <= A; i++)
		p[i] = in.nextDouble();

	    double exp = 1 + B + 1;
	    double succeed = 1;
	    for(int i = 0; i <= A; i++){
		succeed *= p[i];
		double exp2 = 2*(A - i) + B-A + 1 + (1-succeed)*(B + 1);
		if(exp2 < exp) exp = exp2;
	    }
	    
	    System.out.println("Case #" + caseno + ": " + exp);
		    
	}
	
	
	    

    }
}