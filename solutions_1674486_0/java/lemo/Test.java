import java.io.FileReader;
import java.io.FileWriter;
import java.io.BufferedReader;
import java.io.PrintWriter;
import java.io.IOException;
import java.util.*;
import java.text.DecimalFormat;
import java.text.NumberFormat;




public class Test{
	
    static int[][]nodeArray;
    static int[]nodeNumber;
    
	public static void main(String[] args)
        throws IOException {

        BufferedReader inputStream = null;
        PrintWriter outputStream   = null;
        //test();
        
        try {
            inputStream = 
                new BufferedReader(new FileReader("A-small-attempt0.in"));
                //new BufferedReader(new FileReader("test.in"));
            outputStream = 
                new PrintWriter(new FileWriter("test.out"));

            String l;
            l = inputStream.readLine();
            int t = Integer.parseInt(l);
            int index = 1;
            while ((l = inputStream.readLine()) != null) {
                
                int number = Integer.parseInt(l);
                
                nodeArray = new int[number][number];
                nodeNumber = new int[number];
                
                for(int i=0;i<number;i++){
                    l = inputStream.readLine();
                    String[] argsStr = l.split(" ");
                    int size = Integer.parseInt(argsStr[0]);
                    nodeNumber[i] = size;
                    for(int j=0;j<size;j++){
                        int tmpnumber = Integer.parseInt(argsStr[j+1]);
                        nodeArray[i][tmpnumber-1] = 1;
                    }
                }
                
                
                String returnValue = calculate(number);
                String resultStr = "Case #"+index+": "+returnValue;
                outputStream.println(resultStr);

                System.out.println(resultStr);
                index++;
            }
        } finally {
            if (inputStream != null) {
                inputStream.close();
            }
            if (outputStream != null) {
                outputStream.close();
            }
        }
    }
    
    static java.text.DecimalFormat fd=new java.text.DecimalFormat("0.000000"); 
    
    static void visit(int number,int[]visitTime, int startPoint){
        for(int i=0;i<number;i++){
            if(nodeArray[startPoint][i]==1){
                visitTime[i]++;
                visit(number,visitTime,i);
            }
        }
    }
	static String calculate(int number){
        
        int i,j,k;
        
        for(i=0;i<number;i++){
            int[]visitTime = new int[number];
            
            visit(number,visitTime,i);
            
            for(j=0;j<number;j++){
                if(visitTime[j]>1){
                    return "Yes";
                }
            }
        }
        
        
       
        int count = 0;
        
       
        return "No";
    }
}