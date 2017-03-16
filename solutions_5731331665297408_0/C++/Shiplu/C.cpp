#include<bits/stdc++.h>
using namespace std;
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
#define SET(a) memset(a,-1,sizeof(a))
#define CLR(a) memset(a,0,sizeof(a))
#define pb push_back
#define all(a) a.begin(),a.end()
#define eps (1e-9)
#define inf (1<<29)
#define i64 long long
#define u64 unsigned i64

int vis[10],n;
int mat[10][10];
string s[10];
bool isPossible(vector<int> a){
    int i;
    stack<int> st;
    i = 1;
    st.push(a[0]);
    while(i<n){
        while(!st.empty() && !mat[a[i]][st.top()]) st.pop();
        if(st.empty()) return false;
        st.push(a[i]);
        i++;
    }
    return true;
}
int main(){
    freopen("C-small-attempt0.in","r",stdin);
    freopen("C-small-attempt0.out","w",stdout);
    int t,cs=1,i,x,y,m;

    cin>>t;
    while(t--){
        string ans;
        cin>>n>>m;
        vector<int> a;
        for(i = 1;i<=n;i++){
            cin>>s[i];
            a.pb(i);
        }
        CLR(mat);
        for(i = 0;i<m;i++){
            cin>>x>>y;
            mat[x][y] = mat[y][x] = 1;
        }
        do{
            if(isPossible(a)){
                string str = "";
                for(i = 0;i<n;i++){
                    str+=s[a[i]];
                }
                if(ans == "" || str<ans)
                    ans = str;
            }
        }while(next_permutation(all(a)));
        printf("Case #%d: ",cs++);

        cout<<ans<<endl;
    }
	return 0;
}
