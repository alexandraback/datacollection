import java.io.*;
import java.util.*;
public class DetCycle{
	static int ar[]=null,ax[][]=null,cf=0;
	static String reta[]={"No","Yes"};
public static void main(String args[])throws Exception{
BufferedReader br=new BufferedReader(new FileReader("inpxc.txt"));
PrintWriter pw=new PrintWriter("gcgrba.txt");
int tc=Integer.parseInt(br.readLine()),i1=0,i=0,j=0,k=0,l=0;
StringTokenizer st=null;
for(i1=1;i1<=tc;i1++)
{
 int n=Integer.parseInt(br.readLine());
 ax=new int[n][];
 for(i=0;i<n;i++)
 {st=new StringTokenizer(br.readLine());
  ax[i]=new int[Integer.parseInt(st.nextToken())];	
  for(j=0;j<ax[i].length;j++)
       ax[i][j]=Integer.parseInt(st.nextToken())-1;	  
 }
 /*for(i=0;i<ax.length;i++)
 {System.out.print(i+"--");
	 for(j=0;j<ax[i].length;j++)
		 System.out.print(ax[i][j]);
	 System.out.println();
 }*/
 cf=0;
 for(i=0;i<n;i++)
  {ar=new int[n];
 
    dfs(i);
   if(cf==1)break;	  
  }
 pw.println("Case #"+i1+": "+reta[cf]);
}
pw.close();
}

public static void dfs(int lp)
{ if(cf==1)return;
	int i=0;
	ar[lp]=1;
	for(i=0;i<ax[lp].length;i++)
	 {	if(ar[ax[lp][i]]==0)
		    dfs(ax[lp][i]);
			 
		   
	        else
			 {cf=1;	 
			  return;	 
 		         }
	 }
 }
}
