
/**
 * Name: Shivam99
 * email: shivthedestroyer99@gmail.com
 */

import java.io.*;

public class ProblemB
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
            int n=0,s=0,p=0,surp=0,count=0,ans=0;
            int arr[]=new int[100];
            String word="";
            
            for(int ind=0;ind<str.length();ind++){
                char ch=str.charAt(ind);
                if(ch!=' ')
                    word+=ch;
                else{
                    count++;
                    int num=Integer.parseInt(word);
                    if(count==1){
                        n=num;
                        arr=new int[n];
                    }
                        else
                        if(count==2)
                            s=num;
                            else
                            if(count==3)
                                p=num;
                                else
                                arr[count-4]=num;
                    word="";              
                }
            }
            
            arr[count-3]=Integer.parseInt(word);
            int min=p+p+p-4;
            ss+="Case #"+c+": ";

            for(int ind=0;ind<arr.length;ind++){
                if(arr[ind]>=p && arr[ind]>=min)
                    ans++;
                if(arr[ind]==(min) || arr[ind]==(min+1))
                  if(arr[ind]>1)
                    surp++;
            }

           if(s<surp)
               ans=ans+s-surp;
           ss+=ans+"\n";
           c++;
        }
       System.out.print(ss);
       br.close();
       fr.close();
    }
}