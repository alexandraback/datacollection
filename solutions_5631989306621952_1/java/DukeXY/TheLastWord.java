import java.io.BufferedInputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.Scanner;

public class TheLastWord {
	public static void main(String[] args) throws FileNotFoundException {
		System.setOut(new PrintStream(new File("ans1.txt")));
		Scanner a=new Scanner(new BufferedInputStream(new FileInputStream("1.txt")));
		int n=a.nextInt();
		String w=a.nextLine();
		for (int i=1;i<=n;i++) {
			String s=a.nextLine();
			System.out.print("Case #"+i+": ");
			String ans="";
			for (int j=0;j<s.length();j++) {
				String temp1=ans+s.charAt(j);
				String temp2=s.charAt(j)+ans;
				if (temp1.compareTo(temp2)>0) ans=temp1; else ans=temp2;
			}
			System.out.println(ans);
		}
		System.setOut(System.out);
	}
}
