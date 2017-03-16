package round_1c;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Scanner;

public class Q1 {

	static char s[];
	static String find(char s[], int n)
	{
	    int i;
	    int len = s.length;
	    int a[]=new int[len];
	    int count=0,sum=0,j,max=0;
	    for(i=0;i<len;i++)
	    {
	        if(s[i]!='a' && s[i]!= 'e' && s[i] !='i' && s[i]!='o' && s[i]!='u')
	        {
	            a[i] = 1;
	        }
	        else
	        {
	            a[i]  = 0;
	        }
	    }
	    for(i=0;i<len;i++)
	    {
	        max = count = 0;
	        for(j=i;j<len;j++)
	        {
	            if(a[j] == 1)
	            count++;
	            else
	            count =0;
	            if(count>max)
	            max = count;
	            if(max>=n)
	            sum++;
	        }
	    }
	    //System.out.println(sum);
	    return sum+"";
	}

	public static void main(String[] args) throws IOException {
		int n;
		FileReader buf = new FileReader("C:\\Users\\bond\\Desktop\\input.in");
		BufferedReader br = new BufferedReader(buf);
		//BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int cases=Integer.parseInt(br.readLine());
	    String[] outputs=new String[cases];
	    for(int i=1;i<=cases;i++)
	    {
	    	String s1="";
	    	String[] inp=br.readLine().split(" ");
	    	s1=inp[0];
	    	n=Integer.parseInt(inp[1]);
	        s=s1.toCharArray();
	        outputs[i-1]="Case #" + i + ": " + find(s,n)+ "\n";
	    }
	    br.close();
		buf.close();
		FileWriter buf1 = new FileWriter(new File("C:\\Users\\bond\\Desktop\\OutputDance1.txt"), true);
		BufferedWriter bw1 = new BufferedWriter(buf1);
		for (int i = 0; i < cases; i++) {
			bw1.write(outputs[i]);
		}
		bw1.close();
		buf1.close();
	    /*for(int i=0;i<cases;i++){
	    	System.out.println(outputs[i]);
	    }*/

	}

}




