import sys

memo = {}
def probability_correct(a, p):
    if (a,p) in memo:
        return memo[(a,p)]
    acc = 1
    for i in range(a):
        acc *= p[i]
    memo[(a,p)] = acc
    return acc

def expected_chars(c, p):
    a, b = c
    pc = probability_correct(a, p)
    min_typed_chars = 1.0 + b-a
    choice_1 = min_typed_chars + (1-pc)*(b+1)
    return choice_1

def optimal_deletes(c, p):
    a, b = c
    return min((i + expected_chars((a-i,b), p[0:a-i]), i) for i in range(a+1))[1]

def calc_expected(c,p):
    a, b = c

    # choice 1
    choice_1 = expected_chars(c, p)

    # choice 2
    k = optimal_deletes(c, p)
    pc = probability_correct(a-k, p)
    typed_deletes = k
    remaining = b - (a-k)
    min_typed_deletes = typed_deletes + remaining + 1
    choice_2 = min_typed_deletes + (1-pc)*(1 + b)

    # choice 3
    choice_3 = 2. + b

    return min(choice_1, choice_2, choice_3)

def main(args):
    afile = open(args[0])
    aline = afile.readline()
    lines = afile.readlines()
    characters = lines[0::2]
    probabilities = lines[1::2]
    for i, (c, p) in enumerate(zip(characters,probabilities), 1):
        p = tuple(map(float,p.split()))
        c = tuple(map(int, c.split()))
        expected = calc_expected(c,p)
        print "Case #%s: %s" % (i, expected)

if __name__=="__main__":
    main(sys.argv[1:])
