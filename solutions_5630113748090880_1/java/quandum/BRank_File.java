import java.io.File;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class BRank_File {
	static Scanner reader;
	static PrintWriter outWrite;
	static int n,res[],m,a[][];
	static int c[]=new int[3000];
	static void process(){
		int i,j;
		Arrays.fill(c, 0);
		res=new int[n];
		for (i=0;i<m;i++)for (j=0;j<n;j++)
			c[a[i][j]]++;
		j=0;
		for (i=0;i<c.length;i++){
			if ((c[i]%2)==1){
				res[j]=i; j++;
			}
		}
	}
	public static void main(String[] args) throws Exception {
		reader=new Scanner(new File("B-large.in"));
		outWrite=new PrintWriter(new File("B-output.txt"));
		int nTest=reader.nextInt();
		int i,j;
		for (int test=1;test<=nTest;test++){
			n=reader.nextInt();
			m=(2*n)-1;
			a=new int[m][n];
			for (i=0;i<m;i++){
				for (j=0;j<n;j++) 
					a[i][j]=reader.nextInt();
			}
			if (test>1) outWrite.println();
			process();
			outWrite.print("Case #" + test+": ");
			for (j=0;j<res.length;j++){
				if (j>0) outWrite.print(" ");
				outWrite.print(res[j]);
			}
		}
		outWrite.close();

	}

}
