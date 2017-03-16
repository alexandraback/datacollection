#!/usr/bin/python


def odd_from_one(p):
    n = (p + 1) / 2;
    return - n * 2 * ( n + 1 ) + n + n * 2 * ( n  * 2 + 1 ) * ( n + 1 ) / 3

def even_from_two(p):
    n = (p) / 2;
    return n * 2 * ( n  * 2 + 1 ) * ( n + 1 ) / 3;

def calc(MM):
    if( R % 2 == 1):
        return ( even_from_two( R+1+(MM-1)*2) - odd_from_one(R+(MM-1)*2) ) - ( even_from_two( R-1 ) - odd_from_one( R-2) )
    else:
        return ( odd_from_one( R+1+(MM-1)*2) - even_from_two(R+(MM-1)*2) ) - ( odd_from_one( R-1 ) - even_from_two( R-2) )

T = int(raw_input())

for f in xrange(T):
    raw = raw_input()
    [R,total] = raw.split(' ')
    R = int(R)
    total = int(total)
    ans = R
    LL = 1
    RR = 100000000000000000
    while LL+1 < RR:
        MM = (LL+RR)/2
        if calc(MM) <= total:
            LL = MM
        else:
            RR = MM-1
    if calc(LL+1) <= total:
        ans = LL+1
    else:
        ans = LL
    print 'Case #' + str(f+1) + ': ' + str(ans) 


'''

int main(){
    int T, f=0;
    scanf("%d",&T);
    long long int ans;
    while(T--){
        scanf("%lld%lld",&R,&total);
        ans = 0;
        long long int LL, RR, MM, now;
        LL = 1;
        RR = 1000000ll; 
        while(LL+1 < RR){
            MM = (LL+RR)/2;
            fprintf(stderr,"=> %lld %lld\n",MM,calc(MM));
            if( calc(MM) <= total){
                LL = MM;
            }else{
                RR = MM-1;
            }
        }
        
        if( calc(LL+1) <= total ) ans = LL+1;
        else ans = LL;
        printf("Case #%d: %lld\n",++f,ans);
    }


'''
