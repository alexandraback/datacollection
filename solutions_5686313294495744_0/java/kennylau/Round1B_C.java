import java.util.ArrayList;
import java.util.Hashtable;
import java.util.Scanner;

public class Round1B_C {
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		for(int a=1;a<=T;a++){
			int N = sc.nextInt();
			ArrayList<String> list1 = new ArrayList<>();
			ArrayList<String> list2 = new ArrayList<>();
			Hashtable<Integer,Integer> count1 = new Hashtable<>();
			Hashtable<Integer,Integer> count2 = new Hashtable<>();
			for(int b=0;b<N;b++){
				String s1 = sc.next();
				String s2 = sc.next();
				list1.add(s1);
				list2.add(s2);
				int i1 = list1.indexOf(s1);
				int i2 = list2.indexOf(s2);
				if(count1.containsKey(i1)){
					count1.put(i1, count1.get(i1)+1);
				}else{
					count1.put(i1, 1);
				}
				if(count2.containsKey(i2)){
					count2.put(i2, count2.get(i2)+1);
				}else{
					count2.put(i2, 1);
				}
			}
			int count = 0;
			for(int b=0;b<N;b++){
				if((count1.get(list1.indexOf(list1.get(b)))>1)&&(count2.get(list2.indexOf(list2.get(b)))>1)) count++;
			}
			System.out.println("Case #"+a+": "+count);
		}
		sc.close();
	}
}