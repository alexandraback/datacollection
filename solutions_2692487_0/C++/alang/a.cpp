#include <iostream>
#include <vector>
#include <deque>
#include <map>
#include <string>
#include <utility>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <string.h>
#include <math.h>
using namespace std;
typedef unsigned long long ul;
typedef pair<int,int> pii;

int judge(int A, int N, vector<int> &vn)
{
	if(A==1)
		return N;
	sort(vn.begin(),vn.end());
	vector<int> d(N,0);
	int sum=0,csize=A;
	for(int i=0;i<N;i++)
	{
		d[i]=sum+N-i;
		if(csize>vn[i])
			csize+=vn[i];
		else
		{
			int n=0;
			int ntmp=csize;
			while(ntmp<=vn[i])
			{
				ntmp+=ntmp-1;
				n++;
			}
			sum+=n;
			csize=ntmp+vn[i];
		}
	}
	int ms=N+1;
	for(int i=0;i<N;i++)
		ms=min(ms,d[i]);
	return min(ms,sum);
}


int main() {
 
        int T;
        cin>>T;
        int count=1;
        while(T--)
        {
		int A,N;
		cin>>A>>N;
		vector<int> vn(N,0);
		for(int i=0;i<N;i++)
			cin>>vn[i];
                cout<<"Case #"<<count++<<": "<<judge(A,N,vn)<<endl;
        }



        return 0;
}
