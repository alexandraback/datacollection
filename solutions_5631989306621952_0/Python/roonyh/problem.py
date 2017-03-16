lines = [line.rstrip() for line in open('small.in')]

for i in range(int(lines[0])):
    s = lines[i+1]
    sa = [s[0]]

    for a in s[1:]:
        if(a>=sa[0]):
            sa.insert(0, a)
        else:
            sa.append(a)

    print 'Case #%d: %s' % (i+1, "".join(sa))
