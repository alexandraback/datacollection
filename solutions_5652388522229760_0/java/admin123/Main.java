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
	public static void main(String[] args) throws Exception {
		PrintWriter pr = new PrintWriter(System.out, true);

	//	FileInputStream fin=new FileInputStream("C:/Users/4dm1n/Desktop/A-small-attempt0.in");
	//	File myfile=new File("C:/Users/4dm1n/Desktop/A.out");
		
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
	//	RandomAccessFile rand=new RandomAccessFile(myfile,"rw");
		
		int t,n,num,m,tt,i,r,j,digit[],count;
		String sb[];
		StringBuilder s;
		t=Integer.parseInt(br.readLine());
		for(tt=1;tt<=t;tt++){
			n=Integer.parseInt(br.readLine());
			count=0;digit=new int[10];num=0;s=new StringBuilder("");
			s.append("Case #"+tt+": ");
			if(n==0){
				s.append("INSOMNIA");
			}
			else{
				while(count<10){
					num+=n;m=num;
					while(m>0){
						r=m%10;m/=10;
						if(digit[r]==0){
							digit[r]=1;count++;
						}
					}
				}
				s.append(num);
			}
			s.append("\n");
		//	rand.writeBytes(s.toString());
			System.out.print(s);
		}
	}
}