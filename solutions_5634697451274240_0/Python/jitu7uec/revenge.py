T = input()

for j in range(T):
    
    inp = raw_input()

    prev = None
    count = 0
    for c in inp:
        if prev is not None and c == prev:
            continue
        count += 1
        prev = c

    if prev is "+":
        ans = count-1
    else:
        ans = count

    print "Case #%d: %d" % (j+1, ans)
