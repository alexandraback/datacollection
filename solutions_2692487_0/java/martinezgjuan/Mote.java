import java.util.ArrayList;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Scanner;


public class Mote {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		int cases = sc.nextInt();
		
		for(int c = 0; c<cases; c++){
			
			int a = sc.nextInt();
			int n = sc.nextInt();
			
			int[] motes = new int[n];
			for(int i =0; i<n; i++){
				motes[i]= sc.nextInt();
			}
			
			if(a==1){
				System.out.printf("Case #%d: %d\n",(c+1),n);
				continue;
			}
				
			Arrays.sort(motes);
			
			LinkedList<Integer> left = new LinkedList<Integer>();
			
			for(int i =0; i<n; i++){
				if(motes[i]<a){
					a+= motes[i];
				} else {
					left.add(motes[i]);
				}
			}
			
			int count = 0;
			
			while(left.size() > 0){
				if(left.getFirst()<a){
					a+=left.getFirst();
					left.removeFirst();
				} else if(left.getFirst()<2*a-1){
					count++;
					a= 2*a -1;					
				} else {
					
					int times = 1;
					int aux = 2*a-1;
					
					boolean done = false;
					
					LinkedList<Integer> act = new LinkedList<Integer>();
					
					for(int x : left) {

						int added = 0;
						for(int z : act){
							if(z<aux){
								aux+=z;
								added++;
							} else {
								break;
							}
						}
						
						for(int i = 0; i< added; i++){
							act.removeFirst();
						}
						
						if(x < aux){
							count+= times;
							
							for(int i = 0; i< added; i++){
								left.removeFirst();
							}
							a = aux;
							done = true;
							break;
						} else {
							aux = 2*aux-1;
							act.add(x);
							times++;
						}
					}
					
					if(done) continue;
					count += left.size();
					break;
				}
			}				
						
			System.out.printf("Case #%d: %d\n",(c+1),count);
		}

	}

}
