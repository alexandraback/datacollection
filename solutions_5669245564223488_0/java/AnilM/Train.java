import java.util.*;
class Train{
	public static void main(String[] args){
		Scanner in=new Scanner(System.in);
		int T=in.nextInt();
		String[] s=new String[26];
		Arrays.fill(s,"");
		char c='a';
		for(int i=0;i<26;i++)
		{
			for(int j=0;j<106;j++)
			s[i]+=c;
			c++;
		}
		for(int t=1;t<=T;t++)
		{
			long ans=1;
			int N=in.nextInt();
			List<String> str=new ArrayList<String>();
			for(int i=0;i<N;i++)
			str.add(in.next());
			for(int i=0;i<26;i++)
			{
				String app="";
				int mul=0;
				for(ListIterator<String> it=str.listIterator();it.hasNext();)
				{
					String ch=it.next();
					if(s[i].contains(ch))
					{
						app+=ch;
						mul++;
						it.remove();
					}
				}
				if(mul>=1)
				str.add(app);
				while(mul>0)
				{
					ans=(ans*mul)%1000000007L;
					mul--;
				}
			}
			int found=0;
			while(true){
				int m=0,n=0;
				found=0;
				int back=0;
			for(int i=0;i<str.size()-1&&found==0;i++)
			for(int j=i+1;j<str.size()&&found==0;j++)
			{
				String ch1=str.get(i),ch2=str.get(j);
				if(ch1.charAt(ch1.length()-1)==ch2.charAt(0))
				{
					found=1;back=1;
					m=i;n=j;
				}else if(ch1.charAt(0)==ch2.charAt(ch2.length()-1)){
					found=1;back=0;
					m=i;n=j;
				}
			}
			if(found==1)
			{
				if(back==1)
				{
					str.set(m,str.get(m)+str.get(n));
					str.remove(n);
				}else{
					str.set(m,str.get(n)+str.get(m));
					str.remove(n);
				}
			}else
			break;
			}
			int mm=str.size();
			while(mm>0)
			{
					ans=(ans*mm)%1000000007L;
					mm--;
			}
			String check="";
			for(int i=0;i<str.size();i++)
			check+=str.get(i);
			boolean yes=true;
			for(int i=1;i<check.length();i++)
			if(check.charAt(i)!=check.charAt(i-1)&&check.substring(0,i).contains(""+check.charAt(i)))
			{yes=false;break;}
			if(yes)
			System.out.println("Case #"+t+": "+ans);
			else
			System.out.println("Case #"+t+": 0");
		}
	}
}
	
				
				
			
