def decrease(a, n):
    for i in xrange(len(a)):
        if a[i] % n == 0: a[i] /= n

def count2(n):
    count = 0
    while n != 0:
        if (n & 1) == 0: count += 1
        n >>= 1
    return count

def output(a):
    print ''.join(map(str, a))

testcase = int(raw_input())
R, N, M, K = map(int, raw_input().split())
print 'Case #1:'
for noK in range(R):
    a = map(int, raw_input().split())
    #print a
    ans = []
    c5 = 0
    c3 = 0
    for _ in xrange(3):
        for i in xrange(len(a)):
            if a[i] % 5 == 0:
                ans.append(5)
                decrease(a, 5)
                c5 += 1
            if a[i] % 3 == 0:
                ans.append(3)
                decrease(a, 3)
                c3 += 1
    if c5 + c3 == N:
        output(ans)
        continue
    twos = [0] * 12
    for i in xrange(len(a)):
        twos[count2(a[i])] += 1
#    if twos[4] > 0:
#        print '224'
#        continue
    if twos[6] > 0:
        print '444'
        continue
    if twos[5] > 0:
        print '244'
        continue
    if c5 + c3 == N - 1:
        if twos[1] > 0:
            output(ans + [2])
            continue
        elif twos[2] > 0:
            output(ans + [4])
            continue
        else:
            output(ans + [2])
            continue
    if c5 + c3 == N - 2:
        if twos[4] > 0:
            output(ans + [4, 4])
            continue
        if twos[3] > 0 or (twos[1] > 0 and twos[2] > 0):
            output(ans + [2, 4])
            continue
        else:
            output(ans + [2, 2])
            continue
    if c5 + c3 == N - 3:
        if twos[1] > 0:
            print '224'
            continue
    print '222'
            
