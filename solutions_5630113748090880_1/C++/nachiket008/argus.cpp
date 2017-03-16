#include<iostream>
#include<map>
#include<algorithm>
#include<string.h>
using namespace std;

int main()
{
    int i,j,k,x,z,y;
    int N,test;
    cin>>test;
    int ind=0;
    while(test--)
    {
        ind++;
        int arr[105];
        map<int,int> cnt;
        cin>>N;
        for(i=0;i<(2*N-1);i++)
        {
            for(j=0;j<N;j++)
            {cin>>x;
            cnt[x]++;}
        }
        k=0;
        map<int,int> ::iterator gg;
        for(gg=cnt.begin();gg!=cnt.end();gg++)
        {
            //cout<<gg->first<<" "<<gg->second<<endl;
            if(gg->second%2!=0)
                arr[k++]=gg->first;
        }
        sort(arr,arr+N);
        cout<<"Case #"<<ind<<": ";
        for(i=0;i<N;i++)
            cout<<arr[i]<<" ";
        cout<<endl;

    }
}

