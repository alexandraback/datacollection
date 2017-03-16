#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#include <vector>
using namespace std;
double v1,v2,p1,p2,dis;
const double eps=1e-10;
int dcmp(double x1)
{
    if(x1>eps) return 1;
    else if(x1<-eps) return -1;
    else return 0;
}
int getAns()
{
    //if(dcmp(v1-v2)==0) return 0;

    double t=dis/(v1-v2);
    double slowerPos=p2+v2*t;
    if(dcmp(slowerPos-360)>0) return 0;
    else return 1;
}
int main()
{
    int T;
    scanf("%d",&T);
    for(int t=1; t<=T; t++)
    {
        printf("Case #%d: ",t);
        int n;
        scanf("%d",&n);
        vector<int> v;
        vector<int> postition;
        for(int i=1; i<=n; i++)
        {
            int d,h,m;
            scanf("%d%d%d",&d,&h,&m);
            for(int j=1; j<=h; j++)
            {
                v.push_back(m+j-1);
                postition.push_back(d);
            }
        }
        double lenth=360.0;
        if(v.size()==1)
        {
            cout<<0<<endl;
            continue;
        }
        else
        {
            p1=v[0]<v[1] ? postition[0] : postition[1];
            p2=v[0]<v[1] ? postition[1] : postition[0];
            v1=min(v[0],v[1]);
            v2=max(v[0],v[1]);
            if(v1==v2)
            {
                cout<<0<<endl;
                continue;
            }

            dis=p2-p1;
            if(dis==0) dis=360;

            v1=lenth/v1;
            v2=lenth/v2;
            if(dis>0 && dis<360)
            {
                double t=dis/(v1-v2);
                double meetPos=p2+v2*t;
                if(dcmp(meetPos-360)>0)
                {
                    cout<<0<<endl;
                    continue;
                }
                else
                {
                    p1=p2=meetPos;
                    dis=360.0;
                    int res=getAns();
                    cout<<res<<endl;
                    continue;
                }
            }
            else
            {
                if(dis<0) dis+=360;
                int res=getAns();
                cout<<res<<endl;
                continue;
            }
        }
    }
    return 0;
}
