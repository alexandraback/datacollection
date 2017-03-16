import java.io.*;
import java.util.*;

public class Code1C {
	public static final String problem = "CS1";
	public static final boolean testing = false;

	public static final String path = "C:\\Users\\alberto\\Downloads\\";
	public static void main(String[] args) throws IOException {
		System.out.println("Problem:\t" + problem);
		String inf = "src\\input.txt";
		if (!testing){
			inf = path + problem.charAt(0) + "-large.in";		
			if (problem.charAt(1) == 'S'){
				inf = path + problem.charAt(0) + "-small-attempt" + problem.charAt(2) + ".in";
			}			
		}
		Scanner sc = new Scanner(new FileReader(inf));
		PrintWriter pw = new PrintWriter(new FileWriter("src\\output.txt"));
		if(problem.charAt(0) == 'A')		main_A(sc, pw);
		else if(problem.charAt(0) == 'B')	main_B(sc, pw);
		else if(problem.charAt(0) == 'C')	main_C(sc, pw);
		else if(problem.charAt(0) == 'D')	main_D(sc, pw);
		sc.close();
		pw.close();
	}

	public static void main_A(Scanner sc, PrintWriter pw) throws IOException {
		int T=sc.nextInt();
		sc.nextLine();
		
		mainloop: for(int cn=1;cn<=T;cn++) {
			System.out.println("Case:\t" + cn);
			String s[] = sc.nextLine().split("/");			
			long p = Long.parseLong(s[0]);
			long q = Long.parseLong(s[1]);
			//System.out.println(p+" "+q);
			
			int lasts=0;
			double ss=(double)p/q;
			boolean done = false;			
			int steps=1;
			int tsteps=1;
			//System.out.println(ss);
			if(ss!=1)
			{
				double fra = 0.5;							
				while (fra > 1E-40)
				{
					if (ss >= fra)
					{
						//System.out.println(ss + "\t" + fra);
						ss-=fra;
						tsteps=steps;
						if(!done)
						{
							lasts = steps;
							done = true;
						}						
					}
					fra/=2.0;
					steps++;
				}
			}

			//System.out.println("final:\t" + ss + "\t" + lasts);
			if (tsteps > 40 || ss != 0.0)
			{
				pw.println("Case #" + cn + ": impossible");
			}
			else
			{
				pw.println("Case #" + cn + ": " + lasts);
			}
		}
	}

	public static void main_B(Scanner sc, PrintWriter pw) throws IOException {
		int T=sc.nextInt();
		
		mainloop: for(int cn=1;cn<=T;cn++) {
			System.out.println("Case:\t" + cn);
			int n=sc.nextInt();
			sc.nextLine();
			//System.out.println(n);
			String s=sc.nextLine();
			
			String[] ps=s.split(" ");
						
			used = new int[ps.length];
			
			long res=0;
			//for (int c=0;c<26;c++)
			//{				
				int[] alph = new int[26];
				//alph[c]=1;
				String cs="";
				res+=dfsb(ps, -1, 0, alph, cs);				
				//System.out.println(('a' + 0) + "\t" + res);
			//}

			pw.println("Case #" + cn + ": " + (res%1000000007));
		}
	}
	
	public static long dfsb(String[] ps, int cuc, int nus, int[] alph, String cs)
	{
		//System.out.println("top:\t" + cs);
		if(nus==ps.length)
		{			
			return 1;
		}
		int[] calph = new int[26];
		for(int c=0;c<26;c++)
		{
			calph[c]=alph[c];
		}
		long res=0;
		int CC=cuc;
		ttt: for(int cc=0;cc<ps.length;cc++)
		{
			//System.out.println(cs + "\t" + ps[cc]);
			if(used[cc]==0)
			{
				used[cc]=1;
				for(int ccc=0;ccc<ps[cc].length();ccc++)
				{
					int c1=ps[cc].charAt(ccc) - 'a';
					if(c1 != CC)
					{
						//System.out.println("c1:" + (char)(c1+'a') + "no match " + (char)(CC+'a'));
						if(calph[c1]==1)
						{
							//System.out.println("ccc");
							used[cc]=0;
							for(int c=0;c<26;c++)
							{
								calph[c]=alph[c];
							}
							CC=cuc;
							continue ttt;
						}
						else
						{
							CC=c1;
							//System.out.println((char)(CC+'a'));
							calph[c1]=1;
						}
					}					
				}
				//System.out.println(Arrays.toString(ps) + "\t" + (char)(CC+'a') + "\t" + (nus+1) + "\t" + Arrays.toString(calph));
				//System.out.println("bo:\t" + cs+ps[cc] + "\t" + (char)(CC+'a'));
				res+=dfsb(ps,CC,nus+1,calph,cs+ps[cc]);
				used[cc]=0;
				for(int c=0;c<26;c++)
				{
					calph[c]=alph[c];
				}
				CC=cuc;
			}
		}
		return res;
	}
		
	public static int[] used;	

	public static void main_C(Scanner sc, PrintWriter pw) throws IOException {
		int T=sc.nextInt();
		
		mainloop: for(int cn=1;cn<=T;cn++) {
			System.out.println("Case:\t" + cn);
			int n = sc.nextInt();
			int m = sc.nextInt();
			int k = sc.nextInt();
			
			int min = k;
			for (int i=3;i<=n;i++)
			{
				for(int j=3;j<=m;j++)
				{
					int c = (i-2)*2 + (j-2)*2;
					int b =((i-2)*(j-2)) + c;
					if(b >= k)
					{
						if(c < min)
						{
							min = c;
						}
					}
					else
					{
						int cc = (k - b) + c;
						if(cc < min)
						{
							min = cc;
						}
					}
				}
			}
			
			pw.println("Case #" + cn + ": " + min);
		}
	}

	public static void main_D(Scanner sc, PrintWriter pw) throws IOException {
		int T=sc.nextInt();
		
		mainloop: for(int cn=1;cn<=T;cn++) {
			System.out.println("Case:\t" + cn);

			pw.println("Case #" + cn + ": answer");
		}
	}
}
