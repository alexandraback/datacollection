#include <fstream>
#include<iostream>
#include <string>
#include <map>
using namespace std;



long long int swap(long long int n){
    long long ans=0;
    while (n){
        ans=ans*10+n%10;
        n/=10;
    }
    return ans;
}
long long int dg(long long int n){
    long long ans=0;
    while (n){
        ans++;
        n/=10;
    }
    return ans;
}
long long  solve(long long  n)
{
    long long count=0;
    long long tn=1;

    while (n!=1){
        tn=1;
        for (int i=0;i<dg(n)/2;i++)
            tn*=10;
        if (n-1<swap(n)||n%tn!=1||n%10==0){
            if (n%tn>1)
            {
                count+=n%tn-2;
                n-=n%tn-2;
            }
            n--;
        }else n=swap(n);
        count++;
    }
    return count;
}

int main(){
    int T;
    ifstream f("input.txt");
    ofstream w("output.txt");
    f>>T;
    for (int tests=0;tests<T;tests++)
    {
        long long int n;
        f>>n;

        long long count=solve(n);


        w<<"Case #"<<(tests+1)<<": "<<(count+1)<<endl;
    }
    f.close();
    w.close();


    return 0;
}

