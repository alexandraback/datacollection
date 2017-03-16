import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Set;
import java.util.*;




public class DiamondInheritance {

	public void solves(List<List<Integer>> ll){
		
		
		/*for( int i = 0 ; i < ll.size() ; i++){
			System.out.println( ll.get(i).toString());
		}*/
	for( int j = 0 ; j < ll.size() ; j++){
		
	
		
		
		Stack<Integer> st = new Stack<Integer>();
		int T = 1 ;
		int fd[] = new int[ll.size()+1];
		int sd[] = new int[ll.size()+1];
		int c[] = new int[ll.size()+1];
		
		Arrays.fill(fd, Integer.MAX_VALUE);
		Arrays.fill(sd, Integer.MAX_VALUE);
		Arrays.fill(c, 0);
		
		st.push(j);
		c[ j ] =1 ;
		fd[j ] = ++T;
	
		while( !st.isEmpty()){
			int p = st.peek();
			st.pop();
			c[p] = 2;
			sd[p] = ++T;
			//System.out.println(p + "  " +  c[ p] + " " + fd[p] + " " + sd[p]);
			
			List<Integer> lp = ll.get(p);
			for( int i = 0 ; i < lp.size() ; i++){
				//System.out.println(p + "  " + lp.get(i) +" " + c[ lp.get(i)] + " " + fd[lp.get(i)] + " " + sd[lp.get(i)]);
				if( c[ lp.get(i) ] <=0  ){
					st.push(lp.get(i));
					c[ lp.get(i) ]=1;
					fd[ lp.get(i) ] = T++;
				}else{
					if (fd[ lp.get(i) ] <= T ){
						System.out.print("Yes");
						return ;
					}
				}
			}
		}
	}
	System.out.print("No");
	
	}
	
	public static void main(String[] args) throws IOException {
		
		DiamondInheritance si = new DiamondInheritance();
		
		int SZ ;
		String CurLine = ""; 
		        
		InputStreamReader converter = new InputStreamReader(System.in);
		BufferedReader in = new BufferedReader(converter);
		CurLine = in.readLine();
		SZ= Integer.parseInt(CurLine);
		
		for(int i = 0 ; i < SZ;i++) {
			CurLine = in.readLine();
			int N = Integer.parseInt(CurLine);
			
			List<List<Integer>> ll = new ArrayList< List<Integer>>();
			for( int j = 0 ; j <= N ;j++){
				List<Integer> cl = new ArrayList<Integer>();
				cl.clear();
				ll.add(cl);
			}
			
			for( int j = 1 ; j <= N ;j++){
				CurLine = in.readLine();
				String classList[] = CurLine.split(" ");
											
				List<Integer> lp = ll.get(j);
				for( int k = 1 ; k < classList.length ;k++){
					int p = Integer.parseInt(classList[k]);
					lp.add(p);
				}
				ll.set(j, lp);
			}
			System.out.print("Case #"+(i+1)+": ");
			si.solves(ll);
			System.out.println();
		}
		
	}
}
