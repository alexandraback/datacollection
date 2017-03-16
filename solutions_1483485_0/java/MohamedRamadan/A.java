import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;


public class A {

	/**
	 * @param args
	 * @throws IOException 
	 */
	static int[]a;
	static{
		a=new int[1000];
		a['y']='a';
		a['e']='o';
		a['q']='z';
	}
	public static void read() throws IOException
	{
		BufferedReader r=new BufferedReader(new FileReader("file.txt"));
		for (int i = 0; i <4 ; i++) {
			String l=r.readLine();
			String s=r.readLine();

			for (int j = 0; j < l.length(); j++) {
				a[l.charAt(j)]=s.charAt(j);
			}
		
		}
		
	}
	public static String replace(String l)
	{
		StringBuilder sb=new StringBuilder();
		for (int i = 0; i < l.length(); i++) {
			sb.append((char)a[l.charAt(i)]);
			if(a[l.charAt(i)]==0)
			{
				System.out.println(l.charAt(i));
			}
		}
		return sb.toString();
	}
	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		read();
		
		BufferedReader read=new BufferedReader(new InputStreamReader(System.in));
		String l;
		l=read.readLine();
		//System.out.println(l);
		int a=Integer.parseInt(l);
		String k="";
		BufferedWriter write=new BufferedWriter(new FileWriter("aa.out"));
		for (int i = 0; i < a; i++) {
			l=read.readLine();
			System.out.println("Case #"+(i+1)+": "+replace(l));
			k+="Case #"+(i+1)+": "+replace(l)+"\n";
			
		}
		write.write(k);
		write.close();
	}

}
