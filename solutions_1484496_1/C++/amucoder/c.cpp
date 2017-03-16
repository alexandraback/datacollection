#include<iostream>
#include<algorithm>
#include<map>

using namespace std;

int main()
{
    map<int,int> mymap;
    int count=0,bm,T,S,arr[25],sum,i,j,k,ts,tmp,flag;
    cin>>T;
    while(T--)
    {
        mymap.clear();
        sum=0;flag=0;
        cin>>S;
        for(i=0;i<S;i++)
        {
            cin>>arr[i];
            sum+=arr[i];
        }
        bm=0;
        cout<<"Case #"<<++count<<":\n";
        for(bm=1;bm<(1<<S);bm++)
        {
            ts=0;
            for(i=0;i<S;i++)
                if((bm & (1<<i)) >0)
                    ts+=arr[i];
            if(ts <=(sum/2)){
                tmp = mymap[ts];
                if(tmp==0) //no value
                {    mymap[ts]=bm;
                    //cout<<"adding "<<ts<<" "<< bm<<endl;
                }
                else{
                    //cout<<"found tmp = "<<tmp<<"bm = "<<bm<<endl;
                    for(i=0;i<S;i++)
                       if(((bm&(1<<i))>0) && ((tmp&(1<<i))==0))
                            cout<<arr[i]<<" ";
                        cout<<endl;
                    for(i=0;i<S;i++)
                       if(((bm&(1<<i))==0) && ((tmp&(1<<i))>0))
                            cout<<arr[i]<<" ";
                            cout<<endl;
                    flag=1;
                    break;
                }
            }
        }
        if(flag==0) cout<<"Impossible"<<endl;
    }
    return 0;
}
