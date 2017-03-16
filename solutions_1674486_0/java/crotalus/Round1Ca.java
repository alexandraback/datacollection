/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package round1ca;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.ArrayList;

/**
 *
 * @author Stefanos
 */
public class Round1Ca {

    /**
     * @param args the command line arguments
     * 
     */
    
    
    private static ArrayList<Integer> nodes[];
    private static ArrayList<Integer> path = new ArrayList<Integer>();
        
    public static void main(String[] args) {
        
        String input;
        String output = "", res;
        int i = 0;
        int cases, numClasses, temp;


        try {
            FileReader fr = new FileReader(new File("A-small-attempt0.in"));
            BufferedReader br = new BufferedReader(fr);

            FileWriter fstream = new FileWriter("A-small-attempt0.out");
            BufferedWriter out = new BufferedWriter(fstream);

            cases = Integer.parseInt(br.readLine());
            i = 0;

            while (i < cases) {
                
                numClasses = Integer.parseInt(br.readLine());
                nodes = new ArrayList[numClasses];
                output += "Case #" + (++i) + ": ";
                res="No";
                
                for (int j=0; j<numClasses; j++) {
                    nodes[j]=new ArrayList<Integer>();
                    input = br.readLine();
                    String[] split = input.split(" ");
                    
                    for(int k=0; k<Integer.parseInt(split[0]); k++) {
                        nodes[j].add(Integer.parseInt(split[k+1])-1);                    
                    }
                }
                
                
                for (int j=0; j<numClasses; j++) {
                    
                    if(nodes[j].size()>1) {
                        path.clear();
                        tracePath(j); 
                        
                        for (int m=0; m<path.size()-1; m++) {
                            temp = path.get(m);
                            
                            for(int n=m+1; n<path.size(); n++) {
                                if(temp == path.get(n)) {
                                    res="Yes";
                                    break;
                                }
                            }
                        }

                    }
                }
                
                
                output += res;
                out.write(output);
                output = "\n";
            }

            out.close();
            br.close();

        } catch (Exception e) {
            System.err.println("Error: " + e.getMessage());
        }
    }
    
    
    
    private static void tracePath( int cl) {
        
        for (int k = 0; k < nodes[cl].size(); k++) {
            path.add(nodes[cl].get(k));
            tracePath(nodes[cl].get(k));
        }
        
    }
    
    
}
