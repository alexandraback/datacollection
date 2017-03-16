import sys
readline = sys.stdin.readline
def solve(a, ms):
#    print a
#    print ms
    score = len(ms)
    min_score = score
    nextIdx = 0
    l = len(ms)
    while nextIdx < l:
        w = ms[nextIdx]
        if w < a:
            # swallow it, decrease score by 1
            a += w
            score -= 1
            min_score = min(score, min_score)
            nextIdx += 1
        else:
            # add one mote
            if a==1:
                # can't add more mote
                return min(min_score, score)
            a = 2*a -1
            score += 1
    return min_score

def main():
    T = int(readline())
    for i in range(T):
        a, N = map(int, readline().split())
        ms = map(int, readline().split())
        print "Case #%d: %d" % (i+1, solve(a, sorted(ms)))
main()
            
