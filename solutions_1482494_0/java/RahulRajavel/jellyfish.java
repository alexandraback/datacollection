import static java.lang.System.*;
import java.util.*;
import java.io.*;
public class jellyfish {
	public static void one(Scanner keyb)throws IOException{
		
	}
public static void two(Scanner keyb)throws IOException{
		int a=(keyb.nextInt());
		ArrayList<int[]>t=new ArrayList<int[]>();
		ArrayList b[]=new ArrayList[2002];
		ArrayList c[]=new ArrayList[2002];
		int p[]=new int[1001];
		int q[]=new int[1001];
		for(int x=0;x<=2001;x++){
			b[x]=new ArrayList<Integer>();
			c[x]=new ArrayList<Integer>();
		}
		for(int x=1;x<=a;x++){
			int g=keyb.nextInt();
			int h=keyb.nextInt();
			c[h].add(x);
			b[g].add(x);
			p[x]=g;
			q[x]=h;
		}
		keyb.nextLine();
		int s=0;
		int k=1;
		int l=0;
		while(k==1){
			k=-1;
			l++;
			int w=00;
			for(int x=0;x<=s;x++)
			{
				for(int y=0;y<c[x].size();x++){
					int i=(Integer)c[x].remove(y);
					if(p[i]<0)
						s+=1;
					else{
						s+=2;
					}
					p[i]=-1;
					k=1;w=1;
					break;
				}
				if(w==1)break;
			}if(w==1)continue;
			
			int z=-1;
			int u=-1;
			int v=-1;
		
			for(int x=0;x<=s;x++){
				for(int y=0;y<b[x].size();y++){
					
					if(p[(Integer)b[x].get(y)]>=0&&(q[(Integer)b[x].get(y)]>z||z==-1)){
						z=q[(Integer)b[x].get(y)];
						u=y;
						v=x;
				
					}
				}
			}
			if(u>=0){
				p[(Integer)b[v].get(u)]=-1;
				k=1;
				s+=1;
			}

		}
		int cd=0;
		for(int x=1;x<=2001;x++){
			if(c[x].size()==0)cd++;
		}
	if(cd==2001){
			out.println(l-1);
		}else{
			out.println("Too Bad");
		}	
		}
public static void three(Scanner keyb)throws IOException{
	
}

	public static void main(String []args)throws IOException{
		Scanner keyb=new Scanner(new File("B-small-attempt1.in"));
		int a=(keyb.nextInt());
		for(int x=1;x<=a;x++){
			out.print("Case #"+x+": ");
			two(keyb);
		}		
	}
}
