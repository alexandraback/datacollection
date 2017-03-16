ans = {}
ans[0] = "INSOMNIA"
for i in xrange(1,1000005):
    done = set()
    cur = i
    while len(done) < 10:
        done |= set(list(str(cur)))
        cur += i
    ans[i] = cur-i

T = int(raw_input())

for i in xrange(T):
    N = int(raw_input())
    print ("Case #%d: " % (i+1)) + str(ans[N])
