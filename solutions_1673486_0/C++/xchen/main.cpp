#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <cstring>

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>


#define LL long long

#define PB(x) push_back(x)
#define SZ size()

#define out(x) (cout<<" "<<#x<<": "<<x)
#define outln(x) (cout<<" "<<#x<<": "<<x<<endl)
#define outarray(array,begin,end) {for (int i=begin;i<end;i++){out(i);outln(array[i]);}}

#define eps (10e-9)

using namespace std;

const int N = 10001000;


double result = N;
int len1,len2;
double array[N];

double prob[N]; //allright
double allright;

    void inputing(){
        scanf("%d %d",&len1,&len2);
        len2 -= len1;
        for (int i=0;i<len1;i++)
            scanf("%lf",&array[i]);
        result = N*1.0;
    }

    void work1(){

        allright = 1;
        for (int i=0;i<len1;i++)
            allright *= array[i];
        double wrong1 = 1.0 - allright;
        double temp = allright*( 1+len2 ) + wrong1*( 2+len1+len2+len2 );

//        printf("%lf * %d  %lf * %d = %lf\n",allright, 1+len2,wrong1,2+len1+len2+len2,temp);//debug
        result = min(result,temp);

        double now = 1.0;
        for (int i=0;i<len1;i++){
            prob[i] = array[i] * now;
            now = prob[i];
        }

    }

    void work2(){

        for (int i=1;i<=len1;i++){
            //go back i
            double right;
            double wrong;
            if ( len1 -1 - i >=0 ){
                right = prob[ len1 -1 - i];
                wrong = 1.0 - right;
            }
            else {
                right = 0;
                wrong = 1.0;
            }

            double temp = right*( i + i  + len2+1);
            temp += wrong*( i+i+len2+1 +len1+len2+1 );

//            printf("%lf * %d  %lf * %d = %lf\n",right, i + i  + len2+1,wrong,i+i+len2+1 +len1+len2+1,temp);//debug
//            if ( temp>0 )
                result = min(result,temp);
        }
    }

    void work3(){
        double temp = 1.0 + len1 + len2 + 1.0;
//        printf("last  %lf\n",temp);
        result = min(result,temp);
    }



int main()
{
    int cas;
    freopen("D:\\ACM\\A-small-attempt0.in","r",stdin);
    freopen("D:\\ACM\\out.txt","w",stdout);
    //freopen("D:\\ACM\\in.txt","r",stdin);
    scanf("%d",&cas);
    for (int i=0;i<cas;i++){
        inputing();
        work1();
        work2();
        work3();
        printf("Case #%d: %lf\n",i+1,result);
    }



    return 0;
}


