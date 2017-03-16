import java.util.*;
import java.io.*;
public class CountingSheep {
	static PrintWriter w;
	public static void main(String...thegame) throws Exception{
		Scanner seer = new Scanner(System.in);
		w = new PrintWriter("sheep.txt", "UTF-8");
		int t = seer.nextInt();
		for(int i = 0; i < t; i++){
			int n = seer.nextInt();
			w.println(String.format("Case #%d: %s", i+1, process(n)));
			process(n);
		}
		w.close();
	}
	static String process(int n){
		if(n == 0) return "INSOMNIA";
		boolean[] yes = new boolean[10];
		int m = n;
		while(true){
			int aux = m;
			while(aux > 0){
				yes[aux%10]=true;
				aux/=10;
			}
			boolean si = true;
			for(boolean b: yes){
				if(!b) si = false;
			}
			if(si) return m+"";
			m+=n;
		}
	}
}
