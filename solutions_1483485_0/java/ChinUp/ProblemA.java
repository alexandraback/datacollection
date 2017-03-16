package Qualification;

import java.io.BufferedReader;
import java.io.FileReader;
import java.util.ArrayList;
import java.util.Arrays;

public class ProblemA {
	
	public static String normal  = "zqour language is impossible to understand there are twenty six factorial possibilities so it is okay if you want to just give up";
	public static String googles = "qzejp mysljylc kd kxveddknmc re jsicpdrysi rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd de kr kd eoya kw aej tysr re ujdr lkgc jv";
	
	public static char[] map = new char[26]; // - 97
	
	public static void main(String args[]) throws Exception{
	
//		System.out.println(args[0]);
		FileReader fr = new FileReader(args[0]);
		BufferedReader br = new BufferedReader(fr);	
		
		int T = Integer.parseInt(br.readLine());
		
		
		createMapping();
		
//		System.out.println(Arrays.toString(map));
//		System.out.println(T);
		
		for(int t=0;t<T;t++) {
//			String gstring = br.readLine();
			char[] garray = br.readLine().toCharArray();
			
			int size = garray.length;
			for(int i=0; i < size; i++) {
				int index = (int)garray[i] - 97;
				if(index < 0) continue;
				
				garray[i] = map[index];
			}
			System.out.println("Case #" + (t+1) + ": " + String.valueOf(garray));
			
		}
	}
	
	public static void createMapping() {
		normal = normal.replace(" ", "");
		googles = googles.replace(" ", "");
		
//		System.out.println(normal);
//		System.out.println(googles);
		
		char[] narray = normal.toCharArray();
		char[] garray = googles.toCharArray(); 
		
		int size = narray.length;
		for(int i=0; i < 26; i++) {
			map[i] = (char)(i+97);
		}
		
		for(int i=0; i < size; i++) {
			int index = (int)garray[i] - 97;
			map[index] = narray[i];
		}
	}
	
}
