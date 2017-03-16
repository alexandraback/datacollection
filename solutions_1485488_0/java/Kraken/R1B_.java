import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.TreeMap;

public class R1B_ {
public static void main(String[] args) {
		String prblm="B"; boolean fl=!true;
		String filein=prblm+"-"+((fl)?"large":"small")+".in.txt";
		String fileout=prblm+"-"+((fl)?"large":"small")+".out.txt";
		try {
			BufferedReader fr= new BufferedReader(new FileReader(filein));
			BufferedWriter fw= new BufferedWriter(new FileWriter(fileout));
			String s=fr.readLine();
			int T=Integer.parseInt(s);
			for (int i = 1; i <= T; i++) {
				s=fr.readLine();
				String[] tok=s.split(" ");
				int H=Integer.parseInt(tok[0]);
				int N=Integer.parseInt(tok[1]);
				int M=Integer.parseInt(tok[2]);
				int[][] floor=new int[N][M];
				int[][] ceil=new int[N][M];
				for (int j = 0; j < N; j++) {
					s=fr.readLine();
					tok=s.split(" ");
					for (int k = 0; k < M; k++) {
						ceil[j][k]=Integer.parseInt(tok[k]);
					}
				}				
				for (int j = 0; j < N; j++) {
					s=fr.readLine();
					tok=s.split(" ");
					for (int k = 0; k < M; k++) {
						floor[j][k]=Integer.parseInt(tok[k]);
					}
				}
				
				float[][] mt=new float[N][M];
				for (int j = 0; j < mt.length; j++) {
					for (int j2 = 0; j2 < mt[j].length; j2++) {
						mt[j][j2]=Float.MAX_VALUE;
					}
				}
				boolean[][] vis=new boolean[N][M];				
				TreeMap<Float,int[]> trm=new TreeMap<Float,int[]>();
				trm.put(0.0f,new int[]{0,0});				
				while (trm.size()>0) {
					float val=trm.firstKey();
					float tm=Math.round(val*10)/10.0f;
					float CL=H-10*tm;
					int r=trm.get(val)[0]; int c=trm.get(val)[1];
					trm.remove(val);
					if (vis[r][c]) continue;
					vis[r][c]=true;
					if (r>0 && !vis[r-1][c]) {
						if (ceil[r-1][c]-floor[r-1][c]>=50 && ceil[r][c]-floor[r-1][c]>=50 &&
								ceil[r-1][c]-floor[r][c]>=50) {
							float ntm=tm;
							if (CL>ceil[r-1][c]-50){
								ntm+=(CL-(ceil[r-1][c]-50.0))/10.0;
								ntm+=(ceil[r-1][c]-50>=floor[r][c]+20)?1:10;
							}
							else {if (tm==0.0) ntm=0;
								else ntm+=(CL>=floor[r][c]+20)?1:10;
							}
							if (ntm<mt[r-1][c]){
								mt[r-1][c]=ntm;
								trm.put(ntm+((r-1.0f)*M+c)/1000000, new int[]{r-1,c});
							}
						}
					}
					if (r<N-1 && !vis[r+1][c]) {
						if (ceil[r+1][c]-floor[r+1][c]>=50 && ceil[r][c]-floor[r+1][c]>=50 &&
								ceil[r+1][c]-floor[r][c]>=50) {
							float ntm=tm;
							if (CL>ceil[r+1][c]-50){
								ntm+=(CL-(ceil[r+1][c]-50.0))/10.0;
								ntm+=(ceil[r+1][c]-50>=floor[r][c]+20)?1:10;
							}
							else {if (tm==0.0) ntm=0;
								else ntm+=(CL>=floor[r][c]+20)?1:10;
							}
							if (ntm<mt[r+1][c]){
								mt[r+1][c]=ntm;
								trm.put(ntm+((r+1.0f)*M+c)/1000000, new int[]{r+1,c});
							}
						}
					}
					if (c>0 && !vis[r][c-1]) {
						if (ceil[r][c-1]-floor[r][c-1]>=50 && ceil[r][c]-floor[r][c-1]>=50 &&
								ceil[r][c-1]-floor[r][c]>=50) {
							float ntm=tm;
							if (CL>ceil[r][c-1]-50){
								ntm+=(CL-(ceil[r][c-1]-50.0))/10.0;
								ntm+=(ceil[r][c-1]-50>=floor[r][c]+20)?1:10;
							}
							else {if (tm==0.0) ntm=0;
								else ntm+=(CL>=floor[r][c]+20)?1:10;
							}
							if (ntm<mt[r][c-1]){
								mt[r][c-1]=ntm;
								trm.put(ntm+(r*M+c-1.0f)/1000000, new int[]{r,c-1});
							}
						}
					}
					if (c<M-1 && !vis[r][c+1]) {
						if (ceil[r][c+1]-floor[r][c+1]>=50 && ceil[r][c]-floor[r][c+1]>=50 &&
								ceil[r][c+1]-floor[r][c]>=50) {
							float ntm=tm;
							if (CL>ceil[r][c+1]-50){
								ntm+=(CL-(ceil[r][c+1]-50.0))/10.0;
								ntm+=(ceil[r][c+1]-50>=floor[r][c]+20)?1:10;
							}
							else {if (tm==0.0) ntm=0;
							else ntm+=(CL>=floor[r][c]+20)?1:10;
						}
							if (ntm<mt[r][c+1]){
								mt[r][c+1]=ntm;
								trm.put(ntm+(r*M+c+1.0f)/1000000, new int[]{r,c+1});
							}
						}
					}
				}
				System.out.println(mt[N-1][M-1]);
				fw.write("Case #"+i+": "+ mt[N-1][M-1]  +"\n");
			}
			fr.close();
			fw.close();
		} catch (Exception e) {			
			e.printStackTrace();
		}		
	}
}