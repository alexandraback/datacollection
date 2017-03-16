

import java.io.*;
import java.util.ArrayList;
import java.util.Scanner;

public class B {

	/**
	 * @param args
	 */
	public static void main(String[] args) throws IOException {
		Scanner sc = new Scanner(new FileReader(new File("C-small-attempt0.in")));
		PrintWriter out = new PrintWriter(new File("B.out"));
		StringBuilder resultat =new StringBuilder("");
		
		int T = sc.nextInt();

		for (int t = 0; t < T; t++) {
			
			int N = sc.nextInt();
			//System.err.println("N=" + N);
			int[] tab = new int[N];
			for (int i = 0; i < N; i++) {
				tab[i]= sc.nextInt();
				//System.out.println(tab[i]+" ");
			}
			
			
			String r ="Impossible";
			
			ArrayList<Long> sommes = new ArrayList<Long>();
			ArrayList<String> texte = new ArrayList<String>(); 
			
			for (int i = 1; i < Math.pow(2,20); i++) {
				String b = Integer.toBinaryString(i);
				//System.out.println("b=" + b);
				long somme = 0;
				String txt = "";
				for (int j = 0; j < b.length(); j++) {
					int k = b.length()-1-j;
					if(b.charAt(k)=='1'){
						somme += tab[j];
						txt += " "+tab[j];
					}
				}
				
				//System.out.println("somme=" + somme);
				
				if(sommes.contains(somme)){
					
					String oldTexte = texte.get(sommes.indexOf(somme));
					
					
					r = "\n"+oldTexte+"\n"+txt.trim();
					break;
				}
				else{
					sommes.add(somme);
					texte.add(txt.trim());
				}
			}
			

			if(t!=0)
				resultat.append("\n");
			resultat.append("Case #"+(t+1)+":"+r);

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
