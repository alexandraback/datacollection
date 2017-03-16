/*
 * Author:  chlxyd
 * Created Time:  2013/4/27 9:56:27
 * File Name: B.cpp
 */
#include<iostream>
#include<sstream>
#include<fstream>
#include<vector>
#include<list>
#include<deque>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<bitset>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cctype>
#include<cmath>
#include<ctime>
using namespace std;
const double eps(1e-8);
typedef long long lint;
#define clr(x) memset( x , 0 , sizeof(x) )
#define sz(v) ((int)(v).size())
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define repf(i, a, b) for (int i = (a); i <= (b); ++i)
#define repd(i, a, b) for (int i = (a); i >= (b); --i)
#define clrs( x , y ) memset( x , y , sizeof(x) )
multiset<pair<int,int> > st ;
int T , E , R ,n ;
int v[110000] ;
int main(){
    freopen("B.out","w",stdout) ;
    scanf("%d" , &T ) ;
    repf( t , 1 , T ) {
        st.clear() ;
        scanf("%d %d %d" , &E , &R, &n ) ;
        repf( i , 1 , n ) scanf("%d" , &v[i] ) ;
        int hp = E ;
        int ans = 0 ;
        repf( i , 1 , n ) {
            st.insert(make_pair(v[i],E)) ;
            int canuse = min( E , hp + R - E ) ;
            hp = min( hp + R , E ) ;
            if ( st.size() > 0 && canuse > 0 ) {
                set<pair<int,int> >::iterator x = st.end() ;
                for ( x -- ; ; x -- ) {
                    if ( canuse <= 0 ) break ;
                    int nowuse = min( canuse , (*x).second ) ;
                    ans += nowuse * (*x).first ;
                    pair<int,int> p = (*x) ;
                    canuse -= nowuse ; p.second -= nowuse ;
                    st.insert(p) ; st.erase(x) ; x = st.find(p) ;
                	if ( x == st.begin() ) break ;
				} 
            }
            set<pair<int,int> >::iterator x = st.end() ; x -- ;
            while ( st.size() > 0 && (*x).second == 0 ) {
                st.erase(x) ; 
                x = st.end() ;
				if ( x == st.begin() ) break ;
				else x -- ;
            }
        }
        int canuse = hp - R ;
        if ( canuse > 0 ) {      
            if ( st.size() > 0 )   {
                set<pair<int,int> >::iterator x = st.end() ;  
                for ( x -- ; ; x -- ) {
                    if ( canuse <= 0 ) break ;
                    int nowuse = min( canuse , (*x).second ) ;
                    ans += nowuse * (*x).first ;
                    pair<int,int> p = (*x) ;
                    canuse -= nowuse ; p.second -= nowuse ;
                    st.insert(p) ; st.erase(x) ; x = st.find(p) ;
                	if ( x == st.begin() ) break ;
                } 
            }
        }
        printf("Case #%d: %d\n" , t , ans ) ;
    }
}

