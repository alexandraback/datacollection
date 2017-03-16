import java.io.BufferedReader;
import java.io.FileReader;
import java.io.PrintWriter;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.Arrays;

public class Main{
	
	static int ans;
	static void process(String[] str,int nos,int n,String tp,boolean[] fg){
		if(nos==n){
			if(check(tp.substring(0,tp.length()-1))){ ans++;
			// System.out.println(tp);
			}
		}else{
			for(int i=0;i<n;i++){
				if(!fg[i]){
					fg[i]=true;
					process(str,nos+1,n,tp+str[i]+" ",fg);
					fg[i]=false;
				}
			}
		}
	}
	
	static boolean check(String tp){
		String[] str1=tp.split(" ");
		for(int i=0;i<str1.length-1;){
			if(str1[i+1].charAt(0)==str1[i].charAt(str1[i].length()-1)) {i+=2;}
			else return false;
		}
		return (str1[str1.length-1].charAt(0)==str1[str1.length-2].charAt(str1[str1.length-2].length()-1));
	}
	
	public static void main(String args[]){
		try{
			FileReader fr=new FileReader("input.txt");
			BufferedReader br=new BufferedReader(fr);
			PrintWriter pr=new PrintWriter("out.txt");
			String str=br.readLine();
			int T=Integer.parseInt(str);
			for(int t=1;t<=T;t++){
				str=br.readLine();
				// System.out.println(str);
				int n=Integer.parseInt(str);
				ans=0;
				String str1[]=br.readLine().split(" ");
				if(n>1){
					boolean[] fg=new boolean[n];
					process(str1,0,n,"",fg);
				}
				str="Case #"+t+": "+(ans);
				pr.println(str);
				System.out.println(str);
			}
			pr.flush();
		}catch(IOException ioe){
			ioe.printStackTrace();
		}
	}
}