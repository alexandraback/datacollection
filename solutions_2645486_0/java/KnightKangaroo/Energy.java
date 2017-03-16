import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class Energy {
    static Scanner input;
    static BufferedWriter output;

    public static void main(String[] args) throws IOException {
        input = new Scanner(new File(args[0]));
        output = new BufferedWriter(new FileWriter("energy.out"));

        int numCase = input.nextInt();

        for (int i = 0; i < numCase; i++) {
            int E = input.nextInt();
            int R = input.nextInt();
            int N = input.nextInt();
            int[] v = new int[N];
            
            for (int j = 0; j < N; j++)
            	v[j] = input.nextInt();
            
            long sum = 0;
            int EE = E;
            
            if  (N == 1) {
            	for (int j = 0; j <= EE; j++) {
    				long temp = j * v[0];
    				
    				if (temp > sum)
                		sum = temp;
    			}
            }
            else {
	            for (int j = 0; j <= EE; j++) {
	            	long temp = j * v[0] + computeEnergy(EE - j + R, E, R, v, 1, N);
	            	
	            	if (temp > sum)
	            		sum = temp;
	            }
	        }
            
            output.write("Case #" + (i + 1) + ": " + sum +"\n");
        }
        
        output.close();
    }

	private static long computeEnergy(int EE, int E, int R, int[] v, int i, int N) {
		long sum = 0;
		//System.out.println(i + " " + N);
		if (EE > E)
			EE = E;
		
		if (i == N - 1) {
			for (int j = 0; j <= EE; j++) {
				long temp = j * v[i];
				
				if (temp > sum)
            		sum = temp;
			}
		} else {
			for (int j = 0; j <= EE; j++) {
            	long temp = j * v[i] + computeEnergy(EE - j + R, E, R, v, i+1, N);
            	
            	if (temp > sum)
            		sum = temp;
            }
		}
		
		return sum;
	}
    
    
}