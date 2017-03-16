
import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;

/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author shivam
 */
public class tictactoe {

    /**
     * @param args the command line arguments
     */
	static boolean allempty=false;
    static boolean empty=false;
    private static boolean xwin;
    private static boolean owin;
    public static void main(String[] args) throws FileNotFoundException, IOException {
        // TODO code application logic here
        BufferedReader n=new BufferedReader(new FileReader("input.txt"));
        PrintWriter kl=new PrintWriter("out.txt");
        int test=Integer.parseInt(n.readLine());
        int result[]=new int[test];
        boolean[] cases; 
        for(int p=0;p<test;p++)
        {
		allempty=false;
		empty=false;
		xwin=false;
		owin=false;            
		char[][] work=new char[4][4];
	    cases=new boolean[10];
            for(int u=0;u<4;u++)
            {
                String s=n.readLine();
                for(int g=0;g<4;g++)
                {
                    if(s.charAt(g)=='.')
                    {   System.out.println("case "+ p +" line "+u+" place "+g);
			empty=true;
                        cases[u]=true;
                        cases[4+g]=true;
                        if(u==g)
                        {
                            cases[8]=true;
                        }
                        else if(u==3-g)
                        {
                            cases[9]=true;
                        }
                    }
                    work[u][g]=s.charAt(g);
                }
            }
        n.readLine();
        xwin=false;
        owin=false;
        int w=0;
        while(w<10)
        {   System.out.println(w+" "+!cases[w]);
            if(!cases[w])
            {	allempty=true;
		System.out.println("case "+p+" line "+w);
		System.out.println(result[p]);
                if(w<4)
                {
                    checkh(work,w);
                    if(xwin)
                    {
                        result[p]=1;
                        break;
                    }
                    else if(owin)
                    {
                        result[p]=2;
                        break;
                    }
		    else if(empty)
                    {
                        result[p]=3;
                    }
                    else
                    {
                        result[p]=4;
                    }
                }
                else if(w>3 && w<8)
                {
                    checkv(work,w%4);
                    if(xwin)
                    {
                        result[p]=1;
                        break;
                    }
                    else if(owin)
                    {
                        result[p]=2;
                        break;
                    }
		    else if(empty)
                    {
                        result[p]=3;
                    }
                    else
                    {
                        result[p]=4;
                    }
                }
                else
                {
                    checkd(work,w);
                    if(xwin)
                    {
                        result[p]=1;
                        break;
                    }
                    else if(owin)
                    {
                        result[p]=2;
                    }
                    else if(empty)
                    {
                        result[p]=3;
                    }
                    else
                    {
                        result[p]=4;
                    }
                }
            }
            w++;
        }
        if(!allempty){result[p]=3;}}
        for(int o=0;o<test;o++)
        {	String s;
	    if(result[o]==1)	
            {s="X won";}
		else if(result[o]==2){s="O won";}
		else if(result[o]==4){s="Draw";}
		else{s="Game has not completed";}
		kl.println("Case #"+(o+1)+": "+s);}
kl.close();      
    }

    private static void checkh(char[][] work,int w) {
        char[] temp=work[w];
        char temp1=temp[0];
        int f=1;
        if(temp1=='T')
        {
            temp1=temp[1];f++;
        }
        while(f!=4){
        if(temp1==temp[f] || temp[f]=='T')
        {
            
            if(f==3)
            {
                if(temp1=='X')
                {
                    xwin=true;
                }
                else
                {
                    owin=true;
                }
            }
        }
        else
        {
            break;
        }
        f++;
        }
    }

    private static void checkv(char[][] work,int w) {
        char temp=work[0][w];
        int f=1;
        if(temp=='T')
        {
            temp=work[1][w];f++;
        }
        while(f!=4)
        {
            if(temp==work[f][w] || work[f][w]=='T')
            {
                
                if(f==3)
                {
                    if(temp=='X')
                    {
                        xwin=true;
                    }
                    else
                    {
                        owin=true;
                    }
                }
            }
            else
            {
                break;
            }
            f++;
        }
    }

    private static void checkd(char[][] work,int w) {
        if(w==8)
        {
            int i=1;
            char temp=work[0][0];
            if(temp=='T')
            {
                temp=work[1][1];i++;
            }
            while(i!=4)
            {
                
                if(temp==work[i][i] || work[i][i]=='T')
                {
                    if(i==3)
                    {
                        if(temp=='X')
                        {
                            xwin=true;
                        }
                        else
                        {
                            owin=true;
                        }
                    }
                }
                else
                {
                    break;
                }
                i++;
            }
        }
        else
        {
            int i=1;
            char temp=work[0][3];
            if(temp=='T')
            {
                temp=work[1][2];i++;
            }
            while(i!=4)
            {
                
                if(temp==work[i][3-i] || work[i][3-i]=='T')
                {
                    if(i==3)
                    {
                        if(temp=='X')
                        {
                            xwin=true;
                        }
                        else
                        {
                            owin=true;
                        }
                    }
                }
                else
                {
                    break;
                }
		i++;
            }
        }
    }
    
}
        
