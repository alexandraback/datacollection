def num(target):
    targets = str(target)
    minval = target - 10**(len(targets)-1)
    for i in xrange(len(targets)):
        left, right = int("0"+"".join(reversed(list(targets[:i])))), int("0"+targets[i:])
        if right == 0:
            continue
        if left == 1:
            val = right
        else:
            val = left + right
        if val < minval:
            minval = val
    if targets[-1] != "0":
        targets = "".join(list(reversed(targets)))
        for i in xrange(len(targets)):
            left, right = int("0"+"".join(reversed(list(targets[:i])))), int("0"+targets[i:])
            if right == 0:
                continue
            val = left + right + 2
            if val < minval:
                minval = val
    else:
        if target > 0:
            minval = min(minval, num(target - 1) + 1)
    #print target, minval
    return minval

def value(N):
    total = 1
    for i in xrange(1, len(str(N))):
        total += num(int("9"*i)) + 1
    total += num(N)
    return total

if __name__ == "__main__":
    for case in range(input()):
        print "Case #%s:" % (case+1),
        N = int(raw_input())
        #print "N", N
        print value(N)
