#include<bits/stdc++.h>
using namespace std;
int mark[29];
vector<int> Ans;
int main()
{
   freopen("B-small-attempt1.in","r",stdin);
    freopen("CJ2B12.txt","w",stdout);
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
        string s1,s2;
        cin>>s1>>s2;
        int l1=s1.length();
        int l2=s2.length();
        queue<string> Q1,Q2;
        Q1.push("");
        Q1.push("-1");
        for(int v=0;v<l1;v++)
        {
            if(s1[v]!='?')
            {
               // cout<<s1[v]<<"here\n" ;
                while(Q1.front()!="-1")
                {
                    string top=Q1.front();
                    top=top+s1[v];
                    Q1.push(top);
                    Q1.pop();
                }
                Q1.push("-1");
                Q1.pop();
                continue;
            }
            while(Q1.front()!="-1")
                {


                    string top=Q1.front();
                    for(int k=0;k<=9;k++)
                        {
                            char c=k+'0';
                            string xt=top+(c);
                            Q1.push(xt);
                 //           cout<<xt<<"this\n";
                        }
                        Q1.pop();
                }
                Q1.push("-1");
                Q1.pop();

        }
        Q2.push("");
        Q2.push("-1");
        for(int v=0;v<l2;v++)
        {
            if(s2[v]!='?')
            {
                while(Q2.front()!="-1")
                {
                    string top=Q2.front();
                    top=top+(s2[v]);
                    Q2.push(top);
                    Q2.pop();
                }
                Q2.push("-1");
                Q2.pop();
                continue;
            }
            while(Q2.front()!="-1")
                {
                    string top=Q2.front();
                    for(int k=0;k<=9;k++)
                        {
                            char c=k+'0';
                            string xt=top+c;
                            Q2.push(xt);
                        }
                        Q2.pop();
                }
                Q2.push("-1");
                Q2.pop();
        }
        vector<pair<string,int> > A1,A2;
       // cout<<"1"<<"\n";
        while(Q1.front()!="-1")
        {
            string top=Q1.front();
            int p=top.length();
            int lo=0;
            for(int m=0;m<p;m++)
            {
                lo=lo*10+(top[m]-'0');
            }
         //   cout<<top<<" ";
            A1.push_back(make_pair(top,lo));
            Q1.pop();
        }
        //cout<<endl;
        while(Q2.front()!="-1")
        {
            string top=Q2.front();
            int p=top.length();
            int lo=0;
            for(int m=0;m<p;m++)
            {
                lo=lo*10+(top[m]-'0');
            }
            A2.push_back(make_pair(top,lo));
            //A2.push_back(top);
            Q2.pop();
        }
        sort(A1.begin(),A1.end());
        sort(A2.begin(),A2.end());
        int siz1=A1.size();
        int siz2=A2.size();
        //cout<<siz1<<siz2<<"\n";
        int mdif=100000,ind1=-1,ind2=-1;
        for(int j=0;j<siz1;j++)
        {

            for(int k=0;k<siz2;k++)
            {
               int dif=abs(A1[j].second-A2[k].second);
               if(dif<mdif)
               {
                   mdif=dif;
                   ind1=j;
                   ind2=k;
               }
            }
        }
        printf("Case #%d: ",i);
        cout<<A1[ind1].first<<" "<<A2[ind2].first<<endl;
        A1.clear();
        A2.clear();


    }
    return 0;
}
