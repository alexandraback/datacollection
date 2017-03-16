#include <iostream>
#include <vector>
#include <set>
#include <string>

#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;

int tt,n,t,sieve[10010],a[32], r[11];
vector<int> prime;
set<string> s;

int m[1000][11][32];

int main(){
    cin>>tt;
    for(int i=2;i<10000;i++){
        if(sieve[i]>0)continue;
        prime.push_back(i);
        int j = i;
        while(j<10000){sieve[j]=1;j+=i;}
    }

    for(int i=0;i<1000;i++){
        int p = prime[i];
        for(int b=2;b<=10;b++){
            m[i][b][0] = 1;
            for(int k=1;k<=31;k++){
                m[i][b][k] = m[i][b][k-1]*b%p;
            }
        }
    }

    rep(ii,tt){
        cin >> n >> t; a[0] = 1;a[n-1] = 1;
        cout << "Case #"<<ii+1<<": "<<endl;
        while(t > 0)
        {
            for(int i=2;i<n-1;i++)
            {
                a[i] = rand()%2;
            }

            bool valid = true;
            for(int b=2;b<=10;b++){
                int i = 0;
                r[b] = -1;
                for(i=0;i<1000;i++){
                    int p = prime[i];
                    int ans = 0;
                    for(int j=0;j<n;j++){
                        ans  = (ans + (a[j] ? m[i][b][j] : 0))%p;
                    }
                    if(ans == 0){
                        r[b] = p;
                        break;
                    }
                }
                if(i==1000){
                    valid = false;
                    break;
                }
            }


            if(valid){
                string res;
                rep(i,n)res += '0'+a[n-i-1];
                if(s.find(res)==s.end()){
                    cout << res << " ";
                    for(int b=2;b<=10;b++)cout<<r[b]<<" ";cout<<endl;
                    t--;
                    s.insert(res);
                }
            }
        }
    }



}

