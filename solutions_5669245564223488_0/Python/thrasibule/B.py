import sys

def f_mod(n, modulus):
    ans = 1
    for i in range(1, n + 1):
        ans = ans * i % modulus
    return ans % modulus

def test1(l):
    # given a list of words returns True if the inner letters
    # are all disjoint
    return len(set.intersection(*[set(w[1:-1]) for (w, c) in l if len(w)>=2]))==0

def test2(w):
    d = {}
    for i, l in enumerate(w):
        if l in d:
            if i>d[l]+1:
                return False
            else:
                d[l]=i
        else:
            d[l]=i
    return True


def f(l):
    l = [(w, []) for w in l]
    letter_set = set(list("".join(w for (w, c) in l)))
    for letter in letter_set:
        bag = [(w, c) for (w, c) in l if letter in w]
        interesting_bag = [(w, c) for (w, c) in bag if w != letter * len(w)]
        stupid = len(bag) - len(interesting_bag)
        if len(interesting_bag) > 2:
            return 0
        elif len(interesting_bag) == 2:
            (w_1, c_1), (w_2, c_2) = interesting_bag
            if w_1[0] == w_2[-1] == letter:
                w_t = w_2 + w_1
                c_t = c_1 + c_2
            elif w_1[-1] == w_2[0] == letter:
                w_t = w_1 + w_2
                c_t = c_1 + c_2
            else:
                return 0
        elif len(interesting_bag) == 1:
            (w_t, c_t) = interesting_bag[0]
        else:
            w_t, c_t = letter, []
        c_t += [stupid]
        l = [(w_t, c_t)] + [(w, c) for (w, c) in l if letter not in w]
    ans = 1
    for (w, c) in l:
        for u in c:
            ans = ans * f_mod(u, 1000000007) % 1000000007
    ans = ans * f_mod(len(l), 1000000007) % 1000000007
    return ans

with open(sys.argv[1]) as fh:
    T = int(fh.readline())
    for i in range(T):
        N = int(fh.readline())
        words = fh.readline().split(" ")
        print "Case #{0}: {1}".format(i+1, f(words))
