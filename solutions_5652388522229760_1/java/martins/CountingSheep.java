import java.util.*;
import java.io.*;
public class CountingSheep {
	static PrintWriter w; static final String url = "A-large.in";
	public static void main(String...thegame) throws Exception{
		BufferedReader br = new BufferedReader(new FileReader(new File(url)));
//		Scanner seer = new Scanner(System.in);
		w = new PrintWriter("sheep.txt", "UTF-8");
//		int t = seer.nextInt();
		int t = Integer.parseInt(br.readLine());
		for(int i = 0; i < t; i++){
//			long n = seer.nextInt();
			long n = Long.parseLong(br.readLine());
			w.println(String.format("Case #%d: %s", i+1, process(n)));
			process(n);
		}
		w.close();
	}
	static String process(long n){
		if(n == 0) return "INSOMNIA";
		boolean[] yes = new boolean[10];
		long m = n;
		while(true){
			long aux = m; long ten = 10;
			while(aux > 0){
				yes[(int)(aux%ten)]=true;
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
