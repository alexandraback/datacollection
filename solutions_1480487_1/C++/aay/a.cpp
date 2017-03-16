#include<iostream>
#include<vector>
#include<iomanip>

using namespace std;

int main(){
    int N;
    cin>>N;
    for(int num=1;num<=N;++num){
        int T;
        cin>>T;
        int sum=0;
        vector<int> data;
        for(int i=0;i<T;++i){
            int tmp;
            cin>>tmp;
            sum+=tmp;
            data.push_back(tmp);
        }
        int count=0,sum2=0;
        for(int i=0;i<T;++i){
            if(data[i]>=(2.0*sum/T)){
                ++count;
                sum2+=data[i];
            }
        }
        cout<<"Case #"<<num<<":"<<setprecision(6)<<setiosflags(ios::fixed);
        for(int i=0;i<T;++i){
            cout<<" ";
            double tmp;
            tmp=100.0*((2.0*sum-sum2)/(T-count)-data[i])/sum;
            if(tmp<0)tmp=0;
            cout<<tmp;
        }
        cout<<endl;
    }
    return 0;
}
