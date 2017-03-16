import java.io.*;
import java.util.*;




public class GA {

	String s  = null;
	String[] sp = null;
	
	
	
	public void run() throws Exception{
		
		BufferedReader br = new BufferedReader(new FileReader("A-small-attempt1.in"));
		
		BufferedWriter bw = new BufferedWriter(new FileWriter("OUTPUT.txt"));
		s = br.readLine();
		int T = Integer.parseInt(s);
		
		String[] as = {"ejp mysljylc kd kxveddknmc re jsicpdrysi", "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd", "de kr kd eoya kw aej tysr re ujdr lkgc jv"};
		String[] bs = {"our language is impossible to understand", "there are twenty six factorial possibilities", "so it is okay if you want to just give up"};
		
		Map<String, String> map = new HashMap<String, String>();
		
		for(int i = 0; i < as.length; i++){
			String a = as[i];
			String b = bs[i];
			for(int j = 0; j < a.length(); j++){
				String sa = a.substring(j, j+1);
				String sb = b.substring(j, j+1);
				map.put(sa, sb);
			}
		}
		
		map.put("q", "z");
		map.put("y", "a");
		map.put("e", "o");
		
		for(char c = 'a'; c <= 'z'; c++){
			String sa = Character.toString(c);
			if(!map.containsKey(sa)){
				Collection<String> ks = map.values();
				for(char cs = 'a'; cs <= 'z'; cs++){
					String sb =  Character.toString(cs);
					if(!ks.contains(sb)){
						map.put(sa, sb);
						break;
					}
				}
			}
		}
		
		
		
		int t = 1;
		while(t <= T){
			s = br.readLine();
			StringBuilder ans = new StringBuilder();
			
			for(int i = 0; i < s.length(); i++){
				String sa = s.substring(i, i+1);
				String sb = map.get(sa);
				ans.append(sb);
			}
			
			bw.write("Case #" + t + ": " + ans + "\n");
			
			t++;
		}
		
		bw.close();
	}
	

	
	/**
	 * @param args
	 */
	public static void main(String[] args) throws Exception {
		// TODO Auto-generated method stub
		GA b = new GA();
		b.run();

		
	}
	
	

}
