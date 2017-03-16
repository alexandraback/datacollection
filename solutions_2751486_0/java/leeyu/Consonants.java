package codejam1c;

import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class Consonants {

	//char[] vow=new char[]{'a','e','i','o','u'};
	
	
	public static int get(String word,int n){
		int nv=0;
		int base=0;
		int subL=0;
		StringBuilder sb=new StringBuilder();
		for(int i=0;i<word.length();i++){
			if(subL>0) nv+=subL;
			if(word.charAt(i)=='a'||word.charAt(i)=='e'||word.charAt(i)=='i'||word.charAt(i)=='o'||word.charAt(i)=='u'){
				if(sb.length()>0) sb=new StringBuilder();
			}else{
				sb.append(word.charAt(i));
				if(sb.length()==n) {
					if(subL>0) nv-=subL;
					String sbStr=sb.toString();
					sb=new StringBuilder();
					sb.append(sbStr.substring(1));
					subL=base-(n-1)+1;
					nv+=subL;
				}
			}
			base+=1;
		}
		
		return nv;
	}
	
	public static void main(String[] args) throws IOException {
		Scanner sc=new Scanner(new FileReader("1c/A-small-attempt0 (3).in"));
		BufferedWriter bw=new BufferedWriter(new FileWriter("1c/A-small-attempt0 (3).out"));
		int caseN=sc.nextInt();
		System.out.println(caseN);
		for(int i=0;i<caseN;++i){
			String word=sc.next();
			int n=sc.nextInt();
			int nv=get(word,n);
			bw.write("Case #"+(i+1)+": "+nv+"\n");
		}
		bw.close();
		sc.close();
	}

}
