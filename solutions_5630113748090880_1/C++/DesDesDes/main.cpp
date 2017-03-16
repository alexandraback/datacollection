#include <math.h>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int main()
{
    int casenum,n;
    cin>>casenum;
    for(int t=1;t<=casenum;t++)
    {
        cin>>n;
        vector<int> height;
        vector<int>::iterator curr;
        int now;
        for(int i=0;i<2*n-1;i++)
        {
            for(int ii=0;ii<n;ii++)
            {
            cin>>now;
            curr=find(height.begin(),height.end(),now);
            if(curr!=height.end())
                height.erase(curr);
                else
                {
                    height.push_back(now);
                }
        
            }
        }
        sort(height.begin(),height.end());
        cout<<"Case #"<<t<<":";
        for(curr=height.begin();curr<height.end();curr++)
            cout<<" "<<*curr;
        cout<<endl;
    }
    return 0;
}











