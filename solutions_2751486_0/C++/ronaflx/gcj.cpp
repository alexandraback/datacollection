/*
 * =====================================================================================
 *
 *       Filename:  gcj.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  05/12/2013 05:06:17 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  ronaflx
 *        Company:  hit-ACM-Group
 *
 * =====================================================================================
 */

#include <string>
#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;
typedef long long LL;
const int N = 1e6 + 10;

int  len[N];
char str[N];

int main() {
    int t, k, cas = 1;
    scanf("%d", &t);
    while(t-- && scanf("%s %d", str, &k) == 2) {
        queue<pair<int, int> > p;
        int n = strlen(str);
        memset(len, 0, sizeof(len));
        for(int i = 0, j;i < n;i++) {
            for(j = i;j < n && (str[j] != 'a' && str[j] != 'e'
                    && str[j] != 'i' && str[j] != 'o'
                    && str[j] != 'u');j++) {
            }
            if(j - i >= k) p.push(make_pair(i, j));
        }
        LL res = 0;
        for(int i = 0;i < n;i++) {
            while(p.size() && p.front().second - i < k) {
                p.pop();
            }
            if(p.size()) {
                int pos = max(i + k, p.front().first + k);
                res += n - pos + 1;
            }
        }
        printf("Case #%d: %lld\n", cas++, res);
    }
    return 0;
}
