#include<bits/stdc++.h>
using namespace std;

void next(int c[],int n)
{
    for(int i=n-2;i>=1;i--)
    {
        if(c[i]==1)
            c[i]=0;
        else
        {
            c[i]=1;
            break;
        }
    }
}

unsigned long long int res(unsigned long long int n)
{
    for(unsigned long long int i=2;i*i<=n;i++)
    {
        if(n%i==0)
            return i;
    }
    return 1;
}

int main()
{
    ofstream fout ("C-small-attempt0.out");
    ifstream fin ("C-small-attempt0.in");
    int t;
    fin >> t;
    for(int i=1;i<=t;i++)
    {
        int n,j;
        fin >> n >> j;
        fout << "Case #"<<i<<":"<<endl;
        int a[n+1];
        a[0]=1;
        a[n-1]=1;
        for(int k=1;k<=n-2;k++)
            a[k]=0;
        for(int k=1;k<=j;next(a,n))
        {
            int flag=0;
            vector<unsigned long long int>v;
            unsigned long long int ten=0;
            for(unsigned long long int p=0;p<n;p++)
            {
                ten=ten*10+a[p];
            }
            v.push_back(ten);
            for(unsigned long long int x=2;x<=10;x++)
            {
                unsigned long long int temp=0;
                for(unsigned long long int p=0;p<n;p++)
                {
                    temp=temp*x+a[p];
                }
                unsigned long long int temp_res=res(temp);
                if(temp_res==1)
                {
                    flag=1;
                    break;
                }
                else
                {
                    v.push_back(temp_res);
                }
            }
            if(flag==0)
            {
                for(int p=0;p<v.size();p++)
                    fout << v[p] << " ";
                fout << endl;
                k++;
            }
        }
    }
    return 0;
}
