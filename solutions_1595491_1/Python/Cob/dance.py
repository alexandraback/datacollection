import sys
f = sys.stdin

cases = int(f.readline())
for caseno in range(1, cases + 1):
    ln = list(map(int, f.readline().split()))
    n = ln[0]
    s = ln[1]
    p = ln[2]
    scores = ln[3:len(ln)]
    scores.sort(reverse=True)
    cnt = 0
    for i in range(n):
        score = scores[i]
        if score >= 3*p:
            cnt += 1
            continue
        elif score < p:
            continue
        score -= p
        l1 = int(score / 2)
        l2 = score - l1
        st = min(l1, l2)
        if p - st < 2:
            cnt += 1
        elif p - st == 2 and s > 0:
            cnt += 1
            s -= 1
        else:
            break
    print("Case #{0}: {1}".format(caseno, cnt))
    
        