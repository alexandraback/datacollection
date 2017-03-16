#include <cstdio>



using namespace std;




typedef  unsigned long long int ull;


ull b_s(ull t, ull r)
{
    ull max = 0xfffffffffffffff0ull;
    ull min = 1;
    ull mid;
    while( max >= min )
    {
        mid = (max + min) / 2;
        if( 2*r - 1 + 2*mid < t / mid ) min = mid + 1 ;
        else if (2*r -  1 + 2*mid >  t / mid) max = mid - 1 ;
        else return mid;
    }

    return (max + min) / 2;
}


int main()
{
    int T, cases = 0;
    ull t ,r ;
    scanf("%d" , &T);
    while(T--)
    {
        scanf("%lld%lld", &r, &t);
        ull out = b_s(t,r);
        printf("Case #%d: %lld\n", ++cases, out);
    }
    return 0;
}
