package solve;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class pancake {

	public static int countpancake(String a) {
		// TODO Auto-generated constructor stub
		int i=0;
		int count=0;
		char temp=a.charAt(0);
		for(i=1;i<a.length();i++)
		{
			if(a.charAt(i)==temp)
				continue;
			else
			{
				count++;
				temp=a.charAt(i);
			}
		}
		if(temp=='-')
			count++;
		return count;
	}
	public static void main(String[] args) throws IOException {
		Scanner scanner = new Scanner(new File("B-small-attempt0.in"));
		//int [] tall = new int [100];
		int total =Integer.parseInt( scanner.nextLine());
		System.out.println(total);
		FileWriter fw = new FileWriter("out.txt");
		for(int i=0;i<total;i++){	
		   String a = scanner.nextLine();
		   int n=countpancake(a);
		   System.out.println(n);		   
		   fw.write("Case #"+(i+1)+": "+n+"\n");	  
		}
        fw.close();
		
	}
}
