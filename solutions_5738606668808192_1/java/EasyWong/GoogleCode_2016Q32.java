/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package googlecode;

import java.io.BufferedReader;
import java.io.DataInputStream;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.math.BigInteger;

/**
 *
 * @author ASUS
 */
public class GoogleCode_2016Q32 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {

        try {

            String path = "C:\\Users\\ASUS\\Documents\\NetBeansProjects\\GoogleCode\\";
            FileInputStream fstream = new FileInputStream(path + "input.txt");
            DataInputStream in = new DataInputStream(fstream);
            BufferedReader br = new BufferedReader(new InputStreamReader(in));

            String strLine;
            //Read First Line
            strLine = br.readLine();
            for (int i = 0; i < (Integer.parseInt(strLine)); i++) {
                processLine(i, br.readLine());
            }

            in.close();

        } catch (Exception e) {
            System.err.println("Error: " + e.getMessage());
        }
    }

    public static void processLine(int lineNum, String str) {

        System.out.println("Case #" + (lineNum + 1) + ":");

        Integer N = Integer.parseInt(str.split(" ")[0]);
        Integer J = Integer.parseInt(str.split(" ")[1]);

        Long start = (new Double(Math.pow(2, N-1) + 1)).longValue();

        //loop all possible jamcoins
        for (Long i = start; i <= Math.pow(2, N) - 1; i=i+2) {
         
            int[] remList = {0,0,0,0,0,0,0,0,0,0,0};
            String num = Long.toString(Long.parseLong(i.toString(), 10), 2);
            
            //loop base2 to base 10
            for(int base=2;base<=10;base++) {
                
                BigInteger baseValue = new BigInteger(num, base);
                //System.out.println(i);                   
                //check remainder
                int rem = isPrime(baseValue);
                remList[base] = rem;
                if(rem == -1) break;
                
            }
            
            boolean accept = true;
            String remStr = "";
            for(int base=2;base<=10;base++) {
                remStr += remList[base] + " ";
                if(remList[base] == -1) {
                    accept = false;
                    break;
                }
            }
            if(accept) {
                System.out.println(num + " " + remStr);
                J--;
            }
            if(J==0) break;
        }


    }
    
    public static int isPrime(BigInteger n) {
        // fast even test.
        if(n.getLowestSetBit() != 0) return 2;
        // only odd factors need to be tested up to n^0.5
        for(BigInteger bi = BigInteger.valueOf(3); 
                n.compareTo(bi.multiply(bi)) > 0; 
                bi = bi.add(BigInteger.valueOf(2))) {
            if (bi.compareTo(BigInteger.valueOf(20000)) > 0) {
                return -1;
            }
            if (n.mod(bi).equals(BigInteger.ZERO)) {
                return bi.intValue();
            }
        }
        return -1;
    }   
}
