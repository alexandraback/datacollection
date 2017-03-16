import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Map.Entry;
import java.util.StringTokenizer;
import java.util.TreeMap;
import java.util.TreeSet;


public class HallOfMirrors_small {

	/**
	 * @param args
	 */
	public static void main(String[] args) throws Exception {
		// TODO Auto-generated method stub
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw=new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st;
		int T=Integer.parseInt(br.readLine());
		for(int cn=1;cn<=T;cn++){
			st=new StringTokenizer(br.readLine());
			int H=Integer.parseInt(st.nextToken());
			int W=Integer.parseInt(st.nextToken());
			int D=Integer.parseInt(st.nextToken());
			//find X
			int a=-1,b=-1;
			for(int i=0;i<H;i++){
				String s=br.readLine();
				for(int j=0;j<W;j++){
					if(s.charAt(j)=='X'){
						a=i-1;
						b=j-1;
					}
				}
			}
			int y1=50*(H-2)+a;
			int x1=50*(W-2)+b;
//			System.out.println(x1+" "+y1);
			TreeMap<Integer, TreeSet<Integer>> pair=new TreeMap<Integer, TreeSet<Integer>>();
			for(int j=0;j<=101;j++){
				for(int i=0;i<=101;i++){
					int y2=i*(H-2)+((i%2==0)?a:(H-a-3));
					int x2=j*(W-2)+((j%2==0)?b:(W-b-3));
//					System.out.println(j+" "+i+" "+x2+" "+y2);
					int dy=y1-y2;
					int dx=x1-x2;
					double dist=Math.sqrt(dx*dx+dy*dy);
					if(dist<=D){
						int gcd=gcd(Math.abs(dx),Math.abs(dy));
						dx/=gcd; dy/=gcd;
//						System.out.println(">>>"+" "+dx+" "+dy);
						if(!pair.containsKey(dx))
							pair.put(dx, new TreeSet<Integer>());
						pair.get(dx).add(dy);
					}
				}
			}
//			System.out.println();
			int ctr=-1;
			for(Entry<Integer, TreeSet<Integer>> e:pair.entrySet()){
//				System.out.println(">"+e.getKey());
				for(int i:e.getValue()){
					ctr++;
//					System.out.println(" " +i);
				}
			}
			bw.append("Case #"+cn+": "+ctr+"\n");
		}
		bw.flush();
	}
	static int gcd(int a, int b){
		if(a==0&&b==0)
			return 1;
		if(b==0)
			return a;
		if(a==0)
			return b;
		return gcd(b,a%b);
	}
}
