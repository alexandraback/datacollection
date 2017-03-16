from base import cases

def solve(n):
    digs=set()
    n=int(n)
    if n == 0: return "INSOMNIA"
    x = 1
    while True:
        digs.update(str(x*n))
        if len(digs) == 10:
            return x*n
        x+=1

if __name__ == "__main__":
    cases(solve)

def x():
    n = int(raw_input())
    for case in range(n):
        print "Case #{}: {}".format(case+1, ret)

