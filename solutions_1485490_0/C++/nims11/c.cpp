#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
struct item
{
    long long type,count;
};
int main()
{
    int t;
    cin>>t;
    for(int z=1;z<=t;z++)
    {
        int n,m;
        cin>>n>>m;
        vector<struct item>toys,boxes;
        int k1=0,k2=0;
        for(int i=0;i<n;i++)
        {
            struct item x;
            cin>>x.count>>x.type;
            if(i==0)
            {
                toys.push_back(x);
                continue;
            }

            if(x.type!=toys[toys.size()-1].type)
            toys.push_back(x);
            else
            {
                toys[toys.size()-1].count+=x.count;
                k1++;
            }
        }
        for(int i=0;i<m;i++)
        {
            struct item x;
            cin>>x.count>>x.type;
            if(i==0)
            {
                boxes.push_back(x);
                continue;
            }
            if(x.type!=boxes[boxes.size()-1].type)
            boxes.push_back(x);
            else
            {
                boxes[boxes.size()-1].count+=x.count;
                k2++;
            }
        }
        int start1=0,start2=0,end1=n-1-k1,end2=m-1-k2;
        long long ans=0;


        for(int i=0;i<=end1 && start2<=end2;i++)
        {
            long long sacrifice=0;
            long long gain=0;
            int j;
            for(j=start2;j<=end2;j++)
            {
                if(boxes[j].type!=toys[i].type)
                {
                    for(int k=i+1;k<=end1;k++)
                    {
                        if(boxes[j].type==toys[k].type)
                        sacrifice+=min(toys[k].count,boxes[j].count);
                    }

                }else
                {
                    gain=min(boxes[j].count,toys[i].count);
                    break;
                }
            }
            if(gain>sacrifice)
            {
                ans+=gain;
                boxes[j].count-=gain;
                if(boxes[j].count==0)
                j++;
                start2=j;
                toys[i].count-=gain;
                if(toys[i].count!=0)
                i--;
            }
        }
        cout<<"Case #"<<z<<": "<<ans<<endl;
    }
    return 0;
}
