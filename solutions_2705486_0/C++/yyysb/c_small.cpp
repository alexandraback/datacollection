#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int T;
int n;
int m;
char s[600000][20], a[10000];
int f[5000][5];

struct trie{
    trie *ch[26];
    bool term;
}*rt;

void ins(const char *s){
    n = strlen(s);
    trie *p = rt;
    for(int i=0;i<n;++i){
        if(p->ch[s[i]-'a']!=NULL)
            p = p->ch[s[i]-'a'];
        else{
            trie *q = new trie;
            memset(q, 0, sizeof(trie));
            p->ch[s[i]-'a'] = q;
            p = q;
        }
    }
    p->term = true;
}

#define update(i,j,k) if (f[(i)][(j)]==-1 || f[(i)][(j)]>(k)) f[(i)][(j)]=(k)

void search(trie *p, int i, int j, int pos, int lastchg, int cntchg){
    if(p==NULL) return;
    if(p->term){
        int tmpj = pos-1-lastchg;
        if (tmpj>4)tmpj=4;
        //update(pos-1, tmpj, f[i][j]+cntchg);
        for(int x=tmpj; x>-1; --x)
        //for(int x=tmpj; x<5; ++x)
            if(f[pos-1][x]==-1 || f[pos-1][x]>f[i][j]+cntchg)
               f[pos-1][x]=f[i][j]+cntchg;
    }
    if(pos>n) return;
    search(p->ch[a[pos-1]-'a'], i, j, pos+1, lastchg, cntchg);
    if(lastchg+4<pos)
        for(int k=0; k<26; ++k)
            search(p->ch[k], i, j, pos+1, pos, cntchg+1);
}

int main(){
    FILE *dictfile = fopen("garbled_email_dictionary.txt", "r");
    rt = new trie;
    memset(rt, 0, sizeof(trie));
    for(m=0;fscanf(dictfile,"%s",s[m])!=EOF;++m){
        ins(s[m]);
    }


    freopen("C-small-attempt0.in","r",stdin);
    freopen("c.out","w",stdout);
    scanf("%d", &T);
    for(int cs=1;cs<=T;++cs){
        printf("Case #%d: ",cs);
        scanf("%s", a);

        memset(f,255,sizeof(f));
        n = strlen(a);
        for(int i=0; i<5; ++i)
            f[0][i] = 0;
//        for(int i=0; i<5; ++i)
//            for(int j=4; j>=i; --j)
//                f[i][j] = 0;
        for(int i=0;i<n; ++i)
            for(int j=0; j<5; ++j)
                if(f[i][j]!=-1)
                    search(rt,i,j,i+1,i-j,0);
        int ans = n;
        for(int j=0; j<5; ++j)
            if(f[n][j]!=-1 && f[n][j]<ans) ans = f[n][j];
        printf("%d\n", ans);
        fflush(stdout);
    }
}
