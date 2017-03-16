__author__ = 'eidanch'


def get_line():
    return raw_input().strip()

formatIntegerList = lambda s: list(map(int, s.split(' ')))


def standard_input():
    T = int(get_line())
    for i in range(T):
        params = tuple(map(int, get_line().split(' ')))
        keyboard = get_line()
        word = get_line()
        yield (i+1, (params, keyboard, word))


def handle_case(case):
    params, keyboard, word = case
    K, L, S = params
    pc = get_prob(word, keyboard)
    e = (S - (L - 1))*pc
    if e <= 0:
        return 0.0
    max_bananas = get_max_bananas(word, S)
    #print max_bananas, e
    return max_bananas - e


def get_prob(word, keyboard):
    result = 1.0
    real_k = 1.0*len(keyboard)
    for c in word:
        result *= len([k for k in keyboard if k == c])/real_k
    return result


def get_max_bananas(word, S):
    for i in xrange(1, len(word)):
        if word[i:] == word[:-i]:
            j = len(word) - i
            return (S - j) / i
    return S/len(word)

def main():
    for i, case in standard_input():
        print "Case #%d: %.7f" % (i, handle_case(case))

if __name__ == '__main__':
    main()