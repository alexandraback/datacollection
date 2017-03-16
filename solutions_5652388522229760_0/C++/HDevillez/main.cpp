#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <fstream>
#include <bitset>
#include <cstdio>
#include <sstream>
#include <string>
#include <queue>
#include <map>
#include <stack>
#include <set>
#include <cctype>
#include <iomanip>
#include <list>
#include <cstring>

#define INF 2000000000
#define ull unsigned long long int
#define vi vector<int>
#define vii vector<ii>

#define UNVISITED 0
#define OPENED 1
#define CLOSED 2

#define NBNODE 2000


using namespace std;

bool visited[10];
int sum = 0;


bool isOk(unsigned long long int m) {

    while(m != 0){
        int a = m%10;
        m/=10;
        if(!visited[a]) sum += a+1;
        visited[a] = true;
    }

    return (sum == 55);

}



int main () {  

    int nCase = 0;
    scanf("%d", &nCase);

    for(int iCase = 1; iCase <= nCase; iCase++) {    

        for(int i= 0; i < 10; i++) visited[i] = false;
        sum = 0;

        int n;
        scanf("%d", &n);
        

        
        
        if(n ==0) {
            printf("Case #%d: INSOMNIA\n", iCase);
            continue;
        }
       
        unsigned long long int m = n;
        unsigned long long int i;
       
        for(i = 0; !isOk(m) && i>= 0; i++) {
            m += n;
        }
        
        if(i < 0) printf("Case #%d: INSOMNIA\n", iCase);
        printf("Case #%d: %lld\n", iCase, m);

    }    
     
    
    return 0;
}
