from scipy.misc import comb


def binomial_distribution(n, x, big_pyromid_side):
    # P(\xi >= x), \xi distibuted binomially with n experiments
    good_outcomes = range(x, n + 1)
    # print sum([comb(n, out, exact=True) for out in good_outcomes])
    # print sum(comb(n, good_outcomes))
    # print "\n"
    answ_prob = float(sum([comb(n, out, exact=True) for out in good_outcomes])) / 2**n
    # if n > big_pyromid_side:
    #      + range(big_pyromid_side, n + 1)

    return answ_prob


def my_prob(n, x, y):
    if x == 0 and y == 0:
        if n >= 1:
            return 1.0
        else:
            return 0.0

    a = abs(x) + y - 1  # Foundation of the pyromid
    elements_for_pyr = a * (a + 1) / 2
    # print a, elements_for_pyr
    if (n <= elements_for_pyr):
        return 0.0
    experiments = n - elements_for_pyr
    if y == a + 1:
        # Top of the pyromid
        assert (x == 0)
        elements_for_bigger_pyromid = (a + 2) * (a + 3) / 2
        # print elements_for_bigger_pyromid
        if n >= elements_for_bigger_pyromid:
            return 1.0
        else:
            return 0.0
    big_pyromid_side = a + 2
    # We will succed if at least Y + 1 out of 'experiments' will be 1
    # print experiments, y + 1
    if experiments < y + 1:
        return 0.0
    if experiments >= big_pyromid_side + y:
        return 1.0
    print big_pyromid_side + (y + 1)
    answ_prob = binomial_distribution(experiments, y + 1, big_pyromid_side)
    assert(answ_prob >= 0.0 and answ_prob <= 1.0)
    return answ_prob

fin = open("B-large.in", "r")
fout = open("output.txt", "w")
T = int(fin.readline())
for test_case in range(T):
    n, x, y = fin.readline().split()
    n, x, y = int(n), int(x), int(y)

    fout.write("Case #%d: %.10f\n" % (test_case + 1, my_prob(n, x, y)))
    # print"Case #%d: %f\n" % (test_case + 1, my_prob(n, x, y))
