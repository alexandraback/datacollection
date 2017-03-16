#include <bits/stdc++.h>
using namespace std;

int main() {
	 freopen("1AL.txt","r",stdin);
	    freopen("1ALARGE.txt","w",stdout);
	int t;
	long int n,i,j,k;
	scanf("%d",&t);
for(int j=0;j<t;j++)
	{string s,s1;
	cin>>s;
	s1.clear();
	//cout<<s;
	s1.push_back(s[0]);
//cout<<s1[0]<<"  ~~~ "<<s1<<endl;
	for(i=1;i<s.length();i++)
    {//cout<<s1<<"  "<<i<<endl;
        if(s[i]>=s1[0])
            {char c =s[i];
                s1.insert(0,1,c);
                }
        else
            s1.push_back(s[i]);

    }
    cout<<"Case #"<<j+1<<": "<<s1<<endl;

      	//printf("Case #%d: %s\n",j+1,s1);


	}

	// your code goes here
	return 0;
}
