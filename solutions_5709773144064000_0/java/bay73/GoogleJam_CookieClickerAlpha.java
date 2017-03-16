/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package googlejam;

import java.io.*;

/**
 *
 * @author a.bogdanov
 */
public class GoogleJam_CookieClickerAlpha {
    public static final String problemLetter = "B";
    
    public static void solve(BufferedReader reader, PrintWriter writer) throws IOException{
        int caseCount = Integer.parseInt(reader.readLine());
        for(int caseNum=1; caseNum<=caseCount; caseNum++){
            String[] str = reader.readLine().split(" ");
            Double C = Double.parseDouble(str[0]);
            Double F = Double.parseDouble(str[1]);
            Double X = Double.parseDouble(str[2]);
            Double S = Double.parseDouble("2.0");
            Double T0 = Double.parseDouble("0.0");
        	Double TFinish = T0 + X/S;   
            int i = 0;
            while(true){
            	Double dT = C/S;
            	Double newFinish = T0 + dT+ X/(S+F);
            	if(newFinish < TFinish){
            		i++;
            		TFinish = newFinish;
            		S += F;
            		T0 += dT; 
            	}else{
                	break;
            	}
            }
            System.out.println("Case #" + caseNum + ": " + TFinish + "  i="+i);
            writer.println("Case #" + caseNum + ": " + TFinish);
            writer.flush();
        }
    }

    public static void main(String[] args) throws FileNotFoundException, IOException {
        File folder = new File(".");
        for(final File entry:folder.listFiles()){
            if(entry.getName().endsWith(".in") && entry.getName().startsWith(problemLetter)){
                BufferedReader reader = new BufferedReader(new FileReader(entry));
                String fileOut = entry.getName().substring(0, entry.getName().length()-3) + ".out";
                System.out.println(entry.getName() + " -> " + fileOut);
                PrintWriter writer = new PrintWriter(fileOut);
                solve(reader, writer);
                reader.close();
                writer.close();
            }
        }
    }
    
}
