#include <stdio.h>
#include <string.h>
#include <cstdlib>
#include <map>
#include <string>
#include <iostream>
using std::string;
using std::map;
using std::cin;
using std::cout;
using std::endl;
//#define abs(i,j) (i>j? (i-j) : (j-i))
int abs(int i, int j) {
    return i>j? i-j:j-i;
}
int main()
{
    int T;
    int N;
    scanf("%d", &T);
    for (int Ti=1;Ti<=T;Ti++) {
        printf("Case #%d: ", Ti);
        scanf("%d\n", &N);
        //char first[25], sec[25];
        string first, sec;
        map<string, int> num1, num2;

        string str1[1100], str2[1100];
        for (int i=0;i<N;i++)
        {
            //scanf("%s %s\n", first, sec);
            cin >> first >> sec;
            num1[first]++;
            num2[sec]++;
            str1[i] = first;
            str2[i] = sec;
            //cout << first << std::endl;
            //cout << sec << std::endl;
        }
        int ans = 0;
        for (int i=0;i<N;i++)
        {
            if (num1[str1[i]] >=2 && num2[str2[i]] >=2 ) {
                ans++;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}


