
package diamondinheritence;

import java.io.*;

public class DiamondInheritence {

    public static void main(String[] args) throws FileNotFoundException, IOException {
        // TODO code application logic here

        int t=0,n=0,from[][]=null;
        boolean output[]=null;
        
         File file=new File("output.txt");
         FileWriter fileWritter = new FileWriter(file.getName(),true);
         BufferedWriter bufferWritter = new BufferedWriter(fileWritter);
        
         FileInputStream fr=new FileInputStream("C:\\Users\\Sachin\\Desktop\\c2.in");
         @SuppressWarnings("deprecation")
         StreamTokenizer st=new StreamTokenizer(fr);
         st.eolIsSignificant(false);
         st.whitespaceChars(0,32);
         
          int learn=0,flag=0,j=1,i=1,k=1,outputTemp=1;

     while(true)
        {
        flag++;
        
        if(flag!=3)
            learn=st.nextToken();
        if(learn==StreamTokenizer.TT_EOF)
            break;

        if(learn==StreamTokenizer.TT_NUMBER&&flag==1)
        {
            t=(int)st.nval;
            output=new boolean[t+1];
            
        }
            
        if(learn==StreamTokenizer.TT_NUMBER&&flag==2)
        {
            n=(int)st.nval;
            from=new int[n+1][11];
            
        }
        

        else if(learn==StreamTokenizer.TT_NUMBER&&flag==3)
        {
            for(j=1;j<=n;j++)
            {
                learn=st.nextToken();
                from[j][0]=(int)st.nval;
                
                for(i=1;i<=from[j][0];i++)
                {
                    learn=st.nextToken();
                    from[j][i]=(int)st.nval;
                }
            }
            
            int track[]=new int[n+1],temp=1,q[]=new int[n+1];
            boolean found=false;
            for(j=1;j<=n;j++)
            {
                temp=1;
                for(i=1;i<=n;i++)
                    track[i]=0;
                for(i=1;i<=from[j][0];i++)
                {
                        track[from[j][i]]=1;
                        q[temp]=from[j][i];
                        temp++;
                }
                for(i=1;i<temp;i++)
                {
                    for(k=1;k<=from[q[i]][0];k++)
                    {
                        if(track[from[q[i]][k]]==0)
                        {
                            track[from[q[i]][k]]=1;
                            q[temp]=from[q[i]][k];
                            temp++;
                        }
                        else
                        {
                            found=true;
                            i=temp;
                            j=n;
                            break;
                        }
                    }
                }
            }
            output[outputTemp]=found;
            temp=1;
            for(i=1;i<=n;i++)
              track[i]=0;
            outputTemp++;
            flag=1;
        }
        
    }
           
        for(i=1;i<=t;i++)
        {
           bufferWritter.write("Case #"+i+": ");
           if(output[i])
               bufferWritter.write("Yes");
           else
               bufferWritter.write("No");
           if(i!=t)
               bufferWritter.write("\n");
        }
        
        bufferWritter.close();
        
        
    }
}
