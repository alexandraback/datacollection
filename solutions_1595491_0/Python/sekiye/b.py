def solve():
    v = map(int, raw_input().split())
    S = v[1]
    p = v[2]
    t = v[3:]
    t.sort(reverse=True)
    count = 0
    for sum_of_score in t:
        score = sum_of_score / 3
        if sum_of_score % 3 > 0:
            score += 1
        if score >= p:
            count += 1
        elif S > 0:
            if sum_of_score != 0 and sum_of_score % 3 != 1:
                score += 1
                S -= 1
                if score >= p:
                    count += 1
    return count

T = int(raw_input())
for i in range(T):
    print "Case #%d:" % (i + 1), solve()
