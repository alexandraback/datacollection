import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.Scanner;


public class demo2 {
	
	public static boolean isConsonant(String s , int n)
	{
		int count=0;
		boolean flag = false;
		for(char c : s.toCharArray())
		{
			if((c=='a'||c=='e'||c=='i'||c=='o'||c=='u'))
			{
				
				count=0;
			}
			else
			{
				count++;
				if(count>=n)
					break;
			}
		}
		if(count>=n)
			flag=true;
		return flag;
		
	}
	public static void solve(Scanner sc , PrintWriter pw)
	{
		String names = sc.next();
		int n = sc.nextInt();
		
		int ans=0;
		char name[] = names.toCharArray();
		
		System.out.println(names+"  "+n+"  "+names.length());
	  for(int j = n ; j <=names.length() ; j++)
	  {
		 System.out.println("outter loop j :"+j);
		for(int i = 0 ; i <=names.length()-j ; i++ )
		{
		System.out.println("inner loop i :"+i);
			
			if(isConsonant(names.substring(i, i+j),n))
				{ans++;
			 System.out.println("true");
				}
		}
	  }
   System.out.println(ans);
		pw.println(ans);
	}
	
	public static void main(String[] args) throws Exception {
	       

        Scanner sc = new Scanner(new FileReader("input.in"));
        PrintWriter pw = new PrintWriter(new FileWriter("output.in"));
        int caseCnt = sc.nextInt();
     
        for (int caseNum=0; caseNum<caseCnt; caseNum++) {
        	   sc.nextLine();
        	   
            System.out.println("Processing test case " + (caseNum + 1));
            pw.print("Case #" + (caseNum+1) + ": ");
            solve(sc, pw);
            
        }
        pw.flush();
        pw.close();
        sc.close();
    }

}
