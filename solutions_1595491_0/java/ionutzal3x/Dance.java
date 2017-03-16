/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package dance;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.ArrayList;

/**
 *
 * @author ALEX
 */
public class Dance {

   public ArrayList<Scores> al;
    public Dance()
    {
        al=new ArrayList<Scores>();
    }
    /**
     * @param args the command line arguments
     */
   public void readFile()
   {
       try {
             FileReader fin=new FileReader("B-small-attempt0.in");
             BufferedReader in = new BufferedReader(fin);
             FileWriter fout=new FileWriter("result.txt");
             BufferedWriter out=new BufferedWriter(fout);
             int nrt;
             nrt=Integer.valueOf(in.readLine());
             String [] med;
             for(int i=1;i<=nrt;i++)
             {
                 String str=in.readLine();
                 med=str.split(" ");
                 int nrs = Integer.valueOf(med[0]);
                 int su = Integer.valueOf(med[1]);
                 int pe = Integer.valueOf(med[2]);
                 for(int j=1;j<=nrs;j++){
                     Scores ob=new Scores(Integer.valueOf(med[j+2]));
                     al.add(ob);
                 }
                 out.write("Case #"+i+": "+workFun(su,pe));  
                 out.newLine();
                 al.clear();
             }
             in.close();
             fin.close();
             out.close();
             fout.close();
             }
        catch(Exception e){} 
   }
   public int workFun(int sup,int pes)
   {
       int nr=0;
       int sp=0;
       for(int i=0;i<al.size();i++){
           if(al.get(i).getMaxS()>=pes && sp<sup && al.get(i).getMaxUnS()<pes){
               nr++;
               sp++;
           }
           else{
               if(al.get(i).getMaxUnS()>=pes){
                   nr++;
               }
           }               
       }
       return nr;
   }
    public static void main(String[] args) {
        // TODO code application logic here
        Dance d=new Dance();
        d.readFile();
        /*System.out.println(d.isSurprize(23,8,0));
        System.out.println(d.isSurprize(22,8,0));
        System.out.println(d.isSurprize(21,8,0));
        System.out.println(d.nr);
        System.out.println(d.b);*/
    }
}
