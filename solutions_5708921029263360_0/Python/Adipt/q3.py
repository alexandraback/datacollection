def ciel(x):
    if (x!=int(x)):
        return int(x+1)
    return x

def per(a, b):
    if a%b==0:
        return b
    else:
        return a%b

t = int(raw_input())
u = 0
while u<t:
    u+=1
    print "Case #%d:" %u,
    j, p, s, k = map(int, raw_input().split())
    fr = p*s
    tsum = 0
#    f1 = ((k*k*(p/k))+(p%k)*min(k,(s-(p/k))))
 #   print f1*j
    arr = []
    arr_t = []
    for i in range(1, k+1):
        for m in range(1, k+1):
            arr_t.append([1, i, m])
    for i in range(p/k):
        for m in arr_t:
            arr.append([m[0], m[1]+k*i, m[2]+k*i])
    for i in range(k*(p/k) + 1, p+1):
        for m in range(k*(p/k) + 1, min(k*(p/k)+k, s)+1):
            arr.append([1, i, m])
    print len(arr)*j
    for i in range(j):
        for m in arr:
            print per(m[0]+i, j), per(m[1]+i*k, p), m[2]
