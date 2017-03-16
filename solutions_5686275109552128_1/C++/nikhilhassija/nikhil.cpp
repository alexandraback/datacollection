#include <bits/stdc++.h>

#define all(A) A.begin(), A.end()

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    int i,t,d,j,a,z,s;
    vector <int> P;
    cin>>t;
    for(i=0;i<t;++i)
    {
    	cin>>d;
    	P.resize(d);
    	for(j=0;j<d;j++)
    		cin>>P[j];
    	sort(all(P));
    	a = P[P.size()-1];
    	z = 2;
    	while(z<a)
    	{
    		s = 0;
    		for(j=0;j<d;j++)
    			s += (P[j]-1)/z;
    		s += z;
    		a = min(a,s);
    		z++;
    	}
    	cout<<"Case #"<<i+1<<": "<<a<<endl;
    }
    return 0;
}	
