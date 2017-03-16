import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;


public class Dijkstra {
	
	public static void main(String[] args) {
		try {
			Scanner scanner = new Scanner(new FileReader("C-small-attempt0.in"));
	        int T = Integer.parseInt(scanner.nextLine());
	        int[] Ls = new int[T];
	        long[] Xs = new long[T];
	        String[] strings = new String[T];
	        for(int i=0; i<T; i++) {
	        	String str = scanner.nextLine();
	        	String[] array = str.split(" ");
	        	Ls[i] = Integer.parseInt(array[0]);
	        	Xs[i] = Long.parseLong(array[1]);
 	        	strings[i] = scanner.nextLine();
	        }
	        PrintWriter out = new PrintWriter(new FileWriter("output3.txt"));      
	        int[][] matrix = {
	        	{0, 0, 0, 0, 0},
	        	{0, 1, 2, 3, 4},
	        	{0, 2,-1, 4,-3},
	        	{0, 3,-4,-1, 2},
	        	{0, 4, 3,-2,-1}
	        };
	        
	        for(int i=0; i<T; i++) {   	
	        	boolean can = true;
	        	int L = Ls[i];
	        	long X = Xs[i];
	        	String str = strings[i];
	        	str = str.replace('i', '2');
	        	str = str.replace('j', '3');
	        	str = str.replace('k', '4');
	        	String totalStr = "";
	        	for(long j=0; j<X; j++) {
	        		totalStr += str;
	        	}
	        	int result = totalStr.charAt(0)-'0';
	        	int len = totalStr.length();
	        	int index = 1;
	        	while(result != 2 && index < len) {
	        		int sign = result > 0 ? 1 : -1;
	        		int value = Math.abs(result);
	        		int next = totalStr.charAt(index) - '0';
	        		result = sign * matrix[value][next];
	        		index++;
	        	}
	        	result = 1;
	        	while(result != 3 && index < len) {	        		
	        		int sign = result > 0 ? 1 : -1;
	        		int value = Math.abs(result);
	        		int next = totalStr.charAt(index) - '0';
	        		result = sign * matrix[value][next];
	        		index++;
	        	}
	        	result = 1;
	        	while(index < len) {
	        		int sign = result > 0 ? 1 : -1;
	        		int value = Math.abs(result);
	        		int next = totalStr.charAt(index) - '0';
	        		result = sign * matrix[value][next];
	        		index++;
	        	}
	        	if(result == 4) {
	        		out.println("Case #" + (i+1) + ": YES");
	        	} else {
	        		out.println("Case #" + (i+1) + ": NO");
	        	}	        	
	        }
	        out.close();
	       
		} catch(Exception e) {
			e.printStackTrace();
		}
	}
}
