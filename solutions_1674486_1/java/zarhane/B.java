

import java.io.*;
import java.util.ArrayList;
import java.util.Scanner;

public class B {

	/**
	 * @param args
	 */
	public static void main(String[] args) throws IOException {
		Scanner sc = new Scanner(new FileReader(new File("A-large.in")));
		PrintWriter out = new PrintWriter(new File("B.out"));
		StringBuilder resultat =new StringBuilder("");
		
		int T = sc.nextInt();
		
		//System.err.println("T="+T);

		for (int t = 0; t < T; t++) {
			
			int N = sc.nextInt();
			
			//System.err.println("N="+N);
			
			ArrayList<Integer>[] tab = new ArrayList[N];
			
			
			for (int i = 0; i < N; i++) {
				
				tab[i] = new ArrayList<Integer>();
				
				int M = sc.nextInt();
				//System.out.println("M="+M);
				for (int j = 0; j < M; j++) {
					int p = sc.nextInt();
					//System.out.println("p="+p);
					tab[i].add(p);
				}
			}
			
			boolean yes = false;
			for (int i = 0; i < N && yes==false ; i++) {
				ArrayList<Integer> parents = new ArrayList<Integer>();
				parents.addAll(tab[i]);
				
				for (int j = 0; j < parents.size() && yes==false; j++) {
					int p = parents.get(j);
					for (int k = 0; k < tab[p-1].size(); k++) {
						int e = tab[p-1].get(k);
						if(parents.contains(e))
						{
							yes = true;
							break;
						}
						else
						{
							parents.add(e);
						}
					}
				}
			}
			
			
			String r ="No";
			if(yes)
				r = "Yes";
			
			if(t!=0)
				resultat.append("\n");
			resultat.append("Case #"+(t+1)+": "+r);

		}
		
		out.print(resultat);
		out.close();
	}
	
	
	String multiply(String str1, String str2){
		if(str2.length()>str1.length()){
			return multiply(str1, str2);
		}
		else{
			String res="";
			for (int i = 0; i < str1.length(); i++) {
				if(i>=str2.length())
					res+="0";
				else{
					if(str1.charAt(i)=='1' && str2.charAt(i)== '1' )
						res+="1";
					else
						res+="0";
				}
			}
			return res;
		}
	}
	
}
