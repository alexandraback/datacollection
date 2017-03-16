import java.io.FileReader;
import java.io.FileWriter;
import java.io.BufferedReader;
import java.io.PrintWriter;
import java.io.IOException;
import java.util.*;
import java.text.DecimalFormat;
import java.text.NumberFormat;




public class Test{
	
    static int[]firstArray;
    static long[]firstNumber;
    static int[]secondArray;
    static long[]secondNumber;
    
	public static void main(String[] args)
        throws IOException {

        BufferedReader inputStream = null;
        PrintWriter outputStream   = null;
        //test();
        
        try {
            inputStream = 
                new BufferedReader(new FileReader("C-small-attempt2.in"));
                //new BufferedReader(new FileReader("test.in"));
            outputStream = 
                new PrintWriter(new FileWriter("test.out"));

            String l;
            l = inputStream.readLine();
            int t = Integer.parseInt(l);
            int index = 1;
            while ((l = inputStream.readLine()) != null) {
                String[] argsStr = l.split(" ");
                int boxNum = Integer.parseInt(argsStr[0]);
                int toyNum = Integer.parseInt(argsStr[1]);
                
                firstArray = new int[boxNum];
                firstNumber= new long[boxNum];
                secondArray    = new int[toyNum];
                secondNumber   = new long[toyNum];
    
                l = inputStream.readLine();
                argsStr = l.split(" ");
                for(int i=0;i<boxNum;i++){
                    firstNumber[i] = Long.parseLong(argsStr[i*2]);
                    firstArray[i]  = Integer.parseInt(argsStr[i*2+1]);
                }
                 
                l = inputStream.readLine();
                argsStr = l.split(" ");
                for(int i=0;i<toyNum;i++){
                    secondNumber[i] = Long.parseLong(argsStr[i*2]);
                    secondArray[i]  = Integer.parseInt(argsStr[i*2+1]);
                }
                
                
                String returnValue = calculate(boxNum,toyNum);
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
    static long testSecondResult(int firstNum,int secondNum,int firstIndex,int secondIndex){
        
        secondIndex++;
        testF++;
        while(firstIndex<firstNum&&secondIndex<secondNum){
            if(firstArray[firstIndex]!=secondArray[secondIndex]){
                long f = testFirstResult(firstNum, secondNum, firstIndex, secondIndex);
                long s = testSecondResult(firstNum, secondNum, firstIndex, secondIndex);
                //if(f>s){
                //    return f;
                //}
                //else{
                //    return s;
                //}
                return 0;
            }
            else{
                long currentValue = 0;
                if(firstNumber[firstIndex]>secondNumber[secondIndex]){
                    currentValue = secondNumber[secondIndex];
                }
                else{
                    currentValue = firstNumber[firstIndex];
                }
                return currentValue;
            }
        }
        return 0;
    }
    static long testFirstResult(int firstNum,int secondNum,int firstIndex,int secondIndex){
        
        firstIndex++;
        testF++;
        while(firstIndex<firstNum&&secondIndex<secondNum){
            if(firstArray[firstIndex]!=secondArray[secondIndex]){
                //long f = testFirstResult(firstNum, secondNum, firstIndex, secondIndex);
                //long s = testSecondResult(firstNum, secondNum, firstIndex, secondIndex);
                //if(f>s){
                //    return f;
                //}
                //else{
                //    return s;
                //}
                return 0;
            }
            else{
                long currentValue = 0;
                if(firstNumber[firstIndex]>secondNumber[secondIndex]){
                    currentValue = secondNumber[secondIndex];
                }
                else{
                    currentValue = firstNumber[firstIndex];
                }
                return currentValue;
            }
        }
        return 0;
    }
    static int testF = 0;
    static int testS = 0;
	static String calculate(int firstNum,int secondNum){
        
        int firstIndex = 0;
        int secondIndex = 0;
        
        long bigResult = 0;
        while(firstIndex<firstNum&&secondIndex<secondNum){
            //System.out.println("firstArray[firstIndex]:"+firstArray[firstIndex]);
            //System.out.println("secondArray[secondIndex]:"+secondArray[secondIndex]);
            
            if(firstArray[firstIndex]!=secondArray[secondIndex]){
                if(firstIndex==firstNum-1){
                    secondIndex++;
                    continue;
                }
                if(secondIndex==secondNum-1){
                    firstIndex++;
                    continue;
                }
                testF = 0;
                
                long f = testFirstResult(firstNum, secondNum, firstIndex, secondIndex);
                int tF = testF;
                testF = 0;
                long s = testSecondResult(firstNum, secondNum, firstIndex, secondIndex);
                int tS = testF;
                //System.out.println("f:"+f+"; "+"s:"+s+"testF:"+tF+" testS:"+tS);
                //if(tF==tS){
                    if(f>s){
                        firstIndex++;
                    }
                    else{
                        secondIndex++;
                    }
                //}
                //else if(tF>tS){
                //    secondIndex++;
                //}
                //else{
                //    firstIndex++;
                //}
                /*if(f==s){
                    
                }
                else if(f>s){
                    firstIndex++;
                }
                else{
                    secondIndex++;
                }*/
            }
            else{
                long currentValue = 0;
                if(firstNumber[firstIndex]>secondNumber[secondIndex]){
                    currentValue =  secondNumber[secondIndex];
                    firstNumber[firstIndex] -= currentValue;
                    secondIndex++;
                }
                else{
                    currentValue = firstNumber[firstIndex];
                    secondNumber[secondIndex] -= currentValue;
                    firstIndex++;
                }
                bigResult += currentValue;
            }
            //System.out.println("bigResult:"+bigResult);
        }
        
        return ""+bigResult;
    }
}