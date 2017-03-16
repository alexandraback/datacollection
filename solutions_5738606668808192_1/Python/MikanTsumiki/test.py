def solve(n,J):
    x = 2**(n-1) +1
    div=[3, 2, 5, 2, 7, 2, 3, 2, 7]
    def check(w):
        for base in range(2,11):
            if(int(bin(w)[2:],base)%div[base-2]!=0):
                return False
        return True
    while True:
        if check(x):
            print bin(x)[2:],"3 2 5 2 7 2 3 2 7"
            J-=1
        x+=2
        if J==0:break
cas = int(raw_input())
for i in range(1, cas+1):
    print "Case #%d:" %i
    n,J = map(int,raw_input().split())
    solve(n,J)

