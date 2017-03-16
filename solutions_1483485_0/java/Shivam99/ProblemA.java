
/**
 * Name: Shivam99
 * email: shivthedestroyer99@gmail.com
 */

import java.io.*;

public class ProblemA
{
    public static void main(String[] args) throws IOException{
        FileReader fr=new FileReader(args[0]);
        BufferedReader br=new BufferedReader(fr);
        String str=br.readLine();
        int t=Integer.parseInt(str);
        String encrypt="ynficwlbkuomxsevzpdrjgthaq";
        String ss="";
        int c=1;
        while(c<=t){
            str=br.readLine();
            ss+="Case #"+c+": ";
           for(int ind=0;ind<str.length();ind++){
             char ch=str.charAt(ind);
             if(ch!=' '){
               for(int i=0;i<26;i++){
                if(encrypt.charAt(i)==ch)
                    ss+=(char)(97+i);
               }
             }
             else
                ss+=ch;
            }
           ss+='\n';
           c++;
        }
       System.out.print(ss);
       br.close();
       fr.close();
    }
}
