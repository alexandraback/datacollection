package CD;

import java.io.BufferedInputStream;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.DataInputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.sql.SQLException;
import java.util.Hashtable;

public class RC{
	private int first;
	private int second;
	public RC(int i,int i_s){
		this.first=i;
		this.second=i_s;
	}
	public static  int dist(int mi,int mx){
		Hashtable numbers = new Hashtable();
		if (mx<10){
			return 0;
		}
		for(int i=mi;i<=mx;i++){
			String s=Integer.toString(i);
			for(int e=s.length()-1;e>0;e--){
				String new_s=s.substring(e, s.length())+s.substring(0, e);
				int i_s=Integer.parseInt(new_s);
				if (i_s<=mx && i_s!=i && i_s>=mi){
					String c=Integer.toString(i_s)+Integer.toString(i);
					String b=Integer.toString(i)+Integer.toString(i_s);
					if (!(has(numbers,c)) && !(has(numbers,b))){
						numbers.put(c, 0);
					}
				}
			}
		}
		return numbers.size();
	}
	public static  boolean has(Hashtable numbers,String c){
			if (numbers.get(c)==null){
				return false;
			}
			return true;
	}
	public static void main(String[] args) throws IOException{
		int a=dist(1111,3333);
		System.out.println(Integer.toString(a));
	}
}