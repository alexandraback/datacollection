import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.Stack;


public class PasswordProblem {

    public static void main(String[] args) throws Exception {
        BufferedReader reader = new BufferedReader(new FileReader("C:\\Users\\Owner\\Downloads\\A-large.in"));
        BufferedWriter writer = new BufferedWriter(new FileWriter("C:\\Users\\Owner\\Downloads\\output1.txt"));
        int cases = Integer.parseInt(reader.readLine());
        
        for (int cs = 1; cs <= cases; cs++) {
        	String[] tokens = reader.readLine().split(" ");
        	int a = Integer.parseInt(tokens[0]);
            int b = Integer.parseInt(tokens[1]);
        			
        	tokens = reader.readLine().split(" ");
        	double p = 1.0;
        	double min = 2 + b;

    		double t1 = p * (a + b  + 1);
    		double t2 = (1 - p) * (a + b + 1 + b + 1);
    		double t = t1 + t2;
    		if (t < min) 
    			min = t;

        	for (int i = 1; i <= a; i++) {
        		double pp  = Double.parseDouble(tokens[i - 1]);
        		
        		p *= pp;

        		t1 = p * (a - i + b - i + 1);
        		t2 = (1 - p) * (a - i + b - i + 1 + b + 1);
        		t = t1 + t2;

        		if (t < min) 
        			min = t;
        	}
        	
        	writer.write("Case #" + cs + ": " + min + "\r\n");
        }
        
        writer.close();
    }
}
