import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.Arrays;
import java.util.StringTokenizer;


public class ReorderingTrainCars {

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
			int N=Integer.parseInt(br.readLine());
			String car[]=new String[N];
			st=new StringTokenizer(br.readLine());
			for(int i=0;i<N;i++){
				car[i]=st.nextToken();
			}
			System.out.println(Arrays.toString(car));

			int ans=0;
			int p[]=new int[N];
			for(int i=0;i<N;i++)
				p[i]=i;
			do{
				StringBuilder sb=new StringBuilder();
				for(int i=0;i<N;i++)
					sb.append(car[p[i]]);
				if(okay(sb.toString()))
					ans++;
			}while(nextPermutation(p));
			
			System.out.println();
			bw.append("Case #"+cn+": ");
			bw.append(ans+"\n");
		}
		bw.flush();

	}
	static boolean okay(String st){
		boolean used[]=new boolean[26];
		int cur=-1;
		int len=st.length();
		boolean okay=true;
		for(int i=0;i<len;i++){
			int c=st.charAt(i)-'a';
			if(c!=cur){
				if(used[c])
					okay=false;
				used[c]=true;
				cur=c;
			}
		}
		return okay;
	}
	
	static boolean nextPermutation(int[] a){
		int k=a.length-2;
		for(;k>=0&&a[k]>a[k+1];k--);
		if(k==-1)
			return false;
		int l=k+1;
		for(int i=k+1;i<a.length;i++)
			if(a[k]<a[i])
				l=i;
		swap(a,k,l);
		int i=k+1,j=a.length-1;
		while(i<j){
			swap(a,i,j);
			i++;j--;
		}
		return true;
	}
	static void swap(int[] a, int i, int j){
		int temp=a[i];
		a[i]=a[j];
		a[j]=temp;
	}
}
