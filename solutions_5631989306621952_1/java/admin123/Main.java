import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.io.RandomAccessFile;
import java.math.BigInteger;
import java.util.InputMismatchException;

public class Main {
	
	public static void main(String[] args) throws Exception {
		PrintWriter pr = new PrintWriter(System.out, true);

	//	FileInputStream fin=new FileInputStream("C:/Users/4dm1n/Desktop/A-large(1).in");
	//	File myfile=new File("C:/Users/4dm1n/Desktop/A.out");
		
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
	//	RandomAccessFile rand=new RandomAccessFile(myfile,"rw");
		
		int t,n,j,l,i,c,r,tt;
		long nm;
		char ch[];
		String s;
		StringBuilder sb;
		t=Integer.parseInt(br.readLine());
		for(tt=1;tt<=t;tt++){
			sb=new StringBuilder("Case #"+tt+": ");
			s="";
			ch=br.readLine().toCharArray();l=ch.length;
			s=s+ch[0];
			for(i=1;i<l;i++){
				if(s.charAt(0)<=ch[i]) s=ch[i]+s;
				else s+=ch[i];
			}
			sb.append(s+"\n");
		//	rand.writeBytes(sb.toString());
			System.out.print(sb);
		}
	}
}