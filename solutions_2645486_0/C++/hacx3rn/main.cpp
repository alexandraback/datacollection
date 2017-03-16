#include<iostream>
#include<vector>
#include<set>
#include<string>
#include<cmath>
using namespace std;
int e,r,n;
int v[10000];
int main(int argc, char **argv)
{
	int tc=0;
	cin>>tc;
	for (int cc = 1; cc <= tc; ++cc)
	{
        cin>>e>>r>>n;
        long long max_v=0;
        long long result=0;
        for(int i=0;i<n;i++){
            cin>>v[i];
            if(max_v<v[i]){
                max_v=v[i];
            }
        }
        if(r>e)
            r=e;

        for(int i=0;i<n;i++){
            result+=(long long)v[i]*(long long)r;
        }
        result+=max_v*(long long)(e-r);
        cout<<"Case #"<<cc<<": "<<result<<endl;
	}
	return 0;
}
