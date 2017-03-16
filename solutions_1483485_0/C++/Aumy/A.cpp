# include <iostream>
# include <vector>
# include <map>
# include <deque>
# include <set>
# include <algorithm>
# include <memory>
# include <cstring>
# include <cstdio>
# include <cctype>
# include <cstdlib>
# include <cmath>
# include <utility>
# include <string>
# include <queue>
#include <assert.h>
using namespace std;

# define I(n)   scanf("%d",&(n))
# define read(x) freopen(x,"r",stdin)
# define write(x) freopen(x,"w",stdout)

void load(string a,string b,char* arr,char* v)
{
    assert(a.size() == b.size());
    int n = a.size();
    for(int i=0;i<n;i++)
    {
        if ( arr[ a[i] ] == 0 )
        {
            arr[ a[i] ] = b[i];
            assert(v[b[i]] == 0);
            v[ b[i] ] = a[i];
        }
        assert(arr[ a[i] ] == b[i] );
    }
}


int main()
{
    char arr[128]={0};
    char v[128]={0};
    v['a']='y'; arr['y'] = 'a';
    v['z']='q'; arr['q'] = 'z';
    v['o']='e'; arr['e'] = 'o';
    v[' ']=' '; arr[' '] = ' ';

    load("ejp mysljylc kd kxveddknmc re jsicpdrysi","our language is impossible to understand",arr,v);
    load("rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd","there are twenty six factorial possibilities",arr,v);
    load("de kr kd eoya kw aej tysr re ujdr lkgc jv","so it is okay if you want to just give up",arr,v);


    for(int i='a';i<='z';i++){
        if ( v[i] == 0 ){
            arr['z'] = i;
            break;
        }
    }



    read("A-small-attempt0.in");
    write("out.txt");
    int T;
    scanf("%d\n",&T);
    for(int cas=1;cas<=T;cas++)
    {
        string str;
        getline(cin,str);
        //cin>>str;
        cout<<"Case #"<<cas<<": ";
        for(int i=0;i<str.size();i++)
        {
            cout<<arr[str[i]];
        }
        cout<<endl;
    }
	//
	return 0;
}
