#include<bits/stdc++.h>
using namespace std;
long long rev( long long n){

    string s="";
    while(n){

        s+=(char)((n%10)+'0');
        n/=10;
    }
    int l = s.length();
    for(int i = 0; i < l; ++i){
        n = n*10 + (s[i]-'0');
    }
    return n;

}
long long a[1000010];
int main()
{
    int T;
    long long N;
    ifstream cin("A-small-attempt0.in");
    ofstream cout("opppp.txt");
    for(int i=1;i<=1000000;++i)a[i]=INT_MAX;
    for(int i = 1;i<=20;i++)a[i]=i;
    for(int i=21;i<=1000000;++i){
            if(rev(rev(i))==i)a[i]=min(a[i-1],a[rev(i)])+1;
            else a[i]=a[i-1]+1;
    }
    cin >> T;
    //for(N = 21; N <= 100; ++N){
    for(int tt=1;tt<=T;tt++){
        cin >> N;
        /*long long a = 0;
        for(long long i = 1; i <= N; ){
            a++;
            if(rev(i) <= N)
                i=max(i+1,rev(i));
            else i = i+1;
            //cout << i << " ";

        }*/
        //cout << endl;
        cout<<"Case #"<<tt<<": ";
        cout << a[N] <<endl;


    }

    return 0;
}

