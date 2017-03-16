#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define FOR(a,b,c) for(int (a) = (b), _n = (c); (a) <= _n ; (a)++)
#define FORD(a,b,c) for(int (a) = (b), _n = (c) ; (a) >= _n ; (a)--)
#define FOR_N(a,b,c,n) for(int (a) = (b), _m = (n), _n = (c) ; (a) <= _n ; (a)+= _m )
#define FORD_N(a,b,c,n) for(int (a) = (b), _m = (n), _n = (c) ; (a) >= _n ; (a)-= _m)
#define EACH(v,it) for(__typeof(v.begin()) it = v.begin(); it != v.end() ; it++)
#define INF 200000000
#define MAX 1

using namespace std;

const int ONE = 0;
const int I = 1;
const int J = 2;
const int K = 3;
const int M_ONE = 4;
const int M_I = 5;
const int M_J = 6;
const int M_K = 7;
const int TARGET[] = {I,J,K};
const char * ANSWER[] = {"NO","YES"};
//1 i j k -1 -i -j -k
//0 1 2 3  4  5  6  7
int adjMat[10][10] = 
{
    {ONE,I,J,K,M_ONE,M_I,M_J,M_K},
    {I,M_ONE,K,M_J,M_I,ONE,M_K,J},
    {J,M_K,M_ONE,I,M_J,K,ONE,M_I},
    {K,J,M_I,M_ONE,M_K,M_J,I,ONE},  
    {M_ONE,M_I,M_J,M_K,ONE,I,J,K},  
    {M_I,ONE,M_K,J,I,M_ONE,K,M_J},  
    {M_J,K,ONE,M_I,J,M_K,M_ONE,I},  
    {M_K,M_J,I,ONE,K,J,M_I,M_ONE},  
};

char temp[0xFFFF];
bool visited[8][10240];

bool solve(int l, int x, string & s)
{
    int cnt = 0;
    int state = 0;
    bool ret = false;
    memset(visited,0,sizeof(visited));
    while(x--)
    {
        for(int j = 0; j < l; j++)
        {
            int ch = s[j]-'i' + 1;    
            //cerr << s[j] << " " <<ch << " "<< state << " -> " << adjMat[state][ch] << " finish : "<< TARGET[cnt] << endl;         
            state = adjMat[state][ch];            
            if(visited[state][j]) return false;
            visited[state][j] = true;
            if(cnt < 3 && state == TARGET[cnt])
            {
                //cerr << "flush" << endl;
                cnt++;
                memset(visited,0,sizeof(visited));
                state = ONE;
            }
        }
        if(cnt >= 3) break;
    }
    int tempState = ONE;
    cerr << x << endl;
    if(x > 0)
    {
        for(int j = 0; j < l; j++)
        {
            int ch = s[j]-'i' + 1;    
            tempState = adjMat[tempState][ch];            
        }
    }
    if(tempState == M_ONE)
    {
        if(x % 2 == 0) tempState = ONE;
    }
    else if(tempState != ONE)
    {
        if(x % 2 != 0)
        {
             if((x - 1) % 4 != 0) tempState = adjMat[tempState][M_ONE];
        }        
        else if(x % 4 == 0) tempState = ONE;
        else if(x % 2 == 0) tempState = M_ONE;   
    }
    
    state = adjMat[state][tempState];
    if(cnt >=3 && state == ONE) ret = true;
    return ret;
}

int main()
{
    int t;
    scanf("%d",&t);
    for(int ca = 1; ca <= t; ca++)
    {
        int l,x;
        scanf("%d %d",&l,&x);
        scanf("%s",temp);
        string s = temp;
        printf("Case #%d: %s\n",ca,ANSWER[solve(l,x,s)]);
    }
    return 0;
}
