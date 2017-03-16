import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.io.Writer;
import java.util.Arrays;
import java.util.Scanner;


public class A {
	static String CASE = "Case #";
	static String N_L = System.getProperty("line.separator");
	
	static int T;
	
	public static void main(String[] args) {
		String input = "file/A-small-attempt0.in";
		String output = "file/A-small.txt";
		
		run(input, output);
	}
	
	public static void run(String input, String output) {
		Scanner sc = null;
		Writer writer = null;
		StringBuilder result = new StringBuilder();
		
		try {
			sc = new Scanner(new FileInputStream(input));
			writer = new OutputStreamWriter(new FileOutputStream(output));
			
			T = sc.nextInt();
			
			int st = 'a';
			int[] goo = new int[26];
			int[] en = new int[26];
			
			Arrays.fill(goo, -1);
			Arrays.fill(en, -1);
			
			goo['y'-st] = 'a';
			goo['e'-st] = 'o';
			goo['q'-st] = 'z';
			
			String[] trainData = {
					"ejp mysljylc kd kxveddknmc re jsicpdrysi",
					"rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd",
					"de kr kd eoya kw aej tysr re ujdr lkgc jv"
			};
			String[] answer = {
					"our language is impossible to understand",
					"there are twenty six factorial possibilities",
					"so it is okay if you want to just give up"	
			};
			for(int i = 0; i < trainData.length; i++) {
				char[] t = trainData[i].toCharArray();
				char[] a = answer[i].toCharArray();
				for(int j = 0; j < t.length; j++) {
					if(t[j] != ' ') {
						goo[t[j]-st] = a[j];
					}
				}
  			}
			char hidden = 0;
			for(int i = 0; i < goo.length; i++) {
				if(goo[i] != -1) {
					en[goo[i]-st] = goo[i];
				} 
			}
			for(int i = 0; i < en.length; i++) {
				if(en[i] == -1) {
					hidden = (char) (st+i);
				} 
			}
			
			sc.nextLine();
			for(int i = 1; i <= T; i++) {
				String m = sc.nextLine();
				char[] msg = m.toCharArray();
				char[] decode = new char[msg.length];
				for(int j = 0; j < msg.length; j++) {
					if(msg[j] != ' ') {
						if(goo[msg[j]-st] != -1) {
							decode[j] = (char) goo[msg[j]-st];
						} else {
							decode[j] = hidden;
						}
					} else {
						decode[j] = msg[j];
					}
				}
				
				result.append(CASE).append(i).append(": ").append(new String(decode));
				if(i != T) {
					result.append(N_L);
				}
				writer.write(result.toString());
				result.setLength(0);
			}
			writer.flush();
			
		} catch(IOException e) {
			e.printStackTrace();
		} finally {
			sc.close();
			try {
				writer.close();
			} catch (IOException e) {
				e.printStackTrace();
			}
		}
	}
}
