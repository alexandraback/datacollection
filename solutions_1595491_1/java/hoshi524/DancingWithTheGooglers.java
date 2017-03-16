import java.util.Scanner;

public class DancingWithTheGooglers {
	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int t=sc.nextInt();
		for(int i=0;i<t;i++){
			int n=sc.nextInt();
			int s=sc.nextInt();
			int p=sc.nextInt();
			int ans=0;
			for(int j=0;j<n;j++){
				int total=sc.nextInt();
				int score=total/3+((total%3)>0?1:0);
				if(score>=p){
					ans++;
				}else if(s>0 && total>=p){
					int x=(total-p)/2;
					if(x+2>=p){
						s--;
						ans++;
					}
				}
			}
			System.out.println("Case #"+(i+1)+": "+ans);
		}
	}
}
