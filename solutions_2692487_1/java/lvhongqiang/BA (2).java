package test;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Iterator;
import java.util.List;
import java.util.concurrent.locks.Condition;

import javax.management.MXBean;

public class BA {

	private static File fileIn=new File("E:/B/A-large.in");
	private static File fileOut=new File("E:/B/A-large.out");
	private static BufferedReader bReader;
	private static FileWriter bWriter;
	/**
	 * @param args
	 */
	public static void main(String[] args) {
		Integer N=0;
		try {
			bReader=new BufferedReader(new FileReader(fileIn)); 
			bWriter=new FileWriter(fileOut);
			String A = bReader.readLine();
			N=Integer.parseInt(A);
			for(int n=1;n<N+1;n++){
				List<Integer>list=s2i(bReader.readLine());
				Integer now=list.get(0);
				Integer count=list.get(1);
				List<Integer>motes=s2i(bReader.readLine());
				Collections.sort(motes);
				System.out.println(motes);
				bWriter.write("Case #"+n+": "+solu(now, motes)+"\r\n");
			}
			bWriter.close();
			bReader.close();
		} catch (Exception e) {
			System.out.println(e);
		}
		System.out.println("finished");
	}
	public static int solu(Integer now,List<Integer>motes){
		if(now<2)return motes.size();
		int r=0;
		for (int i = 0; i < motes.size(); i++) {
			if(now<=motes.get(i)){
				int steps=0;
				while (now<=motes.get(i)) {
					now=now+(now-1);
					steps++;
				}
				int s=steps+solu(now, motes.subList(i, motes.size()));
				if(s<motes.size()-i)
					r= s;
				else {
					r= motes.size()-i;
				}
			break;
			}
			now+=motes.get(i);
		}
		return r;
		
	}
	public static int steps(Integer a,int b){
		int r=0;
		while (a<=b) {
			a=a+(a-1);
			r++;
		}
		return r;
	}
	
	public static List<Integer> s2i(String string) {
		List<Integer> r = new ArrayList<Integer>();
		for (String s : string.split(" ")) {
			r.add(Integer.parseInt(s));
		}
		return r;
	}
	
}
