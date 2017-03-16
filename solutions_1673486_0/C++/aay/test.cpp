#include<iostream>
#include<vector>
#include<iomanip>

using namespace std;

int main(){
    int N;
    cin>>N;
    for(int num=1;num<=N;++num){
        int A,B;
        cin>>A>>B;
        vector<double> p;
        p.push_back(1);
        double result=B+2,total=1;
        for(int i=0;i<A;++i){
            double tmp;
            cin>>tmp;
            total*=tmp;
            p.push_back(total);
        }
        double r2=total*(B-A+1)+(1-total)*(2*B-A+2);
        if(r2<result)
            result=r2;
        for(int i=1;i<=A;++i){
            double r2=p[A-i]*(B-(A-i)+1)+(1-p[A-i])*(2*B-(A-i)+2);
            if(r2+i<result)
                result=r2+i;
        }
        cout<<"Case #"<<num<<": "<<setprecision(6)<<setiosflags(ios::fixed)<<result<<endl;
    }
    return 0;
}
