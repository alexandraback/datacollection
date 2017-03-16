def solve(A, B, probs):
    return min(B+2, min(expect(A, B, probs, i) for i in range(0, A+1)))

def expect(A, B, probs, i):
    p = 1.0
    for j in range(i):
        p *= probs[j]
    return (A - i) + (B - i) + 1 + (1 - p)*(B+1)

T = int(raw_input())

for t in range(1, T+1):
    A, B = map(int, raw_input().split())
    probs = map(float, raw_input().split())
    print "Case #%d: %f" % (t, solve(A, B, probs))
