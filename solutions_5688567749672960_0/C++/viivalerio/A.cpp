#include<cstdio>
#include<cstring>
#include<iostream>
#include<cstdlib>
#include<string>
#include<algorithm>
#include<limits.h>
#include<iomanip>
#include<cmath>
#include<cassert>
#include<map>
#include<set>
#include<stack>
#include<queue>
#include<deque>
#include<list>
#include<vector>
#include<sstream>

using namespace std;

#define INF 0x7fffffff


typedef pair<int,int> ii;
typedef pair<int, ii> iii;
typedef priority_queue<ii> pqii;
typedef priority_queue<iii> pqiii;
typedef set<int> si;
typedef map<string, int> msi;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef queue<ii> qii;

int vet[1000005];
map<int, int> numbers;

void Precompute()
{

        qii q;
        q.push(make_pair(1,1));
        vet[1] = 1;

        while(!q.empty())
        {
            ii node = q.front(); q.pop();

            stringstream ss;
            ss << node.first;
            //printf("asdfas\n");
            if(node.first== 1000000) break;
            if(node.first<=1000000)
            {
                if(vet[node.first+1] > node.second+1)
                {
                    vet[node.first+1] = node.second+1;
                    q.push(make_pair(node.first+1, node.second+1));
                }
                //if(node.first>= 1000000) break;
                string str;
                ss >> str;
                str = string(str.rbegin(), str.rend());
                stringstream ss1(str);
                ss1 >> node.first;

                //printf("%d %d\n", node);
                if(vet[node.first] > node.second+1)
                {
                    vet[node.first] = node.second+1;
                    q.push(make_pair(node.first, node.second+1));
                }


            }
            else
            {
                if(numbers.count(node.first+1)==0) numbers[node.first+1] = INF;
                if(numbers[node.first+1] > node.second+1)
                {
                    numbers[node.first+1] = node.second+1;
                    q.push(make_pair(node.first+1, node.second+1));
                }
                //if(node.first>= 1000000) break;
                string str;
                ss >> str;
                str = string(str.rbegin(), str.rend());
                stringstream ss1(str);
                ss1 >> node.first;
                if(numbers.count(node.first)==0) numbers[node.first] = INF;
                //printf("%d %d\n", node);
                if(numbers[node.first] > node.second+1)
                {
                    numbers[node.first] = node.second+1;
                    q.push(make_pair(node.first, node.second+1));
                }
            }
        }
}

int main()
{
    int cases = 1;
    int T;
    fill(vet, vet+1000005, INF);
    Precompute();


    while(scanf("%d", &T)!= EOF)
    {
        while(T--)
        {
            int n;
            scanf("%d", &n);

            printf("Case #%d: ", cases++);
            printf("%d\n", vet[n]);
        }

    }

    return 0;
}


