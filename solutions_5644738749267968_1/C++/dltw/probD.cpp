#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string>

using namespace std;

void process(void) {
    int n;
    scanf("%d", &n);
    float naomi[n];
    float ken[n];
    for (int i = 0; i < n; ++i)
    {
        scanf("%f", &naomi[i]);
    }
    sort(naomi, naomi+n, less<float>());
    for (int i = 0; i < n; ++i)
    {
        scanf("%f", &ken[i]);
    }
    sort(ken, ken+n, less<float>());
    int scheat = 0, snormal = n;
    int np=0, kp=0;
    while (np < n && kp < n)
    {
        if (naomi[np] < ken[kp]){
            np++;
        }
        else if(naomi[np] > ken[kp]){
            np++;
            kp++;
            scheat++;
        }
    }

    np = 0; kp = 0;
    while (np < n && kp < n)
    {
        if (naomi[np] < ken[kp]){
            kp++;
            np++;
            snormal--;
        }
        else if(naomi[np] > ken[kp]){
            kp++;
        }
    }
    cout << scheat <<" " << snormal<<endl;
}

int main(void)
{
    int T;
    scanf("%d", &T);
    for(int i=1;i<=T;i++) {
        printf("Case #%d: ", i);
        process();
    }
}