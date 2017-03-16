#include<iostream>

using namespace std;


int main(){
    int T;
    cin>>T;
    for(int i=1;i<=T;++i){
        int N,S,p,count=0;
        cin>>N>>S>>p;
        for(int j=0;j<N;++j){
            int tmp;
            cin>>tmp;
            if(tmp>=3*p-2){
                ++count;
                continue;
            }
            if(S>0&&tmp>=3*p-4&&p>=2){
                --S;
                ++count;
            }
        }
        cout<<"Case #"<<i<<": "<<count<<endl;;
    }
    return 0;
}
