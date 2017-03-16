#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <map>
#include <set>

using namespace std;

int main(){
    int t;
    scanf("%d", &t);
    for(int tt=1;tt<=t;++tt){
        int n,m;
        scanf("%d%d", &n, &m);
        int arr[n][m];
        vector <set <int> > row(105);
        vector <set <int> > col(105);
        vector <int> rowmin(n), rowmax(n);
        vector <int> colmin(m), colmax(m);
        set <int> myset;
        for(int i=0;i<n;++i){
            int mn,mx;
            mn=999;
            mx=0;
            for(int j=0;j<m;++j){
                scanf("%d", &arr[i][j]);
                if(arr[i][j]>mx)
                    mx=arr[i][j];
                if(arr[i][j]<mn)
                    mn=arr[i][j];
                row[arr[i][j]].insert(i);
                col[arr[i][j]].insert(j);
                myset.insert(arr[i][j]);
            }
            rowmin[i]=mn;
            rowmax[i]=mx;
        }
        for(int j=0;j<m;++j){
            int mn=999;
            int mx=0;
            for(int i=0;i<n;++i){
                if(arr[i][j]>mx)
                    mx=arr[i][j];
                if(arr[i][j]<mn)
                    mn=arr[i][j];
            }
            colmin[j]=mn;
            colmax[j]=mx;
        }
        int arr1[n][m];
        memset(arr1, 100, sizeof(arr1));
        set <int>::iterator it;
        it=myset.begin();
        while(it!=myset.end()){
            int num=*it;
            set <int>::iterator it1;
            it1=row[num].begin();
            while(it1!=row[num].end()){
                int r=*it1;
                if(rowmax[r]==num){
                    for(int i=0;i<m;++i){
                            if(arr1[r][i]>=num)
                                arr1[r][i]=num;
                    }
                }
                it1++;
            }
            it1=col[num].begin();
            while(it1!=col[num].end()){
                    int c=*it1;
                    if(colmax[c]==num){
                        for(int i=0;i<n;++i){
                            if(arr1[i][c]>=num){
                                arr1[i][c]=num;
                            }
                        }
                    }
                    it1++;
            }
            it++;
        }
        int flag=0;
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if(arr[i][j]!=arr1[i][j]){
                    flag=1;
                    break;
                }
            }
            if(flag)
                    break;
        }
        if(flag)
            printf("Case #%d: NO\n", tt);
        else
            printf("Case #%d: YES\n",tt);
        //cout<<"yeas"<<endl;
    }
}
