
#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <cmath>
using namespace std;

__int64 a,b;
void Input(){
    cin >> a >> b;
}
int Getans(){
    int ans = 0;
    if(a <= 1 && 1 <= b)
	ans++;
if(a <= 4 && 4 <= b)
	ans++;
if(a <= 9 && 9 <= b)
	ans++;
if(a <= 121 && 121 <= b)
	ans++;
if(a <= 484 && 484 <= b)
	ans++;
if(a <= 10201 && 10201 <= b)
	ans++;
if(a <= 12321 && 12321 <= b)
	ans++;
if(a <= 14641 && 14641 <= b)
	ans++;
if(a <= 40804 && 40804 <= b)
	ans++;
if(a <= 44944 && 44944 <= b)
	ans++;
if(a <= 1002001 && 1002001 <= b)
	ans++;
if(a <= 1234321 && 1234321 <= b)
	ans++;
if(a <= 4008004 && 4008004 <= b)
	ans++;
if(a <= 100020001 && 100020001 <= b)
	ans++;
if(a <= 102030201 && 102030201 <= b)
	ans++;
if(a <= 104060401 && 104060401 <= b)
	ans++;
if(a <= 121242121 && 121242121 <= b)
	ans++;
if(a <= 123454321 && 123454321 <= b)
	ans++;
if(a <= 125686521 && 125686521 <= b)
	ans++;
if(a <= 400080004 && 400080004 <= b)
	ans++;
if(a <= 404090404 && 404090404 <= b)
	ans++;
if(a <= 10000200001 && 10000200001 <= b)
	ans++;
if(a <= 10221412201 && 10221412201 <= b)
	ans++;
if(a <= 12102420121 && 12102420121 <= b)
	ans++;
if(a <= 12345654321 && 12345654321 <= b)
	ans++;
if(a <= 40000800004 && 40000800004 <= b)
	ans++;
if(a <= 1000002000001 && 1000002000001 <= b)
	ans++;
if(a <= 1002003002001 && 1002003002001 <= b)
	ans++;
if(a <= 1004006004001 && 1004006004001 <= b)
	ans++;
if(a <= 1020304030201 && 1020304030201 <= b)
	ans++;
if(a <= 1022325232201 && 1022325232201 <= b)
	ans++;
if(a <= 1024348434201 && 1024348434201 <= b)
	ans++;
if(a <= 1210024200121 && 1210024200121 <= b)
	ans++;
if(a <= 1212225222121 && 1212225222121 <= b)
	ans++;
if(a <= 1214428244121 && 1214428244121 <= b)
	ans++;
if(a <= 1232346432321 && 1232346432321 <= b)
	ans++;
if(a <= 1234567654321 && 1234567654321 <= b)
	ans++;
if(a <= 4000008000004 && 4000008000004 <= b)
	ans++;
if(a <= 4004009004004 && 4004009004004 <= b)
	ans++;

    return ans;
}

bool isOK(char str[]){
    int len = strlen(str);
    for(int i = 0 ; i < len ; i++){
        if(str[i] != str[len-1-(i)])
            return false;
    }
    return true;
}

void biao(){
    int bound = (1e7*1.0);
    for(__int64 i = 1 ; i <= bound ; i++){
        char num1[20];
        char num2[20];
        sprintf(num1,"%I64d",i);
        sprintf(num2,"%I64d",i*i);
        if (isOK(num1) && isOK(num2)){
            printf("if(a <= %s && %s <= b)\n\tans++;\n",num2,num2);
            //cout << "i=" << num1 <<" i*i=" << num2 << endl;
        }
    }
}
int main()
{

    //biao();

    //freopen("11.txt","r",stdin);
    //freopen("2.txt","w",stdout);
    int Ncase;
    cin >> Ncase;
    int ans = 0;
    while(Ncase--){
        Input();
        cout <<"Case #" << ++ans << ": "<< Getans() << endl;
    }
    return 0;
}
