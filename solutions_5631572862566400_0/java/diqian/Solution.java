
import java.util.*;

public class Solution {
	
	public static class Node{
		
		int id;
		Node f;
		boolean visited;
		Node(int a){
			id = a;
			visited = false;
		}
		void set(Node b){
			f = b;
		}
	}
	
	public static void main(String[] args){
		
		Scanner sc = new Scanner(System.in);
		
		
		int T = sc.nextInt();
		for(int i = 1; i<= T; i++){
			
			int num = sc.nextInt();
			Node[] arr = new Node[num+1];
			for(int j = 1; j <= num; j++){
				
				Node a,b;
				int best = sc.nextInt();
				//System.out.println("best of "+j + " is "+best);
				if(arr[j] == null){
					a = new Node(j);
					arr[j] = a;
				}else{
					a = arr[j];
				}
				if(arr[best]  == null){
					b = new Node(best);
					arr[best]  = b;
				}else{
					b = arr[best];
				}
				a.set(b);
			}
			
//			for(int j = 1; j < arr.length; j++ ){
//				Node ha = arr[j];
//				//System.out.println(j+" "+ha.f.id);
//			}
			
			int max = 0;
			for(int j = 1; j < arr.length; j++){
				
				Node a = arr[j];
//				System.out.println(a.id);
				Node temp = a.f;
				int size = arr.length-1;
				int m = 1;
				int count = 1;
				boolean flag = false;
				while(temp.id != a.id && m++ <= size+5){
//					System.out.print(temp.id+" ");
					Node lastNode = temp;
					
					
					if(temp.id == temp.f.f.id){
						flag = true;
						count+=3;
						break;
					}
					count++;
					temp = temp.f;
					
				}
				
				//System.out.println("size: "+size);
				
//				System.out.println("max: "+max+" count: "+count);
				if(count < size+2){
					if(flag == true && count == 4){
						count--;
						flag = false;
					}
					max = max < count ? count : max;
				}
			}
			
			
			System.out.println("Case #"+i+": "+max);
			
		}
		
		
		
		
	}
	
	
}
