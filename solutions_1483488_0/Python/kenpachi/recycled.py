import sys

T = int(sys.stdin.readline())
result = []
generated = {}
for i in range(T):
    A, B = [int(i) for i in sys.stdin.readline().strip().split()]
    count = 0
    for j in range(A, B):
        jstr = str(j)
        generated.clear()
        for k in range(len(jstr) - 1):
            jstr = jstr[-1] + jstr[:-1]
            recycled = int(jstr)
            if j < recycled <= B:
                if not generated.has_key(recycled):
                    generated[recycled] = 1
                    count += 1

    result.append(count)
    

for i, v in enumerate(result):
    print "Case #%d: %d" % (i+1, v)
