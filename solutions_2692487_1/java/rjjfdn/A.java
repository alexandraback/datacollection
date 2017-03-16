import java.util.*;
import java.io.*;

public class A {
	
	static int[] arr;
	static int n;
	static int min;

    public static void main(String[] args) throws Exception {
    	Scanner s = new Scanner(new FileReader("A-large.in"));
    	//Scanner s = new Scanner(System.in);
    	PrintWriter printer = new PrintWriter(new FileWriter("atest.out"));
    	int t = s.nextInt();
    	for(int i=0; i<t; i++) {
    		int a = s.nextInt();
    		n = s.nextInt();
    		arr = new int[n];
    		for(int j=0; j<n; j++)
    			arr[j] = s.nextInt();
    		Arrays.sort(arr);
    		min = -1;
    		backtrack(a, 0, 0, n);
    		printer.println("Case #" + (i+1) +": " + min);
    	}
    	printer.close();
    }
    
    public static void backtrack(int a, int index, int num, int size) {
    	//System.out.println(a + " " + index + " " + num + " " + size);
    	//new Scanner(System.in).nextLine();
    	if(index >= size) {
    		if(min == -1)
    			min = num;
    		else
    			min = Math.min(min, num);
    		//System.out.println("min updated1: " + min);
    	}
    	else if(min == 0)
    		return;
    	else {
    		while(index < arr.length) {
    			if(a <= arr[index])
    				break;
    			a = a+arr[index];
    			index++;
    			if(index == n) {
    				if(min == -1)
    					min = num;
    				else
	    				min = Math.min(min, num);
	    			//System.out.println("min updated: " + min);
	    			break;
    			}
    		}
			if(index != n && a != 1) {
				int count = 0;
				//System.out.print("from " + a);
				int tmp = a;
				while(tmp <= arr[index]) {
					tmp = tmp+tmp-1;
					count++;
				}
				//System.out.println("to " + a);
				//System.out.println("going 2");
				backtrack(tmp, index, num+count, size);
			}
			if(index != n) {
				//System.out.println("going 3");
				backtrack(a, index, num+1, size-1);
			}
    	}
    }
}
