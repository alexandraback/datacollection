
def powerset(iterable):
    "powerset([1,2,3]) --> () (1,) (2,) (3,) (1,2) (1,3) (2,3) (1,2,3)"
    s = list(iterable)
    return from_iterable(combinations(s, r) for r in range(len(s)+1))

def combinations(iterable, r):
    # combinations('ABCD', 2) --> AB AC AD BC BD CD
    # combinations(range(4), 3) --> 012 013 023 123
    pool = tuple(iterable)
    n = len(pool)
    if r > n:
        return
    indices = range(r)
    yield tuple(pool[i] for i in indices)
    while True:
        for i in reversed(range(r)):
            if indices[i] != i + n - r:
                break
        else:
            return
        indices[i] += 1
        for j in range(i+1, r):
            indices[j] = indices[j-1] + 1
        yield tuple(pool[i] for i in indices)

def from_iterable(iterables):
    # chain.from_iterable(['ABC', 'DEF']) --> A B C D E F
    for it in iterables:
        for element in it:
            yield element

def process(s):
    all_nums = map(int, s.split())
    num_set = all_nums[1:]

    ps = powerset(num_set)

    d = {}
    for s in ps:
        the_sum = sum(s)
        if the_sum in d:
            return "\n" + ' '.join([str(e) for e in s]) + "\n" + ' '.join([str(e) for e in d[the_sum]])
        else:
            d[the_sum] = s

    return

#print process('20 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20')
#print process('20 120 266 858 1243 1657 1771 2328 2490 2665 2894 3117 4210 4454 4943 5690 6170 7048 7125 9512 9600')

number_of_cases = int(raw_input())
for case_number in xrange(1, number_of_cases+1):
    s = raw_input()

    result = process(s)

    print "Case #%d: %s" % (case_number, result)
    case_number += 1