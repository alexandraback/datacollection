def solve(A, B, probs):
    sumprobs = [1.0]*(len(probs)+1)
    for i in range(1, len(probs)+1):
        sumprobs[i] = sumprobs[i-1]*probs[i-1]
    return min(B+2, min(expect(A, B, probs, i, sumprobs) for i in range(0, A+1)))

def expect(A, B, probs, i, sumprobs):
    return (A - i) + (B - i) + 1 + (1 - sumprobs[i])*(B+1)

T = int(raw_input())

for t in range(1, T+1):
    A, B = map(int, raw_input().split())
    probs = map(float, raw_input().split())
    print "Case #%d: %f" % (t, solve(A, B, probs))
