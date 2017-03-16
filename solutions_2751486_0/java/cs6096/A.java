import java.io.*;
import java.util.*;
import java.math.*;
public class A {
	public static Scanner scan = null;
	public static Scanner scan2 = null;
	public static PrintWriter out = null;
	public static boolean bg = true;
	public static int no = 1;
	public static HashSet<Character> vowels = new HashSet();
	static{
		try {
			vowels.add('a');
			vowels.add('e');
			vowels.add('i');
			vowels.add('o');
			vowels.add('u');
			scan2 = new Scanner(System.in);
			scan = new Scanner(new FileReader("input"+no+".txt"));
			out = new PrintWriter(new File("output"+no+".txt"));
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}
	}
	public static void main(String[] args){
		if (bg) System.out.println(vowels);
		int t = Integer.parseInt(scan.next());
		for (int count = 0;count<t;count++){
			String str1 = scan.next();
			
			int n = Integer.parseInt(scan.next());
			
			StringBuilder k2 = new StringBuilder();
			for (char e: str1.toCharArray()){
				if (vowels.contains(e) ){
					k2.append('1');
				}
				else {
					k2.append('0');
				}
			}
			str1 = k2.toString();
			StringBuilder k3 = new StringBuilder();
			for (int i=0;i<n;i++){
				k3.append('0');
			}
			String dum = k3.toString();
			
			
			
			HashMap<String,Integer> m1 = new HashMap();
			System.out.println(str1+" "+n);
			long fin = 0;
			for (int i=0;i<str1.length();i++){
				for (int j=i+(n);j<str1.length()+1;j++){
					String temp = str1.substring(i, j);
					if (temp.contains(dum)){
						fin++;
					}
					/*
					boolean ok = true;
					System.out.println(temp);
					for (char e: temp.toCharArray()){
						if (bg) System.out.println("e "+e);
						if (vowels.contains(e)){
							ok=false;
							break;
						}
					}
					if (ok){
						
					}
					*/
					
				}
			}
			System.out.println("fin "+fin);
			System.out.println();
			out.println("Case #"+(count+1)+": "+fin);
			out.flush();
		}
		
	}
}
