
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <deque>
#include <stack>
#include <cmath>
#include <cstdio>
#include <cctype>
#include <cstdlib>
#include <climits>
#include <set>
#include <map>
#include <numeric>
#include <ctime>
#include <functional>
#include <queue>

using namespace std;

int main()
{
    FILE *f,*fw;
    int t,n1,n2;
    char c;
    int i=0,j;
    double ans,pi,strokes,temp,p_cal;
    string s;
    vector<double> p;
    f=fopen("A-large.in","r");
    fw=fopen("ans1_1.txt","w");
    fscanf(f,"%d",&t);
    //cin>>t;
    //while (i>=0)
    //{
    //      if (i%100000==0)cout<<i<<" ";i+=100000;}
    //system("pause");
    //cout<<t;
    //system("pause");
    for (i=0;i<t;i++)
    {
        fscanf(f,"%d%d",&n1,&n2);
        //cin>>n1>>n2;
        p.clear();
        for (j=0;j<n1;j++)
        {
            fscanf(f,"%lf",&pi);
            //cin>>pi;
            p.push_back(pi);
        }
        ans=n2+2;
        p_cal=1;
        for (j=0;j<n1;j++)
        {
            p_cal*=p[j];
            strokes=n2-n1+1+2*(n1-j-1);
            temp=p_cal*strokes+(1.0-p_cal)*(strokes+(double)n2+1.0);
            if (temp<ans)
               ans=temp;
        }        
        cout<<"Case #"<<i+1<<": "<<ans<<endl;
        fprintf(fw,"Case #%d: %.6lf\n",i+1,ans); 
        //system("pause");
    }
        
    fclose(fw);    
    //fclose(f);
    system("pause");
    return 0;
}
