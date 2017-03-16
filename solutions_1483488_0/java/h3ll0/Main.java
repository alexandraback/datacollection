import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Scanner;
import java.util.Stack;


public class Main {

	/**
	 * @param args
	 */
	static int recyclePair(int A, int B){
		int pairCount =0;
		HashSet<Integer> hs = new HashSet<Integer>();
		for(int x=A;x<B;x++){
			hs.clear();
			List<Integer> digits = getDigits(x);
			for(int i =1;i<digits.size();i++){
				int no = 0, k=i;
				for(int j= 0;j<digits.size();j++){
					no = no*10 + digits.get(k); k = (k+1)%digits.size();
				}
				if((x<no)&&(no<=B)&&(!hs.contains(no))){
					pairCount++;
					hs.add(no);
				}
			}
		}
		
		return pairCount;
	}
	
	
	
	
	static List<Integer> getDigits(int x){
		List<Integer> list = new ArrayList<Integer>();
		Stack<Integer> st = new Stack<Integer>();
		while(x>0){
			st.push(x - ((int)(x/10))*10);
			x /= 10;
		}
		
		
		while(!st.isEmpty()){
			list.add(st.pop());
		}
		return list;
	}
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = null;
		BufferedWriter bw = null;
		try{
			sc = new Scanner(new File("input.txt"));
			bw = new BufferedWriter(new FileWriter("gcj3a.txt"));
			int T = sc.nextInt();
			int A, B, x;
			for(int i=0;i<T;i++){
				A = sc.nextInt();
				B = sc.nextInt();
				bw.write("Case #"+(i+1)+": "+recyclePair(A, B));bw.newLine();
			}
		}catch(Exception e){}
		finally{
			try{
				sc.close();bw.close();
			}catch(Exception e){}
		}
		/*
		recyclePair(12345, 12345);
		System.out.println();
		System.out.println(getDigits(120980));
		*/
	}

}
