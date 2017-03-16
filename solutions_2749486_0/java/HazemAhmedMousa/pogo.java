import java.io.File;
import java.io.FileNotFoundException;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;


public class pogo {

	
	public static void main(String[] args) throws FileNotFoundException {
		int max = 201;
		int halfmax = 100;
		
		boolean check  [][]= new boolean [max][max];
		Scanner s = new Scanner (new File("B-small-attempt0.in"));
		int t,i,x,y,j;
		int currx,curry;
		int dx [] = new int []{0 , 1, 0 , -1};
		int dy [] = new int []{1 , 0, -1 , 0};
		char dir[] = new char []{'N','E','S','W'}; 
		i = 0;
		int k = 0;
		t = s.nextInt();
		String p;
		p = "";
		
		int tempx,tempy;
		Queue<Integer> q = new LinkedList<Integer>();
		Queue<String> qs = new LinkedList<String>();
		while(t--!=0)
		{
			for(k = 0 ; k < max;++k)
				Arrays.fill(check[k],false);
			
			q.clear();
			qs.clear();
			x =  s.nextInt();
			y = s.nextInt();
			check[100][100] = true;
			q.add(0);
			q.add(0);
			q.add(0);
			qs.add("");
			while(!q.isEmpty())
			{
				currx = q.poll();
				curry = q.poll();
				j = q.poll()+1;
				p = qs.poll();
				
				if(currx==x && curry == y)
					break;
				
				for(k = 0 ; k < 4 ;++k)
				{			
					tempx = currx+j*dx[k];
					tempy = curry+j*dy[k];
					if(tempx<=halfmax&&tempy<=halfmax&&tempy>=-halfmax&&tempx>=-halfmax&&!check[tempx+halfmax][tempy+halfmax])
					{
						check[tempx+halfmax][tempy+halfmax] = true;
						q.add(tempx);
						q.add(tempy);
						q.add(j);
						qs.add(p+dir[k]);
					}
				}
				
				
				
			}
			System.out.println("Case #"+(++i)+": "+p);
			
		}
		s.close();	
		
		
	} 
	
	
	
}
