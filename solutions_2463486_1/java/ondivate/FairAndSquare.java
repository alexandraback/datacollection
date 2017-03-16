import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.StringTokenizer;
import java.util.TreeMap;


public class FairAndSquare {

	/**
	 * @param args
	 */
	public static void main(String[] args) throws Exception {
		// TODO Auto-generated method stub
		TreeMap<Long,Integer> map=new TreeMap<Long,Integer>();
		int ctr=0;
		int lim=100000000;
		for(long i=0;i<lim;i++){
			//check if palindrome
			if(isPal(i)){
				//square and check if palindrome
				long sq=i*i;
				if(isPal(sq)){
					map.put(sq, ctr++);
					System.out.println(i+" "+sq+" "+ctr);
				}
			}
		}
		System.out.println(ctr);
		
		BufferedReader br=new BufferedReader(new FileReader(new File("in")));
		BufferedWriter bw=new BufferedWriter(new FileWriter(new File("out")));
		StringTokenizer st;
		int T=Integer.parseInt(br.readLine());
		for(int cn=1;cn<=T;cn++){
			st=new StringTokenizer(br.readLine());
			long A=Long.parseLong(st.nextToken());
			long B=Long.parseLong(st.nextToken());
			int aa=map.get(map.lowerKey(A));
			int bb=map.get(map.floorKey(B));
			int ans=bb-aa;
			bw.append("Case #"+cn+": "+ans+"\n");
		}
		bw.flush();
	}
	static boolean isPal(long a){
		String s=a+"";
		int l=s.length();
		boolean okay=true;
		for(int i=0;i<l/2;i++){
			okay&=s.charAt(i)==s.charAt(l-1-i);
		}
		return okay;
	}
}
