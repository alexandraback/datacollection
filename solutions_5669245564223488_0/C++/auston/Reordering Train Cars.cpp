#include<cstdio>
#include<cstring>
#include<map>
#include<set>
using namespace std;

int n, num, let[105], fb[105][2];
bool can;
map<char, set<pair<int, int> > > po;
set<int> mul;

long long mu(long long a, long long int b){
    return ((a%1000000007)*b)%1000000007;
}
void prt(int a){
    long long ans = 1;
    for(int i=1; i<=a; i++)
        ans = mu(ans, i);
    for(set<int>::iterator it = mul.begin(); it!=mul.end(); it++){
        for(int i=1; i<=*it; i++)
            ans = mu(ans, i);
    }
    printf("%lld\n", ans);
}
bool test(int f, int b){
    int k = b;
    while(fb[k][1]!=0){
        if(fb[k][1]==f)
            return false;
        k = fb[k][1];
    }return true;
}
int main(){

    int t, ca=1;
    char c, lc;
    scanf("%d", &t);

    for(; t>0; t--){
        printf("Case #%d: ", ca++);
        can = true;
        po.clear();
        memset(let, 0, sizeof(let));
        memset(fb, 0, sizeof(fb));
        mul.clear();
        num = 0;
        scanf("%d%*c", &n);
        num = n;
        for(int i=1; i<=n; i++){
            lc = 0;
            while((c=getchar())!=' '&&c!='\n'){
                if(lc!=c){
                    let[i]++;
                    po[c].insert(pair<int, int>(i, let[i]));
                }lc = c;
            }
        }
        for(c = 'a'; c<='z'&&can; c++){
            int si = po[c].size();
            if(si!=0&&si!=1){
                int f = 0, b = 0;
                for(set<pair<int, int> >::iterator it = po[c].begin(); it!=po[c].end(); it++){
                    if(let[(*it).first]>1){
                        if((*it).second==1&&b==0&&fb[(*it).first][0]==0){
                            b = (*it).first;
                        }else if((*it).second==let[(*it).first]&&f==0&&fb[(*it).first][1]==0){
                            f = (*it).first;
                        }else{
                            can = false;
                            break;
                        }if(b!=0&&f!=0){
                            if(f!=b&&fb[b][0]==0&&fb[f][1]==0&&test(f, b)){
                                fb[b][0] = f;
                                fb[f][1] = b;
                            }else{
                                can = false;
                                break;
                            }
                        }
                    }
                }num -= si-1;
                if(si-(b>0)-(f>0)>1)
                    mul.insert(si-(b>0)-(f>0));
            }
        }
        if(!can)
            printf("0\n");
        else
            prt(num);
    }
    return 0;
}
