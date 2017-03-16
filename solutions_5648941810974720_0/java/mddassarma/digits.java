import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOError;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Comparator;

public class digits {
	public static String solve(String str){
		/* code for sorting string copied from online (Boann '13) */
		int[] arr=new int[100];
		for (int i = 0; i < str.length(); i++)
		    arr[str.charAt(i)]++;
		int[] n=new int[10];
		n[0]=arr['Z'];
		arr['Z']=0; arr['E']-=n[0];arr['R']-=n[0];arr['O']-=n[0];
		n[2]=arr['W'];
		arr['W']=0; arr['T']-=n[2]; arr['O']-=n[2];
		n[4]=arr['U'];
		arr['U']=0; arr['F']-=n[4]; arr['O']-=n[4]; arr['R']-=n[4];
		n[3]=arr['R'];
		arr['T']-=n[3]; arr['H']-=n[3];arr['R']=0;arr['E']-=2*n[3];
		n[5]=arr['F'];
		arr['F']=0;arr['I']-=n[5];arr['V']-=n[5];arr['E']-=n[5];
		n[6]=arr['X'];
		arr['X']=0;arr['I']-=n[6];arr['S']-=n[6];
		n[7]=arr['V'];
		arr['V']=0;arr['S']-=n[7];arr['N']-=n[7];arr['E']-=2*n[7];
		n[8]=arr['G'];
		n[9]=arr['I']-n[8];
		n[1]=arr['O'];
		StringBuilder sb=new StringBuilder();
		for(int i=0;i<10;i++){
			for(int j=0;j<n[i];j++)
				sb.append(i+"");
		}
		return sb.toString();
		
		
		
	}
	public static void main(String[] args) throws IOException{
		BufferedReader buf=new BufferedReader(new FileReader("digit.in"));
		PrintWriter printer=new PrintWriter("digit.out");
		int N=Integer.parseInt(buf.readLine());
		for(int i=1;i<=N;i++){
			printer.println("Case #"+i+": "+solve(buf.readLine()));
		}
		printer.close();
		
	}

}
