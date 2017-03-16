#include <bits/stdc++.h>

using namespace std;

long long simulate(long long N){
    if(N==0) return -1;
    vector<char> has(10, 0);
    int cnt = 0;
    long long i;
    for(i=N;cnt<10;i+=N){
        for(long long j=i;j>0;j/=10){
            if(has[j%10]==0){
                has[j%10]=1;
                ++cnt;
            }
        }
        if(i>0x3FFFFFFFFFFFFFFFll) return -1;
    }
    return i-N;
}

int test()
{   freopen("out.txt", "w", stdout);
    for(int i=0;i<1000000;++i){
        if(i!=0 && (simulate(i)==0 || simulate(i)/i> 31 )) cout <<setw(7) <<  i << " (" << simulate(i)/i << ")";
        //if(simulate(i) > 0 && simulate(i)/i> 61 ) cout <<i << "\n";
    }
    cout << endl;
    exit(0);
}

int main()
{
    int T, N;
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    cin >> T;
    //if(T==0)test();
    for(int i=1;i<=T;++i){
        cin >> N;
        cout << "Case #" << i << ": ";
        if(N==0) cout << "INSOMNIA\n";
        else cout << simulate(N) << "\n";
    }
}
