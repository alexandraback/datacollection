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

const int N = 11000;

int n;

int a[N];
bool va[N];
int b[N];
bool vb[N];
int result = 0;

    void inputing(){
        scanf("%d",&n);
        for ( int i=0;i<n;i++ ){
            scanf("%d %d",&a[i],&b[i]);
            va[i]= false;vb[i]=false;
        }
    }

    void work(){
        result = 0;
        int sum = 0;
        int star = 0;
        while ( sum < n ){
            //check b
            bool flag = false;
            int debugi = 0;
            for ( int i=0;i<n;i++ )
                if ( !vb[i] && b[i] <= star ){
                    if ( va[i] )
                        star += 1;
                    else star += 2;
                    vb[i] = true;
                    flag = true;
                    sum +=1;
                    debugi = i;
                    result += 1;
                }
            if (flag){
//                cout<<"star "<< star <<" get b "<<debugi<<"  if a: "<<va[debugi]<<endl;
                continue;
            }

            int ia = -1;

            for ( int i=0;i<n;i++ )
                if ( !vb[i] && !va[i] && a[i] <= star ){
                    if ( -1 ==ia || b[i] > b[ia]  ){
                        ia = i;
                    }
                }
            if ( ia != -1 ){
                star += 1;
                va[ia] = true;
                result += 1;
//                printf("s: %d  get %d [%d %d] \n",star,ia,a[ia],b[ia]);
            }
            else {
                result = -1;
                return;
            }
        }
    }



int main()
{
    int cas;
//    freopen("D:\\ACM\\A-large.in","r",stdin);
    freopen("D:\\ACM\\out.txt","w",stdout);
    freopen("D:\\ACM\\B-small-attempt0.in","r",stdin);
    scanf("%d",&cas);
    for (int i=0;i<cas;i++){
        inputing();
        work();
        if ( result != -1 )
            printf("Case #%d: %d\n",i+1,result);
        else printf("Case #%d: Too Bad\n",i+1);
    }



    return 0;
}


