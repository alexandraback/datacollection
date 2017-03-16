import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.HashSet;
import java.util.Scanner;

public class Main {
	
	public static void main(String [] args) throws IOException{
		Scanner cin = new Scanner(new FileReader("input.txt"));
		PrintWriter cout = new PrintWriter(new FileWriter("output.txt"));
		int T = cin.nextInt();
		HashSet<Character>  vow = new HashSet<Character>();
		vow.add('a'); vow.add('o'); vow.add('u'); vow.add('i'); vow.add('e');
		for (int t=0;t<T;++t){
			char []s = cin.next().toCharArray();
			int cnt = 0, N = s.length, n = cin.nextInt();
			for (int i=0;i<N;++i)
				for (int j=i;j<N;++j){
					int l = 0, tt = 0;
					for (int k=i;k<=j-n+1;++k){tt = 0; while (k<=j && !vow.contains(s[k])){k++;tt++;}l = Math.max(l, tt);}
					if (l >= n)cnt++;
			}
			cout.println("Case #"+(t+1)+": "+cnt);
		}
		cout.flush();
	}

}