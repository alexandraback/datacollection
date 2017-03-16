import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Arrays;
import java.util.StringTokenizer;


public class Dijkstra {

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
			boolean okay=true;
			st=new StringTokenizer(br.readLine());
			int L=Integer.parseInt(st.nextToken());
			long X=Long.parseLong(st.nextToken());
			String S=br.readLine();
			

			
			int arr[]=new int[L];
			arr[0]=get(S.charAt(0)+"");
			for(int i=1;i<L;i++){
				arr[i]=mult(arr[i-1],get(S.charAt(i)+""));
			}
			
			//find if prod is -1
			if(pow(arr[L-1],X)!=-1)
				okay=false;
			
			//find "i" from left
			int i1=0, i2=0;
			boolean ifound=false;
			for(int i=0;i<4&&!ifound;i++){
				for(int j=0;j<L&&!ifound;j++){
					if(mult(pow(arr[L-1],i),arr[j])==2){
						ifound=true;
						i1=i; i2=j;
					}
				}
			}
			
			//find "k" from right
			int arr2[]=new int[L];
			arr2[L-1]=get(S.charAt(L-1)+"");
			for(int i=L-2;i>=0;i--){
				arr2[i]=mult(get(S.charAt(i)+""),arr2[i+1]);
			}
			
			int k1=0, k2=0;
			boolean kfound=false;
			for(int i=0;i<4&&!kfound;i++){
				for(int j=L-1;j>=0&&!kfound;j--){
					if(mult(arr2[j],pow(arr2[0],i))==4){
						kfound=true;
						k1=i; k2=j;
					}
				}
			}
			
			if(!(ifound&&kfound))
				okay=false;
			if(ifound&&kfound){
				long total=L*X;
				long sum=L*(i1+k1)+i2+1+(L-k2);
				if(sum>total)
					okay=false;
			}
			
//			if(okay){
//				System.out.println(S);
//				for(int i=0;i<L;i++){
//					System.out.print(get(S.charAt(i)+""));
//				}
//				System.out.println();
//				System.out.println(Arrays.toString(arr));
//				System.out.println(Arrays.toString(arr2));
//				
//				System.out.println(pow(arr[L-1],X));
//				System.out.println(ifound+" "+i1+" "+i2);
//				System.out.println(kfound+" "+k1+" "+k2);
//				System.out.println("L X: "+L+" "+X);
//				
//				System.out.println();
//			}
			
			if(okay)
				bw.append("Case #"+cn+": YES\n");
			else
				bw.append("Case #"+cn+": NO\n");
		}
		bw.flush();
	}
	
	static int mult(int a, int b){
		//1=1, i=2, j=3, k=4
		int sign=(a*b<0?-1:1);
		a=Math.abs(a);
		b=Math.abs(b);
		int arr[][]={
				{0, 0, 0, 0, 0},
				{0, 1, 2, 3, 4},
				{0, 2,-1, 4,-3},
				{0, 3,-4,-1, 2},
				{0, 4, 3,-2,-1}				
		};
		return sign*arr[a][b];
	}
	static int pow(int a, long b){
		int sign=1;
		if(a<0&&b%2==1)
			sign=-1;
		a=Math.abs(a);
		if(a==1||b%4==0)
			return sign*1;
		else if(b%4==1)
			return sign*a;
		else if(b%4==2)
			return sign*-1;
		else
			return sign*-1*a;
	}
	static String getst(int a){
		String ret="";
		if(a<0)
			ret+="-";
		a=Math.abs(a);
		if(a==1)
			ret+="1";
		else if(a==2)
			ret+="i";
		else if(a==3)
			ret+="j";
		else if(a==4)
			ret+="k";
		
		return ret;
	}
	static int get(String a){
		int ret=0;
		if(a.charAt(a.length()-1)=='1')
			ret=1;
		else if(a.charAt(a.length()-1)=='i')
			ret=2;
		else if(a.charAt(a.length()-1)=='j')
			ret=3;
		else if(a.charAt(a.length()-1)=='k')
			ret=4;
		
		if(a.charAt(0)=='-')
			return -ret;
		else
			return ret;
	}

}
