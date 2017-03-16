/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */


import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.StringTokenizer;

/**
 *
 * @author abood
 */
public class Main {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws FileNotFoundException, IOException {
        BufferedReader br = new BufferedReader(new FileReader("A-large.in"));
        PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("A-large.out")));
        int loop=Integer.parseInt(br.readLine());
        String st="";
        int grid[][]=new int [4][4];
        boolean done;
        L: for (int i = 1; i <=loop; i++) {
              done=true;
             
              for (int j = 0; j < 4; j++) {
                  st=br.readLine();
                  for (int k = 0; k < 4; k++) {
                      
                      switch ((st.charAt(k))){
                          case 'X':
                              grid[j][k]=10;
                              break;
                          case 'O':grid[j][k]=3;break;
                          case 'T':grid[j][k]=100;break;
                          case '.':grid[j][k]=0;done =false;break;
                      }
                  }
                
            }
              br.readLine();
              int rowsum[]=new int [4],colsum[]=new int [4],mdiagonal=0,sdiagonal=0;
              for (int j = 0; j < 4; j++) {
                  mdiagonal+=grid[j][j];
                  sdiagonal+=grid[3-j][j];
                  
                  for (int k = 0; k < 4; k++) {
                  rowsum[j]+=grid[j][k];
                  colsum[k]+=grid[j][k];
                      
                  }
                
            }
              if(mdiagonal==12||mdiagonal==109||sdiagonal==12||sdiagonal==109){
                  out.printf("Case #%d: O won\n",i);
                  continue L;
              }
              if(mdiagonal==40||mdiagonal==130||sdiagonal==40||sdiagonal==130){
                  out.printf("Case #%d: X won\n",i);
                   continue L;
              }
              for (int j = 0; j < 4; j++) {
                if(rowsum[j]==12||rowsum[j]==109){
                       out.printf("Case #%d: O won\n",i);
                  continue L;
                }
                if(rowsum[j]==40||rowsum[j]==130){
                       out.printf("Case #%d: X won\n",i);
                  continue L;
                }
                if(colsum[j]==40||colsum[j]==130){
                    out.printf("Case #%d: X won\n",i);
                   continue L;
                }
                if(colsum[j]==12||colsum[j]==109){
                    out.printf("Case #%d: O won\n",i);
                   continue L;
                }
            }
              if(done){
                  out.printf("Case #%d: Draw\n",i);
              }
              else out.printf("Case #%d: Game has not completed\n",i);
        }
   out.close();                             
    System.exit(0);    
    }
}
