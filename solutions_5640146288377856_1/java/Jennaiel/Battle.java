/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package battle;
import java.io.*;
/**
 *
 * @author Ravi
 */
public class Battle {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        try{
            BufferedReader br = new BufferedReader(new FileReader("A-large(1).in"));
            String line = br.readLine();
            int testcases = Integer.parseInt(line);
            BufferedWriter bw = new BufferedWriter(new FileWriter("out.txt"));
            int row,column,width,answer,extra;
            String line_parts[];
            for(int i=0;i<testcases;i++){
                if(i!=0){
                        bw.write("\n");
                    }
                line = br.readLine();
                line_parts = line.split("\\s+");
                row = Integer.parseInt(line_parts[0]);
                column= Integer.parseInt(line_parts[1]);
                width= Integer.parseInt(line_parts[2]);
                if(row==1){
                    
                    answer=column/width+width-1;
                    if (column%width!=0){
                        answer++;
                    }
                    
                }
                else{
                    answer=column/width+width-1;
                    if (column%width!=0){
                        answer++;
                    }
                    extra = column/width;
                    extra *= (row-1);
                    answer+=extra;
                }
                bw.write("Case #"+(i+1)+": "+answer);
                
            }
            br.close();
            bw.close();
            
        }
        catch(Exception e){
            e.printStackTrace();
        }
        
    }
}
