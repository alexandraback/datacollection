package qualification;

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Iterator;
import java.util.Map;
import java.util.TreeMap;

public class FairAndSquareLarge {
	static Map<Long,Integer> map=new TreeMap<Long,Integer>();
	static ArrayList<Long> al=new ArrayList<Long>();
	public static void process() {
		int i=0;
		long n=1,x=0;
		while(i<15000) {
			n=nextPalindrome(n);
			x=n*n;
			if(isPalindrome(x)) {
				map.put(x,1);
			}
			n++;
			i++;
		}
		for(long key:map.keySet()) {
			al.add(key);
		}
		Collections.sort(al);
	}
	public static boolean isPalindrome(long n) {
		String s=String.valueOf(n);
		StringBuffer sb=new StringBuffer(s);
		if(s.equals(sb.reverse().toString())) {
			return true;
		}
		return false;
	}
	public static long nextPalindrome(long n) {
		String number=String.valueOf(n);
		StringBuffer theNumber = new StringBuffer(number);
		int length = theNumber.length();
		int left, right, leftPos, rightPos;
		int offset, offsetPos;
		boolean offsetUpdated;
		String insert;
		for(int i = 0; i < length/2; i++){
			leftPos = i; 
			rightPos = (length-1) - i;
			offsetPos = rightPos -1; offsetUpdated = false;
			left = Integer.parseInt(String.valueOf(theNumber.charAt(leftPos)));
			right = Integer.parseInt(String.valueOf(theNumber.charAt(rightPos)));
			offset = Integer.parseInt(String.valueOf(theNumber.charAt(offsetPos)));
			if(left != right){
				if(right > left){
					right = left;
					insert = Integer.toString(right);
					theNumber.replace(rightPos, rightPos + 1, insert);
					offset++; if (offset == 10) offset = 0;
					insert = Integer.toString(offset);
					theNumber.replace(offsetPos, offsetPos + 1, insert);
					offsetUpdated = true;
					while (offset == 0 && offsetUpdated){ 
						offsetPos--;
						offset =Integer.parseInt(String.valueOf(theNumber.charAt(offsetPos)));
						offset++; if (offset == 10) offset = 0;
						insert = Integer.toString(offset);
						theNumber.replace(offsetPos, offsetPos + 1, insert);
					}
					left = Integer.parseInt(String.valueOf(theNumber.charAt(leftPos)));
					if (right != left){
						right = left;
						insert = Integer.toString(right);
						theNumber.replace(rightPos, rightPos + 1, insert);
					}
				} else {
					right = left;
				}
				insert = Integer.toString(right);
				theNumber.replace(rightPos, rightPos + 1, insert);           
			}
		}
		return Long.valueOf(theNumber.toString());
	}
	public static int getFreq(long n,int flag) {
		int freq=0;
		Iterator<Long> itr=al.iterator();
		if(flag==1) { 
			while(itr.hasNext()) {
				if(n>itr.next()) {
					freq++;
				} else {
					break;
				}
			}
		} else {
			while(itr.hasNext()) {
				if(n>=itr.next()) {
					freq++;
				} else {
					break;
				}
			}
		}
		return freq;
	}
	public static void main(String args[]) throws IOException {
		FileInputStream fis=new FileInputStream("C:/users/baqiral/Desktop/baqir.txt");
		BufferedReader br=new BufferedReader(new InputStreamReader(fis));
		FileOutputStream fos=new FileOutputStream("C:/users/baqiral/Desktop/baqir1.txt");
		process();
		int test=Integer.valueOf(br.readLine());
		int tester=1,pos;
		long a=0,b=0;
		while(tester<=test) {
			String s=br.readLine();
			pos=s.indexOf(" ");
			a=Long.valueOf(s.substring(0,pos));
			b=Long.valueOf(s.substring(pos+1));
			int count=getFreq(b,2)-getFreq(a,1);
			System.out.println("Case #"+tester+": "+count);
			String temp="Case #"+tester+": "+count+"\n";
			byte[] x=temp.getBytes();
			fos.write(x);
			temp="\n";
			x=temp.getBytes();
			fos.write(x);
			tester++;
		}
	}
}