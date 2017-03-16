#include <bits/stdc++.h>

using namespace std;

int a[1001];
vector<int> v1;
map<int,int> mp1;

int power(int b,int e)
{
    if(e==0)
    {
        return 1;
    }
    else if(e==1)
    {
        return b;
    }
    else
    {
        int p=power(b,e/2);

        if(e%2==0)
        {
            return (p*p);
        }
        else
        {
            return (p*p*b);
        }
    }
}

int main()
{
    int t;
    FILE *ftr=fopen("input.txt","r");
    FILE *ftr1=fopen("output.txt","w");
    fscanf(ftr,"%d",&t);

    for(int t1=1;t1<=t;t1++)
    {
        int c,d,v;
        fscanf(ftr,"%d%d%d",&c,&d,&v);
        mp1.clear();
        v1.clear();

        for(int i=0;i<d;i++)
        {
            int temp;
            fscanf(ftr,"%d",&temp);
            a[i]=temp;
        }

        int counter1=power(2,d);
        //printf("%d..\n",counter1);

        for(int i=0;i<counter1;i++)
        {
            int sum1=0;
            int temp1=i;
            int temp2=2;
            for(int j=0;j<d;j++)
            {
                if(temp1%2!=0)
                {
                    sum1=sum1+a[j];
                }
                temp1=temp1/2;
            }

            if(mp1.count(sum1)==0)
            {
                mp1[sum1]=1;
                //v1.push_back(sum1);
            }
        }

        int answer1=0;

        for(int i=1;i<=v;i++)
        {
            if(mp1.count(i)==0)
            {
                answer1++;
                vector<int> v2;

                for(map<int,int>::iterator it=mp1.begin();it!=mp1.end();it++)
                {
                    pair<int,int>t1=(*it);
                    v2.push_back(t1.first+i);
                }

                for(vector<int>::iterator it=v2.begin();it!=v2.end();it++)
                {
                    if(mp1.count((*it))==0)
                    {
                        mp1[(*it)]=1;
                    }
                }
            }
        }
        fprintf(ftr1,"Case #%d: %d\n",t1,answer1);
    }
return 0;}