
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
    prob_correct = 1.0
    for i in xrange(0,A+1):
        # Backspace A-i times.
        prob_error = 1 - prob_correct
        cost = 2*(A-i) + (B - A + 1) + prob_error*(B + 1)
        answer = min(answer, cost)

        if i == A:
            break

        # Update
        prob_correct *= p[i]

    print "Case #{}: {}".format(t, answer)
