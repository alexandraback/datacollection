package qualification;

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;

public class TicTacToeTomek {
	public static char[][] getInput(BufferedReader br) throws IOException{
		char [][]a=new char[4][4];
		String s;
		for(int i=0;i<4;i++) {
			s=br.readLine();
			for(int j=0;j<4;j++) {
				a[i][j]=s.charAt(j);
			}
		}
		br.readLine();
		return a;
	}
	public static void display(char [][]a) {
		for(int i=0;i<4;i++) {
			for(int j=0;j<4;j++) {
				System.out.print(a[i][j]+" ");
			}
			System.out.println();
		}
	}
	public static String getStatus(char [][]a) {
		String status;
		if(check(a,'X')) {
			status="X won";
		} else if(check(a,'O')) {
			status="O won";
		} else if (isFull(a)) {
			status="Draw";
		} else {
			status="Game has not completed";
		}
		return status;
	}
	public static boolean isFull(char [][]a) {
		int i,j;
		for(i=0;i<4;i++) {
			for(j=0;j<4;j++) {
				if(a[i][j]=='.') {
					return false;
				}
			}
		}
		return true;
	}
	public static boolean check(char [][]a,char ch) {
		//For row
		int i,j;
		boolean flag=true;
		for(i=0;i<4;i++) {
			flag=true;
			for(j=0;j<4;j++) {
				if(a[i][j]!=ch && a[i][j]!='T') {
					flag=false;
				}
			}
			if(flag) return true;
		}	
		//For column
		for(i=0;i<4;i++) {
			flag=true;
			for(j=0;j<4;j++) {
				if(a[j][i]!=ch && a[j][i]!='T') {
					flag=false;
				}
			}
			if(flag) return true;
		}
		//For left diagonal
		flag=true;
		for(i=0;i<4;i++) {
			if(a[i][i]!=ch && a[i][i]!='T') {
				flag=false;
			}
		}
		if(flag) return true;
		//For right diagonal
		flag=true;
		for(i=0;i<4;i++) 	{
			j=3-i;
			if(a[i][j]!=ch && a[i][j]!='T') {
				flag=false;
			}
		}
		if(flag) return true;
		return false;
	}
	public static void main(String args[]) throws IOException {
		FileInputStream fis=new FileInputStream("C:/users/baqiral/Desktop/baqir.txt");
		BufferedReader br=new BufferedReader(new InputStreamReader(fis));
		int test=Integer.valueOf(br.readLine());
		int tester=1;
		char [][]a=new char[4][4];
		while(tester<=test) {
			a=getInput(br);
			String status=getStatus(a);
			System.out.println("Case #"+tester+": "+status);
			tester++;
		}
	}
}