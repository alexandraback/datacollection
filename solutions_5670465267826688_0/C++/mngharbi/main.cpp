#include <bits/stdc++.h>

#define all(c) c.begin(),c.end()
#define ll long long
#define ii pair <ll ,ll>
#define iii pair <int, ii >
#define vi vector <int>
#define vii vector < ii >
#define viii vector < iii >
#define oo numeric_limits<ll>::max()
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define MAXN 100000

using namespace std;

int op (int a,int b) {
    if(a==-2 || b==-2)
        return -2;
    if(a==-1) {
        switch (b) {
            case -1: return 1; break;
            case 1: return -1; break;
            case 2: return 3; break;
            case 3: return 2; break;
            case 4: return 5; break;
            case 5: return 4; break;
            case 6: return 7; break;
            case 7: return 6; break;
        }
    }
    if(a==1) {
        return b;
    }
    if(a==2) {
        switch (b) {
            case -1: return 3; break;
            case 1: return 2; break;
            case 2: return -1; break;
            case 3: return 1; break;
            case 4: return 6; break;
            case 5: return 7; break;
            case 6: return 5; break;
            case 7: return 4; break;
        }
    }
    if(a==3) {
        switch (b) {
            case -1: return 2; break;
            case 1: return 3; break;
            case 2: return 1; break;
            case 3: return -1; break;
            case 4: return 7; break;
            case 5: return 6; break;
            case 6: return 4; break;
            case 7: return 5; break;
        }
    }
    if(a==4) {
        switch (b) {
            case -1: return 5; break;
            case 1: return 4; break;
            case 2: return 7; break;
            case 3: return 6; break;
            case 4: return -1; break;
            case 5: return 1; break;
            case 6: return 2; break;
            case 7: return 3; break;
        }
    }
    if(a==5) {
        switch (b) {
            case -1: return 4; break;
            case 1: return 5; break;
            case 2: return 6; break;
            case 3: return 7; break;
            case 4: return 1; break;
            case 5: return -1; break;
            case 6: return 3; break;
            case 7: return 2; break;
        }
    }
    if(a==6) {
        switch (b) {
            case -1: return 7; break;
            case 1: return 6; break;
            case 2: return 4; break;
            case 3: return 5; break;
            case 4: return 3; break;
            case 5: return 2; break;
            case 6: return -1; break;
            case 7: return 1; break;
        }
    }
    if(a==7) {
        switch (b) {
            case -1: return 6; break;
            case 1: return 7; break;
            case 2: return 5; break;
            case 3: return 4; break;
            case 4: return 2; break;
            case 5: return 3; break;
            case 6: return 1; break;
            case 7: return -1; break;
        }
    }
}

int V[10000];
int R[10000][10000];

int main()
{
    freopen("input.in","r+",stdin);
    freopen("output.txt","w+",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T,L,X,k;
    char c;
    cin >> T;
    for(int t=1;t<=T;t++) {
        cin >> L >> X;
        for(int i=0;i<L;i++) {
            cin >> c;
            switch(c) {
                case 'i':k=2;break;
                case 'j':k=4;break;
                case 'k':k=6;break;
            }
            V[i] = k;
        }
        for(int i=1;i<X;i++)
            for(int j=0;j<L;j++)
                V[i*L+j] = V[j];
        memset(R,-2,sizeof(R));
        R[0][0] = V[0];
        for(int i=1;i<L*X;i++) {
            R[i][i] = V[i];
            for(int j=0;j<i;j++) {
                R[j][i] = op(R[j][i-1],V[i]);
            }
        }
        bool found = false;
        for(int a=0;a<L*X-2;a++) {
            int first = R[0][a];
            for(int b=a+1;b<L*X-1;b++) {
                int second = R[a+1][b];
                int third = R[b+1][L*X-1];
                if(first == 2 && second == 4 && third == 6) {
                    found = true;
                    break;
                }
            }
            if(found) break;
        }
        cout << "Case #" << t << ": ";
        if(found)
            cout << "YES";
        else
            cout << "NO";
        cout << endl;
    }
    return 0;
}
