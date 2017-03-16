package Round1C2016;

import java.util.*;
import java.io.*;


public class C {
	
	static int best=0;
	static int j=0;
	static int p=0;
	static int s=0;
	static int k=0;
	static int [][][] sol;
	static String solut="";
	public static String newline = System.getProperty("line.separator");
	
	
	public static void main(String [] args) throws IOException{
		
		
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		for(int i=0;i<t;i++){
			best=0;
			int top = i+1;
			j= sc.nextInt();
			p= sc.nextInt();
			s= sc.nextInt();
			k= sc.nextInt();
			
			solut="";
			
			int [][][] count= new int [j][p][s];
			
			int [][] count12= new int [j][p];
			int [][] count23= new int [p][s];
			int [][] count13= new int [j][s];
 			
			search(count, count12,count23,count13,0,-1,"");
		
			System.out.print("Case #"+top+": "+best);
			System.out.print(solut);
			System.out.println();
			/*for(int m=0;m<k;m++){
				for(int a=0;a<j;a++){
					for(int b=0;b<p;b++){
						for(int c=0;c<s;c++){
						if(sol[a][b][c]>0){
							int tp1=a+1;
							int tp2=b+1;
							int tp3=c+1;
							System.out.println(tp1+" "+tp2+" "+tp3);
							sol[a][b][c]-=1;
						}
							
						}
					}
				}
			}*/
		}
		
	}
	
	public static void search(int [][][] count, int [][] count12, int [][] count23 ,int [][] count13, int counter, int last, String so){
		for(int a=0;a<j;a++){
			for(int b=0;b<p;b++){
				for(int c=0;c<s;c++){
					if(count12[a][b]<k && count23 [b][c]<k && count13[a][c]<k && a*100+b*10+c != last){
						int [][]count12b=count12.clone();
						int [][]count23b=count23.clone();
						int [][]count13b=count13.clone();
						count12b[a][b]+=1;
						count23b[b][c]+=1;
						count13b[a][c]+=1;
						count[a][b][c]+=1;
						int tp1=a+1;
						int tp2=b+1;
						int tp3=c+1;
						so+=newline+tp1+" "+tp2+" "+tp3;
						
						search(count,count12b, count23b, count13b,counter+1,a*100+b*10+c,so);
						//System.out.println(a+""+b+""+c);
					}
				}	
			}
		}
		if(counter>best){
			best=counter;
			sol=count.clone();
			solut=so;
		}
	}

}
