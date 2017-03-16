import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

public class jump{
	public static String out="";
//	public static String[][][] sol;
//	public static String jump(int jum, int X, int Y){
//		int x,y,i,j,k;
//		String[][][] sol=new String[1001][1001][501];
//		String n,s,e,w;
//		x=500+X;
//		y=500+Y;
//		for(i=1;i<500;i++){
//			sol[500+i][500][i]="E";
//			sol[500-i][500][i]="W";
//			sol[500][500+i][i]="N";
//			sol[500][500-i][i]="S";
//		}
//		for(i=1;i<500;i++)
//			for(j=1;j<500;j++)
//				for(k=1;k<500;k++){
//					sol[500+]
//				}
//		
//		
//		
//	}
//	
//	public static String rejump(int jum, int X, int Y){
//		String n,s,e,w;
//		if(sol[500+X][500+Y][jum]!=-1)
//			return sol[500+X][500+Y][jum];
//		else{
//			n="N"+sol[500+X][500+Y-jum][jum+1];
//			if(n.length()<=500){
//				sol[500+X][500+Y][jum]=n;
//				return n;
//			}
//			
//				
//		}
//	}
	
	public static String bf(int x, int y){
		String res="";
		int i,j;
		if(x>=0&&y>=0){
			for(i=0;i<x;i++)
				res+="WE";
			for(i=0;i<y;i++)
				res+="SN";
		}else if(x>=0&&y<0){
			y=-y;
			for(i=0;i<x;i++)
				res+="WE";
			for(i=0;i<y;i++)
				res+="NS";
		}else if(x<0&&y<=0){
			x=-x;
			y=-y;
			for(i=0;i<x;i++)
				res+="EW";
			for(i=0;i<y;i++)
				res+="NS";
		}else{
			x=-x;
			for(i=0;i<x;i++)
				res+="EW";
			for(i=0;i<y;i++)
				res+="SN";
		}
		return res;
	}
	
	public static void main(String[] args) {
		BufferedReader br = null;
		BufferedWriter writer = null;
		try {

			br = new BufferedReader(new FileReader("C:/codejam/B-small-attempt1.in"));
			int T, N, X, Y, j, i,n;
			String s;
			String res;
			String result;
			String tmpd;
			T = Integer.parseInt(br.readLine());
			for (i = 1; i < T + 1; i++) {
				out += "Case #" + i + ": ";
				tmpd = br.readLine();
				String[] d = tmpd.split(" ");
				X = Integer.parseInt(d[0]);
				Y = Integer.parseInt(d[1]);
				res=bf(X,Y);
				System.out.println("Case #"+ i+ ": "+ res);
				out += res;
				out += "\n";
			}

			writer = new BufferedWriter(new FileWriter("C:/codejam/output.out"));
			System.out.println(out);
			writer.write(out);


		} catch (IOException e) {
			e.printStackTrace();
		} finally {
			try {
				if (writer != null)
					writer.close();
			} catch (IOException e) {
			}
		}

	}
}