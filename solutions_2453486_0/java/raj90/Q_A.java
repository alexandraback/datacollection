/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package codejam;

/**
 *
 * @author user
 */
import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.io.StreamTokenizer;
import java.util.Arrays;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Set;
public class Q_A {
     public static void main(String[] args) throws FileNotFoundException, IOException {
        //StreamTokenizer in=new StreamTokenizer(new FileReader("test.txt"));
        BufferedReader br=new BufferedReader(new FileReader("Q_A.txt"));
        PrintWriter out=new PrintWriter(new FileWriter("Q_A_ans.txt"));
        String s[];int i,j,k,l,m=0,n=0,t;boolean ex=false,com=false;
        t=Integer.parseInt(br.readLine());
        for(i=0;i<t;i++){
            ex=false;com=false;
            s=new String[4];
            for(j=0;j<4;j++){
                s[j]=br.readLine();
            }
            br.readLine();
            for(j=0;j<4;j++){
                for(k=0;k<4;k++){
                    if(s[j].charAt(k)=='T'){
                        m=j;n=k;
                        System.out.println(m+" "+n);
                        ex=true;
                    }
                    else if(s[j].charAt(k)=='.')
                        com=true;
                }
            }
            boolean t1=false;
            for(j=0;j<4;j++){
                
                  if(s[j].charAt(0)=='X'&&s[j].charAt(1)=='X'&&s[j].charAt(2)=='X'&&s[j].charAt(3)=='X'){
                      out.println("Case #"+(i+1)+": X won");
                      t1=true;
                      break;
                  }  
                  else if(s[j].charAt(0)=='O'&&s[j].charAt(1)=='O'&&s[j].charAt(2)=='O'&&s[j].charAt(3)=='O'){
                      out.println("Case #"+(i+1)+": O won");
                      t1=true;
                      break;
                      
                  }  
                  else if(s[0].charAt(j)=='X'&&s[1].charAt(j)=='X'&&s[2].charAt(j)=='X'&&s[3].charAt(j)=='X'){
                      out.println("Case #"+(i+1)+": X won");
                      t1=true;
                      break;
                      
                  }  
                  else if(s[0].charAt(j)=='O'&&s[1].charAt(j)=='O'&&s[2].charAt(j)=='O'&&s[3].charAt(j)=='O'){
                      out.println("Case #"+(i+1)+": O won");
                      t1=true;
                      break;
                      
                  }
            
        }
            if(!t1){
                if(s[0].charAt(0)=='X'&&s[1].charAt(1)=='X'&&s[2].charAt(2)=='X'&&s[3].charAt(3)=='X'){
                      out.println("Case #"+(i+1)+": X won");
                      t1=true;
            }
                else if(s[0].charAt(0)=='O'&&s[1].charAt(1)=='O'&&s[2].charAt(2)=='O'&&s[3].charAt(3)=='O'){
                      out.println("Case #"+(i+1)+": O won");
                      t1=true;
            }
                else if(s[0].charAt(3)=='X'&&s[1].charAt(2)=='X'&&s[2].charAt(1)=='X'&&s[3].charAt(0)=='X'){
                      out.println("Case #"+(i+1)+": X won");
                      t1=true;
            }
                else if(s[0].charAt(3)=='O'&&s[1].charAt(2)=='O'&&s[2].charAt(1)=='O'&&s[3].charAt(0)=='O'){
                      out.println("Case #"+(i+1)+": O won");
                      t1=true;
            }
            }
            boolean xc=false,oc=false;int sumx=0,sumo=0;
            if(ex==true&&!t1){
               for(j=0;j<4;j++)
               {
                   if(j!=n){
                       if(s[m].charAt(j)=='X')
                           sumx++;
                       else if(s[m].charAt(j)=='O')
                           sumo++;
               }
            }
               if(sumx==3){
                   out.println("Case #"+(i+1)+": X won");
                   sumx=0;
                   t1=true;
               }
               else if(sumo==3){
                   out.println("Case #"+(i+1)+": O won");
                   sumo=0;
                   t1=true;
               }
            
    }
            sumx=0;sumo=0;
            if(ex==true&&!t1){
               for(j=0;j<4;j++)
               {
                   if(j!=m){
                       if(s[j].charAt(n)=='X')
                           sumx++;
                       else if(s[j].charAt(n)=='O')
                           sumo++;
               }
            }
               if(sumx==3){
                   out.println("Case #"+(i+1)+": X won");
                   System.out.println("n = "+n);
                   sumx=0;
                   t1=true;
               }
               else if(sumo==3){
                   out.println("Case #"+(i+1)+": O won");
                   sumo=0;
                   t1=true;
               }
            
    }
            sumx=0;sumo=0;
            if(!t1&&ex&&m==n){
                for(j=0;j<4;j++)
               {
                   if(j!=m){
                       if(s[j].charAt(j)=='X')
                           sumx++;
                       else if(s[j].charAt(j)=='O')
                           sumo++;
               }
            }
               if(sumx==3){
                   out.println("Case #"+(i+1)+": X won");
                   sumx=0;
                   t1=true;
               }
               else if(sumo==3){
                   out.println("Case #"+(i+1)+": O won");
                   sumo=0;
                   t1=true;
               }
            }
            sumx=0;sumo=0;
            if(!t1&&ex&&(m==3-n)){
                for(j=0;j<4;j++)
               {
                   if(j!=m){
                       if(s[j].charAt(3-j)=='X')
                           sumx++;
                       else if(s[j].charAt(3-j)=='O')
                           sumo++;
               }
            }
               if(sumx==3){
                   out.println("Case #"+(i+1)+": X won");
                   sumx=0;
                   t1=true;
               }
               else if(sumo==3){
                   out.println("Case #"+(i+1)+": O won");
                   sumo=0;
                   t1=true;
               }
            }
            if(!t1&&com)
                out.println("Case #"+(i+1)+": Game has not completed");
            else if(!t1)
                out.println("Case #"+(i+1)+": Draw");
}
        out.flush();
        out.close();
     }
}