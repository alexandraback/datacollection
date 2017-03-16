import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.StringTokenizer;


public class ProjectA {

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
            
            long[] r = new long[T];
            long[] t = new long[T];
            for(int i = 0; i < T; i++){
            	tempString = reader.readLine();
            	StringTokenizer st = new StringTokenizer(tempString);
            	r[i] = Long.parseLong(st.nextToken());
            	t[i] = Long.parseLong(st.nextToken());
            }
            
            int[] num = process(r, t, T);
            for(int i = 0; i < T; i++){
            	System.out.println("Case #" + (i+1) + ": " + num[i]);
            	writer.write("Case #" + (i+1) + ": " + num[i]);
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

	private static int[] process(long[] r, long[] t, int T) {
		int[] num = new int[T];
		for(int i = 0; i < T; i++){
			num[i] = (int) Math.floor(0.25*(-3-2*r[i]+Math.sqrt(1-4*r[i]+4*r[i]*r[i]+8*t[i])))+1;
		}
		return num;
	}
}
