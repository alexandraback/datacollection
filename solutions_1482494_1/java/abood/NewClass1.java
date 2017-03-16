
import java.io.*;
import java.util.StringTokenizer;

/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */


/**
 *
 * @author abood
 */
public class NewClass1 {
    public static void main(String[] args) throws FileNotFoundException, IOException {
        BufferedReader br = new BufferedReader(new FileReader("B-large (1).in"));
       PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("B-large (1).out")));
       int l=Integer.parseInt(br.readLine());
       L: for (int i = 1; i <=l; i++) {
           int maxs=0;
            int len=Integer.parseInt(br.readLine());
            int f[]=new int [len];
            int s[]=new int [len];
            for (int j = 0; j < len; j++) {
                StringTokenizer st=new StringTokenizer(br.readLine());
                
                f[j]=Integer.parseInt(st.nextToken());
                s[j]=Integer.parseInt(st.nextToken());
                if(maxs<s[j]){maxs=s[j];}
            }
            int count =0,stars=0,xf,xs,fi,si,first=0;;
            
            W: while(stars<len*2){
             xf=xs=fi=si=-1;
                for (int j = 0; j < s.length; j++) {
                if(s[j]==-1)continue;
              if(s[j]<=stars){si=j;break;}
              else if (f[j]!=-1&&f[j]<=stars&&xf<s[j]){xf=s[j];fi=j;}
           }
              if(si>=0){if(f[si]!=-1)stars+=2;else stars+=1;s[si]=-1;count++;
                  //System.out.println("s "+(si+1)+" "+stars);
              }
              else if (fi>=0){stars++;f[fi]=-1;count++;first++;
                  //System.out.println("f "+(fi+1)+" "+stars);
              }
              else if (si==-1&&fi==-1) {break W;}
                if(stars>=maxs){stars=len*2;count=first+len;break W;}
         }
           // System.out.println(stars+" "+count);
            if(stars==len*2)out.println("Case #"+i+": "+count);
            else out.println("Case #"+i+": "+"Too Bad");
            
            
            
        }
       
       out.close();                                  
    System.exit(0);
    }
    
}
