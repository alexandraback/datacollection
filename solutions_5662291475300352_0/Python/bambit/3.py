inp = open('3.test')

T = int(inp.readline().rstrip())
for t in range(1,T+1):
    N = int(inp.readline().rstrip())

    hikers = []
    for n in range(N):
        startloc, numhikers, fastest = map(int, inp.readline().rstrip().split())
        for i in range(numhikers):
            hikers.append((fastest+i, startloc))

    if len(hikers) == 1:
        answer = 0
    else:
        hikers.sort()
        fht, fhs = hikers[0]
        sht, shs = hikers[1]

        shd = 360 - shs
        fhd = 360 - fhs + 360

        # Won't catch
        if shd * sht < fhd * fht:
            answer = 0
        else:
            answer = 1

    print 'Case #%d: %d' % (t, answer)
