import java.io.File;
import java.io.FileNotFoundException;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class C{
	public static void main(String[] args) throws FileNotFoundException
	{
		Scanner sc = new Scanner(new File("C.txt"));
		int testCase = Integer.parseInt(sc.nextLine());
		for(int Case=1; Case<=testCase; Case++)
		{
			int total = 0;
			int st = sc.nextInt();int en = sc.nextInt();
			int len = (new Integer(st)).toString().length();
			for(int i=en; i>=st;i--)
			{
				Set s = new HashSet();
				for(int j=1; j<=len-1;j++)
				{
					String sam = (new Integer(i).toString());
					//System.out.println(i+ "Actual String:" + sam);
					StringBuffer temp=new StringBuffer();
					//System.out.println("temp 1:"+temp.toString());
					temp.append(sam.substring(j));
					//System.out.println("temp 2:"+temp.toString());
					temp.append(sam.substring(0, j));
					//System.out.println("temp 3:"+temp.toString());
					int num = Integer.parseInt(temp.toString());
					if(num>=st && num<=en && num<i){s.add(num);}
				}
				total += s.size();
			}
			System.out.println("Case #"+Case+": "+total);
		}
	}
}