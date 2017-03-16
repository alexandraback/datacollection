import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.StringTokenizer;


public class ProjectB {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		File file = new File(args[0]);
        File ofile = new File(args[0] + ".out");
        
        BufferedReader reader = null;
        BufferedWriter writer = null;
        try {
            reader = new BufferedReader(new FileReader(file));
            writer = new BufferedWriter(new FileWriter(ofile));
            
            String tempString = reader.readLine();
            int T = Integer.parseInt(tempString);
            
            StringTokenizer st;
            for(int i = 0; i < T; i++){
            	tempString = reader.readLine();
            	st = new StringTokenizer(tempString);
            	long E = Long.parseLong(st.nextToken());
            	long R = Long.parseLong(st.nextToken());
            	int N = Integer.parseInt(st.nextToken());
            	long[] v = new long[N];
            	tempString = reader.readLine();
            	st = new StringTokenizer(tempString);
            	for(int j = 0; j < N; j++){
            		v[j] = Long.parseLong(st.nextToken());
            	}
            	
            	System.out.println(E);
            	System.out.println(R);
            	System.out.println(N);
            	for (int j = 0; j < N; j++) {
            		System.out.print(v[j]);
            		System.out.println();
				}
            	
            	long num = process(E, R, N, v);
            	
            	System.out.println("Case #" + (i+1) + ": " + num);
            	writer.write("Case #" + (i+1) + ": " + num);
            	writer.newLine();
            }           
            reader.close();
            writer.flush();
            writer.close();
        } catch (IOException e) {
            e.printStackTrace();
        } finally {
            if (reader != null) {
                try {
                    reader.close();
                } catch (IOException e1) {
                }
            }
        }
	}

	private static long process(long e, long r, int n, long[] v) {
		// TODO Auto-generated method stub
		long maxv = v[0];
		for (int i = 1; i < n; i++) {
			if (v[i] > maxv)
				maxv = v[i];
		}
		long total = 0;
		for (int i = 0; i < n; i++) {
			total += v[i];	
		}
		return total * r + (e - r) * maxv;
	}


}
