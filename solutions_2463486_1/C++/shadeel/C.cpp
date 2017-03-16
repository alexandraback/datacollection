#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

/****************
1, 2, 3, 11, 22, 111, 121, 212, 1111, 11111, 11211, 111111, 1111111, 11111111, 111111111
****************/

using namespace std;

queue<string> que;
vector<string> st;

void rec(string str, string now, string inv, string mid, int start, int half, int remain){
    if( start==half ){
        int len = str.size();
        string s = now + str[start], z = str[start] + inv, put;
        for(int i=0; i<remain; ++i){
            s += "0";
            z = "0" + z;
        }
        // get the palindrome
        if( len&1 ) put = s + str[start+1] + z;
        else        put = s + str[start+1] + mid + str[start+2] + z;
        que.push(put);
    }else{
        string s = now + str[start], z = str[start] + inv;
        for(int i=0; i<=remain; ++i, s+="0", z="0"+z)
        rec(str,s,z,mid,start+1,half,remain-i);
    }
}

void produce( string str ){
    int len=str.size(), half=(len-3)/2, limit=50-len;
    
    if( len==2 ){
        string s = "0";
        for(int i=1; i<=limit; ++i,s+="0")
            que.push(str[0]+s+str[1]);
    }else if( len&1 ){  // number len is odd, hole number is even
        for(int i=2; i<=limit; i+=2){    // increase zero
            rec(str,"","","",0,half,i/2);
        }
    }else{              // number len is even, hole number is odd
        for(int i=1; i<=limit; ++i){    // increase zero
            string mid = (i&1)?("0"):("");
            for(int j=(i&1)?(1):(0); j<=i; j+=2, mid+="00") // increase zero at middle
            rec(str,"","",mid,0,half,(i-j)/2);
        }
    }
}

void squr( string str ){
    char ans[105] = {0};
    int len = str.size();
    for(int i=0,j=len*2-1; i<j; ++i)
        ans[i] = '0';
    
    for(int i=0; i<len; ++i)for(int j=0; j<len; ++j)
        ans[i+j] += (str[i]-'0')*(str[j]-'0');
    
    string put = ans;
    st.push_back(ans);
}

bool compare(string a, string b){
    int lena = a.size(), lenb = b.size();
    if( lena < lenb )       return true;
    else if( lena > lenb )  return false;
    else{
        for(int i=0; i<lena; ++i)
        if( a[i] < b[i] )       return true;
        else if( a[i] > b[i] )  return false;
    }
    return false;
}


int main(void){
    
    freopen("C-large-1.in", "r", stdin);
    freopen("out.txt", "w", stdout);
    
    int cas, c=0;
    string str[15] = {"1","2","3", "11", "22", "111", "121", "212", "1111", "11111", "11211", "111111", "1111111", "11111111", "111111111"};
    char a[105], b[105];
    
    // produce other sequence
    st.clear();
    for(int i=0; i<15; ++i){
        que.push(str[i]);
        if( str[i].size()>1 ) produce(str[i]);
    }
    // square all the sequences
    while( !que.empty() ){
        string s = que.front();
        que.pop();
        squr(s);
    }
    // sorting all the sequences
    sort(st.begin(), st.end(), compare);
    
    
    scanf("%d", &cas);
    while( cas-- ){
        scanf("%s %s", a, b);
        int ans = 0;
        for(int i=0,j=st.size(); i<j; ++i){
            if( compare(st[i],a) )  continue;
            if( compare(b,st[i]) )  break;
            ++ans;
        }
        printf("Case #%d: %d\n", ++c, ans);
    }
    
    return 0;
}
