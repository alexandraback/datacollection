import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.io.RandomAccessFile;
import java.util.InputMismatchException;

public class Main {
	
	static void swap(char ch[],int l){
		int i=0;
		char c;
		for(i=0;i<=l;i++) ch[i]=ch[i]=='+'?'-':'+';
		while(i<l){
			c=ch[i];ch[i]=ch[l];ch[l]=c;i++;l--;
		}
	}
	
	public static void main(String[] args) throws Exception {
		PrintWriter pr = new PrintWriter(System.out, true);

	//	FileInputStream fin=new FileInputStream("C:/Users/4dm1n/Desktop/B-large.in");
	//	File myfile=new File("C:/Users/4dm1n/Desktop/A.out");
		
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
	//	RandomAccessFile rand=new RandomAccessFile(myfile,"rw");
		
		int t,n,num,l,m,tt,i,r,j,digit[],count,f;
		char ch[];
		String sb[];
		StringBuilder s;
		t=Integer.parseInt(br.readLine());
		for(tt=1;tt<=t;tt++){
			ch=br.readLine().toCharArray();l=ch.length;s=new StringBuilder("");count=0;
			s.append("Case #"+tt+": ");
			for(i=l-1;i>=0;i--){
				if(ch[i]=='+') continue;
				for(j=0,f=0;j<i;j++){
					if(ch[j]=='-') break;
					ch[j]='-';f=1;
				}
				count+=f+1;
				swap(ch,i);
			}
			s.append(count+"\n");
		//	rand.writeBytes(s.toString());
			System.out.print(s);
		}
	}
}