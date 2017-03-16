#include <iostream>
#include <cstdio>
#include <map>
#define M 504
using namespace std;

int num[M];
bool flag1[M],flag2[M];
map<int,int> mymap;
pair<map<int,int>::iterator,bool> p;

void set(bool aa[],int k,int n)
{
    for(int j=0; j<n; j++)
    {
        if((1<<j)&k)
            aa[j]=1;
    }

}

int main()
{
    freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
    int cas,n,cot,sum,i,j,tmp;
    cin >>cas;

    for(int t=1; t<=cas; t++)
    {
        cin >>n;
        cout<<"Case #"<<t<<":\n";
        for(i=0; i<n; i++)
            cin>>num[i];
        mymap.clear();
        cot=1<<n;

        for(i=0; i<cot; i++)
        {
            sum=0;
            for(j=0; j<n; j++)
            {
                if((1<<j)&i)
                    sum += num[j];
            }
            p = mymap.insert(make_pair(sum,i));
            if(!p.second)
            {
                tmp=mymap[sum];
                for(j=0; j<M; j++)
                    flag1[j] = flag2[j] = false;
                set(flag1,i,n);
                set(flag2,tmp,n);

                for(j=0; j<n; j++)
                    if(flag1[j] && !flag2[j])
                    {
                        cout<<num[j];
                        break;
                    }
                for(j=j+1; j<n; j++)
                {
                    if(flag1[j] && !flag2[j])
                        cout<<" "<<num[j];
                }
                cout<<endl;
                for(j=0; j<n; j++)
                    if(flag2[j] && !flag1[j])
                    {
                        cout<<num[j];
                        break;
                    }
                for(j=j+1; j<n; j++)
                    if(flag2[j] && !flag1[j])
                        cout<<" "<<num[j];
                cout<<endl;
                break;
            }
        }
        if(i == cot)
            cout<<"Impossible"<<endl;
    }
    return 0;
}




