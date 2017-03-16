
import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.StringTokenizer;

/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author cs1120252
 */
public class lawnmower {
    private static int min;
    private static int max;

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws FileNotFoundException, IOException {
        // TODO code application logic here
        BufferedReader n=new BufferedReader(new FileReader("input.txt"));
        int test=Integer.parseInt(n.readLine());
	PrintWriter r=new PrintWriter("out.txt");
        boolean[] result=new boolean[test];
        int temp=0;
        for(int d=0;d<test;d++)
        {
            StringTokenizer l=new StringTokenizer(n.readLine());
            int N=Integer.parseInt(l.nextToken());
            int M=Integer.parseInt(l.nextToken());
            int[][] work=new int[N+2][M+2];
            for(int s=0;s<N;s++)
            {
                StringTokenizer op=new StringTokenizer(n.readLine());
                min=0;
                max=0;
                for(int c=0;c<M;c++)
                {//System.out.println(c);
                    temp= Integer.parseInt(op.nextToken());//System.out.println(temp);
                    if(c==0){min=temp;max=min;;}//System.out.println(min+"   "+max);
                    if(min>temp){min=temp;}
                    if(max<temp){max=temp;}
                    work[s][c]=temp;
                }
                work[s][M]=min;
                work[s][M+1]=max;
            }
            for(int u=0;u<M;u++)
            {
                min=work[0][u];max=min;;
                for(int k=1;k<N;k++)
                {
                    if(work[k][u]>max){max=work[k][u];}
                    else if(work[k][u]<min){min=work[k][u];}
                }
                work[N][u]=min;work[N+1][u]=max;
            }
	for(int z=0;z<N;z++)
            {	
                for(int x=0;x<M;x++)
                {
                    if(work[z][x]<work[z][M+1])
                    {	//System.out.print(work[z][x]+"  ");System.out.println(work[z][M+1]);
			//System.out.println(z+"   "+x);
                        if(work[z][x]<work[N+1][x])
                        {	//System.out.println("here");
				//System.out.print(work[z][x]+"  ");System.out.println(work[N+1][x]);
                            result[d]=true;
                            
                        }
                    }
                }
            }//System.out.println("end of case");
            
            
        }
        for(int v=0;v<test;v++)
        {
		if(result[v]){            
		r.println("Case #"+(v+1)+": NO");}
		else{r.println("Case #"+(v+1)+": YES");}
        }
        r.close();
    }
}
