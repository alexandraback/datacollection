def count_trans(cake):
    f = cake[0]
    cnt=0
    for tf in cake[1:]:
        if f!=tf:
            cnt=cnt+1
            f=tf
    return cnt

for tc in range(input()):
    cake = raw_input()
    cnt = count_trans(cake)
    if cake[-1]=='-':
        cnt=cnt+1
    print "Case #%d: %d" % (tc + 1, cnt)
