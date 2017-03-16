T = input()

def findLast(s, val):
    ans = []
    first = 'A'
    for c in s:
        if c >= first:
            ans.insert(0,c)
            first = c
        else:
            ans.append(c)

    return ''.join(ans)


for i in range(1, T + 1):
    s = raw_input()
    print "Case #%d: %s" % (i, findLast(s,[]))