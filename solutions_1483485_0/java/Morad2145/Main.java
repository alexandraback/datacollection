package googlerese;

import java.io.*;

public class Main {

	static char[] map;
	
	public static void main(String[] args) throws IOException {
		map = new char[26];
		loadMap();
		
		File file = new File("A-small-attempt3.in");
		FileReader fr = new FileReader(file);
		BufferedReader in = new BufferedReader(fr);
		
		String line=in.readLine();
		int num = Integer.parseInt(line);
		int i=1;
		while(i<=num){
			line=in.readLine();
			System.out.print("Case #"+i+": ");
			for(int j=0;j<line.length();j++){
				if(line.charAt(j)==' '){
					System.out.print(' ');
				} else {
					System.out.print(map[line.charAt(j)-'a']);
				}
			}
			System.out.println();
			i++;
		}
	}

	private static void loadMap(){
		String from = "ejp mysljylc kd kxveddknmc re jsicpdrysi rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd de kr kd eoya kw aej tysr re ujdr lkgc jv z q";
		String to   = "our language is impossible to understand there are twenty six factorial possibilities so it is okay if you want to just give up q z";
		
		char ch1, ch2;
		
		for(int i=0;i<map.length;i++){
			map[i] = 0;
		}
		
		for(int i=0;i<from.length();i++){
			if(from.charAt(i)!=' '){
				ch1 = from.charAt(i);
				ch2 = to.charAt(i);
				
				if(map[ch1-'a']==0){
					map[ch1-'a'] = ch2;
				} else if(map[ch1-'a']!=ch2){
					System.out.println("ERROR, two different mappings at i="+i);
					System.exit(0);
				}
			}
		}
		
		for(int i=0;i<map.length;i++){
			if(map[i]==0){
				System.out.print("ERROR: No maping ");
				System.out.println((char)('a'+i)+": "+map[i]);
			}
		}
	}
}
