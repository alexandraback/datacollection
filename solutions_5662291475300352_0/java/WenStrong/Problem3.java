import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Scanner;


public class Problem3 {
	
	public static class Hiker {
		int start;
		int num;
		int time;
	}
	public static void main(String[] args) {
		try {
			Scanner scanner = new Scanner(new FileReader("C-small-1-attempt0.in"));
	        int T = scanner.nextInt();
	        ArrayList<ArrayList<Hiker>> data = new ArrayList<ArrayList<Hiker>>(); 
	        int[] Ds = new int[T];
	        for(int i=0; i<T; i++) {
	        	Ds[i] = scanner.nextInt(); 
	        	ArrayList<Hiker> list = new ArrayList<Hiker>();
	        	for(int j=0; j<Ds[i]; j++) {
	        		Hiker h = new Hiker();
		        	h.start = scanner.nextInt();
		        	h.num = scanner.nextInt();
		        	h.time = scanner.nextInt();
		        	list.add(h);
	        	}   
	        	data.add(list);
	        }
	        PrintWriter out = new PrintWriter(new FileWriter("output3.txt"));  
	        for(int i=0; i<T; i++) {
	        	ArrayList<Hiker> list = new ArrayList<Hiker>();
	        	list = data.get(i);
	        	int D = Ds[i];
	        	if(list.size() <= 1) {
	        		out.println("Case #" + (i + 1) + ": " + 0);
	        	} else {
	        		Hiker h1 = list.get(0);
	        		Hiker h2 = list.get(1);
	        		double t1 = (360.0-h1.start)/360.0*(double)h1.time;
	        		double t2 = (360.0-h2.start)/360.0*(double)h2.time;
	        		if(t1 >= t2 + h2.time || t2 >= t1 + h1.time) {
	        			out.println("Case #" + (i + 1) + ": " + 1);
	        		} else {
	        			out.println("Case #" + (i + 1) + ": " + 0);
	        		}
	        	}        	
	        } 
	        out.close();	       
		} catch(Exception e) {
			e.printStackTrace();
		}
	}
}
