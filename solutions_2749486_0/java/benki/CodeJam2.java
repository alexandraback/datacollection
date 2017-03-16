import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

import javax.swing.text.DefaultEditorKit.CutAction;

public class CodeJam2 {
    
    static double[][] value ;
    
    
    public static void main(String[] args) throws IOException {

        BufferedReader reader = new BufferedReader(new FileReader(new File(
                 "/home/girish/Desktop/coding/codejam/input")));
        BufferedWriter writer = new BufferedWriter(new FileWriter(new File(
                "/home/girish/Desktop/coding/codejam/output")));
        
         int t = Integer.parseInt(reader.readLine());
         for (int i = 1; i <= t; i++) {
             String input  = reader.readLine();
             String[] tokens = input.split(" ");
            // String inStr = tokens[0];
             int X = Integer.parseInt(tokens[0]);
             int Y = Integer.parseInt(tokens[1]);
             String finalAns = getAns(X,Y);
             writer.write("Case #" + i + ": "+finalAns+"\n");
             //System.out.print("Case #" + i + ": ");
             //System.out.println(finalAns);    
         }
         writer.close();
    }

    private static void init(int N) {
        // TODO Auto-generated method stub
        value = new double[100][100];
        for(int i =0;i<value.length;i++){
            for(int j = 0;j<value[i].length;j++){
                value[i][j] = 0;
            }
        }
        
        for(int i =0;i<N;i++){
            
            for(int k =N;k>=0;k--){
                if(value[0][k] == 0){
                    k--;
                }
            }
        }
        
    }
    
    

    private static String getAns(int X, int Y) {
       // System.out.println(A);
       // System.out.println(N);
       // System.out.println(values);
        String tmp;
        if(Y <= 0)
            tmp = getValueY(Y, false);
        else
            tmp = getValueY(Y, true);
        
        String tmp1;
        if(X <=0)
            tmp1 = getValueX(X, false);
        else
            tmp1 = getValueX(X, true);
        
        return tmp+tmp1;
    }

    private static String getValueX(int XX, boolean val) {
        int ABXX = Math.abs(XX);
        if(ABXX == 0)
            return "";
        if(ABXX == 1){
            if(val)
                return "WE";
            else
                return "EW";
        }
        String vStr = "";
        if(val)    
          vStr = "WE";
        else
            vStr = "EW";
        
        for(int y = 2;y<=ABXX;y++){
            if(val)
            vStr = vStr +"WE";
            else
                vStr = vStr + "EW";
        }
        return vStr;
    }

    private static boolean isValid(int x,int y){
        
         if(x >=-100 && x<=100 && y>=-100 && y<=100)
             return true;
         else
             return false;
    }
    
    private static String getValueY(int YY, boolean val) {
        
        int ABYY = Math.abs(YY);
        if(ABYY == 0)
            return "";
        if(ABYY == 1){
            if(val)
                return "SN";
            else
                return "NS";
        }
        
        String vStr = "";
        if(val)    
              vStr = "SN";
        else
              vStr = "NS";
            
        
        for(int y = 2;y<=ABYY;y++){
            if(val)
            vStr = vStr +"SN";
            else
                vStr = vStr + "NS";
        }
        return vStr;
    }
    
}

