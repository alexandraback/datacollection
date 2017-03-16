import sys
def solve(n):
    curr = n
    prev = None
    digi = ['0','1','2','3','4','5','6','7','8','9']
    coeff = 2
    while prev != curr and len(digi):
        s = str(curr)
        #print(prev,file=sys.stderr)
        #print(s,file=sys.stderr)
        #print(digi,file=sys.stderr)
        for d in s:
            if d in digi:
                pos = digi.index(d)
                digi.pop(pos)
        prev = curr
        curr = n*coeff
        coeff += 1

    if prev == curr:
        return "INSOMNIA"
    else:
        return str(prev)

t = int(input())
for i in range(1,t+1):
    n = int(input())
    print("Case #"+str(i)+": "+solve(n))
