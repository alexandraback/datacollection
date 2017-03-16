import java.util.Scanner;


public class cj_03 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		int t=0;
		while(t<=n){
			t++;
			int a=sc.nextInt();
			int b=sc.nextInt();
			sc.nextLine();
			String s=sc.nextLine();
			char[] c=new char[a*b];
			char[] result=new char[a*b];
			for(int i=0;i<b;i++)
				for(int j=0;j<a;j++)
					c[i*a+j]=s.charAt(j);
			result[0]=c[0];
			for(int i=1;i<a*b;i++)
				result[i]=mul(result[i-1],c[i]);
			if(result[a*b-1]!='0'){
				System.out.println("Case #"+t+": NO");
				continue;
			}
			int i=0;
			for(i=0;i<a*b;i++)
				if (result[i]=='i')
					break;
			boolean flag=false;
			for(int k=i+1;k<a*b;k++){
				if(result[k]=='k'){
					flag=true;
				}			
			}
			if(flag){
				System.out.println("Case #"+t+": YES");	
			}
			else
			System.out.println("Case #"+t+": NO");			
		}
	}
	static char mul (char a,char b){
		if(a=='1'){
			if(b=='i')
				return 'i';
			if(b=='j')
				return 'j';
			if(b=='k')
				return 'k';
		}
		if(a=='i'){
			if(b=='i')
				return '0';
			if(b=='j')
				return 'k';
			if(b=='k')
				return 'J';
		}
		if(a=='j'){
			if(b=='i')
				return 'K';
			if(b=='j')
				return '0';
			if(b=='k')
				return 'i';

		}
		if(a=='k'){
			if(b=='i')
				return 'j';
			if(b=='j')
				return 'I';
			if(b=='k')
				return '0';

		}
		if(a=='0'){
			if(b=='i')
				return 'I';
			if(b=='j')
				return 'J';
			if(b=='k')
				return 'K';
		}
		if(a=='I'){
			if(b=='i')
				return '1';
			if(b=='j')
				return 'K';
			if(b=='k')
				return 'j';
		}
		if(a=='J'){
			if(b=='i')
				return 'k';
			if(b=='j')
				return '1';
			if(b=='k')
				return 'I';
		}
		if(a=='K'){
			if(b=='i')
				return 'J';
			if(b=='j')
				return 'i';
			if(b=='k')
				return '1';

		}
		return 'a';
	}

}
