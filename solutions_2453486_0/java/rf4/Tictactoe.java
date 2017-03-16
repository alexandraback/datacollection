/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package tictactoe;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

/**
 *
 * @author Rizal ZAF
 */
public class Tictactoe {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws IOException {
        
        BufferedReader br = null;        
                    
        br = new BufferedReader(new FileReader("A-small-attempt0.in"));
        FileWriter writer = new FileWriter("ttt.out.txt");
        
        int num = Integer.parseInt(br.readLine().trim());
        
        for (int i=0;i<num;i++){
            char[][] tt = new char[4][4];
            for(int j=0;j<4;j++){
                tt[j] = br.readLine().toCharArray();
            }    
            
            char ch = check(tt);
            if (ch == 'X'){
                writer.write("Case #" + (i+1) + ": X won\r\n");
            }
            else if (ch == 'O'){
                writer.write("Case #" + (i+1) + ": O won\r\n");
            }
            else {
                boolean finish = isfinish(tt);
                if (finish){
                    writer.write("Case #" + (i+1) + ": Draw\r\n");
                }
                else {
                    writer.write("Case #" + (i+1) + ": Game has not completed\r\n");
                }
            }
            
            br.readLine();
        }
        
        writer.close();
    }
    
    public static boolean isfinish(char[][] inp){
        boolean result = true;
        
        for (int i=0;i<4;i++){
            int n = countVerticalNoT(inp, '.', i);
            if (n > 0){
                result = false;
                break;
            }
        }
        
        return result;
    }
    
    public static char check(char[][] inp){
        char ch = '-';
        
        for (int i=0;i<4;i++){
            int n = countVertical(inp, 'X', i);
            if (n == 4) {
                ch = 'X';
                break;
            }
            else {
                n = countVertical(inp, 'O', i);
                if (n == 4) {
                    ch = 'O';
                    break;
                }
            }
        }
        
        if (ch == '-'){
            for (int i=0;i<4;i++){
                int n = countHorizontal(inp, 'X', i);
                if (n == 4) {
                    ch = 'X';
                    break;
                }
                else {
                    n = countHorizontal(inp, 'O', i);
                    if (n == 4) {
                        ch = 'O';
                        break;
                    }
                }
            }
        }
        
        if (ch == '-'){
            int n = countDiagonal(inp, 'X');
            if (n == 4) {
                ch = 'X';                
            }
            else {
                n = countDiagonal(inp, 'O');
                if (n == 4) {
                    ch = 'O';                    
                }
            }
        }
        
        if (ch == '-'){
            int n = countDiagonal2(inp, 'X');
            if (n == 4) {
                ch = 'X';                
            }
            else {
                n = countDiagonal2(inp, 'O');
                if (n == 4) {
                    ch = 'O';                    
                }
            }
        }
        
        return ch;
    }
    
    public static int countVertical(char[][] inp, char ch, int idx){
        int num =0;        
        for (int i=0;i<4;i++){
            if (inp[i][idx] == ch || inp[i][idx] == 'T') num++;
        }
        return num;
    }
    
     public static int countVerticalNoT(char[][] inp, char ch, int idx){
        int num =0;        
        for (int i=0;i<4;i++){
            if (inp[i][idx] == ch ) num++;
        }
        return num;
    }
    
    public static int countHorizontal(char[][] inp, char ch, int idx){
        int num =0;        
        for (int j=0;j<4;j++){
            if (inp[idx][j] == ch || inp[idx][j] == 'T') num++;
        }
        return num;
    }
    
    public static int countDiagonal(char[][] inp, char ch){
        int num =0;        
        for (int i=0;i<4;i++){
            if (inp[i][i] == ch || inp[i][i] == 'T') num++;
        }
        return num;
    }
    
    public static int countDiagonal2(char[][] inp, char ch){
        int num =0;        
        for (int i=0;i<4;i++){
            if (inp[i][3-i] == ch || inp[i][3-i] == 'T') num++;
        }
        return num;
    }
}
