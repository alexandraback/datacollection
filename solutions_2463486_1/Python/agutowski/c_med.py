def is_pal(x):
    n = len(x)
    return x[:n/2][::-1] == x[(n+1)/2:]
i = 1
nums = []
while i**2<=1e14:
    if is_pal(str(i)) and is_pal(str(i**2)): nums.append(i)
    i+=1
T = input()
for t in range(1,T+1):
    A, B = raw_input().split()
    A = int(A)
    B = int(B)
    res = 0
    for i in nums:
        if i**2<A: continue
        if i**2>B: break
        res += 1
    print "Case #{0}: {1}".format(t,res)
