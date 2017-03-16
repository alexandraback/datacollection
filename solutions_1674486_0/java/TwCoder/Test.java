import java.io.BufferedReader;
import java.io.FileReader;
    import java.io.IOException;
    import java.io.InputStreamReader;
    import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Iterator;
import java.util.Random;
import java.util.StringTokenizer;

    public class Test {
            static BufferedReader reader;
            static StringTokenizer tokenizer;
            static PrintWriter writer;

            static int nextInt() throws IOException {
                    return Integer.parseInt(nextToken());
            }

            static long nextLong() throws IOException {
                    return Long.parseLong(nextToken());
            }

            static double nextDouble() throws IOException {
                    return Double.parseDouble(nextToken());
            }

            static String nextToken() throws IOException {
                    while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                            tokenizer = new StringTokenizer(reader.readLine());
                    }
                    return tokenizer.nextToken();
            }

            public static void main(String[] args) throws IOException {
                    reader = new BufferedReader(new InputStreamReader(System.in));
                    tokenizer = null;
                    writer = new PrintWriter(System.out);
                    solve();
                    reader.close();
                    writer.close();
            }

            private static void solve() throws IOException {
            	int T=nextInt();
            	for (int i=0;i<T;i++)
            	{
            	int N=nextInt();
            	int[][] Clas=new int[N][N];
            	int[][] Cla=new int[N][];   
            	int[] inh=new int[N];
            	boolean ans=false;
            	for (int e=0;e<N;e++)
            	{
            		int y=nextInt();
            		Cla[e]=new int[y];
            		for (int z=0;z<y;z++)
            			{
            			int yy=nextInt()-1;
            			Cla[e][z]=yy;
            			inh[yy]++;
            			}
            	}
            	boolean go=true;
            	int numinh=0;
            	for (int e=0;e<N;e++)
            	{
            		if (inh[e]==0)
            			numinh++;
            	}
            	int[][] cll=new int[N][numinh];
            	for (int e=0;e<N;e++)
            	{
            		for (int zz=0;zz<numinh;zz++)
                    	cll[e][zz]=-1;
            	}
            	for (int e=0;e<N;e++)
            	{
            		if (inh[e]==0)
            		   	cll[e][0]=e;
            	}
            	
            	while(go)
            	{
            		go=false;
            	for (int e=0;e<N;e++)
            	{
            		if (inh[e]==0)
            		{
            			for (int zz=0;zz<Cla[e].length;zz++)
            			{
            				for (int z=0;z<numinh;z++)
            			
            			{
            			while(cll[e][z]!=-1){
            			if (Clas[Cla[e][zz]][cll[e][z]]==1)
            				{ans=true;break;}
            			else
            				Clas[Cla[e][zz]][cll[e][z]]=1;
            			int q=0;
            			while(cll[Cla[e][zz]][q]!=-1)
            				q++;
            			cll[Cla[e][zz]][q]=cll[e][z];
            			z++;
            			go=true;
            			if (z==(numinh))
                			break;
            			}
            			if (ans)
                			break;
            			}
            			inh[Cla[e][zz]]--;
            			if (ans)
                			break;
            			}
            		inh[e]--;
            		}
            		if (ans)
            			break;
            	}
            	if (ans)
        			break;
            	}
            	
    			
            	String anser="Case #"+Integer.toString(i+1)+": ";
            	String an="No";
            	if (ans)
            		an="Yes";
            		
            	if(i!=T-1)
            		writer.println(anser+an);
            	else
            		writer.print(anser+an);
        	
            	}
            }


    }