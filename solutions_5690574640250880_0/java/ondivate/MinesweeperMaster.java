import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.LinkedList;
import java.util.StringTokenizer;


public class MinesweeperMaster {

	/**
	 * @param args
	 */
	public static void main(String[] args) throws Exception {
		// TODO Auto-generated method stub
		BufferedReader br=new BufferedReader(new FileReader(new File("in")));
		BufferedWriter bw=new BufferedWriter(new FileWriter(new File("out")));
		StringTokenizer st;
		
		int T=Integer.parseInt(br.readLine());
		for(int cn=1;cn<=T;cn++){
			st=new StringTokenizer(br.readLine());
			int R=Integer.parseInt(st.nextToken());
			int C=Integer.parseInt(st.nextToken());
			int M=Integer.parseInt(st.nextToken());
			System.out.println(R+" "+C+" "+M);

			int target=R*C-M;
			char arr[][]=new char[R+2][C+2];
			for(int i=1;i<=R;i++){
				for(int j=1;j<=C;j++){
					arr[i][j]='*';
				}
			}
			for(int i=0;i<R+2;i++){
				arr[i][0]='.';
				arr[i][C+1]='.';
			}
			for(int j=0;j<C+2;j++){
				arr[0][j]='.';
				arr[R+1][j]='.';
			}
			LinkedList<Integer> next=new LinkedList<Integer>();//100*i+j
			arr[1][1]='c';
			next.add(101);
			int revealed=1;
			int loopctr=0;
			while(!next.isEmpty()&&loopctr<25000){
				int n=next.pollFirst();
				int x=n/100, y=n%100;
//				System.out.println("x,y="+x+" "+y);
				//check surroundings
				int toReveal=0;
				for(int d=0;d<8;d++){
					int nx=x+dx[d], ny=y+dy[d];
					if(arr[nx][ny]=='*'){
						toReveal++;
					}
				}
				loopctr++;
				if(toReveal==0||revealed+toReveal>target)
					continue;
				else if(revealed+toReveal+1==target&&!next.isEmpty()){
					next.add(n);
					continue;
				}
				//set as '0' cell
				for(int d=0;d<8;d++){
					int nx=x+dx[d], ny=y+dy[d];
					if(arr[nx][ny]=='*'){
						arr[nx][ny]='.';
						revealed++;
						next.add(nx*100+ny);
					}
				}
			}
			//check if it worked
			int ctr=0;
			for(int i=1;i<=R;i++){
				for(int j=1;j<=C;j++){
					if(arr[i][j]=='*')
						ctr++;
				}
			}
			bw.append("Case #"+cn+":\n");
			if(ctr!=M)
				bw.append("Impossible\n");
			else{
				for(int i=1;i<=R;i++){
					for(int j=1;j<=C;j++){
						bw.append(arr[i][j]);
					}
					bw.append("\n");
				}
			}
		}
		bw.flush();

	}
	static int dx[]={-1,0,1,-1,1,-1,0,1};
	static int dy[]={-1,-1,-1,0,0,1,1,1};
}
