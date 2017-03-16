/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package codejam;

import java.io.BufferedReader;
import java.io.DataInputStream;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

/**
 *
 * @author hp
 */
public class tacTicToe {
    public static void main(String[] args) throws FileNotFoundException, IOException {
        FileInputStream fstream = new FileInputStream("E:/Users/hp/Documents/NetBeansProjects/codejam/src/codejam/A-large.in");
        DataInputStream in = new DataInputStream(fstream);
        BufferedReader br = new BufferedReader(new InputStreamReader(in));
        int cases = Integer.parseInt(br.readLine());
        for(int i=1;i<=cases;i++){
            int[][] comb = new int [4][4];
            for(int j=0;j<4;j++){
                String a = br.readLine();
                for(int k=0;k<4;k++){
                    char b = a.charAt(k);
                    if(b=='X') comb[j][k]=10;
                    else if(b=='O') comb[j][k] = 1;
                    else if(b=='T') comb[j][k] = 11;
                    else if(b=='.')comb[j][k] = 0;
                }
            }
            int sum=0;
            for(int j=0;j<4;j++){
                if(sum/10==4||sum%10==4)break;
                sum=0;
                for(int k=0;k<4;k++){
                    sum+=comb[j][k];
                }
            }
            for(int j=0;j<4;j++){
                if(sum/10==4||sum%10==4)break;
                sum=0;
                for(int k=0;k<4;k++){
                    sum+=comb[k][j];
                }
            }
            if(sum/10!=4&&sum%10!=4){
                sum=0;
                sum = comb[0][0]+comb[1][1]+comb[2][2]+comb[3][3];
            }
            if(sum/10!=4&&sum%10!=4){
                sum=0;
                sum = comb[0][3]+comb[1][2]+comb[2][1]+comb[3][0];
            }
            System.out.print("Case #"+i+": ");
            if(sum/10==4) System.out.print("X won");
            else if(sum%10==4) System.out.print("O won");
            else{
                int j;
               for(j=0;j<4;j++){
                   int k;
                for(k=0;k<4;k++){
                    if(comb[j][k]==0) break;
                }
                if(k<4) break;
                }
               if(j<4) System.out.print("Game has not completed");
               else System.out.print("Draw");
            }
            System.out.print('\n');
            br.readLine();
        }
    }
}
