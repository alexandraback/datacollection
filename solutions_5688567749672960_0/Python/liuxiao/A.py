
#def calc(n):
#    now = 1
#    count = 1
#    while now < n:
#        reverse = int(str(now)[::-1])
#        now_1   = now + 1
#        now     = max(now_1, reverse)
#        if now > n:
#            now = now_1
#        count += 1
#    return count

#min_count = {1 : 1}
#
#def calc(n):
#    if n in min_count:
#        return min_count[n]
#    next_n  = calc(n - 1)
#    reverse = int(str(n)[::-1])
#    if reverse != n:
#        count = min(reverse, next_n)
#    else:
#        count = next_n
#    min_count[n] = count + 1
#    return count + 1

min_count = {1 : 1}
max_avail = 1

def calc(n):
    global max_avail
    if n <= max_avail:
        return min_count[n]
    for i in range(max_avail + 1, n + 1):
        reverse = int(str(i)[::-1])
        count   = min_count[i - 1]
        if reverse < i and i % 10:
            count = min(count, min_count[reverse])
        min_count[i] = count + 1
    max_avail = n
    return min_count[n]

T = input()
for t in range(T):
    n = input()
    result = calc(n)
    print 'Case #%d: %d' % (t + 1, result)
