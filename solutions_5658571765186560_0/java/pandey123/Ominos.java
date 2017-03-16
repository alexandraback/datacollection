import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;


public class Ominos{
	public static int min(int a,int b){
		if(a>b)
			return b;
		else 
			return a;
	}
	public static int max(int a,int b){
		if(a>b)
			return a;
		else 
			return b;
	}
public static void main(String args[]){
		
		try {
			BufferedReader br = new BufferedReader(new FileReader("input0.in"));
			BufferedWriter bw = new BufferedWriter(new FileWriter("out.txt"));
			int test = Integer.parseInt(br.readLine());
			int testcase= 1;
			while(test>= testcase)
			{
				String r[]= br.readLine().split(" ");
				int x = Integer.parseInt(r[0]);
				int row = Integer.parseInt(r[1]);
				int col = Integer.parseInt(r[2]);
				
				boolean flag = true;
				if(x>=7){
					flag =false;
				}
				else if(x>row & x>col){
					flag = false;
				}
				else if((row*col %x) !=0){
					flag = false;
				}
				else if((x+1)/2 > min(row,col)){
					flag = false;
				}
				else if (x ==1 || x==2 || x==3){
					flag = true;
				}
				else if(x ==4){
					flag = min(row,col)>2;
				}
				else if(x ==5){
					flag = !(min(row, col) == 3 && max(row, col) == 5);
				}
				else if(x ==6){
					flag = min(row, col) > 3;
				}
				
				if(flag){
					System.out.println("Case #"+testcase+": GABRIEL");
					bw.write("Case #"+testcase+": GABRIEL");
				}
				else{
					System.out.println("Case #"+testcase+": RICHARD");
					bw.write("Case #"+testcase+": RICHARD");
				}
				testcase++;
				if(testcase<=test){
					bw.write("\n");
				}
			}
			bw.close();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

}