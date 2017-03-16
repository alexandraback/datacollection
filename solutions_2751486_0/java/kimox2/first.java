import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class first {

	/**
	 * @param args
	 * @throws IOException
	 * @throws NumberFormatException
	 */
	public static void main(String[] args) throws NumberFormatException,
			IOException {
		BufferedReader reader = new BufferedReader(new FileReader(new File("tes.in"))); 
				
		int l = Integer.parseInt(reader.readLine());
		boolean v[]=new boolean[27];
		v['a'-'a']=true;
		v['e'-'a']=true;
		v['i'-'a']=true;
		v['o'-'a']=true;
		v['u'-'a']=true;
		String st[];
		char map[];
		int n;
		for (int cas = 0; cas < l; cas++) {
			st=reader.readLine().split(" ");
			map=st[0].toCharArray();
			n=Integer.parseInt(st[1]);
			
			int count=0;
			int concount = 0;
			for(int i=0;i<map.length;i++)
			{
				for(int j=i+n-1;j<map.length;j++)
				{
					concount=0;
					for(int k=i;k<=j;k++)
					{
						if(!v[map[k]-'a'])
							concount++;
						else
							concount=0;
						if(concount>=n)
						{
							//System.out.println(i+" "+j);
							count++;
							break;
						}
					}
				}
			}
			System.out.println("Case #"+(cas+1)+": "+count);
		}
	}

}
