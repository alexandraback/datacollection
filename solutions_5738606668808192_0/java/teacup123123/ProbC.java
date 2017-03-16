package codejam;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;

public class ProbC extends Prob{

	public static void main(String[] args) {
		ProbC pb= new ProbC();
		pb.fromFile("C:\\Users\\user\\Downloads\\test.in");
	}

	@Override
	public void load(BufferedReader br,BufferedWriter bw) {
		try{
			int T=Integer.parseInt(br.readLine());
			for(int i=0;i<T;i++)
			{
				int N,J,got=0;
//				N=Integer.parseInt(br.readLine());
				N=16;//2~10;
				J=50;
				//2 3 4 5 6 7 8 9 0
				//3 4
//				J=Integer.parseInt(br.readLine());
				//base 2
				bw.write("Case #"+(i+1)+":");bw.newLine();
				for(int j=0;j<Math.min(J, 32);j++)
				{
					String midRight=Integer.toBinaryString(j);
					midRight=new String(new char[7-midRight.length()]).replaceAll("\0", "0")+midRight;
					String midLeft=new StringBuilder(midRight).reverse().toString();
					String str="1"+midLeft+midRight+"1";
					bw.write(str);
					for(int base=2;base<=10;base++)
					{
//						int num=Integer.parseInt(str,base);
//						if(num%(base+1)!=0)
//							throw new Error();
						int dividend=(base+1);
						bw.write(" "+dividend);
					}
					bw.newLine();
					got++;
				}
				for(int j=1;j<19;j++)
				{
					String midRight=Integer.toBinaryString(j);
					midRight=new String(new char[7-midRight.length()]).replaceAll("\0", "0")+midRight;
					String midLeft=new StringBuilder(midRight).reverse().toString();
					midLeft=midLeft.substring(5, 7)+midLeft.substring(0, 5);
					String str="1"+midLeft+midRight+"1";
					bw.write(str);
					for(int base=2;base<=10;base++)
					{
						int dividend=(base+1);
						bw.write(" "+dividend);
					}
					bw.newLine();
					got++;
				}
			}
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
}
