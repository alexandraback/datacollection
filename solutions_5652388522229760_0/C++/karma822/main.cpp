#include <iostream>

using namespace std;

void solve(int N){
    if(N==0){
        cout<<"INSOMNIA"<<endl;
        return;
    }
    int count = 0;
    int array[10]={0};
    long long int num = N;
    long long int mul=0;
    
    while(count<10){
        mul++;
        num=N*mul;
        while(num>0){
            int n=num%10;
            if(!array[n]){
                count++;
                array[n]=1;
            }
            num/=10;
        }
    }
    cout<<N*mul<<endl;
}

int main(int argc, const char * argv[]) {
    int T;
    scanf("%d", &T);
    for(int i=0;i<T;i++){
        int N;
        scanf("%d", &N);
        cout<<"Case #"<<i+1<<": ";
        solve(N);
    }
    return 0;
}
