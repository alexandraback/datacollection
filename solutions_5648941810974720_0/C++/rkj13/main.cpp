#include <iostream>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <time.h>
#include <assert.h>
#define lli long long int
#define pb push_back
#define mod 1000000007
#define pii pair<int,int>

using namespace std;
int cnt[30]={0};
int ans[12]={0};
string arr[10]={"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
int getind(char x){
    return int(x-'A');
}
void sub(int x){
    for(int i=0;i<arr[x].size();i++){
        int j = int(arr[x][i]-'A');
        cnt[j]-=ans[x];
    }
    return;
}
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int t,i,j,a,b,c,tc=0;
    cin>>t;
    string str;
    while(t--){
        cin>>str;
        memset(cnt,0,sizeof(cnt));
        memset(ans,0,sizeof(ans));
        for(i=0;i<str.size();i++){
            j=int(str[i]-'A');
            cnt[j]++;
        }
        // 0
        ans[0]+=cnt[getind('Z')];
        sub(0);

        // 2
        ans[2]+=cnt[getind('W')];
        sub(2);
        //6
        ans[6]+=cnt[getind('X')];
        sub(6);
        //4
        ans[4]+=cnt[getind('U')];
        sub(4);
        //1
        ans[1]+=cnt[getind('O')];
        sub(1);
        //7
        ans[7]+=cnt[getind('S')];
        sub(7);
        //5
        ans[5]+=cnt[getind('V')];
        sub(5);
        //3
        ans[3]+=cnt[getind('R')];
        sub(3);
        //8
        ans[8]+=cnt[getind('G')];
        sub(8);
        //9
        ans[9]+=cnt[getind('I')];
        sub(9);
        printf("Case #%d: ",++tc);
        for(i=0;i<10;i++){
            while(ans[i]>0){
                cout<<i;
                ans[i]--;
            }
        }
        cout<<endl;

    }
    return 0;
}
