package contests.googleJam;

import java.io.*;
import java.util.StringTokenizer;


public class googleDance 
{
   public static void main(String[] args) 
    {
       int noOfDancers;
       int requiredSpecial;
       int bestScore;
       StringTokenizer st;
       char ch;
       BufferedReader br = null;
 
		try {
                        FileWriter fstream = new FileWriter("output.out");
                        BufferedWriter out = new BufferedWriter(fstream);
			String sCurrentLine;
 
			br = new BufferedReader(new FileReader("B-large.in"));
                        sCurrentLine = br.readLine();//read the no. of test cases
                        int i = 1;
                        while ((sCurrentLine = br.readLine()) != null) 
                        {     
                            out.write("Case #" + i++ + ": ");
                            st = new StringTokenizer(sCurrentLine," ");
                            noOfDancers = Integer.parseInt(st.nextToken());//no. of dancers
                            requiredSpecial = Integer.parseInt(st.nextToken());//no. of special cases
                            bestScore = Integer.parseInt(st.nextToken());//best score required
                            int ans = 0;
                            int special_Max = 0;
                            for (int j = 0; j < noOfDancers; j++) 
                            {
                                int total = Integer.parseInt(st.nextToken());
                                int last2 = total - bestScore;
                                int second = last2/2;
                                if(total > 28 || (last2/2) >= bestScore || total >= (bestScore + 2*(bestScore-2)) + 2)
                                    ans++;
                                else if(total < 2 )
                                {
                                    if(total >= bestScore)
                                        special_Max++;
                                }
                                else if(total >= (bestScore + 2*(bestScore-2)))
                                {
                                    special_Max++;
                                }
                            }
                            if(special_Max <= requiredSpecial)
                                out.write(ans + special_Max + "\n");
                            else
                                out.write(ans + requiredSpecial + "\n");
                        }
                        out.close();
 
		} catch (IOException e) {
			e.printStackTrace();
		} finally {
			try {
				if (br != null)br.close();
			} catch (IOException ex) {
				ex.printStackTrace();
			}
		} 
    }
}
