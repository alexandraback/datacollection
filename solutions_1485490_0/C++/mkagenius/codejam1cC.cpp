/*
ID: mkagenius1
LANG: C++
TASK:
*/

#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<map>
#include<string.h>
#include<string>
#include<vector>
#include<math.h>
#include<set>
#include<queue>

using namespace std;
#define LL long long 
LL a[110], b[110], A[110], B[110];
LL maxval[110][110];
LL n, m;
LL solve(int i, int j, vector<LL> aa, vector<LL> bb){
    //cout << i << ", " << j  << endl;
    if(i == n || j == m) return 0;
   // if(maxval[i][j] != -1) return maxval[i][j];
    LL sold  =0 ;
    
    if(A[i] == B[j]){
        sold += min(aa[i],  bb[j]);
        aa[i] -= sold;
        bb[j] -= sold;
        int ii = i;
        int jj = j;
        if(aa[i] == 0) ii++;
        if(bb[j] == 0) jj++;
        sold += solve(ii, jj, aa, bb);
    }
    
    sold = max(sold, max(solve(i+1, j, aa, bb), solve(i, j+1, aa, bb)));
    
    return sold;
}
    
int preprocess(){
    vector<pair<int, int> > q;
    
    vector<pair<int, int> > w;
    for(int i = 0 ;i < n;){
        int k = i;
        LL z =0;
        while(k <n && A[i] == A[k]){
          
            z+=a[k];
            k++;
        }
        q.push_back(make_pair(z, A[i]));
        i = k;
    }
    for(int i = 0 ;i < m;){
        int k = i;
        LL z = 0;
        while(k <m && B[i] == B[k]){
            
            z+=b[k];k++;
        }
        w.push_back(make_pair(z, B[i]));
        i = k;
    }
    n = q.size();  m = w.size();
    for(int i =0 ; i < n; i ++){
        a[i] = q[i].first;
        A[i] = q[i].second;
    }
     for(int i =0 ; i < m; i ++){
        b[i] = w[i].first;
        B[i] = w[i].second;
    }
}
/* Main Code goes Here-after */
int main()
{
    int t; cin >> t;
    int kase = 0;
    while(t--){
      //  memset(maxval, -1, sizeof maxval); 
        
        cin >> n >> m;
        
        for(int i = 0; i < n; i++){
            cin >> a[i] >> A[i];
        }
        for(int i = 0; i < m; i++){
            cin >> b[i] >> B[i];
        }
        preprocess();
        vector<LL> v1, v2;
        for(int i = 0 ; i < n; i ++){
            v1.push_back(a[i]);
        }
        for(int i = 0 ; i < m; i ++){
            v2.push_back(b[i]);
        }
        LL ans = 0, fi = 0;
        for(int i = 0; i <= m; i ++){
            for(int j = 0 ; j + i <= m; j++){
                vector<LL> t1, t2;
                t1 = v1;
                t2 = v2;
                ans = 0;
                int k = m  - i  - j;
                LL rem = 0;
                int p;
                if(0 < n)
                {
                for(p = 0; p < i; p++){
                    if(A[0] == B[p]){
                        rem += v2[p];
                        if(rem >= v1[0] ) break;
                    }
                }
                if(rem > v1[0] && B[p] == 0) v2[p] -= v1[0] - (rem - v2[p]);
                rem = min(v1[0], rem);
                ans += rem;
                //v2[] -= rem;
                }
                rem  = 0;
                if(1 < n)
                {
                for(; p < i+j; p++){
                    if(A[1] == B[p]){
                        rem += v2[p];
                        if(rem >= v1[1]) break;
                    }
                }
                if(rem > v1[1] && B[p] == 1) v2[p] -= v1[1] - (rem - v2[p]);
                rem = min(v1[1], rem);
                ans += rem;}
                rem  = 0;
                if(2 < n){
                for(; p < m; p++){
                    if(A[2] == B[p]){
                        rem += v2[p];
                        if(rem > v1[2]) break;
                    }
                }
               // if(rem > v1[1] && B[i+j-1] == 1) v2[i+j-1] -= v1[1] - (rem - v2[i+j-1]);
                rem = min(v1[2], rem);
                ans += rem;}
                fi = max(ans, fi);
                v1 = t1;
                v2 = t2;
            }
        }
                
        kase++;
        cout << "Case #" << kase << ": " << fi<< endl;
    } 
    return 0;
}
