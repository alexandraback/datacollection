#include<bits/stdc++.h>

using namespace std;

int h[105],ans[105];

string cc,jj;

int p[5];

int num(string a)
{
	int ans=0;
	
	for(int i=0;i<a.size();i++)
		ans=ans*10+(a[i]-'0');
		
	return ans;
}

void send(int a,int b)
{
	int x=a,cnt=0;
	
	while(x)
	{
		cnt++;
		x/=10;
	}
	
	if(!a)
		cnt++;
	
	for(int i=0;i<b-cnt;i++)
		cout << "0";
		
	cout << a;
}

void check(int f,int s)
{
	if(f==cc.size() && s==jj.size())
	{
		//cout << num(cc) << " " << num(jj) << endl;
		if(abs(p[0]-p[1])>abs(num(cc)-num(jj)))
		{
			p[0]=num(cc);
			p[1]=num(jj);
		}
		else if(abs(p[0]-p[1])==abs(num(cc)-num(jj)))
		{
			if(p[0]>num(cc))
			{
				p[0]=num(cc);
				p[1]=num(jj);
			}
			else if(p[0]==num(cc) && p[1]>num(jj))
			{
				p[0]=num(cc);
				p[1]=num(jj);
			}
		}
		
		return;
	}
	
	if(f==cc.size())
	{
		if(jj[s]!='?')
		{
			check(f,s+1);
			return;
		}
		
		for(int i=0;i<10;i++)
		{
			jj[s]=i+'0';
			
		check(f,s+1);
		
		jj[s]='?';
	}
	}
	else
	{
		if(cc[f]!='?')
		{
			check(f+1,s);
			return;
		}
		
		for(int i=0;i<10;i++)
		{
			cc[f]=i+'0';
			
		check(f+1,s);
		
		cc[f]='?';
	}
	}
	
}

int main()
{
	
	//freopen("A-small-attempt0.in","r",stdin);
	//freopen("aa.txt","w",stdout);
	
	int t;
	
	cin >> t;
	
	for(int tt=0;tt<t;tt++)
	{
		cout << "Case #" << tt+1 << ": ";
		
		p[0]=1000000;
		p[1]=100000000;
		
		cin >> cc >> jj;
		
		//cout << num("19");
		
		check(0,0);
				
		send(p[0],cc.size() );
		cout << " ";
		 send(p[1],jj.size()); 
			
		cout << endl;	
	}
	
	//fclose(stdin);
	//fclose(stdout);
	
	return 0;
}
