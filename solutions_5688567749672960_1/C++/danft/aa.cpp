#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define mk make_pair
#define pb push_back
#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<bool> vb;

char num[100];

int nz;
ll n;
void rev() {
        int sz = strlen(num);
        for ( int i = 0; i<sz/2; i++ )
                swap(num[i],num[sz-i-1]);
}

ll cc(bool mx ) {
        int sz = strlen(num);
        ll ret = 0;
        for( int i = (sz+mx)/2; i<sz; i++ )
                ret = ret*10 + num[i]-'0';
        return ret;
}

bool canrev() {
        return num[nz-1]!='0';
}

bool nrev() {
        bool ok = num[0]=='1';
        For(i,1,nz/2) ok &= (num[i]=='0');
        return !ok;
}

void tr() {
        num[nz-1] = '1';
        for( int i = nz-2; i>=nz/2; i-- )
                num[i]='0';
}
void sub() {
        for( int i = nz-1; i>=0; i-- )
        {
                num[i]--;
                if( num[i] < '0' ) num[i] = '9';
                if( num[i]!='9' ) break;
        }
        if( num[0]=='0')
        {
                For(i,0,nz-1) num[i]=num[i+1];
                nz--;
                num[nz]='\0';
        }
        //printf("%s#\n", num );
}

void dec() {
        For(i,0,nz-1) num[i]='9';
        nz--;
        num[nz]='\0';
}

int main(){
        int t,ca=1;cin >> t;

        while(t--)
        {
                scanf("%s", num);
                nz = strlen(num);
                ll ans = 0;
                while( nz > 0 )
                {
                        if( nz == 1)
                        {
                                ans += num[0]-'0';
                                break;
                        }
                        bool beh=0;
                        if( nz > 1 && nrev() && canrev() )
                        {
                                //printf("%s %d@\n", num, cc(false) );
                                ans += cc(false);
                                beh = 1;
                                //cout << ans << "\n";
                                rev();
                        }
                        else if( !canrev())
                        {
                                //cout << "!!\n";
                                sub();
                                //printf("%s\n", num );
                                ans++;
                                continue;
                        }
                        //printf("%s %d\n", num, cc(beh) );
                        ans += cc(beh);
                        if( nz > 1 ) ans++;
                        //cout << ans << "#\n";
                        dec();
                }
                cout << "Case #" << ca++ << ": ";
                cout << ans << "\n";
        }

        return 0;
}
