lines = int(raw_input())

for i in range(lines):
    st = raw_input().split()
    a, b = int(st[0]), int(st[1])
    p = 0
    for n in range(a, b+1):
        m = []
        n_str = str(n)
        for sw in range(len(n_str) - 1):
            if n_str[sw+1] == '0':
                continue
            new = n_str[sw+1:] + n_str[:sw+1]
            #if new[0] == '0':
                #continue
            #print n, new
            if int(new) > n and int(new) <= b:
                if new not in m:
                    p += 1
                    m.append(new)
                #print n, new, m
    print "Case #{0}: {1}".format(i+1,p)
    #print a, b
