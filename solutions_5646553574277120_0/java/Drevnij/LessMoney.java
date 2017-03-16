import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.HashSet;
import java.util.Set;




public class LessMoney {
	
    public static void main( String[] args ) throws Exception {
	    	BufferedReader in = new BufferedReader(new FileReader("in.txt"));
			BufferedWriter out = new BufferedWriter(new FileWriter("out.txt"));
			String line = in.readLine();
			int t = new Integer(line);
			
			
			for (int caseNum=1; caseNum<=t; caseNum++) {
				line = in.readLine();
				String[] sa = line.split(" ");
				int c = new Integer(sa[0]);
				int d = new Integer(sa[1]);
				int v = new Integer(sa[2]);
				line = in.readLine();
				String[] sa2 = line.split(" ");
				int answer=0;

				int range =0;
				for (int i =0; i<sa2.length; i++) {
					int cur = new Integer(sa2[i]);
					if (range<v && range+1<cur) {
						answer++;
						range*=2;
						range++;
						i--;
					} else {
						range+=cur;
					}
				}
				
				while (range<v) {
					answer++;
					range*=2;
					range++;
				}
				
				out.write("Case #"+caseNum+": "+answer+"\n");

			}
			
			
			in.close();
			out.flush();
			out.close();

		}


}

