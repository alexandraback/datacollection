#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <climits>
#include <string.h>

#define SZ(c) c.size()
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define SORT(a) sort(a.begin(),a.end())
#define tests int test; scanf("%d",&test); while(test--)
#define dbg(n) cout<<#n<<" = "<<n<<endl;

using namespace std;

int strToInt(string str) {int ans; stringstream s; s<<str; s>>ans; return ans;}
string intToStr(int n) {string str; stringstream s; s<<n; s>>str; return str;}
int MAX(int a,int b) {if(a >b) return a; return b;}
int MIN(int a,int b) {if(a <b) return a; return b;}
int ABS(int a) {if(a >0) return a; return -a;}


int counter[60];

bool valid(int helper[], int n, vector<string> &arr)
{
    string str = "";
    for(int i=0; i<n ;i++)
       {
            str += (arr[helper[i]]);
            //cout<<helper[i]<<" ";
       }
    //   cout<<str<<endl;

    int len = str.size();
    int visited[60], value[60];
    for(int i=0; i<26; i++)
        visited[i] = value[i] =0;
    char last = str[0];
    string amit  = "";
    for(int i=0; i<len; i++)
    {
        if(str[i] == last )
        {
            amit += str[i];
        }
        else
        {
            if(amit.size() != counter[amit[0]-'a'])
                return false;

            amit = "";
            amit += str[i];
            last = str[i];
        }
    }
    if(amit.size() != counter[amit[0]-'a'])
                return false;

    return true;

}

bool fail(string first, string second)
{
    int len1 = first.size();
    int len2 = second.size();
    for(int i=0; i<len1; i++)
    {
        for(int j=0; j<len2; j++)
        {
            if(first[i] == second[j])
                return true;
        }
    }
    return false;
}

string make (string first)
{
    //cout<<"!"<<first<<"! ";
     char ch = first[0];
    int index =0, len = first.size();
    while((index < len) && (ch == first[index]))
        index ++;
    int bacc = len -1;
    ch = first[len -1];
    while((bacc >0 ) && (ch == first[bacc]))
        bacc--;

    string amit = "";
    for(int i= (index); i <= (bacc); i++)
    {
        amit += first[i];
    }
   // cout<<"#"<<amit<<"#"<<endl;
    return amit;
}

bool zero(vector<string> &arr, int n, vector<string> &made)
{
    string x, y;
    for(int i=0; i<n; i++)
    {
         x = arr[i];
        for(int j=(i+1); j<n ; j++)
        {
            y = arr[j];
            if(fail( made[i],made[j]))
                return true;
            if(fail(made[i], y))
                return true;
            if(fail(x, made[j]))
                return true;
        }
    }
    return false;
}

int main()
{
    freopen("carSecond.txt", "r", stdin);
    //freopen("read.txt", "r", stdin);
    freopen("writecarsSecond.txt", "w", stdout);
    int test;
    scanf("%d\n",&test);
    int n;
    vector<string> arr(1000);
    vector<string> made(1000);
    int forcedtest = 50;
    for(int running=1; running <= test; running++)
    {
        scanf("%d",&n);
        for(int i=0; i<n; i++)
        {
            cin>>arr[i];
            made[i] = make(arr[i]);
        }
        if(running <= skip)
        	continue;
//        for(int i=0; i<n; i++)
//            cout<<arr[i]<<" ";
//        cout<<endl;
        if(zero(arr, n, made))
        {
            printf("Case #%d: 0\n", running);
           // cout<<"here"<<endl;
        }

        else
        {
            int ans =0;
            vector<string> amit(n);
            int fre[60];
            for(int i=0; i<60; i++)
                fre[i] =0;
            for(int i=0; i<n; i++)
            {
                amit[i] = "";
                amit[i] += (arr[i][0]);
                amit[i] +=  (arr[i][arr[i].size()-1]);
                fre[amit[i][0]-'a'] ++;
                fre[amit[i][1]-'a']++;
          //      cout<<"amit "<<(amit[i])<<endl;
            }

            int helper[n];
            for(int i=0; i<n ;i++)
            {
                helper[i] = i;
            }
            do{
                string cars= "";
                for(int i=0; i<n; i++)
                {
                    cars += amit[helper[i]];
                }
               // cout<<cars<<endl;
                bool flag = true;

                int len = cars.size();
                int value =1;
                for(int i=0; i<len-1; i++)
                {
                    if(cars[i] == cars[i+1])
                    {
                         value++;
                    }
                    else
                    {
                        if(value != fre[cars[i]-'a'])
                        {
                            flag = false;
                            break;
                        }

                        value = 1;
                    }
                }

                if(flag)
                    ans++;

            }while(next_permutation(helper, helper+n));
            printf("Case #%d: %d\n", running, ans);
        }
    }
    return 0;
}

