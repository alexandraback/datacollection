import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;
import java.util.Map.Entry;


public class C_1B {
	static int[] arr;
	
	public static void main(String[] args) throws Exception {
		Scanner in =new Scanner(System.in);
		int T=in.nextInt();
		for(int tt=1;tt<=T;tt++){
			int n=in.nextInt();
			arr=new int[n];
			for(int i=0;i<n;i++)arr[i]=in.nextInt();
			HashMap<Integer,ArrayList<Integer>> map=new HashMap<Integer, ArrayList<Integer>>();
			for(int i=1;i<(1<<n)-1;i++){
				int sum=0;
				for(int j=0;j<n;j++){
					if((i&(1<<j))==1<<j){
						sum+=arr[j];
					}
				}
				if(map.containsKey(sum)){
					map.get(sum).add(i);
				}else {
					ArrayList<Integer> list=new ArrayList<Integer>();
					list.add(i);
					map.put(sum, list);
				}
			}
			int s1=-1,s2=-1;
			loop:for(Entry<Integer,ArrayList<Integer>> e:map.entrySet()){
				ArrayList<Integer> list = e.getValue();
				for(int i=0;i<list.size();i++)for(int j=i+1;j<list.size();j++)if((list.get(i)&list.get(j))==0){
					s1=list.get(i);s2=list.get(j);
					break loop;
				}
			}
			System.out.println("Case #"+tt+":");
			if(s1==-1)System.out.println("Impossible");else{
				for(int j=0;j<n;j++){
					if((s1&(1<<j))==(1<<j))System.out.print(arr[j]+" ");
				}
				System.out.println();
				for(int j=0;j<n;j++){
					if((s2&(1<<j))==(1<<j))System.out.print(arr[j]+" ");
				}
				System.out.println();
			}
			
		}
	}
}
