import os

fp = open('test')
of = open('416-01','w')
s = map(lambda x: x.strip(), fp.readlines())
s = s[1:]
cnt = 0
for string in s:
    print string
    cnt += 1
    ll = [];
    idx = 0;
    for ch in string:
        if idx == 0:
            ll.append(ch)
            idx += 1
            continue
        if ch >= ll[0]:
            ll.insert(0, ch)
        else:
            ll.append(ch)

    print >>of, 'Case #%d: %s' % (cnt, ''.join(ll))


