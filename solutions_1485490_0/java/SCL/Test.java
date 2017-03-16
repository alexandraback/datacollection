import java.util.*;
import java.io.*;
import java.math.BigDecimal;

public class Test {

	public static void main(String args[]) throws Exception{
		Scanner input = new Scanner(new FileReader("./iothings/C-small-attempt2.in"));
		PrintWriter pw = new PrintWriter(new FileWriter("./iothings/output.txt"));
        int n = input.nextInt();
        for(int i = 0 ; i < n ; i++){
        	int n2 = input.nextInt();
        	int m = input.nextInt();
        	long a[] = new long[n2];
        	int A[] = new int[n2];
        	long b[] = new long[m];
        	int B[] = new int[m];
        	for(int j = 0 ; j < n2 ; j++){
        		a[j] = input.nextLong();
        		A[j] = input.nextInt();
        	}
        	for(int j = 0 ; j < m ; j++){
        		b[j] = input.nextLong();
        		B[j] = input.nextInt();
        	}
            pw.println("Case #"+(i+1)+": "+num(n2,m,a,A,b,B));
        }
		input.close();
		pw.flush();
		pw.close();
	}
	    	
    public static long num(int n2,int m,long[] a,int[] A,long[] b,int[] B){
    	long max = 0;
    	Queue<String> q = new PriorityQueue<String>();
    	q.add(0+","+0+","+0+","+a[0]+","+b[0]);
    	while(!q.isEmpty()){
    		String[] sl = q.poll().split(",");
        	int aindex = Integer.parseInt(sl[0]);
        	int bindex = Integer.parseInt(sl[1]);
        	long sum = Long.parseLong(sl[2]);
        	long rest = Long.parseLong(sl[3]);
        	long restb = Long.parseLong(sl[4]);
    		if(aindex == a.length || bindex == b.length){
    			max = Math.max(max,sum);
    		}else{
    			if(A[aindex] == B[bindex]){
    				if(rest > restb){
    					if(bindex+1 != b.length){
    						q.add(aindex+","+(bindex+1)+","+(sum+restb)+","+(rest-restb)+","+b[bindex+1]);
    					}else{
        					q.add(aindex+","+(bindex+1)+","+(sum+restb)+","+(rest-restb)+","+0);
    					}
    				}else{
    					if(aindex+1 != a.length){
    						q.add((aindex+1)+","+bindex+","+(sum+rest)+","+a[aindex+1]+","+(restb-rest));
    					}else{
    						q.add((aindex+1)+","+bindex+","+(sum+rest)+","+0+","+(restb-rest));
    					}
    				}
    			}else{
    				if(aindex+1 != a.length){
    					q.add((aindex+1)+","+bindex+","+sum+","+a[aindex+1]+","+restb);
    				}else{
    					q.add((aindex+1)+","+bindex+","+sum+","+0+","+restb);
    				}
    				if(bindex+1 != b.length){
    					q.add(aindex+","+(bindex+1)+","+sum+","+rest+","+b[bindex+1]);
    				}else{
    					q.add(aindex+","+(bindex+1)+","+sum+","+rest+","+0);    					
    				}
    			}
    		}
    	}
    	return max;
    	
    }
}