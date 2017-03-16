#include<iostream>
#include<cstdio>
#include<cmath>
#include<fstream>

using namespace std;

int dp[55][55][2600][2];
int rr,cc,mm;

int recur(int r,int c,int m,int f) {
    //cout << r << " " << c << " " << m <<  " " << f << endl;
    if(m == 0) return 1;
    if(m > r*c) return 0;
    if(r == 1) return 1;
    if(r == 2) {
        if(f==0) {
            //cout << ((m<=r*c-4) && (m%2 == 0)) << " ";
            return dp[r][c][m][f] = ((m<=r*c-4) && (m%2 == 0));
        } else {
            //cout << m%2 << " ";
            return dp[r][c][m][f] = m%2==0;
        }
    }
    //if(dp[r][c][m][f] != -1) return dp[r][c][m][f];
    bool ff = 0;
    for(int i=0;i<c;i++) {
        if(!f&&i==1) continue;
        if(m-(c-i) < 0) continue;
        ff |= recur(r-1,c-i,m-(c-i),(f==0)?(i!=0):f);
        if(ff) break;
    }
    return dp[r][c][m][f] = ff;
}

void doit(int r,int c,int m,int f) {
    //cout << r << " " << c << " " << m << " " << f << endl;
    if(m == 0) {
        for(int i=0;i<r;i++) {
            for(int j=0;j<cc;j++) {
                    if(i==0&&j==0) cout << "c";
                    else cout << ".";
            }
            cout << endl;
        }
        return;
    }
    if(m > r*c) return;
    if(r == 1) {
        cout << "c";
        for(int i=1;i<cc;i++) {
            if(i>=(cc-m)) cout << "*";
            else cout << ".";
        }
        cout << endl;
        return;
    }
    //cout << r << " ";
    //cout << m << " ";
    if(r == 2) {
        //cout << r << " " << m << " ";
        if(f == 0) {
            if(m<=r*c-4 && m%2 == 0) {
                doit(r-1,c,m/2,0);
                //cout << 5;
                for(int i=0;i<cc;i++) {

                    if(i>=(cc-(m/2))) cout << "*";
                    else cout << ".";
                }
                cout << endl;
                return;
            }
        } else {
                if(m%2 == 0) {
                    doit(r-1,c,m/2,1);
                    //cout << 5;
                    for(int i=0;i<cc;i++) {
                        if(i>=(cc-(m/2))) cout << "*";
                        else cout << ".";
                    }
                    cout << endl;
                    return;
                }
        }
    }

    for(int i=0;i<c;i++) {
        if(!f&&i==1) continue;
        if(m-(c-i) < 0) continue;
        if(recur(r-1,c-i,m-(c-i),(f==0)?(i!=0):f) == 1) {
            doit(r-1,c-i,m-(c-i),(f==0)?(i!=0):f);
            int xx = c-i;
            //cout << "x";
            for(int j=0;j<cc-xx;j++) cout << ".";
            for(int j=cc-xx;j<cc;j++) cout << "*";
            cout << endl;
            break;
        }
    }
    return;
}

int main()
{
    freopen("C-small-attempt8.in","r",stdin);
    freopen("output.txt","w",stdout);

    int t;
    cin >> t;
    for(int i=0;i<6;i++) for(int j=0;j<6;j++)
            for(int k=0;k<50;k++) dp[i][j][k][0] = dp[i][j][k][1] = -1;
    for(int te=1;te<=t;te++) {
        int r,c,m;
        cin >> rr >> cc >> m;

        cout << "Case #" << te << ": \n";
        if(m == rr*cc-1) {
            for(int i=0;i<rr;i++) {
                for(int j=0;j<cc;j++) {
                    if(i == 0 && j == 0) cout << "c";
                    else cout << "*";
                }
                cout << endl;
            }
            continue;
        }
        if(recur(rr,cc,m,0) == 0) {
            cout << "Impossible\n";
        } else {
            doit(rr,cc,m,0);
        }
    }
    return 0;
}









