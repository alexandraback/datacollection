import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Scanner;


public class circle {
	public static int findc(int[] a)
	{
		int max=0;
		int l=a.length;
		
		for(int i=0;i<l;i++)
		{
			int now=i;
			HashMap<Integer, Integer> hmap = new HashMap<Integer, Integer>();
			ArrayList<Integer> obj = new ArrayList<Integer>();
			hmap.put(i, 0);
			//obj.add(i);
			int index=1;
			while(!hmap.containsKey(a[now]))
			{
				
				hmap.put(a[now], index);
				//obj.add(a[now]);
				now=a[now];
				index=index+1;
			}
			int maxt;
			if(now==a[a[now]])
			{
				maxt=hmap.size();
				for(int k=0;k<l;k++)
				{
					if(k==a[a[k]]&&!hmap.containsKey(k)&&!hmap.containsKey(a[k]))
					{
						maxt=maxt+2;
						break;
					}
					if(a[k]==now&&!hmap.containsKey(k))
					{
						maxt++;
						break;
					}
				}
			}
			else
				maxt=hmap.size()-hmap.get(a[now]);
			System.out.print(maxt+" "+hmap.size()+" "+a[now]+" ");
			
			max=Math.max(max, maxt);
		}
		System.out.println("");
		return max;
	}
	public static void main(String[] args) throws IOException {
		Scanner scanner = new Scanner(new File("C-small-attempt1.in"));
		//int [] tall = new int [100];
		int total = scanner.nextInt();
		System.out.println(total);
		
		FileWriter fw = new FileWriter("out.txt");
		for(int i=0;i<total;i++){
			int n = scanner.nextInt();
			int[] a=new int[n];
			
		   for(int j=0;j<n;j++)
		   {
			   a[j]=scanner.nextInt()-1;
			   //System.out.print(a[j]);
		   }
		   
		   int max=findc(a);
		   fw.write("Case #"+(i+1)+": "+max+"\n");
		   
		}
        fw.close();
		
	}

}
