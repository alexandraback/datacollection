#include <vector>
#include <algorithm>

#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <cmath>
using namespace std;
int res[2000001]={0};
int main()
{
     //	freopen("D:\\GCJ 2012\\C-small-attempt0.in","r",stdin);freopen("D:\\GCJ 2012\\C-small-attempt0.out","w",stdout);
    	freopen("D:\\GCJ 2012\\C-small-attempt1.in","r",stdin);freopen("D:\\GCJ 2012\\C-small-attempt1.out","w",stdout);
    //	freopen("D:\\GCJ 2012\\C-large.in","r",stdin);freopen("D:\\GCJ 2012\\C-large.out","w",stdout);
      int testcase;
    char flag[100];
    cin>>testcase;
    cin.getline(flag,100);
    for (int caseId=1;caseId<=testcase;caseId++)
    {
        int N;
        cin>>N;
        int a[501];
        for(int i=0;i<N;i++)
        {
            cin>>a[i];
        }
        sort(a,a+N);
        for(int i=0;i<200001;i++)res[i]=0;
        vector <int> asw;
        vector <string> kk;
        int q=-1;
        for(int i=0;i<N;i++)
        {
            int n=asw.size();
            char tep='a'+i;
            string t="";
            t+=tep;
            for(int j=0;j<n;j++)
            {
                asw.push_back(asw[j]+a[i]);
                res[asw[j]+a[i]]++;
                kk.push_back(kk[j]+tep);
                if(res[asw[j]+a[i]]>1)
                {
                    q=asw[j]+a[i];
                }
            }
            asw.push_back(a[i]);
            kk.push_back(t);
            res[a[i]]++;
            if(q!=-1)i=N+1;
        }
        printf("Case #%d:\n",caseId);
        if(q==-1)cout<<"Impossible"<<endl;
        else {
            for(int i=0;i<asw.size();i++)
            {
                if(asw[i]==q)
                {
                    for(int j=0;j<kk[i].size()-1;j++)
                    {
                        cout<<a[kk[i][j]-'a']<<" ";
                    }
                    cout<<a[kk[i][kk[i].size()-1]-'a']<<endl;
                }
            }
        }
    }
    return 0;
}