#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;

int main(){
    freopen("A-small-attempt0.in", "r", stdin);
    freopen("out.txt", "w", stdout);

    int t;
    cin>>t;
    int h[27];

    string T[10]={"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};

    //cout<<T[0]<<endl;

    for(int k=1; k<=t; k++){
        memset(h, 0, sizeof h);
        string S;
        cin>>S;
        for(int i=0; i<S.size(); i++){
            h[S[i]-'A']++;
        }
        //cout<<"yes\n";
        vector<int>ans;
        int c;
        c=h['Z'-'A'];
        for(int i=0; i<c; i++){
            ans.push_back(0);
        }
        for(int i=0; i<T[0].size(); i++){
            h[T[0][i]-'A']-=c;
        }

        c=h['U'-'A'];
        for(int i=0; i<c; i++){
            ans.push_back(4);
        }
        for(int i=0; i<T[4].size(); i++){
            h[T[4][i]-'A']-=c;
        }

        c=h['W'-'A'];
        for(int i=0; i<c; i++){
            ans.push_back(2);
        }
        for(int i=0; i<T[2].size(); i++){
            h[T[2][i]-'A']-=c;
        }

        c=h['G'-'A'];
       for(int i=0; i<c; i++){
            ans.push_back(8);
        }
        for(int i=0; i<T[8].size(); i++){
            h[T[8][i]-'A']-=c;
        }

        c=h['X'-'A'];
        for(int i=0; i<c; i++){
            ans.push_back(6);
        }
        for(int i=0; i<T[6].size(); i++){
            h[T[6][i]-'A']-=c;
        }

        c=h['T'-'A'];
        for(int i=0; i<c; i++){
            ans.push_back(3);
        }
        for(int i=0; i<T[3].size(); i++){
            h[T[3][i]-'A']-=c;
        }

        c=h['O'-'A'];
        for(int i=0; i<c; i++){
            ans.push_back(1);
        }
        for(int i=0; i<T[1].size(); i++){
            h[T[1][i]-'A']-=c;
        }

        c=h['F'-'A'];
        for(int i=0; i<c; i++){
            ans.push_back(5);
        }
        for(int i=0; i<T[5].size(); i++){
            h[T[5][i]-'A']-=c;
        }

        c=h['S'-'A'];
        for(int i=0; i<c; i++){
            ans.push_back(7);
        }
        for(int i=0; i<T[7].size(); i++){
            h[T[7][i]-'A']-=c;
        }

        c=h['I'-'A'];
        for(int i=0; i<c; i++){
            ans.push_back(9);
        }
        for(int i=0; i<T[9].size(); i++){
            h[T[9][i]-'A']-=c;
        }
        sort(ans.begin(), ans.end());
        cout<<"Case #"<<k<<": ";
        for(int i=0; i<ans.size(); i++){
            cout<<ans[i];
        }
        cout<<endl;
    }

    return 0;
}
