#include <iostream>
#include <math.h>
#include <map>
using namespace std;

char res[1000][1000];
int sign[1000][1000];

void init()
{
	res['i']['i']='1';
	sign['i']['i']=-1;
	
	res['i']['1']='i';
	sign['i']['1']=1;
	
	res['i']['j']='k';
	sign['i']['j']=1;
	
	res['i']['k']='j';
	sign['i']['k']=-1;
	//-----------------
	
	res['1']['i']='i';
	sign['1']['i']=1;
	
	res['1']['1']='1';
	sign['1']['1']=1;
	
	res['1']['j']='j';
	sign['1']['j']=1;
	
	res['1']['k']='k';
	sign['1']['k']=1;
	
	//-----------------
	res['j']['i']='k';
	sign['j']['i']=-1;
	
	res['j']['1']='j';
	sign['j']['1']=1;
	
	res['j']['j']='1';
	sign['j']['j']=-1;
	
	res['j']['k']='i';
	sign['j']['k']=1;
	//-----------------
	
	res['k']['i']='j';
	sign['k']['i']=1;
	
	res['k']['1']='k';
	sign['k']['1']=1;
	
	res['k']['j']='i';
	sign['k']['j']=-1;
	
	res['k']['k']='1';
	sign['k']['k']=-1;
	

}
char prec[100001];
int prei[100001];
int solvek(string s,long long m,string rem)
{
	if(m<0)
		return 0;
	char h='1';
	int ss=1;
	int q=0;
//	cout<<" "<<m<<" "<<rem.length()<<endl;
//	cout<<rem.length()<<" ";
	if(rem.length()!=0)
	{
		ss*=prei[s.length()-rem.length()];
		h=prec[s.length()-rem.length()];
	}
//	cout<<h<<" "<<m<<" "<<ss<<endl;
	if(m%2!=0)
	{
//		cout<<endl<<h<<" "<<prei[0]<<" \n";
		ss*=sign[h][prec[0]]*prei[0];
		h=res[h][prec[0]];
		m--;
	}
//	cout<<h<<" "<<m<<" "<<ss<<endl;
	int qw=sign[prec[0]][prec[0]];
//	cout<<sign[prec[0]][prec[0]]<<endl;
//	cout<<m/2<<endl;
	ss*=pow(qw,m/2);
//	cout<<h<<" "<<m<<" "<<ss<<endl;
	if(h=='k'&&ss==1)
	{
//		cout<<1<<" ";
	
		return 1;
		
	}
	else
		return 0;
}
int solvej(string s ,long long m,string rem)
{
	if(m<0)
		return 0;
	char h='1';
	int ss=1;
	int q=0;
	//cout<<rem.length();
	for(int i=0;i<rem.length();i++)
	{
		ss*=sign[h][rem[i]];
		h=res[h][rem[i]];
	//	cout<<h<<" "<<ss<<endl;
		if(h=='j'&&ss==1)
		{
			string rem1=string(rem.begin()+i+1,rem.end());
			q=max(q,solvek(s,m,rem1));
			if(q==1)
				return 1;
		}
	 }
	for(int j=0;j<10;j++)
	{
		m--;
		if(m<0)
			break;
		for(int i=0;i<s.length();i++)
		{
			ss*=sign[h][s[i]];
			h=res[h][s[i]];
			//cout<<h<<" "<<ss<<" "<<s[i]<<endl;
			if(h=='j'&&ss==1)
			{
				string rem=string(s.begin()+i+1,s.end());
				q=max(q,solvek(s,m,rem));
				if(q==1)
					return 1;
			}
		}
		
	}	
	return q;
}

int solvei(string s,long long m)
{
	char h='1';
	int ss=1;
	int q=0;
	
	for(int j=0;j<10;j++)
	{
		m--;
		if(m<0)
			break;
		
		for(int i=0;i<s.length();i++)
		{
			ss*=sign[h][s[i]];
			h=res[h][s[i]];
		//	cout<<h<<" "<<ss<<endl;
			if(h=='i'&&ss==1)
			{
				string rem=string(s.begin()+i+1,s.end());
		//		cout<<"i  "<<" "<<rem<<" "<<m<<endl;
			
				q=max(q,solvej(s,m,rem));
				if(q==1)
					return 1;
			}
		}
			
	}

	return q;
}
int main() {
	init();
	int t;
	cin>>t;

	for(int qq=1;qq<=t;qq++)
	{
		long long l,m;
		cin>>l>>m;
		string s;
		cin>>s;
		
		prec[s.length()-1]=s[s.length()-1];
		prei[s.length()-1]=1;
		for(int i=s.length()-2;i>=0;i--)
		{
			prec[i]=res[s[i]][prec[i+1]];
			prei[i]=sign[s[i]][prec[i+1]]*prei[i+1];
		}	
	//	cout<<prec[0]<<" "<<prei[0]<<endl;
		if(solvei(s,m))
			cout<<"Case #"<<qq<<": "<<"YES\n";
		else
			cout<<"Case #"<<qq<<": "<<"NO\n"; 
	}
	
	return 0;
}
