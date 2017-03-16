import java.io.*;
import java.util.*;
public class dijkstra {
	private static String test;
	private static int x;
	private static Map<String,String> values=new HashMap<String,String>();
	private static List<Integer>iendpositions;
	private static PrintWriter o;
	public static void main(String[]args) throws Exception
	{
		values.put("1i","i");
		values.put("1j","j");
		values.put("1k","k");
		values.put("ii","-1"); //
		values.put("ij","k");
		values.put("ik","-j");
		values.put("ji","-k");
		values.put("jj","-1"); //
		values.put("jk","i");
		values.put("ki","j");
		values.put("kj","-i");
		values.put("kk","-1"); //

		values.put("-1i","-i");
		values.put("-1j","-j");
		values.put("-1k","-k");
		values.put("-ii","1"); 
		values.put("-ij","-k");
		values.put("-ik","j");
		values.put("-ji","k");
		values.put("-jj","1");
		values.put("-jk","-i");
		values.put("-ki","-j");
		values.put("-kj","i");
		values.put("-kk","1"); 
		o=new PrintWriter("dijkstraout4.txt");
		Scanner scan=new Scanner(new File("C-small-attempt3.in"));
		int n=Integer.parseInt(scan.nextLine());
		for(int i=1;i<=n;i++)
		{
			iendpositions=new ArrayList<Integer>();
			String[]c=scan.nextLine().split(" ");
			//String testorig=scan.nextLine();
			//test="";
			test=scan.nextLine();
			x=Integer.parseInt(c[1]);
			//for(int j=0;j<Integer.parseInt(c[1]);j++)
			//{
			//	test+=testorig;
			//}
			/*/
			System.out.println("ijk"+multiply("ijk"));
			System.out.println(multiply("jjk"));
			System.out.println(multiply("kjk"));
			System.out.println(multiply("ikk"));
			System.out.println(multiply("jkk"));
			System.out.println(multiply("kkk"));
			System.out.println(multiply("iik"));
			System.out.println(multiply("jik"));
			System.out.println(multiply("kik"));

			System.out.println(multiply("iji"));
			System.out.println(multiply("jji"));
			System.out.println(multiply("kji"));
			System.out.println(multiply("iki"));
			System.out.println("jki"+multiply("jki"));
			System.out.println(multiply("kki"));
			System.out.println(multiply("iii"));
			System.out.println(multiply("jii"));
			System.out.println(multiply("kii"));

			System.out.println(multiply("ijj"));
			System.out.println(multiply("jjj"));
			System.out.println(multiply("kjj"));
			System.out.println(multiply("ikj"));
			System.out.println(multiply("jkj"));
			System.out.println(multiply("kkj"));
			System.out.println(multiply("iij"));
			System.out.println(multiply("jij"));
			System.out.println("kij"+multiply("kij"));
			//*/
			//System.out.println(test);
			boolean b=findsolutionhelper();
			//*/
			//boolean b=findSolution(test, 0, 3);
			if(b)
			{
				//System.out.println("Case #"+i+": YES");
				o.println("Case #"+i+": YES");
			}
			else
			{
				//System.out.println("Case #"+i+": NO");
				o.println("Case #"+i+": NO");
			}
			//o.println();
			System.out.println(iendpositions.size());
			//*/
		}
		scan.close();
		o.close();
	}
	private static boolean findsolutionhelper()
	{
		if(test.length()*x<3)
		{
			//System.out.println("too short");
			//o.println("too short");
			return false;
		}
		String testmult=multiply(test);
		//System.out.println(testmult);
		if(testmult.equals("1"))
		{
			//System.out.println("multiplies to 1");
			//o.println("multiplies to 1");
			return false;
		}
		else if(testmult.equals("-1"))
		{
			if(x%2==0)
			{
				//System.out.println("testmult=1 and x is even");
				//o.println("testmult=1 and x is even");
				return false;
			}
			//else
			//{
			//	for(int copy=1;copy<x&&copy<6;copy+=2)
			//}
		}
		else if(x%4!=2)
		{
			//System.out.println("testmult!=1 or -1, and x%4!=2");
			//o.println("testmult!=1 or -1, and x%4!=2");
			return false;
		}
		return findSolutionHelper2(testmult);
	}
	private static boolean findSolutionHelper2(String testmult)
	{
		String testroot=new String(test);
		if(testmult.equals("-1"))
		{
			mMultiply(testmult, test,1);
			if(iendpositions.size()==0)
			{
				return false;
			}
			for(int y:iendpositions)
			{
				if(y<test.length()-1)
				{
					String sresult="1";
					for(int i=y;i<test.length()-1;i++)
					{
						sresult=values.get(sresult+test.substring(i,i+1));
						if(sresult.equals("j"))
							return true;
					}
				}
			}
			if(x>1)
			{
				test+=testroot;
				test+=testroot;
				for(int y:iendpositions)
				{
					if(y<testroot.length()*2+1)
					{
						String sresult="1";
						for(int i=y;i<test.length()-1;i++)
						{
							sresult=values.get(sresult+test.substring(i,i+1));
							if(sresult.equals("j"))
								return true;
						}
					}
				}
				if(x>3)
				{
					test+=testroot;
					test+=testroot;
					for(int y:iendpositions)
					{
						if(y<testroot.length()*2+1)
						{
							String sresult="1";
							for(int i=y;i<test.length()-1;i++)
							{
								sresult=values.get(sresult+test.substring(i,i+1));
								if(sresult.equals("j"))
									return true;
							}
						}
					}
				}
			}
			//System.out.println("testmult=-1 and failed to find solution");
			//o.println("testmult=-1 and fail to find solution");
			return false;
		}
		else
		{
			testmult=mMultiply(testmult,test,1);
			testmult=mMultiply(testmult,test,2);
			testmult=mMultiply(testmult,test,3);
			if(iendpositions.size()==0)
			{
				return false;
			}
			test+=testroot;//now 2;
			for(int y:iendpositions)
			{
				if(y<test.length()-1)
				{
					String sresult="1";
					for(int i=y;i<test.length()-1;i++)
					{
						sresult=values.get(sresult+test.substring(i,i+1));
						if(sresult.equals("j"))
							return true;
					}
				}
			}
			if(x>2)
			{
				test+=testroot;
				test+=testroot;
				test+=testroot;
				test+=testroot;//now 6
				for(int y:iendpositions)
				{
					if(y<testroot.length()*4+1)
					{
						String sresult="1";
						for(int i=y;i<test.length()-1;i++)
						{
							sresult=values.get(sresult+test.substring(i,i+1));
							if(sresult.equals("j"))
								return true;
						}
					}
				}
				if(x>6)
				{
					test+=testroot;
					test+=testroot;
					test+=testroot;
					test+=testroot;//now 10
					for(int y:iendpositions)
					{
						if(y<testroot.length()*4+1)
						{
							String sresult="1";
							for(int i=y;i<test.length()-1;i++)
							{
								sresult=values.get(sresult+test.substring(i,i+1));
								if(sresult.equals("j"))
									return true;
							}
						}
					}
				}
			}
			//System.out.println("testmult!=-1 or 1, and fail to find solution");
			//o.println("testmult not -1 or 1, and fail to find solution");
			return false;
		}
	}
	private static String multiply(String a)
	{
		String sresult="1";
		for(int i=0;i<a.length();i++)
		{
			sresult=values.get(sresult+a.substring(i,i+1));
			if(sresult.equals("i"))
				iendpositions.add(i+1);
		}
		return sresult;
	}
	private static String mMultiply(String b, String a, int count)
	{
		for(int i=0;i<a.length();i++)
		{
			b=values.get(b+a.substring(i,i+1));
			if(b.equals("i"))
				iendpositions.add(test.length()*count+i+1);
		}
		return b;
	}
}