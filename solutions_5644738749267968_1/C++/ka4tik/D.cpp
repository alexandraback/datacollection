/*
 *Kartik Singal @ ka4tik
 */
#include<bits/stdc++.h>
#define db(x) cerr << #x << ": " << x << endl;
#define db2(x, y) cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define db3(x, y, z) cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
#define db4(a, b, c, d) cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << endl;
#define db5(a, b, c, d, e) cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << endl;
#define db6(a, b, c, d, e, f) cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << " | " << #f << ": " << f << endl;
using namespace std;
#define s(n) scanf("%d",&n)
int main()
{

    freopen("in","r",stdin);
    freopen("out","w",stdout);

    int test;s(test);
    int kase=0;
    while(test--)
    {
        kase++;
        int N;s(N);
        vector<double> a(N);
        vector<double> b(N);
        for(int i=0;i<N;i++)
            cin>>a[i];
        for(int i=0;i<N;i++)
            cin>>b[i];

        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        int a1=0;
        int a2=0;
        double mx;
        double mn;
        vector<bool> used(N,0);
        do
        {
            int ans1=0;
            used.assign(N,0);
            int l=0,r=N-1;
            for(int i=0;i<a.size();i++)
            {
                mn=b[l];
                mx=b[r];
                if(mn<a[i])
                {
                    ans1++;
                    l++;
                }
                else if(mx>a[i])
                    r--;
                else
                {
                    l++;
                    ans1++;
                }
            }
            a1=max(ans1,a1);
            break;
        }while(next_permutation(a.begin(),a.end()));
        sort(a.begin(),a.end());
        used.assign(N,0);
        int ans2=0;
        for(int i=0;i<a.size();i++)
        {
            double mn=2;
            int imn=0;
            double ch=2;
            int ich=0;
            int flag=0;
            for(int j=0;j<b.size();j++)
            {
                if(!used[j])
                {
                    if(b[j]>a[i])
                    {
                        flag=1;
                        ch=min(ch,b[j]);
                        if(ch==b[j])
                            ich=j;
                    }
                    mn=min(mn,b[j]);
                    if(mn==b[j])
                        imn=j;
                }
            }
            if(flag)
                used[ich]=1;
            else
            {
                used[imn]=1;
                ans2++;
            }
        }
        a2=max(a2,ans2);
        reverse(a.begin(),a.end());
        used.assign(N,0);
        ans2=0;
        for(int i=0;i<a.size();i++)
        {
            double mn=2;
            int imn=0;
            double ch=2;
            int ich=0;
            int flag=0;
            for(int j=0;j<b.size();j++)
            {
                if(!used[j])
                {
                    if(b[j]>a[i])
                    {
                        flag=1;
                        ch=min(ch,b[j]);
                        if(ch==b[j])
                            ich=j;
                    }
                    mn=min(mn,b[j]);
                    if(mn==b[j])
                        imn=j;
                }
            }
            if(flag)
                used[ich]=1;
            else
            {
                used[imn]=1;
                ans2++;
            }
        }
        a2=max(a2,ans2);
        printf("Case #%d: %d %d\n",kase,a1,a2);
    }

    return 0;
}

