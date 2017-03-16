import java.util.*;

public class train
{
	static Scanner scan;
	static int T, N;
	static String out;
	static String[] cars;
	static int[][] startEnd;
	static int[] dp;
	static int m= 1000000007;
	static int ans;
	static int[] perm;
	static int[] count;
	static void init()
	{
		N=scan.nextInt();
		cars= new String[N];
		dp = new int[N];
		perm= new int[N];
		count= new int[26];
		startEnd= new int[26][26];
		ans=0;
		
		for(int i=0; i<N; i++)
		{
			perm[i]=i;
			cars[i]=scan.next();
			startEnd[cars[i].charAt(0)-'a'][cars[i].charAt(cars[i].length()-1)-'a']++;
			
			for(int j=0; j<cars[i].length(); j++)
				count[cars[i].charAt(j)-'a']++;
		}
		
	}
	public static boolean nextPermutation(int[] p) {          
          //Step 1
          int a = p.length - 2;          
          while (a >= 0 && p[a] >= p[a + 1]) {              
              a--;          
          }          
          if (a == -1) {              
              return false;          
          }
          
          //Step 2
          int b = p.length - 1;          
          while (p[b] <= p[a]) {              
              b--;          
          }
          
          //Step 3
          int t = p[a];          
          p[a] = p[b];          
          p[b] = t;          
          
          //Step 4
          for (int i = a + 1, j = p.length - 1; i < j; i++, j--) {              
              t = p[i];              
              p[i] = p[j];
              p[j] = t;
          }
          return true;
      }
	static boolean isValid()
	{
		String s= "";
		for(int i=0; i<N; i++)
		{
			s+= cars[perm[i]];
		}
//		System.out.println(s);
//		System.out.println(count[1]);
		for(int i=0; i<s.length();)
		{
			char cur=s.charAt(i);
			int j=1;
			for(; j<count[cur-'a']; j++)
				if(s.charAt(i+j)!=s.charAt(i))
					return false;
	//		System.out.println(s+" "+i+" "+j);
			i+=j;
		}
		return true;
	}
	public static void main(String[] args)
	{
		scan= new Scanner(System.in);
		T= scan.nextInt();
			
		for(int t=1; t<=T; t++)
		{	
			init();
			
			do 
			{
				if(isValid())
					ans++;
			}while(nextPermutation(perm));
			out= ans+"";
			System.out.println("Case #"+t+": "+out);
		}
	}
}