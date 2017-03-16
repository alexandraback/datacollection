/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package googlejam;

import java.io.*;
import java.util.Arrays;

/**
 *
 * @author a.bogdanov
 */
public class GoogleJam_DeceitfulWar {
    public static final String problemLetter = "D";
    
    public static void solve(BufferedReader reader, PrintWriter writer) throws IOException{
/*        for(int i=1;i<1500;i++){
        	writer.print(1./i + " ");
        }
        writer.println("");
        for(int i=1;i<1500;i++){
        	writer.print(i*1./1500 + " ");
        }
        writer.println("");
        */
    	int caseCount = Integer.parseInt(reader.readLine());
        for(int caseNum=1; caseNum<=caseCount; caseNum++){
        	int N = Integer.parseInt(reader.readLine());
            double n[] = new double[N];
            double k[] = new double[N];
            String[] str = reader.readLine().split(" ");
            for(int i=0;i<N;i++){
            	n[i] = Double.parseDouble(str[i]);
            }
            str = reader.readLine().split(" ");
            for(int i=0;i<N;i++){
            	k[i] = Double.parseDouble(str[i]);
            }
            Arrays.sort(n);
            Arrays.sort(k);
            int nInd = 0;
            int kInd = 0;
            int nWin = 0;
            int kWin = 0;
            while(kInd < N){
            	if(n[nInd] < k[kInd]){
            		nInd++;
            		kInd++;
            		kWin++;
            	} else{
            		kInd++;
            		nWin++;
            	}
            }
            nInd = 0;
            kInd = 0;
            int ndWin = 0;
            int kdWin = 0;
            while(nInd < N){
            	if(n[nInd] < k[kInd]){
            		nInd++;
            		kdWin++;
            	} else{
            		nInd++;
            		kInd++;
            		ndWin++;
            	}
            }
            System.out.println("Case #" + caseNum + ": " + ndWin + " " + nWin);
            writer.println("Case #" + caseNum + ": " + ndWin + " " + nWin);
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
