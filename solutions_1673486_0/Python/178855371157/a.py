
def prod(xs):
    ret = 1.0
    for x in xs:
        ret *= x
    return ret

T = input()
for t in range(1,T+1):
    [A, B] = [int(x) for x in raw_input().split()]
    p = [float(x) for x in raw_input().split()]

    # Option 3.
    answer = B + 2

    # Options 1 and 2.
    for i in range(0,A):
        # i backspaces
        prob_error = 1 - prod(p[:A-i])
        cost = i + (B - A + 1 + i) + prob_error*(B + 1)
        answer = min(answer, cost)

    print "Case #{}: {}".format(t, answer)
