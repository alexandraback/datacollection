import sys,math

def printerr(*a,**b):
    print(*a,file=sys.stderr,**b)

def find_div(a):
    i = 1
    l = math.sqrt(a)
    while i < (min(l,100)): # We don't need that many coins, we can
                            # restrict to small factors
        i += 2
        if (a % i) == 0:
            return i
    return None

def main_gen(N):
    for v in range(2**(N-2)):
        vv = 2**(N-1) + 2*v + 1
        s = "{:b}".format(vv)
        divs = [find_div(int(s,b)) for b in range(2,11)]
        if None not in divs:
            yield (s,divs)
        
def main(J,N):
    res = []
    gen = main_gen(N)
    for i in range(J):
        nxt = next(gen)
        res.append(nxt)
        printerr(i,nxt)
    return res


if __name__ == "__main__":
    T = int(input())
    for c in range(T):
        ## Input
        N,J = [int(i) for i in input().split()]
        
        ## Processing
        res = main(J,N)
        
        ## Output
        print("Case #{}:".format(c+1))
        for r in res:
            cj,divs = r
            print(cj," ".join(map(str,divs)))


