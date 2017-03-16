/*
 * Author: szk1347
 * Created Time:  2012/4/28 9:52:51
 * File Name: B_small.cpp
 */
#include <cctype>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <string>
#include <map>
#include <set>
#include <algorithm>
using namespace std;
#define out(v) cerr << #v << ": " << (v) << endl
#define SZ(v) ((int)(v).size())
const int maxint = -1u>>1;
template <class T> bool get_max(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> bool get_min(T& a, const T &b) {return b < a? a = b, 1: 0;}

int a[20],b[20];
bool vis[2][20];
int T;
int N;

bool check(){
    for(int i = 0;i < N;++i){
        if(!vis[1][i])
            return false;
    }
    return true;
}
inline bool cmp(const int x,const int y){
    return ((b[x] > b[y]) || (b[x] == b[y] && a[x] < a[y]));
}

int main() {
    freopen("B_in.txt","r",stdin);
    freopen("B_out.txt","w",stdout);
    cin >> T;
    for(int cas = 1;cas <= T;++cas){
        memset(vis,0,sizeof(vis));
        int star = 0;
        bool is = true;
        cin >> N;
        for(int i = 0;i < N;++i){
            cin >> a[i] >> b[i];
        }
        vector<int> idx;
        for(int i = 0;i < N;++i)
            idx.push_back(i);
        sort(idx.begin(),idx.end(),cmp);
        int cnt = 0;
        while(!check()){
            bool can = false;
            for(int i = 0;i < N;++i){
                if(!vis[0][idx[i]] && !vis[1][idx[i]] && star >= b[idx[i]]){
                    star += 2;
                    vis[1][idx[i]] = true;
                    ++cnt;
                    //cout << '2' << idx[i] << endl;
                    //cout << star << endl;
                    can = true;
                    break;
                }
            }
            if(!can){
                for(int i = 0;i < N;++i){
                    if(!vis[1][idx[i]] && star >= b[idx[i]]){
                        star += 1;
                        vis[1][idx[i]] = true;
                        ++cnt;
                        //cout << '2' << idx[i] << endl;
                        //cout << star << endl;
                        can = true;
                        break;
                    }
                }
            }
            if(!can){
                for(int i = 0;i < N;++i){
                    if(vis[1][idx[i]] &&!vis[0][idx[i]] && star >= a[idx[i]]){
                        star += 1;
                        vis[0][idx[i]] = true;
                        ++cnt;
                        //cout << '1' << idx[i] << endl;
                        //cout << star << endl;
                        can = true;
                        break;
                    }
                }
            }

            if(!can){
                for(int i = 0;i < N;++i){
                    if(!vis[0][idx[i]] && star >= a[idx[i]]){
                        star += 1;
                        vis[0][idx[i]] = true;
                        ++cnt;
                        //cout << '1' << idx[i] << endl;
                        //cout << star << endl;
                        can = true;
                        break;
                    }
                }
            }
            if(!can){
                is = false;
                break;
            }
        }
        if(!is){
            printf("Case #%d: Too Bad\n",cas);
        }
        else{
            printf("Case #%d: %d\n",cas,cnt);
        }
    }
    return 0;
}

