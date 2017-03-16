#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<math.h>
#include<sstream>

using namespace std;

int main()
{
	int T,R,N,M,K;//T,R=100,N=3,M=5,K=7;
	cin>>T;
	cin>>R>>N>>M>>K;
	int set[3],i,j,l;
	cout<<"Case #1:\n";
	for(int r=0;r<R;r++)
	{
		vector<int> cand,poss;
		for(i=0;i<K;i++)
		{
			cin>>j;
			bool flag=false;
			for(int k=0;k<cand.size();k++) if(cand[k]==j) flag=true;
			if(!flag) cand.push_back(j);
		}
		for(l=0;l<64;l++)
		{
			int L=l;
			set[0]=L%4+2;
			L/=4;
			set[1]=L%4+2;
			L/=4;
			set[2]=L%4+2;
			poss.clear();
			for(int s=0;s<8;s++)
			{
				int S=s;
				j=1;
				if(S%2==1) j*=set[0];
				S/=2;
				if(S%2==1) j*=set[1];
				S/=2;
				if(S%2==1) j*=set[2];
				poss.push_back(j);
			}
			sort(poss.begin(),poss.end());
			sort(cand.begin(),cand.end());
			int ma=0;
			i=0;j=0;
			while(i<8&&j<cand.size())
			{
				if(poss[i]==cand[j])
				{
					ma++;
					i++;
					j++;
				}
				else if (poss[i]<cand[j])
					i++;
				else
					j++;
			}
			if(ma>=cand.size())
			{
				cout<<set[0]<<set[1]<<set[2]<<endl;
				break;
			}
		}
		if(l==64)
		{
			cout<<set[0]<<set[1]<<set[2]<<endl;
		}
	}
	return 0;
}
