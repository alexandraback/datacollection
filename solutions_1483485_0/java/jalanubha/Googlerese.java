import java.io.*;

public class Googlerese 
{
    public static void main(String[] args) 
    {
        char[] map = {'y','h','e','s','o','c','v','x','d',
        'u','i','g','l','b','k','r','z','t','n','w','j','p',
            'f','m','a','q'};
       char ch;
       BufferedReader br = null;
 
		try {
                        FileWriter fstream = new FileWriter("output.out");
                        BufferedWriter out = new BufferedWriter(fstream);
			String sCurrentLine;
 
			br = new BufferedReader(new FileReader("textfile.in"));
                        sCurrentLine = br.readLine();
                        int i = 1;
                        while ((sCurrentLine = br.readLine()) != null) 
                        {     
                            out.write("Case #" + i++ + ": ");
                            System.out.println(sCurrentLine);
                            for (int j = 0; j < sCurrentLine.length(); j++) {
                                ch = sCurrentLine.charAt(j);
                                out.write((ch!=' ')?map[(int)ch-97]:ch);
                            }
                            out.write("\n");
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
