/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package googlecodejam;
import java.io.*;
import java.util.*;
import java.util.logging.Level;
import java.util.logging.Logger;
import java.lang.Math;
/**
 *
 * @author akhilesh.m
 */
public class NewLotteryGame 
{
    int A;
    int B;
    int K;
    
    int GetAnswer()
    {
        int num = 0;
        for(int i = 0; i < A; i++)
        {
            for(int j = 0; j < B; j++)
            {
                if((i&j) < K)
                {
                    num++;
                }
            }
        }
        return num;
    }
    public void Solve() throws FileNotFoundException
    {
        File Inputfil = new File("Input.txt");
        Scanner scanner = new Scanner(Inputfil);        
        
        File Outputfile = new File("Output.txt");

        // if Ouput file doesnt exists, then create it
        if (!Outputfile.exists()) 
        {
            try 
            {
                Outputfile.createNewFile();
            } 
            catch (IOException ex)
            {
                Logger.getLogger(NewLotteryGame.class.getName()).log(Level.SEVERE, null, ex);
            }
        }
        
        //File writer to write to a file
        FileWriter fw = null;
        try 
        {
            fw = new FileWriter(Outputfile);
        } 
        catch (IOException ex) 
        {
            Logger.getLogger(NewLotteryGame.class.getName()).log(Level.SEVERE, null, ex);
        }
        
        
	BufferedWriter bw = new BufferedWriter(fw);
        
        
        int numTestCases = 0;
        if(scanner.hasNextInt())
        {
            numTestCases = scanner.nextInt();
        }
        int CaseItr = 0;
        while(CaseItr < numTestCases)
        {
            //Insert from input file here
            
            A = scanner.nextInt();
            B = scanner.nextInt();
            K = scanner.nextInt();
            //Algorithm space
            
            
            
            int num = GetAnswer();
            
            
            //Algorithm ends here
            
            String answer = new String();
            answer += "Case #";
            answer += Integer.toString(CaseItr + 1);
            answer += ": ";
            //Write relevant answer here
            answer += Integer.toString(num);
            //Printing answer to a file
            answer += "\n";
            try 
            {
                bw.write(answer);
                System.out.println(answer);
            } 
            catch (IOException ex) 
            {
                Logger.getLogger(NewLotteryGame.class.getName()).log(Level.SEVERE, null, ex);
               // bw.close();
            }
            CaseItr++;
        }
        try 
        {
            bw.close();
        } 
        catch (IOException ex) 
        {
            Logger.getLogger(NewLotteryGame.class.getName()).log(Level.SEVERE, null, ex);
        }
    }
    
   
    public static void main(String[] args) 
    {
        // TODO code application logic here
        NewLotteryGame solver = new NewLotteryGame();
        
        try 
        {
            solver.Solve();
        } 
        catch (FileNotFoundException ex) 
        {
            Logger.getLogger(NewLotteryGame.class.getName()).log(Level.SEVERE, null, ex);
        }
    }
}
