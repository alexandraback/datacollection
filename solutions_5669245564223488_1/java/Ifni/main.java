import java.io.File;
import java.io.FileNotFoundException;
import java.text.DecimalFormat;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.HashMap;
import java.util.List;
import java.util.Scanner;
import java.util.regex.Pattern;


public class main {
	
	 static public void publishResult(long s, int N){
		 System.out.print("Case #"+N+": "+s);
		 System.out.println(); 
	 }
	 
	 static public boolean checkQ(long Q){
		 for(int i=0; i<41; i++){
			 if(Q== Math.pow(2, i))
				 return true;
			 }
		 return false;
		 }
	 
	 static public long factorial(int n){
		 long result=1;
		 for (int i=1; i<=n; i++)
			 result=result*i %1000000007;
		 return result;
	 }
	
	 static public boolean checkallfinished(int[] used){
		 for(int i=0; i<26; i++){
			 if(used[i]==-1)
				 return false;
		 }
		 return true;
	 }
	 
	 static public int checkCars(String[] cars, int[] used){
		 int[] tempused;
		 int current;
		 boolean changedsense;
		 boolean haschanged;
		 tempused=used.clone();
		 for(int i=0; i<cars.length; i++){
			 changedsense=false;
			 haschanged=false;
			 if(cars[i].length()>2){
				 for(int j=1; j<cars[i].length()-1; j++){
					 current=cars[i].charAt(j);
					 if(tempused[current-97]==0){
						 tempused[current-97]=-1;
						 haschanged=true;
					 }
					 else if(!changedsense && current==cars[i].charAt(j-1))
						 changedsense=false;
					 else if(!changedsense && current!=cars[i].charAt(j-1) && current==cars[i].charAt(j+1))
						 changedsense=true;
					 else if(changedsense &&  current==cars[i].charAt(j+1))
						 changedsense=true;
					 else
						 return 0;
				 }
			 }
			 if(haschanged && cars[i].charAt(0)==cars[i].charAt(cars[i].length()-1))
				 return 0;
		 }
		 return 1;
	 }
	 
	public static void main(String[] args) throws FileNotFoundException {
		//Scanner sc = new Scanner(System.in);
		Scanner sc = new Scanner( new File("/home/loic/workspace/CodeJam1/src/input.txt"));
		//Scanner res = new Scanner( new File("/home/workspace/CodeJam1/bin/Result.txt"));
		int T = sc.nextInt(); int N;String[] cars;
		int[] used; int current; int[] number; boolean[] independent;
		int[] starting, depending, joker; int component;
		int[] who;
		long result; boolean allfinished;
		for(int z = 0; z<T; z++){
			N=sc.nextInt();
			cars= new String[N]; used=new int[26];
			number=new int[26]; starting=new int[26];
			depending=new int[26]; joker=new int[26];
			who=new int[26];
			result=1; component=0;
			allfinished=false;
			for(int i=0; i<N; i++){
				cars[i]=sc.next();
			}
			for(int i=0; i<26; i++){
				used[i]=-1;
				for (int j=0; j<N; j++){
					if(cars[j].charAt(0)==97+i && cars[j].charAt(cars[j].length()-1)==97+i){
						joker[i]++;
					}
					else if(cars[j].charAt(0)==97+i){
						starting[i]++;
						who[i]=cars[j].charAt(cars[j].length()-1)-97;
					}
					else if(cars[j].charAt(cars[j].length()-1)==97+i){
						depending[i]++;
					}
				}
				if(depending[i]>1||starting[i]>1){
					result=0;}
				if(depending[i]==0 && starting[i]==0 && joker[i]==0)
					used[i]=0;
			}
			
			if(result==0)
				publishResult(0,z+1);
			else if(checkCars(cars, used)==0)
				publishResult(0,z+1);
			else{
				current=0;
				while(!allfinished){
					for (int i=0; i<26; i++){
						current=i+1;
						if(used[i]==-1 && depending[i]==0){
							current=i;
							used[current]=0;
							component++;
							break;						
						}
					}
					if(current==26){
						result=0;
						break;
					}
					result*=factorial(joker[current])%1000000007;
					while(starting[current]!=0){
						current=who[current];
						used[current]=0;
						result*=factorial(joker[current])%1000000007;
					}
					allfinished=checkallfinished(used);
				}
				publishResult(result*factorial(component) %1000000007, z+1);
			}
				
			/*for(int i=0; i<26; i++){
				starting=0; depending=0; joker=0;
				for (int j=0; j<N; j++){
					if(cars[j].charAt(0)==97+i && cars[j].charAt(cars[j].length())==97+i){
						joker++;
					}
					else if(cars[j].charAt(0)==97+i){
						starting++;
					}
					else if(cars[j].charAt(cars[j].length())==97+i){
						depending++;
					}
				}
				if(depending>1||starting>1){
					publishResult(0, z+1);
					break;
				}
				else if(depending==1){
					result*
				}*/
			//publishResult(result, z+1);
			
		}
	}
}
