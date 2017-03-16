import java.io.*;
import java.util.*;
import java.math.*;
/** @author Samuel Ahn */

public class A {
    public static void main(String args[]) throws Exception {
	Scanner in = new Scanner(System.in);
	int T = in.nextInt();
	for (int i = 1; i <= T; i++) {
	    float N = in.nextFloat();
	    float[] array = new float[(int)N];
	    float sum = 0f;
	    for (int j = 0; j < N; j++) {
		array[j] = in.nextFloat();
		sum += array[j];
	    }
	    float temp1 = 2f*sum;
	     temp1 = temp1 / N;
	    float x = N;
	    float sum1 = 0f;
	    for (int j = 0; j < N; j++) {
		if (array[j] > temp1) {
		    array[j] = -1;
		    x--;
		} else {
		    sum1 += array[j];
		}
	    }
		float temp = sum + sum1;
	    temp = temp / x;
		    
	    System.out.printf("Case #%d:", i);
	    for (int j = 0; j < N; j++) {
		if (array[j] == -1) {
		    System.out.printf(" %f", 0f);
		} else {
		    System.out.printf(" %f", (temp - array[j])*(100)/sum);
		}
	    } 
	    //System.out.printf("Case #%d: %0.6f\n", i, sum);
	    System.out.println();
	}
    }
}
