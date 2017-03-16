import java.io.*;
import java.util.LinkedList;
import java.util.StringTokenizer;

public class RecycledNumbers 
{
    public static void main(String[] args) 
    {
       StringTokenizer st;
       BufferedReader br = null;
 
		try {
                        FileWriter fstream = new FileWriter("output.out");
                        BufferedWriter out = new BufferedWriter(fstream);
			String sCurrentLine;
 
			br = new BufferedReader(new FileReader("C-small-attempt0.in"));
                        sCurrentLine = br.readLine();//no. of cases
                        int i = 1;
                        while ((sCurrentLine = br.readLine()) != null) 
                        {     
                            out.write("Case #" + i++ + ": ");
                            st = new StringTokenizer(sCurrentLine," ");
                            String n = st.nextToken();
                            int N = Integer.parseInt(n);
                            int m = Integer.parseInt(st.nextToken());
                            int count = 0;
                            for (int j = N; j < m; j++) 
                            {
                                String recycled = Integer.toString(j);
                                LinkedList<String> possible_rotations = new LinkedList<String>();
                                for (int k = 0; k < n.length(); k++)
                                {
                                    recycled = recycled.substring(1)+recycled.charAt(0);
                                    if(!possible_rotations.contains(recycled) && Integer.parseInt(recycled) > j && Integer.parseInt(recycled) <= m)
                                        count++;
                                    possible_rotations.addLast(recycled);
                                }
                            }
                            out.write(count + "\n");
                        }
                        out.close();
 
		} catch (IOException e) {
			e.getMessage();
		} finally {
			try {
				if (br != null)br.close();
			} catch (IOException ex) {
				ex.getMessage();
			}
		} 
    }
}
