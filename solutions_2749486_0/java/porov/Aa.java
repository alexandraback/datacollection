import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;


public class Aa {
	public static void solve(Scanner sc , PrintWriter pw)
	{
		
		int posX = sc.nextInt();
		int posY = sc.nextInt();
		boolean ansFound=true;
		String ans ="";
		int X =0, Y=0;
		int count =0;
		//System.out.println("posX "+posX+"  posY "+posY);
		while(true)
		{	count++;
		    //System.out.println(ans);
		     
			if(ans.length()>500)
			{
				ansFound = false;
			}
			if(X==posX&&Y==posY)
			{
				break;
			}
			
			if(X+count<=posX)
			{
			 X+=count;
			 ans +="E";
			 continue;
			}
			else if(X!=posX)
			{
				X-=count;
				ans+="W";
				continue;
			}
			if(Y+count<=posY)
			{
			 Y+=count;
			 ans +="N";
			 continue;
			}
			else if(Y!=posY)
			{
				Y-=count;
				ans+="S";
				continue;
			}
		
		}
		
		pw.println(ans);
	}
	
	public static void main(String[] args) throws Exception {
	       

        Scanner sc = new Scanner(new FileReader("input.in"));
        PrintWriter pw = new PrintWriter(new FileWriter("output.in"));
        int caseCnt = sc.nextInt();
        sc.nextLine();
        for (int caseNum=0; caseNum<caseCnt; caseNum++) {
            System.out.println("Processing test case " + (caseNum + 1));
            pw.print("Case #" + (caseNum+1) + ": ");
            solve(sc, pw);
        }
        pw.flush();
        pw.close();
        sc.close();
    }
}
