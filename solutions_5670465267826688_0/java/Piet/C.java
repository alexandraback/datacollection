package problems;

import java.io.IOException;
import java.io.Writer;
import java.util.Scanner;

import codeBook.GCJProblem;
import codeBook.GCJProblemHandler;

/**
 * @author piet
 *
 *	GCJ: Qualification 2015 Problem C
 */
public class C implements GCJProblem{
	long L,X;
	char[] str;
	
	public static void main(String[] args) {
		new GCJProblemHandler("C-small-0", C.class).run();
	}

	@Override
	public void readTestcase(Scanner in) {
		L = in.nextInt();
		X = in.nextLong();
		str = in.next().toCharArray();
		if(str.length != L) System.out.println("error !!!!!!!!!!!!!!!!!!!!!!!!");
	}

	@Override
	public void solve(Writer out) throws IOException {	
		Quaternion q = new Quaternion();
		for(char c:str) q.multR(new Quaternion(c));
		if(!q.pow(X).equals(new Quaternion(1,true))){
			out.write(" NO");
			return;
		}
		
		q = new Quaternion();
		Quaternion i = new Quaternion(2,false);
		int iSubstrLength = 0;
		boolean foundISubstr = false;
		for(int num=0;!foundISubstr && num<4;num++)
			for(char c:str){
				q = q.multR(new Quaternion(c));
				iSubstrLength++;
				if(q.equals(i)){
					foundISubstr = true;
					break;
				}
			}
		if(!foundISubstr) { out.write(" NO"); return; }
		
		q = new Quaternion();
		Quaternion k = new Quaternion(4,false);
		int kSubstrLength = 0;
		boolean foundKSubstr = false;
		for(int num=0;!foundKSubstr && num<4;num++)
			for(int cnum=str.length-1;cnum >= 0;cnum--){
				q = q.multL(new Quaternion(str[cnum]));
				kSubstrLength++;
				if(q.equals(k)){
					foundKSubstr = true;
					break;
				}
			}
		if(!foundKSubstr) { out.write(" NO"); return; }
		
		if(iSubstrLength + kSubstrLength >= L * X) { out.write(" NO"); return; }
		
		out.write(" YES");
	}
}

class Quaternion{
	int value; // 1,i,j,k = 1,2,3,4
	boolean neg;
	
	public Quaternion(){value = 1;neg = false;}
	public Quaternion(char c){value = c - 103;neg = false;}
	public Quaternion(int value, boolean neg){
		this.value = value;
		this.neg = neg;
	}
	
	public Quaternion multR(Quaternion rhs){
		neg ^= rhs.neg;
		if(value == 1 || rhs.value == 1) value *= rhs.value; 
		else if(value == rhs.value) {value = 1; neg = !neg;}
		else {
			if((rhs.value - value +3)%3 != 1) neg = !neg;
			value = 9 - value - rhs.value;
		}
		return this;
	}
	
	public Quaternion multL(Quaternion lhs){ return lhs.multR(this); }
	
	public Quaternion pow(long exp){
		if(exp == 1) return this;
		if(exp % 4 == 0) return new Quaternion(1,false);
		return copy().multR(pow(exp-1));
	}
	
	public boolean equals(Quaternion q){return value == q.value && neg == q.neg;}
	
	public Quaternion copy(){ return new Quaternion(value, neg); }
	
	public String toString(){
		return (neg?"-":" ") + value;
	}
}
