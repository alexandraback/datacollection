/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package javaapplication17;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
/**
 *
 * @author sunil
 */
public class JavaApplication17 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws FileNotFoundException, IOException {
        // TODO code application logic here
         String readLine="";
        BufferedReader br = new BufferedReader(new FileReader("//home//sunil//Desktop//CODEJAM//round1//B-small-attempt0.in"));
        int no_test= Integer.parseInt(br.readLine());
        
         FileWriter output = null;

        output = new FileWriter("//home//sunil//Desktop//CODEJAM//round1//B-small-attempt0.out");
        BufferedWriter writer = new BufferedWriter(output);
        
        for(int i=0;i<no_test;i++)
        {
            String str = br.readLine();            
            int max_energy= Integer.parseInt(str.split(" ")[0]);
            int regain= Integer.parseInt(str.split(" ")[1]);
            int no_act= Integer.parseInt(str.split(" ")[2]);
            int[] values = new int[no_act];
            str= br.readLine();
            String [] arr_str = str.split(" ");
            for(int j=0;j<no_act;j++)
            {
                values[j]= Integer.parseInt(arr_str[j]);
            }
            int[] energy_1 = new int[max_energy+1];
            for(int j=1;j<=max_energy;j++)
            {
                energy_1[j]= (j)*values[no_act-1];
            }
            for(int j=no_act-2;j>=0;j--)
            {
                int[] energy_2 = new int[max_energy+1];
                for(int k=1;k<=max_energy;k++)
                {
                    energy_2[k]= (k)*values[j];
                }
                int[] energy_3 = new int[max_energy+1];
                
                for(int k=0;k<=max_energy;k++)
                {
                    int enrgy = k+regain>max_energy? max_energy:k+regain;
                    int max_point = 0;
                    for(int l=0;l<=enrgy;l++)
                    {
                        int enrgy1 = enrgy-l+regain>max_energy?max_energy:enrgy-l+regain;
                        if(energy_2[l]+energy_1[enrgy1]>max_point)
                            max_point=energy_2[l]+energy_1[enrgy1];
                    }
                    energy_3[enrgy]= max_point;
                }
                energy_1=java.util.Arrays.copyOf(energy_3, max_energy+1);                
            }
            int max_value =0;
            for(int j=0;j<=max_energy;j++)
            {
                
                if(max_value<energy_1[j])
                    max_value=energy_1[j];
            }
            writer.write("Case #"+(i+1)+": "+max_value);
            writer.write("\n");
            writer.flush();
                
        }
       
    }
}
