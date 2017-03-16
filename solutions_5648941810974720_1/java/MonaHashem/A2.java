import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;


public class A2 {
	public static void main(String[] args) throws IOException {
		BufferedReader bf= new BufferedReader(new FileReader("A-large.in"));
		int t= Integer.parseInt(bf.readLine());
		PrintWriter out= new PrintWriter(new FileWriter("SmallA.txt"));
		for(int c=1; c<=t; c++){
			String s= bf.readLine();
			out.printf("Case #%d: ",c );
			int lett[]= new int [26];
			int r[]= new int [10];
			int len= s.length();
			for(int i=0; i<len; i++)
				lett[s.charAt(i)-'A']++;
			String real[]= {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
			int zero=lett['Z'-'A'];
			r[0]=zero;
			for(int k=0; k<4; k++)
				lett[real[0].charAt(k)-'A']-=zero;
			
			int two=lett['W'-'A'];
			r[2]=two;
			for(int k=0; k<3; k++)
				lett[real[2].charAt(k)-'A']-=two;
				
			int four=lett['U'-'A'];
			r[4]=four;
			for(int k=0; k<4; k++)
				lett[real[4].charAt(k)-'A']-=four;
			
			int six=lett['X'-'A'];
			r[6]=six;
			for(int k=0; k<3; k++)
				lett[real[6].charAt(k)-'A']-=six;
			
			int eight=lett['G'-'A'];
			r[8]=eight;
			for(int k=0; k<5; k++)
				lett[real[8].charAt(k)-'A']-=eight;
			
			for(int i=0; i<=9; i++){
				len= real[i].length();
				int max=2000;
				for(int j=0; j<len; j++){
					max= Math.min(max, lett[real[i].charAt(j)-'A']);
				}
				if(max>0){
					for(int j=0; j<max; j++)
						r[i]++;
					for(int j=0; j<len; j++){
						lett[real[i].charAt(j)-'A']-=max;
					}
				}
			}
			for(int i=0; i<10; i++)
				for(int j=0; j<r[i];j++)
					out.print(i);
			out.println();
		}
		out.flush();
		out.close();
		
	}

}
