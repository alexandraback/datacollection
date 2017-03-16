import sys

#sys.stdin = open("A-large.in", "r")
#sys.stdout = open("out.txt", "w")

t = int(input())

for i in range(t):
    n = int(input())
    if n == 0:
        print("Case #%d: INSOMNIA"%(i+1))
        continue
    counter = {}
    for k in range(1, 100):
        nstr = str(n * k)
        for c in nstr:
            counter[int(c)] = 1
        if len(counter) == 10:
            print("Case #%d: %d"%(i+1, n * k))
            break
#sys.stdout.close()
