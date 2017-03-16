#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
ll tc,len,mnv,mns;
char a[22],b[22],cur[22];
char ma[22],mb[22];

void solve(ll idx) {
    ll i, ia, ib;
    if(len==idx) {
        for(i=0;i<len;i++) {
            ma[i] = cur[i];
            mb[i] = cur[i];
        }
        return;
    }
    if(a[idx]=='?' && b[idx]=='?') {
        ia = 0, ib = 0;
        for(i=0;i<idx;i++) {
            ia *= 10; ia += cur[i]-'0';
            ib *= 10; ib += cur[i]-'0';
        }
        ia *= 10; ia += 1;
        ib *= 10; ib += 0;
        for(i=idx+1;i<len;i++) {
            ia *= 10; ia += (a[i]=='?'?0:a[i]-'0');
            ib *= 10; ib += (b[i]=='?'?9:b[i]-'0');
        }
        if(abs(ia-ib)<mnv || (abs(ia-ib)==mnv && (ia+ib)<mns)) {
            mnv = abs(ia-ib); mns = ia+ib;
            for(i=0;i<idx;i++) {
                ma[i] = cur[i]; mb[i] = cur[i];
            }
            ma[idx] = '1'; mb[idx] = '0';
            for(i=idx+1;i<len;i++) {
                ma[i] = (a[i]=='?'?'0':a[i]);
                mb[i] = (b[i]=='?'?'9':b[i]);
            }
        }
        ia = 0, ib = 0;
        for(i=0;i<idx;i++) {
            ia *= 10; ia += cur[i]-'0';
            ib *= 10; ib += cur[i]-'0';
        }
        ia *= 10; ia += 0;
        ib *= 10; ib += 1;
        for(i=idx+1;i<len;i++) {
            ia *= 10; ia += (a[i]=='?'?9:a[i]-'0');
            ib *= 10; ib += (b[i]=='?'?0:b[i]-'0');
        }
        if(abs(ia-ib)<mnv || (abs(ia-ib)==mnv && (ia+ib)<mns)) {
            mnv = abs(ia-ib); mns = ia+ib;
            for(i=0;i<idx;i++) {
                ma[i] = cur[i]; mb[i] = cur[i];
            }
            ma[idx] = '0'; mb[idx] = '1';
            for(i=idx+1;i<len;i++) {
                ma[i] = (a[i]=='?'?'9':a[i]);
                mb[i] = (b[i]=='?'?'0':b[i]);
            }
        }
        cur[idx] = '0';
        solve(idx+1); return;
    }
    else if(a[idx]=='?') {
        if(b[idx]!='9') {
            ia = 0, ib = 0;
            for(i=0;i<idx;i++) {
                ia *= 10; ia += cur[i]-'0';
                ib *= 10; ib += cur[i]-'0';
            }
            ia *= 10; ia += b[idx]-'0'+1;
            ib *= 10; ib += b[idx]-'0';
            for(i=idx+1;i<len;i++) {
                ia *= 10; ia += (a[i]=='?'?0:a[i]-'0');
                ib *= 10; ib += (b[i]=='?'?9:b[i]-'0');
            }
            if(abs(ia-ib)<mnv || (abs(ia-ib)==mnv && (ia+ib)<mns)) {
                mnv = abs(ia-ib); mns = ia+ib;
                for(i=0;i<idx;i++) {
                    ma[i] = cur[i]; mb[i] = cur[i];
                }
                ma[idx] = b[idx]+1; mb[idx] = b[idx];
                for(i=idx+1;i<len;i++) {
                    ma[i] = (a[i]=='?'?'0':a[i]);
                    mb[i] = (b[i]=='?'?'9':b[i]);
                }
            }
        }
        if(b[idx]!='0') {
            ia = 0, ib = 0;
            for(i=0;i<idx;i++) {
                ia *= 10; ia += cur[i]-'0';
                ib *= 10; ib += cur[i]-'0';
            }
            ia *= 10; ia += b[idx]-'0'-1;
            ib *= 10; ib += b[idx]-'0';
            for(i=idx+1;i<len;i++) {
                ia *= 10; ia += (a[i]=='?'?9:a[i]-'0');
                ib *= 10; ib += (b[i]=='?'?0:b[i]-'0');
            }
            if(abs(ia-ib)<mnv || (abs(ia-ib)==mnv && (ia+ib)<mns)) {
                mnv = abs(ia-ib); mns = ia+ib;
                for(i=0;i<idx;i++) {
                    ma[i] = cur[i]; mb[i] = cur[i];
                }
                ma[idx] = b[idx]-1; mb[idx] = b[idx];
                for(i=idx+1;i<len;i++) {
                    ma[i] = (a[i]=='?'?'9':a[i]);
                    mb[i] = (b[i]=='?'?'0':b[i]);
                }
            }
        }
        cur[idx] = b[idx];
        solve(idx+1); return;
    }
    else if(b[idx]=='?') {
        if(a[idx]!='0') {
            ia = 0, ib = 0;
            for(i=0;i<idx;i++) {
                ia *= 10; ia += cur[i]-'0';
                ib *= 10; ib += cur[i]-'0';
            }
            ia *= 10; ia += a[idx]-'0';
            ib *= 10; ib += a[idx]-'0'-1;
            for(i=idx+1;i<len;i++) {
                ia *= 10; ia += (a[i]=='?'?0:a[i]-'0');
                ib *= 10; ib += (b[i]=='?'?9:b[i]-'0');
            }
            if(abs(ia-ib)<mnv || (abs(ia-ib)==mnv && (ia+ib)<mns)) {
                mnv = abs(ia-ib); mns = ia+ib;
                for(i=0;i<idx;i++) {
                    ma[i] = cur[i]; mb[i] = cur[i];
                }
                ma[idx] = a[idx]; mb[idx] = a[idx]-1;
                for(i=idx+1;i<len;i++) {
                    ma[i] = (a[i]=='?'?'0':a[i]);
                    mb[i] = (b[i]=='?'?'9':b[i]);
                }
            }
        }
        if(a[idx]!='9') {
            ia = 0, ib = 0;
            for(i=0;i<idx;i++) {
                ia *= 10; ia += cur[i]-'0';
                ib *= 10; ib += cur[i]-'0';
            }
            ia *= 10; ia += a[idx]-'0';
            ib *= 10; ib += a[idx]-'0'+1;
            for(i=idx+1;i<len;i++) {
                ia *= 10; ia += (a[i]=='?'?9:a[i]-'0');
                ib *= 10; ib += (b[i]=='?'?0:b[i]-'0');
            }
            if(abs(ia-ib)<mnv || (abs(ia-ib)==mnv && (ia+ib)<mns)) {
                mnv = abs(ia-ib); mns = ia+ib;
                for(i=0;i<idx;i++) {
                    ma[i] = cur[i]; mb[i] = cur[i];
                }
                ma[idx] = a[idx]; mb[idx] = a[idx]+1;
                for(i=idx+1;i<len;i++) {
                    ma[i] = (a[i]=='?'?'9':a[i]);
                    mb[i] = (b[i]=='?'?'0':b[i]);
                }
            }
        }
        cur[idx] = a[idx];
        solve(idx+1); return;
    }
    else {
        if(a[idx]!=b[idx]){
            ia = 0, ib = 0;
            for(i=0;i<idx;i++) {
                ia *= 10; ia += cur[i]-'0';
                ib *= 10; ib += cur[i]-'0';
            }
            ia *= 10; ia += a[idx]-'0';
            ib *= 10; ib += b[idx]-'0';
            for(i=idx+1;i<len;i++) {
                ia *= 10; ia += (a[i]=='?'?0:a[i]-'0');
                ib *= 10; ib += (b[i]=='?'?9:b[i]-'0');
            }
            if(abs(ia-ib)<mnv || (abs(ia-ib)==mnv && (ia+ib)<mns)) {
                mnv = abs(ia-ib); mns = ia+ib;
                for(i=0;i<idx;i++) {
                    ma[i] = cur[i]; mb[i] = cur[i];
                }
                ma[idx] = a[idx]; mb[idx] = b[idx];
                for(i=idx+1;i<len;i++) {
                    ma[i] = (a[i]=='?'?'0':a[i]);
                    mb[i] = (b[i]=='?'?'9':b[i]);
                }
            }
            ia = 0, ib = 0;
            for(i=0;i<idx;i++) {
                ia *= 10; ia += cur[i]-'0';
                ib *= 10; ib += cur[i]-'0';
            }
            ia *= 10; ia += a[idx]-'0';
            ib *= 10; ib += b[idx]-'0';
            for(i=idx+1;i<len;i++) {
                ia *= 10; ia += (a[i]=='?'?9:a[i]-'0');
                ib *= 10; ib += (b[i]=='?'?0:b[i]-'0');
            }
            if(abs(ia-ib)<mnv || (abs(ia-ib)==mnv && (ia+ib)<mns)) {
                mnv = abs(ia-ib); mns = ia+ib;
                for(i=0;i<idx;i++) {
                    ma[i] = cur[i]; mb[i] = cur[i];
                }
                ma[idx] = a[idx]; mb[idx] = b[idx];
                for(i=idx+1;i<len;i++) {
                    ma[i] = (a[i]=='?'?'9':a[i]);
                    mb[i] = (b[i]=='?'?'0':b[i]);
                }
            }
        }
        else {
            cur[idx] = a[idx];
            solve(idx+1); return;
        }
    }
}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    ll i,k;
    scanf("%lld",&tc);
    for(k=1;k<=tc;k++) {
        scanf("%s%s",&a,&b);
        len = strlen(a); mnv = INF; mns = INF;
        solve(0);
        printf("Case #%d: ",k);
        for(i=0;i<len;i++) printf("%c",ma[i]);
        printf(" ");
        for(i=0;i<len;i++) printf("%c",mb[i]);
        puts("");
        for(i=0;i<len;i++) {
            ma[i] = 0;
            mb[i] = 0;
            a[i] = 0;
            b[i] = 0;
            cur[i] = 0;
        }
    }
}
