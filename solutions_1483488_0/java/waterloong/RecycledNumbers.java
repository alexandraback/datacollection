import java.util.Arrays;
import java.util.Scanner;
import java.util.StringTokenizer;


public class RecycledNumbers {
	
	public static void main(String[] args) {
		Scanner in=new Scanner(System.in);
		int cases=Integer.parseInt(in.nextLine())+1;
		Boolean[] arr=new Boolean[2000001];
		Arrays.fill(arr,false);
		for(int tt=1;tt<cases;tt++){
			StringTokenizer cmd=new StringTokenizer(in.nextLine());
			int low=Integer.parseInt(cmd.nextToken());
			int high=Integer.parseInt(cmd.nextToken());
			int pair=0;
			for(int i=low;i<high;i++){
				if(arr[i]){
					continue;
				}
				int count=0;
				int j=back(i);
				while(i!=j){
					if(j<=high&&j>=low){
						count++;
						arr[j]=true;
					}
					j=back(j);
				}
				if(count>0){
					pair+=(count*(count+1)/2);
					//System.out.println(i+" "+arr2[i]);
					arr[i]=true;
				}
			}
			System.out.printf("Case #%d: %d\n",tt,pair);
			for(int i=low;i<=high;i++){
				arr[i]=false;
			}
		}
	}
	public static int back(int n){
		int r=n%10;
		String str=n+"";
		if(r>0){
			str=r+str.substring(0,str.length()-1);
			//System.out.println("1 "+str);
		}
		if(r==0){
			int i;
			for(i=str.length()-1;str.charAt(i)=='0';i--);
			str=str.substring(i)+str.substring(0,i);
			//System.out.println("2 "+str);
		}
		n=Integer.parseInt(str);
		return n;
	}
}

