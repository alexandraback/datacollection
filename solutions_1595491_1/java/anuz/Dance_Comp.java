package dance_comp;

import java.io.*;

public class Dance_Comp {
    int N,count=0;
    String s="",temp[];
    public Dance_Comp() {
        try {
            FileInputStream fis=new FileInputStream("B-large.in");
            DataInputStream dis=new DataInputStream(fis);
            FileOutputStream fos = new FileOutputStream("B-large.out");
            DataOutputStream dos=new DataOutputStream(fos);
            N=Integer.parseInt(dis.readLine());
            for(int i=1;i<=N;i++)
            {
                s=dis.readLine();
                count=0;
                temp=s.split(" ");
                int dancer=Integer.valueOf(temp[0]),surp=Integer.valueOf(temp[1]),cut_of=Integer.valueOf(temp[2]);
                int mrk;
                for(int j=0;j<dancer;j++)
                {
                    mrk=Integer.valueOf(temp[3+j]);
                    int r=mrk%3;
                    mrk=mrk/3;
                    if(mrk>=cut_of || (mrk==(cut_of-1) && r>0))
                    {
                        count++;
                    }
                    else if(surp>0 && ((mrk==(cut_of-2) && r==2) || (mrk==(cut_of-1) && mrk>0)))
                    {
                        count++;
                        surp--;
                    }
                }
                
                s="Case #"+i+": "+count;
                if(i!=N)
                {
                    s=s+"\n";
                }
//                System.out.println(s);
                dos.writeBytes(s);
            }
            fis.close();
            fos.close();
            }catch(Exception e){
                System.out.println("Error: "+e);
            }
    }

    public static void main(String[] args) {
        new Dance_Comp();
    }
}
