data = open('A-small-attempt0.in', 'r')
T = int(data.readline().strip())
for case in range(1, T + 1):
    (A, B) = tuple(map(int, data.readline().split()))
    p = list(map(float, data.readline().split()))
    cumulative = [1.0]
    for i in range(A):
        cumulative.append(cumulative[-1] * p[i])
    # print cumulative

    emin = float(B + 2)
    # print 'break now', float(B + 2)
    for b in range(0, A+1):
        ethis = (B - A) + 1 + 2*b + (B + 1) * (1.0 - cumulative[A-b])
        if ethis < emin:
            emin = ethis
            # print 'backspace {} => {}'.format(b, emin)
    print 'Case #{}: {}'.format(case, emin)
