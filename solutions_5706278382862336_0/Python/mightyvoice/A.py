
def gcd(x,y):
    if x % y == 0:
        return y;
    else:
        return gcd(y, x%y);

def exist(x):
    ans = 1;
    while(1):
        if(ans > x):
            return 0;
        if(ans == x):
            return 1;
        ans *= 2;

def solve(x,y):
    t = gcd(x,y);
    x /= t;
    y /= t;
    if(exist(y) == 0):
        return 0;
    ans = 0;
    while(1):
        if(x >= y/2):
            ans += 1;
            break;
        y /= 2;
        ans += 1;
    return ans;

if __name__ == '__main__':
    f1 = open('A-small-attempt0 (1).in', 'r');
    f2 = open('out.txt', 'w');
    T = map(int, f1.readline().split())[0];
    for test in range( T):
        f2.write( "Case #%d: " % (test+1));
        a,b = map(int, f1.readline().split('/'));
        tmp = solve(a,b);
        if(tmp == 0):
            f2.write("impossible\n");
        else:
            f2.write("%d\n" % tmp);
        

