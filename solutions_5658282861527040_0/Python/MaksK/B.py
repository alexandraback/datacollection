asd = int(raw_input())

for asdf in range(asd):
    a, b, k = map(int, raw_input().split())
    num = 0
    for i in range(a):
        for j in range(b):
            if i&j < k:
                num += 1
    print "Case #%d: %d" % (asdf+1, num)

