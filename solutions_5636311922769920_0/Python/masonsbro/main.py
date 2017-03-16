T = int(raw_input())

for t in range(1,T+1):
    K, C, S = map(int, raw_input().split())
    arr = [1]
    for k in range(K-1):
        arr.append(arr[-1] + K ** (C - 1))
    print "Case #%d: %s" % (t, " ".join(map(str, arr)))