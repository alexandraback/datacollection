import sys
ncases = int(raw_input())
for case in range(ncases):
    n = int(raw_input())
    if n == 0:
        print "Case #%d: INSOMNIA" % (case + 1)
        continue
    seen = set()
    acc = 0
    for i in range(1,100000):
        acc += n
        for ch in str(acc):
            seen.add(ch)
        if len(seen) == 10:
            print "Case #%d: %d" % (case + 1, acc)
            break
