#include<iostream>
#include<vector>
using namespace std;

int main()
{
        int n;
        cin>>n;
        for(int i=1;i<=n;i++){
                int x,s,p,y,count=0;
                cin>>x>>s>>p;
                vector<int> v(x);
                for(int j=0;j<x;j++) cin>>v[j];
                for(int j=0;j<x;j++){
                        int ch=v[j]%3;
                        if(ch==0 && ( (v[j]/3) ) >= p ) count++;
                        else if(ch==0 && s >0 && ( (v[j]/3)+1 ) >= p && v[j] > 0) count++,s--;
                        if(ch==1 && ( (v[j]/3)+1 ) >= p ) count++;
                        if(ch==2 && ( (v[j]/3)+1 ) >= p ) count++;
                        else if(ch==2 && ( (v[j]/3)+2 ) >= p && s > 0) s--,count++;
                        
                }
                cout<<"Case #"<<i<<": "<<count<<endl;
        }
        return 0;
}
