import java.util.Scanner;


public class Solution {
	public static void main(String[] args){
		Scanner scan = new Scanner(System.in);
	    int T = scan.nextInt();
	    
	    double[][] results= new double[T][];
	    
	    for(int i=0;i<T;i++){
	    	int N = scan.nextInt();
	    	int[] judge = new int[N];
	    	double[] result = new double[N];
	    	double sum1=0.0;
	    	for(int j=0;j<N;j++){
	    		judge[j]= scan.nextInt();
	    		sum1+=judge[j];
	    	}
	    	int count = 0;	    	
	    	double ave= 2*sum1/N;
	    	double sum2=0.0;
	    	boolean[] remove = new boolean[N];
	    	
	    	boolean hasRemove = true;
	    	while(hasRemove){
	    		hasRemove = false;
	    		sum2=0.0;
	    		count=0;
	    		for(int j=0;j<N;j++){
	    			if(!remove[j]){
	    				if(judge[j]>ave){	    			
	    					remove[j] =true;
	    					hasRemove = true;
	    				}else{
	    					sum2+=judge[j];
	    					count++;
	    				}
	    			}
	    		}
	    		
	    		ave = (sum1+sum2)/count;	    		
	    		
	    	}
	    	
	    	
	    	for(int j=0;j<N;j++){
	    		if(remove[j]){
	    			result[j]=0.0;
	    		}else{
	    			result[j]= (ave-judge[j])/sum1*100;
	    		}
	    	}
	    	results[i]=result;
	    }
	    
	    for(int i=0;i<T;i++){
	    	System.out.format("Case #%d:", (i+1));
	    	int n = results[i].length;
	    	for(int j=0;j<n;j++){
	    		System.out.format(" %f", results[i][j]);
	    	}
	    	System.out.println();
	    }
	}
	
}
