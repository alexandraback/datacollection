/*
 * @author Mingxuan Zha
 * @date April 2016, created
 */

import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.*;

import javax.swing.JFileChooser;
public class R1ProblemC {
	
	public static int last;
	public static ArrayList<Integer> list = new ArrayList<>();
	
	public static void main (String[] args)throws Exception{
		JFileChooser ourChooser = new JFileChooser(".");
		int retval = ourChooser.showOpenDialog(null);
	    if (retval == JFileChooser.APPROVE_OPTION) {
	        File file = ourChooser.getSelectedFile();
	        Scanner input = new Scanner(file);
	        int testSize = Integer.parseInt(input.nextLine());
	        for(int i=0; i<testSize; i++){
	        	String s0 = input.nextLine();
	        	int num = Integer.parseInt(s0);
	        	String s = input.nextLine();
	        	System.out.println("Case #"+(i+1)+": "+getResult(num, s));
	        }
	    }
	}
	
	public static int getResult(int num, String s){
		String[] bffs = s.split(" ");
		int[] bff = new int[num];
		for(int i=0; i<num; i++){
			bff[i] = Integer.parseInt(bffs[i])-1;
		}
		int result = 0;
		for(int i=0; i<num; i++){
			list.clear();
			boolean[] check = new boolean[num];
			boolean[] temp = countTotal(i, bff, check);
		    int comp = 0;
			boolean flag = true;
			for(int j=0; j<num; j++){
				int x = last;
				if((!temp[j]) && (temp[bff[j]]) && (flag) && (bff[j]==last) && (bff[bff[bff[j]]] == bff[j])){
//					(bff[bff[bff[j]]] == bff[j])
					//check that temp[j]'s bff is not both occupied
//					int cond = 0;
//					if((temp[bff[bff[j]]]) && (bff[bff[j]] != j)){
//						cond = 1;
//					}
//					for(int k=0; k<num; k++){
//						if((k!=j) && (temp[k]) && (bff[k] == bff[j])){
//							cond++;
//						}
//					}
					
//					int cond = 0;
//					if(temp[bff[bff[j]]]){
//						cond = 1;
//					}
//					for(int k=0; k<num; k++){
//						if(temp[k] && (bff[k] == bff[j])){
//							cond++;
//						}
//					}
//					if(cond < 2){
					comp = comp + 1;
					flag = false;
//					}
				}
				if(temp[j]){
					comp = comp + 1;
				}
			}
			result = Math.max(result, comp);
		}
		return result;
	}
	
	public static boolean[] countTotal(int i, int[] bff, boolean[] check){
		if(check[i]){//already added in the group
			if((list.get(0) == i) || (list.get(list.size()-2) == i)){
				return check;
			}
			int count = 0;
			while(list.get(count) != i){
				count++;
			}
			boolean[] newCheck = new boolean[check.length];
			while(count<list.size()){
				newCheck[list.get(count)] = true;
				count++;
			}
			return newCheck;
		}
		check[i] = true;
		list.add(i);
		last = i;
		int index = bff[i];
		return countTotal(index, bff, check);
	}
}
