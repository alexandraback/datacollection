#include <bits/stdc++.h>
#define fore(i,j,k) for(int i = j;i<k;i++)
#define forr(i,j,k) for(int i = j;i>k;i--)
#define LL long long

using namespace std;

int J,P,S,k;
int ans [1001][3],cnt = 0;

void rec (int jp[3][3],int ps[3][3], int js[3][3], int jps[3][3][3]){

    fore(j,0,J)
        fore(p,0,P)
            fore(s,0,S)
                if((!jps[j][p][s]) && (jp[j][p]<k) && (js[j][s]<k) && (ps[p][s]<k)){
                    jp[j][p] ++; js[j][s] ++; ps[p][s]++; jps[j][p][s] = 1;
                    rec(jp,ps,js,jps);
                    ans[cnt][0] = j;
                    ans[cnt][1] = p;
                    ans[cnt][2] = s;
                    cnt++;
                    break;
                }

}

int main () {
    ios_base :: sync_with_stdio(false);

    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int t;
    cin >> t;

    fore(tc,1,t+1){
        cout << "case #" << tc << ": ";
        cin >> J >> P >> S >> k;
        cnt = 0;
        int jp[3][3] = {0},js[3][3] = {0},ps[3][3] = {0},jps[3][3][3] = {0};
        rec(jp,ps,js,jps);
        cout << cnt << endl;
        fore(i,0,cnt)
            cout << ans[i][0]+1 << " " << ans[i][1]+1 << " " << ans [i][2]+1 << endl;

    }



    return 0;
}

/// flaw = orders are indeed not in order
