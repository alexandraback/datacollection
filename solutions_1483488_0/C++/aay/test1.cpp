#include<iostream>

using namespace std;

const int decpow[]={1,1e1,1e2,1e3,1e4,1e5,1e6,1e7,1e8};

inline int next(int x,int count){
    return (x%(decpow[count-1]))*10+x/(decpow[count-1]);
}

int main(){
    int N;
    cin>>N;
    
    for(int i=1;i<=N;++i){
        int A,B,tmp;
        cin>>A>>B;
        int count=1;
        tmp=A;
        while(tmp/=10)
            ++count;
        int result=0;
        if(count>1)
        for(int x=A;x<=B;++x){
            int t=next(x,count);
            while(t!=x){
                if(t>x&&t<=B)
                    ++result;
                t=next(t,count);
            }
        }
        cout<<"Case #"<<i<<": "<<result<<endl;
    }
    return 0;
}

