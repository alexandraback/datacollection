#include <iostream>
#include <string>
#include <vector>

using namespace std;

int t,len;
int ss[100],maxx[100];
pair <int,char> alph [1000];
int check(int s[],int l, int ll, string word){
	int ans = 0;
	for (int i = 0; i<l; i++)
	{
		
		bool is = true;
		for (int j = 0; j<ll; j++)
			if (!((i+j)<l && word[j]==alph[s[i+j]].second))
			{
				is = false;
				break;
			}
		if (is)
			ans++;
	}
	if (ll>l) ans=0;
	return ans;
}

void plu(int l){
	int i = 0;
	while (i<l && (len-1)==ss[i])
	{
		ss[i]=0;
		i++;
	}

	if (i<l && (len-1)>ss[i])
		ss[i]++;

	if (i==l)
		ss[0]=-1;
}

double ot(int s, int totaln){
	double ans=1;
	for (int i = 0; i<s; i++)
		ans*= (double)alph[ss[i]].first / (double)totaln;
	return ans;
}

void main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);


	cin>>t;
	for (int i = 0; i<t; i++){
		int k,l,s;
		cin>>k>>l>>s;

		string alf;
		string word;
		cin>>alf>>word;
		double ans = 0;
		
		len = 0;

		for (int j = 0; j<k; j++)
		{
			bool bul = false;
			int y;
			for (y = 0; y<len; y++)
				if (alph[y].second==alf[j]) 
				{
					bul=true;
					break;
				}
			if (!bul)
			{
				alph[len].second=alf[j];
				alph[len].first=1;
				len++;
			}
			else
			{
				alph[y].first++;
			}
		}

		
		for (int j = 0; j<s; j++)
			ss[j]=0;

		int maxn = 0;
		int numofmax = 0;
		int total = 0;
		while (true){
			int num = check(ss,s,l,word);
			total++;

			ans+=(double)num*ot(s,k);
			if (num>maxn)
			{
				maxn=num;
				numofmax=num;
				//ans = ot(s,k);
			}
			//else
				//if (num==maxn && num!=0)
					//numofmax++;//,ans+=ot(s,k)
			
			plu(s);

			if (ss[0] == -1)
				break;
		}

		printf("Case #%i: %.7f\n",i+1,numofmax - ans);
	}
}
