for t in range(input()):
    print "Case #%s:" % str(t + 1),
    n = input()
    kids = map(lambda x: int(x) - 1, raw_input().split())
    # print kids
    cyclist = set()
    free = set()
    res = 0
    legs = [0 for _ in range(n)]
    for i in range(n):
        if i in cyclist or i in free:
            continue
        trace = set()
        e = i
        while (True):
            if e in trace:
                cyclist.update(trace)
                l = 1
                end = e
                e = kids[e]
                while e != end:
                    e = kids[e]
                    l += 1
                res = max(res, l)
                break
            trace.add(e)
            if e in free:
                legs[e] = max(legs[e], len(trace))
                break
            elif kids[kids[e]] == e :
                free.update( [e, kids[e]])
                legs[e] = max(legs[e], len(trace))
                legs[kids[e]] = 1
                break
            elif kids[e] in cyclist:
                cyclist.update(trace)
                break
            else:
                e = kids[e]
    # print legs
    print max(res, sum(legs))
