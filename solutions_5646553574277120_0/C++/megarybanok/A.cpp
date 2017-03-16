#include <iostream>
#include <string>
#include <vector>

using namespace std;

int t;
int c,d,v;
int dd[5000];
int s[3100];
int j;

void count(){
	long long ans = 1;
	for (int j = 0; j<d; j++)
		ans*=2;

	int s1[20];
	

	for (int y = 0; y<ans; y++)
	{
		int ss = y;
		memset(s1,0,sizeof(s1));
		int i = 0;
		while (ss!=0)
		{
			s1[i] = ss%2;
			i++;
			ss/=2;
		}

		int sum=0;
		for (int k = 0; k<d; k++)
			sum+=s1[k]*dd[k];

		s[sum] = 1;
	}
}

void main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);


	cin>>t;
	for (int i = 0; i<t; i++){
		cin>>c>>d>>v;
		for (j = 0; j<d; j++)
			cin>>dd[j];

		
		memset(s,0,sizeof(s));
		int ans = 0;
		while (true)
		{
			count();

			bool bul = false;
			for (j = 1; j<=v; j++)
				if (s[j]==0)
				{
					bul=true;
					break;
				}
			if (bul)
				dd[d]=j,d++,ans++;
			else
				break;	
		}
		printf("Case #%i: %i\n",i+1,ans);
	}
}
