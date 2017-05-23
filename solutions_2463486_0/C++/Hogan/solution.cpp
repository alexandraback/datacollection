#include<cstdio>
#include<cstring>

char left[110], right[110];
int cnt;

bool small(int a[], int b[], int la, int ra){
    if (la == ra){
        for (int i=la-1; i>=0; i--){
            if (a[i] == b[i])   continue;
            return a[i] < b[i];
        }
        return true;
    }
    return la < ra;
}

bool squareTest(int n, int in[]){
    int ans[110] = {0}, low[110], high[110];

    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            ans[i + j] += in[i] * in[j];
        }
    }

    int q = 0, flag;
    for (flag=0; flag<2*n-1 || q; flag++){
        q = ans[flag] / 10;
        ans[flag+1] += q;
        ans[flag] %= 10;
    }

    bool suc = true;
    for (int i=0; i<flag/2; i++){
        if (ans[i] != ans[flag-1-i])    suc = false;
    }

    int llen = strlen(left);
    for (int i=0; i<llen; i++)  low[i] = left[llen-1-i] - '0';

    int rlen = strlen(right);
    for (int i=0; i<rlen; i++)  high[i] = right[rlen-1-i] - '0';

    if (!small(low, ans, llen, flag))   suc = false;
    if (!small(ans, high, flag, rlen))  suc = false;

    return suc;
}

void dfs(int now, int des, int con[]){
    if (now == (des + 1)/2){
        //for (int i=0; i<des; i++)   printf("%d ", con[i]);
        //puts("");
        if (squareTest(des, con)){
            //printf("%d %d\n", now, des);
            //for (int i=0; i<des; i++)   printf("%d", con[i]);
            //puts("==");
            cnt++;
        }
        return;
    }

    for (int k=0; k<10; k++){
        if (now == 0 && k == 0) continue;
        con[now] = con[des-1-now] = k;
        dfs(now + 1, des, con);
    }
}

int main(){
    int t, con[110];

    freopen("C-small-attempt0.in", "r", stdin);
    freopen("C-small-attempt0.out", "w", stdout);

    //freopen("B-large.in", "r", stdin);
    //freopen("B-large.out", "w", stdout);

    scanf("%d", &t);

    for (int l=0; l<t; l++){
        scanf("%s%s", left, right);
        int n = strlen(right)/2 + 1;
        cnt = 0;

        // assume n = 1;
        for (int i=0; i<n; i++){
            dfs(0, i + 1, con);
        }
        printf("Case #%d: %d\n", l+1, cnt);
    }
}

/*

10
1 100000000000000

*/
