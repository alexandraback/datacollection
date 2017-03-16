#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <cassert>
#include <algorithm>
using namespace std;

vector<string> zipcode;
int n , m ;
vector< pair<int,int> > flight ;

vector<int> v;
void dfs( int cur , string now , vector<int>&path );
string ans = "z";

int dfs(){
}
int comp( const pair<int,int> &a , const pair<int,int> &b ){
    return zipcode[a.second] < zipcode[b.second] ;
}
int work(){
    ans = "z";
    flight.clear();
    zipcode.clear();
    int i ;
    cin>>n >> m ;
    for ( int i = 0 ; i < n ; ++i ){
        string tmp ;
        cin >> tmp ;
        zipcode.push_back( tmp );
    }
    for ( int i = 0 ; i < m ; ++i ){
        int a , b ;
        cin >> a >> b ;
        a-- ; b--;
        flight .push_back( make_pair (a,b) );
    }

    //sort( flight.begin() , flight.end() , comp ) ;
    for ( int i = 0 ; i <n ; ++i ){
        v.clear();
        v.resize(n+1);
        vector<int> tmp;        
        dfs( i , zipcode[i] , tmp );
    }
    cout<<ans <<endl;
}
void dfs( int cur , string now , vector<int>&path ){
    if ( now > ans )
        return ;
    //check if solution found
    int cnt = 0;
    for ( int i = 0 ; i < n ;++i )
        if ( v[i] || cur==i )
            ++cnt ;
    if ( cnt == n ){
        //found solution
        if(now.size() == n*5)
        if ( now < ans ){
            cerr<<now<<':'<<ans<<endl;
            ans = now ;
        }
        return;
    }
    //do search
    int flag = 0 ;
    if (!v[cur]){
        flag = 1 ;
        v[cur] = 1 ;
        path.push_back( cur );
    }else
        v[cur] = 2 ;
    for ( int i= 0 ; i < m ; ++i ){
        if ( flight[i].first == cur ){
            //now can go to flight[i].second
            if (!v[ flight[i].second ] ){
                dfs( flight[i].second , now + zipcode[flight[i].second] , path );
            }        
        }
        if ( flight[i].second == cur ){
            //now can go to flight[i].first
            if (!v[ flight[i].first ] ){
                dfs( flight[i].first , now + zipcode[flight[i].first] , path );
            }        
        }
    }
    //do a return
    if ( path.size() > 1  ){
        path.pop_back();
        int last = (path.back());
        dfs( last , now , path );
    }
    if ( flag )
        v[cur] = 0;
}

int main(){
    int t ;
    scanf("%d",&t);
    for ( int i = 0 ; i < t; ++i ){ 
        cout<<"Case #"<<i+1<<": ";
        work();
    }
}
