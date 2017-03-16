
/**
 * Name: Shivam99
 * email: shivthedestroyer99@gmail.com
 */

import java.io.*;

public class ProblemC
{
    public static void main(String[] args) throws IOException{
        FileReader fr=new FileReader(args[0]);
        BufferedReader br=new BufferedReader(fr);
        String str=br.readLine();
        int t=Integer.parseInt(str);
        String ss="";
        int c=1;
        while(c<=t){
            str=br.readLine();
            int pos=str.indexOf(' ');
            String f=str.substring(0,pos);
            String s=str.substring(++pos,str.length());
            int a=Integer.parseInt(f);
            int b=Integer.parseInt(s);
            int ans=0;
            ss+="Case #"+c+": ";
            
            if(a!=b && f.length()>1){
              for(int ind=a;ind<b;ind++){
                int arr[]={0,0,0,0,0,0,0,0};
                String copy=""+ind;
                int count=1;
                while(count<copy.length()){
                  String next=copy.charAt(copy.length()-1)+copy.substring(0,copy.length()-1);
                  copy=next;
                  int num=Integer.parseInt(next);
                  if(num>ind && num<=b){
                      arr[count]=num;
                      boolean chk=true;
                      for(int j=1;j<=count;j++){
                        if(arr[j-1]==num)
                            chk=false;
                      }
                      if(chk)
                         ans++;
                  }
                  count++;
                }
              }
            }
           ss+=ans+"\n";
           c++;
        }
       System.out.print(ss);
       br.close();
       fr.close();
    }
}
