#  Technobabble

def technobabble(topics):
    ret = len(topics)
    for b in range(1 << len(topics)):
        f = []
        s = []
        t = 0
        for i in range(len(topics)):
            if b & (1 << i) != 0:
                f.append(topics[i][0])
                s.append(topics[i][1])
                t += 1
        cov = True
        for i in range(len(topics)):
            if not topics[i][0] in f:
                cov = False
            if not topics[i][1] in s:
                cov = False
        if cov:
            ret = min(ret, t)
    return len(topics) - ret

cases = int(raw_input())
for case in range(1, cases + 1):
    n = int(raw_input())
    topics = [raw_input().split(' ') for i in range(n)]
    print "Case #" + str(case) + ": " + str(technobabble(topics))
