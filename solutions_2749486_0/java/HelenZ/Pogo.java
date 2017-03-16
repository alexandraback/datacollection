import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;

public class Pogo {
	
	public static void main(String [] args) throws IOException{
		Scanner cin = new Scanner(new FileReader("input.txt"));
		PrintWriter cout = new PrintWriter(new FileWriter("output.txt"));
		int T = cin.nextInt();
		for (int t=0;t<T;++t){
			String s = "";
			int x = cin.nextInt(), y = cin.nextInt();
			if (x < 0)for (int i=0;i<-x;++i)s += "EW";
			else for (int i=0;i<x;++i)s += "WE";
			if (y < 0)for (int i=0;i<-y;++i)s += "NS";
			else for (int i=0;i<y;++i)s += "SN";
			cout.println("Case #"+(t+1)+": "+s);
		}
		cout.flush();
	}

}