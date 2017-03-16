from sys import stdin as IN

for _ in range(int(IN.readline())):
    print "Case #%s:" % (_+1),
    firsts = []
    seconds = []
    for _ in range(int(IN.readline())):
        f, s = IN.readline().split()
        firsts.append(f)
        seconds.append(s)
    answer = 0
    q = [[0, 0, firsts, seconds]]
    while q:
        count, i, fs, ss = q.pop(0)
        if i == len(fs):
            continue
        if fs[i] in fs[:i] + fs[i+1:] and ss[i] in ss[:i] + ss[i+1:]:
            q.append([count + 1, i, fs[:i] + fs[i + 1:], ss[:i] + ss[i + 1:]])
            if count + 1 > answer:
                answer = count + 1
        q.append([count, i+1, fs, ss])

    print answer
