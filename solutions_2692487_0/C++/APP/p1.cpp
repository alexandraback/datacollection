#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main()
{
    int T;
    cin>>T;
    for(int t=1;t<=T;t++)
    {
        int A,N;
        cin>>A>>N;
        vector<int> motes;
        for(int n=0;n<N;n++)
        {
            int t;
            cin>>t;
            motes.push_back(t);
        }
        sort(motes.begin(),motes.end());
        vector<int> adds(motes.size(), 0);
        int a=A;
        if(a==1)
        {
            cout<<"Case #"<<t<<": "<<motes.size()<<endl;
            continue;
        }
        int i=0;vector<int>::iterator it=motes.begin();
	while(i<motes.size())
	{
		for(;it!=motes.end();it++)
		{
			if(*it<a)
			{
				a+=*it;
				//if(i!=0) adds.at(i)=adds.at(i-1);
				//else adds.at(i)=0;
				i++;
			}
			else break;
		}
		if(it==motes.end()) break;
		a+=(a-1);
		adds.at(i)+=1;
	}
	for(int i=1;i<adds.size();i++)
	{
		adds.at(i)+=adds.at(i-1);
	}
	int ans=101;
	int dels=0;
	for(int i=motes.size()-1;i>=0;i--, dels++)
	{
		if(adds.at(i)+dels<ans)
			ans=adds.at(i)+dels;
	}
	if(dels<ans)
		ans=dels;
	/*int ans=0;
	for(int i=motes.size()-1;i>=0;i--)
	{
		ans+=adds.at(i);
	}
	*/
	cout<<"Case #"<<t<<": "<<ans<<endl;
	

    }
	    return 0;
}
	



