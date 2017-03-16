import java.util.Scanner;


public class Solution {
	public static void main(String[] args){
		Scanner scan = new Scanner(System.in);
	    int T = scan.nextInt();
	    double[] result = new double[T];
	    for(int i=0;i<T;i++){
	    	int A = scan.nextInt();
	    	int B = scan.nextInt();
	    	double[] p= new double[A];
	    	double[] c= new double[A];
	    	p[0] = scan.nextDouble();
	    	c[0]=p[0];
	    	
	    	double min=2.0+B;
	    	
	    	double temp =c[0]*(A-1+B)+(1-c[0])*(A+B+B);
	    	if(temp<min){
	    		min=temp;
	    	}
	    	
	    	for(int j=1;j<A;j++){
	    		p[j] = scan.nextDouble();
	    		c[j] = p[j]*c[j-1];	
	    		temp = c[j]*(A-2*j+B-1) +(1-c[j])*(A-2*j+B-1+B+1);
	    		if(temp<min){
	    			min=temp;
	    		}
	    		
	    	}
	    	temp=A+B+1;
	    	if(temp<min){
	    		min=temp;
	    	}  
	    	
	    	result[i]=min;    	
	    }
	    
	    for(int i=0;i<T;i++){
	    	System.out.format("Case #%d: %f%n",(i+1),result[i]);
	    }
	}
	
}
