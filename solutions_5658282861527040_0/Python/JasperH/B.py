def solve(testnum):
    a,b,k = [int(x) for x in input().split()]
    out = 0
    for i in range(a):
        for j in range(b):
            if i&j < k: out += 1
    print("Case #%d: %d"%(testnum,out))

for i in range(int(input())): solve(i+1)
