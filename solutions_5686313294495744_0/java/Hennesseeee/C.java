import java.io.*;
import java.math.*;
import java.util.*;

public class C{
	public static void main(String[] args) throws IOException{
		BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter writer = new PrintWriter("out.txt", "UTF-8");
		int T = Integer.parseInt(reader.readLine());
		for(int i = 1; i<=T; i++){
			int N = Integer.parseInt(reader.readLine());
			HashMap<String, Integer> first = new HashMap<>();
			HashMap<String, Integer> second = new HashMap<>();

			String[] words = new String[N];
			int solution = 0;

			for(int k = 0; k < N; k++){
				words[k] = reader.readLine();
				String[] wordsSplit = words[k].split("\\s+");
				if(first.get(wordsSplit[0]) == null){
					first.put(wordsSplit[0],1);
				} else {
					first.put(wordsSplit[0], first.get(wordsSplit[0])+1);
				}

				if(second.get(wordsSplit[1]) == null){
					second.put(wordsSplit[1], 1);
				} else {
					second.put(wordsSplit[1], second.get(wordsSplit[1])+1);
				}
			}

			for(int k = 0; k < N; k++){
				String[] wordsSplit = words[k].split("\\s+");
				if(first.get(wordsSplit[0]) > 1){
					if(second.get(wordsSplit[1]) > 1){
						solution++;
					}
				}
			}
			writer.println("Case #" + i + ": " + solution);
		}
		writer.close();
	}
}