#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <map>
#include <queue>
#include <set>
#include <iomanip>
using namespace std;

int L[26];

int main()
{

    freopen("in.in","r",stdin);
    freopen("out.txt","w",stdout);
    string s;
    int cases, cnt = 0;
    scanf("%d\n",&cases);
    while(cases--){
        cnt++;
        getline(cin,s);
        memset(L,0,sizeof L);
        vector<int> numbers;
        for(int i = 0; i < s.size(); i++){
            int k = (int)s[i] - (int)'A';
            L[k]++;
        }
        //0
        while(L[25]){
            numbers.push_back(0);
            L[25]--;
            L[4]--;
            L[17]--;
            L[14]--;
        }
        //2
        while(L[22]){
            numbers.push_back(2);
            L[22]--;
            L[19]--;
            L[14]--;
        }
        //6
        while(L[23]){
            numbers.push_back(6);
            L[23]--;
            L[18]--;
            L[8]--;
        }
        //7
        while(L[18]){
            numbers.push_back(7);
            L[18]--;
            L[21]--;
        }
        //5
        while(L[21]){
            numbers.push_back(5);
            L[21]--;
            L[5]--;
            L[8]--;
        }
        //4
        while(L[5]){
            numbers.push_back(4);
            L[5]--;
            L[17]--;
            L[14]--;
        }
        //3
        while(L[17]){
            numbers.push_back(3);
            L[17]--;
        }
        //8
        while(L[6]){
            numbers.push_back(8);
            L[6]--;
            L[8]--;
        }
        //9
        while(L[8]--){
            numbers.push_back(9);
        }
        //1
        while(L[14]--){
            numbers.push_back(1);
        }
        sort(numbers.begin(),numbers.end());
        printf("Case #%d: ",cnt);
        for(int i = 0; i < numbers.size(); i++){
            printf("%d",numbers[i]);
        }
        printf("\n");
    }
    return 0;
}
