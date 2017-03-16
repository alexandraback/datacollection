import java.util.*;
import java.io.*;

public class A {
	
	static int[] arr;
	static int n;
	static int min;

    public static void main(String[] args) throws Exception {
    	Scanner s = new Scanner(new FileReader("a.in"));
    	//Scanner s = new Scanner(System.in);
    	PrintWriter printer = new PrintWriter(new FileWriter("a.out"));
    	int t = s.nextInt();
    	for(int i=0; i<t; i++) {
    		int a = s.nextInt();
    		n = s.nextInt();
    		printer.print("Case #" + (i+1) +": ");
    		arr = new int[n];
    		for(int j=0; j<n; j++)
    			arr[j] = s.nextInt();
    		Arrays.sort(arr);
    		min = -1;
    		backtrack(a, 0, 0, n);
    		printer.println(min);
    	}
    	printer.close();
    }
    
    public static void backtrack(int a, int index, int num, int size) {
    	if(index >= size) {
    		if(min == -1)
    			min = num;
    		else
    			min = Math.min(min, num);
    	}
    	else if(min == 0)
    		return;
    	else {
    		if(a > arr[index]) {
				//System.out.println("can eat " + arr[index] + " = " + (a+arr[index]) + " " + (index+1) + " " + (size-1));    			
    			backtrack(a+arr[index], index+1, num, size);
    		}
    		else {
    			//System.out.println("remove last element. now size = " + (size-1));
    			backtrack(a, index, num+1, size-1);
    			if(a != 1) {
					//System.out.println("added value to a: " + (a+a-1));    				
	    			backtrack(a+a-1, index, num+1, size);
    			}
    		}
    	}
    }
}
